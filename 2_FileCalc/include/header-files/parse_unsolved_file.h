#ifndef PARSE_UNSOLVED_H
#define PARSE_UNSOLVED_H
#define EQU_HEADER_LENGTH 27

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "equation_types.h"
#include "return_solved_struct.h"

extern int loop_tracker;

int parse_unsolved_file(Unsolved_Equation *uequation, struct dirent *directory_entry, char *input_dir_arg, char *output_dir_arg);

#endif