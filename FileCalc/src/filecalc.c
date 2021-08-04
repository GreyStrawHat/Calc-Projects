#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>

#include "filecalc.h"
#include "the_maths.h"

int read_dir(const char * in_dir, const char * out_dir)
{
    DIR * input_directory = NULL;
    DIR * output_directory = NULL;
    struct dirent * entry = NULL;
    char * out_file_name = NULL;
    char extension[5] = ".out";
    int total_files = 0;
    int in_dir_file_desc = 0;
    int out_dir_file_desc = 0;
    int in_fd = 0;
    int out_fd = 0;
    uint32_t file_magic_number = 0;
    int valid = 0;
    int exit_code = 0;

    //Open directories
    input_directory = opendir(in_dir);
    if (NULL == input_directory)
    {
        perror("read_dir(): opendir():");
        goto EXIT;
    }
    output_directory = opendir(out_dir);
    if (NULL == output_directory)
    {
        perror("read_dir(): opendir():");
        goto EXIT;
    }

    //Record directory file descriptors
    in_dir_file_desc = dirfd(input_directory);
    out_dir_file_desc = dirfd(output_directory);
    
    #ifdef DEBUG
    puts("Reading in_dir");
    #endif

    //Check each file in input directory
    for (;;)
    {
        entry = readdir(input_directory);
        if (NULL == entry)
        {
            break;
        }

        //Gets rid of the ".", ".."
        if ((0 != strncmp(entry->d_name, ".", 1)) && 
            (0 != strncmp(entry->d_name, "..", 2)))
        {
            total_files++;

            #ifdef DEBUG
            printf("FILE %2d:\t%s\n", total_files, entry->d_name);
            #endif

            //Open file, read and validate, increment and record fd
            in_fd = openat(in_dir_file_desc, 
                                  (const char *)entry->d_name, 
                                  O_RDONLY|__O_CLOEXEC); //NOLINT: Yell at the the man-pages, not me
            //Get input file magic number
            if (0 >= in_fd)
            {
                goto EXIT;
            }
            if (4 != read(in_fd, &file_magic_number, 4))
            {
                goto EXIT;
            }

            if (HDR_MAG_NUM == file_magic_number)
            {
                valid++;
                out_file_name = calloc((strlen(entry->d_name)+5), sizeof(char));
                if (NULL == out_file_name)
                {
                    goto EXIT;
                }
                strncpy(out_file_name, entry->d_name, strlen(entry->d_name));
                strncat(out_file_name, extension, 5);

                out_fd = openat(out_dir_file_desc, 
                        (const char *)out_file_name, 
                        O_CREAT|O_WRONLY|O_APPEND,//NOLINT: Yell at the the man-pages, not me
                        S_IRUSR|S_IWUSR|S_IROTH|S_IRWOWN);//NOLINT: Yell at the the man-pages, not me
                if (0 >= out_fd)
                {
                    goto EXIT;
                }
                if (0 != handle_files(in_fd, out_fd))
                {
                    fprintf(stderr, "Could not process %s.\n", out_file_name);
                }
                free(out_file_name);
                out_file_name = NULL;
            } 
        }
    }

    EXIT:
    {
        if (NULL != out_file_name)
        {
            free(out_file_name);
            out_file_name = NULL;
        }
        if (NULL != input_directory)
        {
            closedir(input_directory);
        }
        
        if (NULL != output_directory)
        {
            closedir(output_directory);
        }
        close(in_fd);
        close(out_fd);
        return exit_code;
    }
} 

