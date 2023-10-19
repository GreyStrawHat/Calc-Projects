#include "parse_solved_file.h"
#ifndef O_CLOEXEC  //Placed here to remove Intellisense issues
#define O_CLOEXEC	02000000 
#endif

int parse_solved_file(file_header_t * solved_header, solved_equation_t * sequation, char * output_dir_arg)
{
    int        return_value = 0;
    static int loop_tracker = 0;
    ssize_t    file_size =
        (solved_header->num_of_e * SOLVED_EQUATION_LENGTH) + EQU_HEADER_LENGTH;
    int    fd                = ERROR_CODE;
    char * output_filepath_p = realpath(output_dir_arg, NULL);

    if ((NULL == sequation) || (NULL == output_dir_arg))
    {
        fprintf(stderr, RED "Error: NULL pointer\n");
        DEBUG_PRINT(YELLOW "[*] Error %d " RESET, errno);
        return_value = ERROR_CODE;
        goto END;
    }

    if (ERROR_CODE == open_output_dir(output_dir_arg))
    {
        fprintf(stderr, RED "Error opening output directory\n");
        return_value = ERROR_CODE;
        goto END;
    }

    char reversed_byteorder_filename[FILENAME_BUFFER];
    memset(reversed_byteorder_filename, NULL_BYTE, FILENAME_BUFFER);
    char solved_filename[FILENAME_BUFFER];
    memset(solved_filename, NULL_BYTE, FILENAME_BUFFER);

    snprintf(solved_filename, FILENAME_BUFFER, "%016lx", solved_header->file_id);

    reverse_string_byte_order(solved_filename, reversed_byteorder_filename);

    strncat(output_filepath_p, "/", (strlen("/") + NULL_BYTE_SIZE));
    strncat(output_filepath_p,
            reversed_byteorder_filename,
            strlen(reversed_byteorder_filename));
    strncat(output_filepath_p, ".sol", (strlen(".sol") + NULL_BYTE_SIZE));

    printf("Storing results in solution file: %s\n", output_filepath_p);

    fd = open(output_filepath_p,
              O_RDWR | O_CREAT | O_CLOEXEC,
              S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
    if (ERROR_CODE == fd)
    {
        DEBUG_PRINT("Error opening solved file %s\n", output_filepath_p);
        return_value = ERROR_CODE;
        goto END;
    }

    if (file_size <= lseek(fd, 0, SEEK_END))
    {
        DEBUG_PRINT("Expected file size: %ld\n", file_size);
        goto END;
    }

    if (ENOENT == errno)
    {
        errno = 0;
    }

    if (0 == loop_tracker)
    {
        printf("Writing header to file..\n");
        lseek(fd, 0, SEEK_SET);
        write(fd, &solved_header->magic_num, sizeof(solved_header->magic_num));
        write(fd, &solved_header->file_id, sizeof(solved_header->file_id));
        write(fd, &solved_header->num_of_e, sizeof(solved_header->num_of_e));
        write(fd, &solved_header->header_flag, sizeof(solved_header->header_flag));
        write(fd,
              &solved_header->equation_offset,
              sizeof(solved_header->equation_offset));
        write(fd,
              &solved_header->num_of_opt_headers,
              sizeof(solved_header->num_of_opt_headers));
    }
    lseek(fd, 0, SEEK_END);
    write(fd, &solved_header->equation_id, sizeof(solved_header->equation_id));
    write(fd, &sequation->solved_flag, sizeof(sequation->solved_flag));
    write(fd, &sequation->data_type, sizeof(sequation->data_type));
    write(fd, &sequation->result, sizeof(sequation->result));

    close(fd);

    DEBUG_PRINT(" Loop Tracker: %d\n", loop_tracker);

    loop_tracker++;
    if (loop_tracker == solved_header->num_of_e)
    {
        loop_tracker = 0;
    }

END:
    free(output_filepath_p);
    output_filepath_p = NULL;
    return return_value;
}

/*** end of file ***/
