#include "parse_solved_file.h"

int parse_solved_file(Solved_Equation * sequation, char * output_dir_arg)
{

    if (open_output_dir(output_dir_arg) == -1)
    {
        printf("Error opening output directory\n");
        return -1;
    }

    static int loop_tracker = 0; // tracks times function has been called for
                                 // writing equations to file

    if (loop_tracker == sequation->num_of_e)
    {
        loop_tracker = 0;
    }

    char * output_filepath = realpath(output_dir_arg, NULL);

    char reversed_byteorder_filename[FILENAME_BUFFER];
    memset(reversed_byteorder_filename, '\0', FILENAME_BUFFER);

    char solved_filename[FILENAME_BUFFER];
    memset(solved_filename, '\0', FILENAME_BUFFER);

    snprintf(solved_filename, FILENAME_BUFFER, "%016lx", sequation->file_id);

    reverse_string_byte_order(solved_filename, reversed_byteorder_filename);

    strncat(output_filepath, "/", (strlen("/") + NULL_BYTE_SIZE));

    strncat(output_filepath,
            reversed_byteorder_filename,
            strlen(reversed_byteorder_filename));

    strncat(output_filepath, ".data", (strlen(".data") + NULL_BYTE_SIZE));

    if (access(output_filepath, F_OK) == 0)
    {
        printf("File: %s already exists, skipping..\n", output_filepath);
        free(output_filepath);
        output_filepath = NULL;
        return 0;
    }

    printf("File: %s doesn't exist, creating it now..\n", output_filepath);

    int fd = open(output_filepath,
                  O_RDWR | O_CREAT | O_CLOEXEC,
                  S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
    if (fd == -1)
    {
        DEBUG_PRINT("Error opening solved file %s\n", output_filepath);
        free(output_filepath);
        output_filepath = NULL;
        return -1;
    }

    if (loop_tracker == 0)
    {
        lseek(fd, 0, SEEK_SET);
        write(fd, &sequation->magic_num, sizeof(sequation->magic_num));
        write(fd, &sequation->file_id, sizeof(sequation->file_id));
        write(fd, &sequation->num_of_e, sizeof(sequation->num_of_e));
        write(fd, &sequation->header_flag, sizeof(sequation->header_flag));
        write(fd,
              &sequation->equation_offset,
              sizeof(sequation->equation_offset));
        write(fd,
              &sequation->num_of_opt_headers,
              sizeof(sequation->num_of_opt_headers));
    }

    lseek(fd, 0, SEEK_END);
    write(fd, &sequation->equation_id, sizeof(sequation->equation_id));
    write(fd, &sequation->solved_flag, sizeof(sequation->solved_flag));
    write(fd, &sequation->data_type, sizeof(sequation->data_type));
    write(fd, &sequation->result, sizeof(sequation->result));

    close(fd);

    free(output_filepath);
    output_filepath = NULL;

    printf("Closing output Directory\n");
    loop_tracker++;

    return 0;
}

/*** end of file ***/
