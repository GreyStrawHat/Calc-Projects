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
#include "unsigned_ec_operations_64.h"

Solved_Equation * filecalc(Unsolved_Equation * Equation,
                           Solved_Equation *   sequation);

#endif