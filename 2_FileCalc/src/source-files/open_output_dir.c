#include "open_output_dir.h"

int open_output_dir(char * output_dir_arg)
{
    int return_value = 0;

    DIR * output_directory = opendir(output_dir_arg);

    if ((NULL == output_directory) && (ENOENT == errno))
    {
        mkdir(output_dir_arg, RWXRXRX);
        printf("Output Directory doesn't exist, creating it now..\n");
        output_directory = opendir(output_dir_arg);
        if (NULL == output_directory)
        {
            DEBUG_PRINT("Error opening directory %s\n", output_dir_arg);
            return_value = ERROR_CODE;
            goto END;
        }
        errno = 0;
    }
    else if (NULL == output_directory)
    {
        DEBUG_PRINT("Error opening directory %s\n", output_dir_arg);
        return_value = ERROR_CODE;
        goto END;
    }

    closedir(output_directory);

END:
    return return_value;
}

/*** end of file ***/
