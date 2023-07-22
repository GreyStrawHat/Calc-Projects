#ifndef PARSE_SOLVED_H
#define PARSE_SOLVED_H
#define FILENAME_BUFFER 255
#define NULL_BYTE_SIZE  1

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "equation_types.h"
#include "reverse_byte_string_order.h"
#include "open_output_dir.h"

int parse_solved_file(Solved_Equation * sequation, char * output_dir_arg);

#endif