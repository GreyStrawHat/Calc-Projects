#ifndef OUTPUT_DIR_H
#define OUTPUT_DIR_H
#define RWXRXRX 0755

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include "debug.h"

int open_output_dir(char * output_dir_arg);

#endif