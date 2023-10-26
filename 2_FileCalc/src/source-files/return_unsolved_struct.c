#include "return_unsolved_struct.h"
#ifndef DT_REG   //Placed here to remove Intellisense issues
#define DT_REG 8 
#endif

unsolved_equation_t * return_unsolved_struct(char * input_dir_arg,
                                           char * output_dir_arg)
{
    unsolved_equation_t * return_value_p = NULL;
    unsolved_equation_t * uequation_p  = NULL;
    file_header_t * unsolved_file_header_p = NULL;

    struct stat *       path_st      = calloc(1, sizeof(struct stat));
    if (path_st == NULL)
    {
        fprintf(stderr, RED "Calloc Error\n");
        return_value_p = NULL;
        goto END;
    }

    if ((NULL == input_dir_arg) || (NULL == output_dir_arg))
    {
        fprintf(stderr, RED "Error: NULL pointer\n");
        DEBUG_PRINT(YELLOW "[*] Error %d " RESET, errno);
        return_value_p = NULL;
        goto END;
    }

    stat(input_dir_arg, path_st);

    if (0 == S_ISDIR(path_st->st_mode))
    {
        fprintf(
            stderr, RED "[ERROR] %s is not a directory\n" RESET, input_dir_arg);
        return_value_p = NULL;
        goto END;
    }

    stat(output_dir_arg, path_st);

    if (0 == S_ISDIR(path_st->st_mode))
    {
        fprintf(stderr,
                RED "[ERROR] %s is not a directory\n" RESET,
                output_dir_arg);
        return_value_p = NULL;
        goto END;
    }

    unsolved_file_header_p = (file_header_t *)calloc(1, sizeof(file_header_t));
    if (NULL == unsolved_file_header_p)
    {
        fprintf(stderr, "Calloc Error\n");
        return_value_p = NULL;
        goto END;
    }

    uequation_p = (unsolved_equation_t *)calloc(1, sizeof(unsolved_equation_t));
    if (NULL == uequation_p)
    {
        fprintf(stderr, "Calloc Error\n");
        return_value_p = NULL;
        goto END;
    }

    DIR * input_directory = opendir(input_dir_arg);
    if (NULL == input_directory)
    {
        DEBUG_PRINT("Error opening dir %s..\n", input_dir_arg);
        return_value_p = NULL;
        goto END;
    }

    errno = 0;

    struct dirent * directory_entry;

    while (NULL != (directory_entry = readdir(input_directory)))
    {
        if (DT_REG == directory_entry->d_type)
        {
            if (ERROR_CODE == parse_unsolved_file(unsolved_file_header_p, uequation_p,
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
        free(unsolved_file_header_p);
        unsolved_file_header_p = NULL;
        uequation_p  = NULL;
        return_value_p = NULL;
        goto END;
    }
    return_value_p = uequation_p;
END:
    if (NULL == return_value_p)
    {
        free(uequation_p);
        uequation_p = NULL;
        free(unsolved_file_header_p);
        unsolved_file_header_p = NULL;
    }
    free(path_st);
    free(unsolved_file_header_p);
    return return_value_p;
}

/*** end of file ***/
