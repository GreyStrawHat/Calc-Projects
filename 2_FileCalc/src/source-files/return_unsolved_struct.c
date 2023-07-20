#include "return_unsolved_struct.h"

Unsolved_Equation *return_unsolved_struct(char *input_dir_arg, char *output_dir_arg)
{
    Unsolved_Equation *uequation = (Unsolved_Equation *)calloc(1, sizeof(Unsolved_Equation));
    if (uequation == NULL)
    {
        printf("Calloc Error\n");
        return NULL;
    }

    DIR *input_directory = opendir(input_dir_arg);
    if (input_directory == NULL)
    {
        printf("Error opening dir..\n");
        free(uequation);
        uequation = NULL;
        return NULL;
    }

    errno = 0;

    struct dirent *directory_entry;

    while ((directory_entry = readdir(input_directory)) != NULL)
    {
        if (directory_entry->d_type == 8)
        {
            if (parse_unsolved_file(uequation, directory_entry, input_dir_arg, output_dir_arg) == -1)
            {
                printf("Error Parsing File\n");
                free(uequation);
                uequation = NULL;
                errno += 1;
                break;
            }
        }
    }

    closedir(input_directory);

    if (errno != 0)
    {
        free(uequation);
        return NULL;
    }

    return uequation;
}

/*** end of file ***/
