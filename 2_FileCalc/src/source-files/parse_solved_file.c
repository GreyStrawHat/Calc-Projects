#include "parse_solved_file.h"

int parse_solved_file(Solved_Equation *sequation, char *output_dir_arg)
{
    DIR *output_directory = opendir(output_dir_arg);

    if ((output_directory == NULL) && (errno == 2))
    {
        mkdir(output_dir_arg, 0755);
        printf("Output Directory doesn't exist, creating it now\n");
        output_directory = opendir(output_dir_arg);
        if (output_directory == NULL)
        {
            printf("Error opening directory\n");
            return -1;
        }
        errno = 0;
    }
    else if (output_directory == NULL)
    {
        printf("Error opening directory %s\n", output_dir_arg);
        return -1;
    }
    else
    {
        printf("Opening Directory %s\n", output_dir_arg);
    }

    static int loop_tracker = 0; //tracks times function has been called for writing equations to file

    if (loop_tracker == 5)
    {
        loop_tracker = 0;
    }

    char filepath[strlen(output_dir_arg) + (sizeof(sequation->file_id) * 2) + 10];
    memset(filepath, '\0', sizeof(filepath));

    char *output_filepath = realpath(output_dir_arg, NULL);

    char inversed_solved_filename[50];
    memset(inversed_solved_filename, '\0', sizeof(inversed_solved_filename));

    char *solved_filename = (char *)calloc(50, sizeof(char));

    snprintf(solved_filename, 50, "%08lx", sequation->file_id);

    reverse_string_byte_order(solved_filename, inversed_solved_filename);

    printf("Beginning test - Buffer: %s Filename: %s\n", solved_filename, inversed_solved_filename);

    //snprintf(filepath, sizeof(filepath), "%s/%s.data", output_dir_arg, inversed_solved_filename);

    strncat(output_filepath, "/", 2);

    strncat(output_filepath, inversed_solved_filename, strlen(inversed_solved_filename));

    strncat(output_filepath, ".data", strlen(".data") + 1);

    printf("Filename : %s\n", output_filepath);

    int fd = open(output_filepath, O_RDWR | O_CREAT | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
    if (fd == -1)
    {
        printf("Error opening solved file\n");
        free(output_filepath);
        output_filepath = NULL;
        free(solved_filename);
        solved_filename = NULL;
        closedir(output_directory);
        return -1;
    }

    printf("Loop Tracker: %d\n", loop_tracker);

    if (loop_tracker == 0)
    {
        lseek(fd, 0, SEEK_SET);
        write(fd, &sequation->magic_num, sizeof(sequation->magic_num));
        write(fd, &sequation->file_id, sizeof(sequation->file_id));
        write(fd, &sequation->num_of_e, sizeof(sequation->num_of_e));
        write(fd, &sequation->header_flag, sizeof(sequation->header_flag));
        write(fd, &sequation->equation_offset, sizeof(sequation->equation_offset));
        write(fd, &sequation->num_of_opt_headers, sizeof(sequation->num_of_opt_headers));
    }

    lseek(fd, 0, SEEK_END);
    write(fd, &sequation->equation_id, sizeof(sequation->equation_id));
    write(fd, &sequation->solved_flag, sizeof(sequation->solved_flag));
    write(fd, &sequation->data_type, sizeof(sequation->data_type));
    write(fd, &sequation->result, sizeof(sequation->result));

    close(fd);

    free(solved_filename);
    solved_filename = NULL;

    free(output_filepath);
    output_filepath = NULL;

    printf("Closing output Directory\n");
    closedir(output_directory);
    loop_tracker++;
    printf("Loop Tracker: %d\n", loop_tracker);

    return 0;
}

/*** end of file ***/
