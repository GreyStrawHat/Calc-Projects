#ifndef CALC_H
#define CALC_H

#include <stdint.h>


/**
 * @brief Function to process math operations and print results.
 * 
 * @param operand1 First operand.
 * @param operator_val Value to indict which operation to perform on supplied operands.
 * @param operand2 Second operand.
 * @return int Returns an int to determine error status of function.
 */
int calc(char *operand1, char *operator_val, char *operand2);

#endif