#ifndef DCASE_H
#define DCASE_H

#include <stdint.h>

/**
 * @brief Performs calculations on two operands based on the provided bitwise
 * operator.
 *
 * The function takes two operands and an operator as inputs and performs the
 * specified mathematical operation.If an unsupported operator is provided,
 * the function returns an error.
 *
 * @param operand1 The first operand as a string.
 * @param operator_val The operator as a string.
 * @param operand2 The second operand as a string.
 * @return Returns 0 if operation is successful. Returns 1 in case of any
 * errors.
 */
int default_case(char * operand1, char * operator_val, char * operand2);

#endif