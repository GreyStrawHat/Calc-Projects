#ifndef SIGNED_EC_OPERATIONS_H
#define SIGNED_EC_OPERATIONS_H
#define ERROR_CODE          -1
#define UNSIGNED_ERROR_CODE 1
#define BASE_TEN            10

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "args.h"
#include "error_msg.h"
#include "handle_args.h"
#include "signed_math_operations.h"

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the addition operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_addition(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the subtraction operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the erro code is a false positive
 */
bool ec_subtraction(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the multiplication operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the erro code is a false positive
 */
bool ec_multiplication(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the division operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_division(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the modulo operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_modulo(char * operand1, char * operand2);

#endif