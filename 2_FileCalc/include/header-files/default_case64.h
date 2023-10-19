#ifndef DEFAULT_64_H
#define DEFAULT_64_H
#define ADDITION       0x01
#define SUBTRACTION    0x02
#define MULTIPLICATION 0x03
#define DIVISION       0x04
#define MODULUS        0x05
#define LEFT_SHIFT     0x06
#define RIGHT_SHIFT    0x07
#define BITWISE_AND    0x08
#define BITWISE_OR     0x09
#define BITWISE_XOR    0x0a
#define LEFT_ROTATE    0x0b
#define RIGHT_ROTATE   0x0c

#include <stdio.h>
#include <stdlib.h>
#include "equation_types.h"
#include "unsigned_ec_operations_64.h"
#include <errno.h>

/**
 * @brief Solve an equation based on the operator_value.
 *
 * This function takes an Unsolved_Equation and Solved_Equation as input and
 * solves the equation based on the operator_value specified in the
 * Unsolved_Equation. The result is stored in the Solved_Equation.
 *
 * @param Equation Pointer to the Unsolved_Equation to be solved.
 * @param sequation Pointer to the Solved_Equation where the result will be
 * stored.
 * @return Pointer to the Solved_Equation with the result of the equation.
 */
solved_equation_t * default_case64(unsolved_equation_t * Equation,
                                 solved_equation_t *   sequation);

#endif

/*** end of file ***/
