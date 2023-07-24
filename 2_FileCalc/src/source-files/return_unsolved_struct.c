#include "return_unsolved_struct.h"

Unsolved_Equation * return_unsolved_struct(char * input_dir_arg,
                                           char * output_dir_arg)
{
    Unsolved_Equation * return_value = NULL;
    Unsolved_Equation * uequation_p  = NULL;
    struct stat *       path_st      = calloc(1, sizeof(struct stat));
    if (path_st == NULL)
    {
        fprintf(stderr, RED "Calloc Error\n");
        return_value = NULL;
        goto END;
    }

    if ((NULL == input_dir_arg) || (NULL == output_dir_arg))
    {
        fprintf(stderr, RED "Error: NULL pointer\n");
        return_value = NULL;
        goto END;
    }

    stat(input_dir_arg, path_st);

    if (0 == S_ISDIR(path_st->st_mode))
    {
        fprintf(
            stderr, RED "[ERROR] %s is not a directory\n" RESET, input_dir_arg);
        return_value = NULL;
        goto END;
    }

    stat(output_dir_arg, path_st);

    if (0 == S_ISDIR(path_st->st_mode))
    {
        fprintf(stderr,
                RED "[ERROR] %s is not a directory\n" RESET,
                output_dir_arg);
        return_value = NULL;
        goto END;
    }

    uequation_p = (Unsolved_Equation *)calloc(1, sizeof(Unsolved_Equation));
    if (NULL == uequation_p)
    {
        fprintf(stderr, "Calloc Error\n");
        return_value = NULL;
        goto END;
    }

    DIR * input_directory = opendir(input_dir_arg);
    if (NULL == input_directory)
    {
        DEBUG_PRINT("Error opening dir %s..\n", input_dir_arg);
        return_value = NULL;
        goto END;
    }

    errno = 0;

    struct dirent * directory_entry;

    while (NULL != (directory_entry = readdir(input_directory)))
    {
        if (DT_REG == directory_entry->d_type)
        {
            if (ERROR_CODE == parse_unsolved_file(uequation_p,
                                                  directory_entry,
                                                  input_dir_arg,
                                                  output_dir_arg))
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
        free(uequation_p);
        uequation_p  = NULL;
        return_value = NULL;
        goto END;
    }
    return_value = uequation_p;
END:
    if (NULL == return_value)
    {
        free(uequation_p);
        uequation_p = NULL;
    }
    free(path_st);
    return return_value;
}

/*** end of file ***/
