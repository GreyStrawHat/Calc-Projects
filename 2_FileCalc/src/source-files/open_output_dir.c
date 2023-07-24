#include "open_output_dir.h"

int open_output_dir(char * output_dir_arg)
{
    DIR * output_directory = opendir(output_dir_arg);

    if ((NULL == output_directory) && (ENOENT == errno))
    {
        mkdir(output_dir_arg, RWXRXRX);
        printf("Output Directory doesn't exist, creating it now..\n");
        output_directory = opendir(output_dir_arg);
        if (NULL == output_directory)
        {
            DEBUG_PRINT("Error opening directory %s\n", output_dir_arg);
            return ERROR_CODE;
        }
        errno = 0;
    }
    else if (NULL == output_directory)
    {
        DEBUG_PRINT("Error opening directory %s\n", output_dir_arg);
        return ERROR_CODE;
    }

    closedir(output_directory);

    return 0;
}

/*** end of file ***/
