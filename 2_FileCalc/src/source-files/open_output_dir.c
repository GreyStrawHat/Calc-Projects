#include "open_output_dir.h"

int open_output_dir(char * output_dir_arg)
{
    DIR * output_directory = opendir(output_dir_arg);

    if ((output_directory == NULL) && (errno == 2))
    {
        mkdir(output_dir_arg, RWXRXRX);
        printf("Output Directory doesn't exist, creating it now..\n");
        output_directory = opendir(output_dir_arg);
        if (output_directory == NULL)
        {
            DEBUG_PRINT("Error opening directory %s\n", output_dir_arg);
            return -1;
        }
        errno = 0;
    }
    else if (output_directory == NULL)
    {
        DEBUG_PRINT("Error opening directory %s\n", output_dir_arg);
        return -1;
    }

    closedir(output_directory);

    return 0;
}

/*** end of file ***/
