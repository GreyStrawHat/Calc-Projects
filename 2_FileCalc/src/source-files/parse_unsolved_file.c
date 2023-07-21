#include "parse_unsolved_file.h"

int parse_unsolved_file(Unsolved_Equation *uequation, struct dirent *directory_entry, char *input_dir_arg, char *output_dir_arg)
{

    char *input_filepath = realpath(input_dir_arg, NULL);

    strncat(input_filepath, "/", 2);

    strncat(input_filepath, directory_entry->d_name, sizeof(directory_entry->d_name) + 1);

    //snprintf(input_filepath, path_size, "%s/%s", input_dir_arg, directory_entry->d_name);

    int fd = open(input_filepath, O_RDONLY| O_CLOEXEC);
    if (fd == -1)
    {
        printf("Error opening file %s\n", directory_entry->d_name);
        free(input_filepath);
        input_filepath = NULL;
        return -1;
    }
    printf("Opening File %s\n", directory_entry->d_name);

    ssize_t file_size = lseek(fd, 0, SEEK_END);

    lseek(fd, 0, SEEK_SET);

    read(fd, &uequation->magic_num, sizeof(uequation->magic_num));
    read(fd, &uequation->file_id, sizeof(uequation->file_id));
    read(fd, &uequation->num_of_e, sizeof(uequation->num_of_e));
    read(fd, &uequation->header_flag, sizeof(uequation->header_flag));
    read(fd, &uequation->equation_offset, sizeof(uequation->equation_offset));
    read(fd, &uequation->num_of_opt_headers, sizeof(uequation->num_of_opt_headers));

    int iterator = 0;

    while (iterator < uequation->num_of_e)
    {
        read(fd, &uequation->equation_id, sizeof(uequation->equation_id));
        read(fd, &uequation->reserved_flag, sizeof(uequation->reserved_flag));
        read(fd, &uequation->operand1, sizeof(uequation->operand1));
        read(fd, &uequation->operator_value, sizeof(uequation->operator_value));
        read(fd, &uequation->operand2, sizeof(uequation->operand2));
        read(fd, &uequation->padding_8bytes, sizeof(uequation->padding_8bytes));
        read(fd, &uequation->padding_2bytes, sizeof(uequation->padding_2bytes));

        if (((uequation->num_of_e * 32) + EQU_HEADER_LENGTH) != file_size)
        {
            printf("Invalid File data\n");
            free(input_filepath);
            input_filepath = NULL;
            close(fd);
            return -1;
        }

        printf("File Size is valid\n");

        if (uequation->header_flag != 0)
        {
            printf("Error in file header\n");
            free(input_filepath);
            input_filepath = NULL;
            close(fd);
            return -1;
        }

        Solved_Equation *sequation = return_solved_struct(uequation, output_dir_arg);
        free(sequation);

        iterator++;
    }

    free(input_filepath);
    input_filepath = NULL;
    close(fd);

    return 0;
}

/*** end of file ***/
