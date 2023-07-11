#ifndef ARGS_H
#define ARGS_H
#define BASE_TEN 10

#include <stdio.h>
#include <stdlib.h>
#include "error_msg.h"
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Checks that the supplied value falls within the range of 32-bit
 * unsigned integers.
 *
 * @param arg expects 32-bit unsigned operand
 * @return uint32_t
 */
uint32_t sanitize_uarg(char * arg);

/**
 * @brief Checks that the supplied value falls within the range of 32-bit signed
 * integers.
 *
 * @param arg expects 32-bit signed operand
 * @return int32_t
 */
int32_t sanitize_iarg(char * arg);

/**
 * @brief Checks the return value of the sanitize_iargs function for false positives
 * 
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if there is an error
 * @return false if there is a false flag
 */
bool signed_error_checker(char * operand1, char *operand2);

/**
 * @brief Checks the return value of the sanitize_uargs function for false positives
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if there is an error
 * @return false if there is a false flag
 */
bool unsigned_error_checker(char * operand1, char *operand2);

#endif