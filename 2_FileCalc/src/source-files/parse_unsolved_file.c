#include "parse_unsolved_file.h"
#ifndef O_CLOEXEC   //Placed here to remove Intellisense issues
#define O_CLOEXEC 02000000 
#endif

int parse_unsolved_file(file_header_t * unsolved_header,
                        unsolved_equation_t * uequation,
                        struct dirent *     directory_entry,
                        char *              input_dir_arg,
                        char *              output_dir_arg)
{
    int     return_value     = 0;
    ssize_t file_size        = 0;
    char *  input_filepath_p = realpath(input_dir_arg, NULL);

    if ((NULL == unsolved_header) || (NULL == output_dir_arg) ||
        (NULL == directory_entry) || (NULL == input_dir_arg))
    {
        fprintf(stderr, RED "Error: NULL pointer\n");
        DEBUG_PRINT(YELLOW "[*] Error %d " RESET, errno);
        return_value = ERROR_CODE;
        goto END;
    }

    strncat(input_filepath_p, "/", (strlen("/") + NULL_BYTE_SIZE));

    strncat(input_filepath_p,
            directory_entry->d_name,
            sizeof(directory_entry->d_name) + 1);

    int fd = open(input_filepath_p, O_RDONLY | O_CLOEXEC);
    if (ERROR_CODE == fd)
    {
        DEBUG_PRINT("[ERROR] - Failed to open file %s\n", input_filepath_p);
        return_value = ERROR_CODE;
        goto END;
    }

    printf("\nTarget Equation File: %s\n", directory_entry->d_name);

    file_size = lseek(fd, 0, SEEK_END);

    printf("File Size: %ld\n", file_size);

    unsolved_header = parse_unsolved_header(fd, unsolved_header);

    if (((unsolved_header->num_of_e * UNSOLVED_EQUATION_LENGTH) +
         EQU_HEADER_LENGTH) != file_size)
    {
        DEBUG_PRINT("[ERROR] - Expected File Size %ld, Actual File Size: %ld\n",
                    ((unsolved_header->num_of_e * UNSOLVED_EQUATION_LENGTH) +
                     EQU_HEADER_LENGTH),
                    file_size);
        close(fd);
        return_value = ERROR_CODE;
        goto END;
    }

    read_unsolved_equations(fd, unsolved_header, uequation, output_dir_arg);

    close(fd);

END:
    free(input_filepath_p);
    input_filepath_p = NULL;
    return return_value;
}

file_header_t * parse_unsolved_header(int fd, file_header_t * unsolved_header)
{
    lseek(fd, 0, SEEK_SET);

    int bytes_read = 0;

    bytes_read += read(fd, &unsolved_header->magic_num, sizeof(unsolved_header->magic_num));
    bytes_read += read(fd, &unsolved_header->file_id, sizeof(unsolved_header->file_id));
    bytes_read += read(fd, &unsolved_header->num_of_e, sizeof(unsolved_header->num_of_e));
    bytes_read +=
        read(fd, &unsolved_header->header_flag, sizeof(unsolved_header->header_flag));
    bytes_read += read(
        fd, &unsolved_header->equation_offset, sizeof(unsolved_header->equation_offset));
    bytes_read += read(fd,
                       &unsolved_header->num_of_opt_headers,
                       sizeof(unsolved_header->num_of_opt_headers));

    if (bytes_read != EQU_HEADER_LENGTH)
    {
        fprintf(stderr,
                RED "[ERROR] - Failed to read header from file\n" RESET);
    }

    return unsolved_header;
}

int read_unsolved_equations(int                 fd,
                            file_header_t * unsolved_header,
                            unsolved_equation_t * uequation,
                            char *              output_dir_arg)
{
    int               return_value = 0;
    int               iterator     = 0;
    solved_equation_t * sequation_p  = NULL;

    while (iterator < unsolved_header->num_of_e)
    {
        int bytes_read = 0;

        bytes_read +=
            read(fd, &unsolved_header->equation_id, sizeof(unsolved_header->equation_id));
        bytes_read += read(
            fd, &uequation->reserved_flag, sizeof(uequation->reserved_flag));
        bytes_read +=
            read(fd, &uequation->operand1, sizeof(uequation->operand1));
        bytes_read += read(
            fd, &uequation->operator_value, sizeof(uequation->operator_value));
        bytes_read +=
            read(fd, &uequation->operand2, sizeof(uequation->operand2));
        bytes_read += read(
            fd, &uequation->padding_8bytes, sizeof(uequation->padding_8bytes));
        bytes_read += read(
            fd, &uequation->padding_2bytes, sizeof(uequation->padding_2bytes));

        if (bytes_read != UNSOLVED_EQUATION_LENGTH)
        {
            fprintf(stderr,
                    RED "[ERROR] - Failed to read equation from file\n" RESET);
            close(fd);
            return_value = ERROR_CODE;
            goto END;
        }

        if (0 != unsolved_header->header_flag)
        {
            DEBUG_PRINT("[ERROR] - Invalid Header Value: %02X\n",
                        unsolved_header->header_flag);
            close(fd);
            return_value = ERROR_CODE;
            goto END;
        }

        sequation_p = return_solved_struct(unsolved_header, uequation, output_dir_arg);

        iterator++;
        free(sequation_p);
        sequation_p = NULL;
    }

END:
    return return_value;
}

/*** end of file ***/
