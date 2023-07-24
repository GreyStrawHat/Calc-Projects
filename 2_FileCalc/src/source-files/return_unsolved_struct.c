#include "return_unsolved_struct.h"

Unsolved_Equation * return_unsolved_struct(char * input_dir_arg,
                                           char * output_dir_arg)
{
    struct stat * path_st = calloc(1, sizeof(struct stat));
    if (path_st == NULL)
    {
        printf("Calloc Error\n");
        return NULL;
    }

    stat(input_dir_arg, path_st);

    if (0 == S_ISDIR(path_st->st_mode))
    {
        printf(RED "[ERROR] %s is not a directory\n" RESET, input_dir_arg);
        free(path_st);
        return NULL;
    }

    stat(output_dir_arg, path_st);

    if (0 == S_ISDIR(path_st->st_mode))
    {
        printf(RED "[ERROR] %s is not a directory\n" RESET, output_dir_arg);
        free(path_st);
        return NULL;
    }

    free(path_st);

    Unsolved_Equation * uequation =
        (Unsolved_Equation *)calloc(1, sizeof(Unsolved_Equation));
    if (NULL == uequation)
    {
        printf("Calloc Error\n");
        return NULL;
    }

    DIR * input_directory = opendir(input_dir_arg);
    if (NULL == input_directory)
    {
        DEBUG_PRINT("Error opening dir %s..\n", input_dir_arg);
        free(uequation);
        uequation = NULL;
        return NULL;
    }

    errno = 0;

    struct dirent * directory_entry;

    while (NULL != (directory_entry = readdir(input_directory)))
    {
        if (DT_REG == directory_entry->d_type)
        {
            if (ERROR_CODE ==
                parse_unsolved_file(
                    uequation, directory_entry, input_dir_arg, output_dir_arg))
            {
                fprintf(stderr,
                        RED "Error Parsing Equation File %s\n" RESET,
                        directory_entry->d_name);
            }
        }
    }

    closedir(input_directory);

    if (0 != errno)
    {
        free(uequation);
        uequation = NULL;
        return NULL;
    }

    return uequation;
}

/*** end of file ***/
