#ifndef RETURN_UNSOLVED_H
#define RETURN_UNSOLVED_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "equation_types.h"
#include "parse_unsolved_file.h"

Unsolved_Equation *return_unsolved_struct(char *input_dir_arg, char *output_dir_arg);

#endif