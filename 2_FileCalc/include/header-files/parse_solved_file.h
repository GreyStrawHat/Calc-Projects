#ifndef PARSE_SOLVED_H
#define PARSE_SOLVED_H
#define FILENAME_BUFFER        255
#define NULL_BYTE_SIZE         1
#define SOLVED_EQUATION_LENGTH 14

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

/**
 * @brief Parse the Solved_Equation and store results in a solution file.
 *
 * This function takes a Solved_Equation and an output directory path as input.
 * It creates or opens the specified output directory and writes the results of
 * the Solved_Equation to a solution file in the directory. If the file already
 * exists, it appends the results to the file.
 *
 * @param sequation Pointer to the Solved_Equation to be stored in the file.
 * @param output_dir_arg The path to the output directory where the solution
 * file will be stored.
 * @return 0 on success, or an error code on failure.
 */
int parse_solved_file(Solved_Equation * sequation, char * output_dir_arg);

#endif