int handle_files(const int in_fd, int out_fd)
{
    int exit_code = 0;
    uint32_t hdrlen = 0;
    eq_hdr_t * in_hdr = NULL;
    uint8_t flag = SOLVED;

    in_hdr = calloc(1, sizeof(eq_hdr_t));
    if (NULL == in_hdr)
    {
        goto EXIT;
    }
    lseek(in_fd, 0, SEEK_SET);

    //Get file header info from input file
    if (sizeof(in_hdr->magic) !=   read(in_fd, &in_hdr->magic, sizeof(in_hdr->magic)) ||
        sizeof(in_hdr->file_id) != read(in_fd, &in_hdr->file_id, sizeof(in_hdr->file_id)) ||
        sizeof(in_hdr->num_eq) !=  read(in_fd, &in_hdr->num_eq, sizeof(in_hdr->num_eq)) ||
        sizeof(in_hdr->flags) !=   read(in_fd, &in_hdr->flags, sizeof(in_hdr->flags)) ||
        sizeof(in_hdr->offset) !=  read(in_fd, &in_hdr->offset, sizeof(in_hdr->offset))
        )

    {
        perror("handle_files(): read():");
        printf("IN FILE HDR:\nMAGIC: %u\nID: %lu\nNUM EQU: %lu\nFLAGS: %u\nOFFSET: %u\n", in_hdr->magic, in_hdr->file_id, in_hdr->num_eq, in_hdr->flags, in_hdr->offset);
        goto FAIL;
    }

    //Write out file header
    if (sizeof(in_hdr->magic) !=         write(out_fd, &in_hdr->magic, sizeof(in_hdr->magic)) ||
        sizeof(in_hdr->file_id) !=       write(out_fd, &in_hdr->file_id, sizeof(in_hdr->file_id)) ||
        sizeof(in_hdr->num_eq) !=        write(out_fd, &in_hdr->num_eq, sizeof(in_hdr->num_eq)) ||
        sizeof(in_hdr->flags) !=         write(out_fd, &flag, sizeof(in_hdr->flags)) ||
        sizeof(in_hdr->offset) !=        write(out_fd, &in_hdr->offset, sizeof(in_hdr->offset)) ||
        sizeof(in_hdr->addtl_headers) != write(out_fd, &in_hdr->addtl_headers, sizeof(in_hdr->addtl_headers))
        )
    {
        perror("handle_files(): write():");
        goto FAIL;
    }
    
    if (0 != solve_equations(in_fd, in_hdr->num_eq, out_fd, in_hdr->offset))
    {
        fprintf(stderr, "handle_files(): couldn't solve equations.\n");
        goto FAIL;
    }

    goto EXIT;

    FAIL:
        fprintf(stderr, "handle_files() failed.\n");
        exit_code = 1;

    EXIT:
    {
        if (NULL != in_hdr)
        {
            free(in_hdr);
            in_hdr = NULL;
        }
        return exit_code;
    }
}

int solve_equations(const int in_fd, 
                    uint64_t num_eq, 
                    int out_fd, 
                    uint32_t offset)
{
    int exit_code = 0;
    off_t current = 0;
    uint64_t equation = 0;
    unsolved_eq_t * unsolved_equation = NULL;
    solved_eq_t * solved_equation = NULL;
    bin_ser_t * eq_serial = NULL;

    unsolved_equation = calloc(1, sizeof(unsolved_eq_t));
    eq_serial = calloc(1, sizeof(bin_ser_t));
    solved_equation = calloc(1, sizeof(solved_eq_t));
    if (NULL == unsolved_equation || 
        NULL == eq_serial || 
        NULL == solved_equation)
    {
        fprintf(stderr, "solve_equations(): couldn't allocate memory.\n");
        exit_code = 1;
        goto EXIT;
    }

    lseek(in_fd, offset, SEEK_SET);
    lseek(out_fd, offset, SEEK_CUR);

    //Get each equation
    while (equation < num_eq && equation < MAX_EQUATIONS)
    {
        current = lseek(in_fd, 0, SEEK_CUR);
        if (sizeof(eq_serial->id) !=            read(in_fd, &eq_serial->id, sizeof(eq_serial->id)) ||
            sizeof(eq_serial->flags) !=         read(in_fd, &eq_serial->flags, sizeof(eq_serial->flags)) ||
            sizeof(unsolved_equation->num_1) != read(in_fd, &unsolved_equation->num_1, sizeof(unsolved_equation->num_1)) ||
            sizeof(unsolved_equation->op) !=    read(in_fd, &unsolved_equation->op, sizeof(unsolved_equation->op)) ||
            sizeof(unsolved_equation->num_2) != read(in_fd, &unsolved_equation->num_2, sizeof(unsolved_equation->num_2))
            )
        {
            perror("solve_equations(): read():");
            printf("ID: %u\nFLAGS: %u\nNUM1: %lu\nOP: %u\nNUM2: %lu\n", eq_serial->id, eq_serial->flags, unsolved_equation->num_1, unsolved_equation->op, unsolved_equation->num_2);
            exit_code = 1;
            goto EXIT;
        }

        solved_equation->id = eq_serial->id;
    
        //each equation block is padded to 32 bytes
        lseek(in_fd, PADDING, SEEK_CUR); 

        //Perform calculations and get solution information
        math(unsolved_equation, solved_equation);

        //Write solution to out file
        if (sizeof(solved_equation->id) !=   write(out_fd, &solved_equation->id, sizeof(solved_equation->id)) ||
            sizeof(solved_equation->flag) != write(out_fd, &solved_equation->flag, sizeof(solved_equation->flag)) ||
            sizeof(solved_equation->sol) !=  write(out_fd, &solved_equation->sol, sizeof(solved_equation->sol))
        )
        {
            perror("solve_equations(): write:");
            printf("%u\n", solved_equation->id);
            goto EXIT;
        }
        equation++;
    }

    EXIT:
        if (NULL != unsolved_equation)
        {
            free(unsolved_equation);
            unsolved_equation = NULL;
        }
        if (NULL != eq_serial)
        {
            free(eq_serial);
            eq_serial = NULL;
        }
        if (NULL != solved_equation)
        {
            free(solved_equation);
            solved_equation = NULL;
        }
            close(out_fd);
            return exit_code;
}

