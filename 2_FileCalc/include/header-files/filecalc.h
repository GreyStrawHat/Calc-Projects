#ifndef FILECALC_H
#define FILECALC_H
#define EQU_HEADER_LENGTH 27
#define ADDITION          0x01
#define SUBTRACTION       0x02
#define MULTIPLICATION    0x03
#define DIVISION          0x04
#define MODULUS           0x05
#define LEFT_SHIFT        0x06
#define RIGHT_SHIFT       0x07
#define BITWISE_AND       0x08
#define BITWISE_OR        0x09
#define BITWISE_XOR       0x0a
#define LEFT_ROTATE       0x0b
#define RIGHT_ROTATE      0x0c

#include <stdio.h>
#include <stdlib.h>
#include "equation_types.h"
#include "signed_ec_operations_64.h"
#include "default_case64.h"

/**
 * @brief Solve an equation based on the operator_value.
 *
 * This function takes an unsolved_equation_t and solved_equation_t as input and
 * solves the equation based on the operator_value specified in the
 * unsolved_equation_t. The result is stored in the solved_equation_t.
 *
 * @param Header Pointer to the file header info
 * @param Equation Pointer to the unsolved_equation_t to be solved.
 * @param sequation Pointer to the solved_equation_t where the result will be
 * stored.
 * @return Pointer to the solved_equation_t with the result of the equation.
 */
solved_equation_t * filecalc(file_header_t * Header, unsolved_equation_t * Equation,
                           solved_equation_t * sequation);

#endif

/*** end of file ***/
