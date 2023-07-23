#ifndef PARSE_UNSOLVED_H
#define PARSE_UNSOLVED_H
#define EQU_HEADER_LENGTH        27
#define UNSOLVED_EQUATION_LENGTH 32
#define NULL_BYTE_SIZE           1
#define MAG_NUM                  (int32_t)0xDD77BB55

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "equation_types.h"
#include "return_solved_struct.h"

int parse_unsolved_file(Unsolved_Equation * uequation,
                        struct dirent *     directory_entry,
                        char *              input_dir_arg,
                        char *              output_dir_arg);

Unsolved_Equation * parse_unsolved_header(int                 fd,
                                          Unsolved_Equation * uequation);

int read_unsolved_equations(int                 fd,
                            Unsolved_Equation * uequation,
                            char *              output_dir_arg);

#endif