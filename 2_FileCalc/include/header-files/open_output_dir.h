#ifndef OUTPUT_DIR_H
#define OUTPUT_DIR_H
#define RWXRXRX    0755
#define ERROR_CODE -1

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include "debug.h"

/**
 * @brief Open or create an output directory.
 *
 * This function attempts to open the specified output directory. If the
 * directory does not exist, it creates the directory with the specified
 * permissions.
 *
 * @param output_dir_arg The path to the output directory to be opened or
 * created.
 * @return 0 on success, or an error code on failure.
 */
int open_output_dir(char * output_dir_arg);

#endif