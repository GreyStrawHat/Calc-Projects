#ifndef RETURN_SOLVED_H
#define RETURN_SOLVED_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "equation_types.h"
#include "parse_solved_file.h"
#include "filecalc.h"

/**
 * @brief Return a solved equation structure.
 *
 * This function takes an Unsolved_Equation structure (`Equation`) and an output
 * directory path (`output_dir_arg`) as input and returns a Solved_Equation
 * structure containing the solved equation. The function allocates memory for
 * the Solved_Equation structure using calloc and initializes its fields based
 * on the data in the Unsolved_Equation structure. It then calls the `filecalc`
 * function to calculate the result of the equation and stores the result in the
 * `sequation->result` field. If the equation is successfully solved, the
 * `solved_flag` field in the `sequation` structure is set to true, otherwise,
 * it is set to false.
 *
 * @param Equation Pointer to the Unsolved_Equation structure containing the
 * equation to be solved.
 * @param output_dir_arg The path to the output directory where the solved
 * equation will be stored.
 * @return Pointer to the Solved_Equation structure containing the solved
 * equation on success, or NULL on failure.
 */
Solved_Equation * return_solved_struct(Unsolved_Equation * Equation,
                                       char *              output_dir_arg);

#endif

/*** end of file ***/