eq_flags_t math(unsolved_eq_t * unsolved_eq, solved_eq_t * solution)
{
    eq_flags_t exit_code = EQ_SOLVED;

    if (NULL == unsolved_eq || NULL == solution)
    {
        fprintf(stderr, "math(): invalid argument(s)\n");
        exit_code = 1;
        goto EXIT;
    }
 
    //Identifies and performs appropriate operation
    switch(unsolved_eq->op)
    {
        case ADDITION:
            exit_code = addition(unsolved_eq->num_1, 
                                 unsolved_eq->num_2, 
                                 &solution->sol);
        break;

        case SUBTRACTION:
            exit_code = subtraction(unsolved_eq->num_1, 
                                    unsolved_eq->num_2, 
                                    &solution->sol);
        break;

        case MULTIPLICATION:
            exit_code = multiplication(unsolved_eq->num_1, 
                                       unsolved_eq->num_2, 
                                       &solution->sol);
        break;

        case DIVISION:
            exit_code = divide(unsolved_eq->num_1, 
                               unsolved_eq->num_2, 
                               &solution->sol);
        break;

        case MODULO:
            exit_code = modulo(unsolved_eq->num_1, 
                               unsolved_eq->num_2, 
                               &solution->sol);
        break;

        case AND:
            exit_code = bit_and((uint64_t)unsolved_eq->num_1, 
                                (uint64_t)unsolved_eq->num_2, 
                                (uint64_t*)&solution->sol);
        break;

        case OR:
            exit_code = bit_or((uint64_t)unsolved_eq->num_1, 
                               (uint64_t)unsolved_eq->num_2, 
                               (uint64_t*)&solution->sol);
        break;

        case XOR:
            exit_code = bit_xor((uint64_t)unsolved_eq->num_1, 
                                (uint64_t)unsolved_eq->num_2, 
                                (uint64_t*)&solution->sol);
        break;

        case LSHIFT:
            exit_code = left_shift((uint64_t)unsolved_eq->num_1, 
                                   (uint64_t)unsolved_eq->num_2, 
                                   (uint64_t*)&solution->sol);
        break;

        case RSHIFT:
            exit_code = right_shift((uint64_t)unsolved_eq->num_1, 
                                    (uint64_t)unsolved_eq->num_2, 
                                    (uint64_t*)&solution->sol);
        break;

        case LROT:
            exit_code = rotate_left((uint64_t)unsolved_eq->num_1, 
                                    (uint64_t)unsolved_eq->num_2, 
                                    (uint64_t*)&solution->sol);
        break;

        case RROT:
            exit_code = rotate_right((uint64_t)unsolved_eq->num_1, 
                                     (uint64_t)unsolved_eq->num_2, 
                                     (uint64_t*)&solution->sol);
        break;

        default:
            solution->sol = 0;
            fprintf(stderr, "math(): Invalid operation.\n");
            exit_code = ERROR;
        break;
    }

    EXIT:
        solution->flag = exit_code;
        return exit_code;
}

int main(int argc, char ** argv)
{
    if (argc == 3 && strlen(argv[1]) <= ARG_LIMIT && strlen(argv[2]) <= ARG_LIMIT)
    { 
        read_dir(argv[1], argv[2]);
    }

    else
    {
        puts("ARGUMENT ERROR");
    }
    
    return 0;
}