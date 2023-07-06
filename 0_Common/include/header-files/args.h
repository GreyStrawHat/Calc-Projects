#ifndef ARGS_H
#define ARGS_H

#include <stdint.h>

/**
 * @brief Checks that the supplied value falls within the range of 32-bit unsigned integers. 
 * 
 * @param arg expects 32-bit unsigned operand
 * @return uint32_t 
 */
uint32_t sanitize_uarg(char *arg);

/**
 * @brief Checks that the supplied value falls within the range of 32-bit signed integers.
 * 
 * @param arg expects 32-bit signed operand
 * @return int32_t 
 */
int32_t sanitize_iarg(char *arg);

#endif