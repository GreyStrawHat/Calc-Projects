#include "parse_unsolved_file.h"

int parse_unsolved_file(Unsolved_Equation * uequation,
                        struct dirent *     directory_entry,
                        char *              input_dir_arg,
                        char *              output_dir_arg)
{
    int     return_value   = 0;
    ssize_t file_size      = 0;
    char *  input_filepath = realpath(input_dir_arg, NULL);

    strncat(input_filepath, "/", (strlen("/") + NULL_BYTE_SIZE));

    strncat(input_filepath,
            directory_entry->d_name,
            sizeof(directory_entry->d_name) + 1);

    int fd = open(input_filepath, O_RDONLY | O_CLOEXEC);
    if (ERROR_CODE == fd)
    {
        DEBUG_PRINT("[ERROR] - Failed to open file %s\n", input_filepath);
        return_value = ERROR_CODE;
        goto END;
    }

    printf("\nTarget Equation File: %s\n", directory_entry->d_name);

    file_size = lseek(fd, 0, SEEK_END);

    printf("File Size: %ld\n", file_size);

    uequation = parse_unsolved_header(fd, uequation);

    if (((uequation->num_of_e * UNSOLVED_EQUATION_LENGTH) +
         EQU_HEADER_LENGTH) != file_size)
    {
        DEBUG_PRINT("[ERROR] - Expected File Size %ld, Actual File Size: %ld\n",
                    ((uequation->num_of_e * UNSOLVED_EQUATION_LENGTH) +
                     EQU_HEADER_LENGTH),
                    file_size);
        close(fd);
        return_value = ERROR_CODE;
        goto END;
    }

    read_unsolved_equations(fd, uequation, output_dir_arg);

    close(fd);

END:
    free(input_filepath);
    input_filepath = NULL;
    return return_value;
}

Unsolved_Equation * parse_unsolved_header(int fd, Unsolved_Equation * uequation)
{
    lseek(fd, 0, SEEK_SET);

    int bytes_read = 0;

    bytes_read += read(fd, &uequation->magic_num, sizeof(uequation->magic_num));
    bytes_read += read(fd, &uequation->file_id, sizeof(uequation->file_id));
    bytes_read += read(fd, &uequation->num_of_e, sizeof(uequation->num_of_e));
    bytes_read +=
        read(fd, &uequation->header_flag, sizeof(uequation->header_flag));
    bytes_read += read(
        fd, &uequation->equation_offset, sizeof(uequation->equation_offset));
    bytes_read += read(fd,
                       &uequation->num_of_opt_headers,
                       sizeof(uequation->num_of_opt_headers));

    if (bytes_read != EQU_HEADER_LENGTH)
    {
        fprintf(stderr,
                RED "[ERROR] - Failed to read header from file\n" RESET);
    }

    return uequation;
}

int read_unsolved_equations(int                 fd,
                            Unsolved_Equation * uequation,
                            char *              output_dir_arg)
{
    int               return_value = 0;
    int               iterator     = 0;
    Solved_Equation * sequation    = NULL;

    while (iterator < uequation->num_of_e)
    {
        int bytes_read = 0;

        bytes_read +=
            read(fd, &uequation->equation_id, sizeof(uequation->equation_id));
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

        if (0 != uequation->header_flag)
        {
            DEBUG_PRINT("[ERROR] - Invalid Header Value: %02X\n",
                        uequation->header_flag);
            close(fd);
            return_value = ERROR_CODE;
            goto END;
        }

        sequation = return_solved_struct(uequation, output_dir_arg);

        iterator++;
        free(sequation);
        sequation = NULL;
    }

END:
    return return_value;
}

/*** end of file ***/
