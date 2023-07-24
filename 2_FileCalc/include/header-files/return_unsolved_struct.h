#ifndef RETURN_UNSOLVED_H
#define RETURN_UNSOLVED_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "equation_types.h"
#include "parse_unsolved_file.h"

/**
 * @brief Return an Unsolved_Equation structure containing unsolved equations.
 *
 * This function takes two directory paths (`input_dir_arg` and
 * `output_dir_arg`) as input and returns an Unsolved_Equation structure
 * containing information about the unsolved equations found in the specified
 * input directory. The function searches for regular files in the input
 * directory and calls the `parse_unsolved_file` function to parse each file and
 * generate solved equations for them. The resulting Unsolved_Equation structure
 * will store the parsed header data and the generated solved equations for all
 * the files in the input directory.
 *
 * @param input_dir_arg The path to the input directory containing the unsolved
 * equation files.
 * @param output_dir_arg The path to the output directory where the generated
 * solved equations will be stored.
 * @return Pointer to the Unsolved_Equation structure containing the unsolved
 * equations on success, or NULL on failure.
 */
Unsolved_Equation * return_unsolved_struct(char * input_dir_arg,
                                           char * output_dir_arg);

#endif