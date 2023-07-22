#ifndef SIGNED_EC_OPERATIONS64_H
#define SIGNED_EC_OPERATIONS64_H
#define ERROR_CODE          -1
#define UNSIGNED_ERROR_CODE 1
#define BASE_TEN            10

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "error_msg.h"
#include "signed_math_operations_64.h"

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the addition operation as well as Debug info.
 *
 * @param operand1 Takes first 64-bit signed operand
 * @param operand2 Takes second 64-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_addition64(int64_t operand1, int64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the subtraction operation as well as Debug info.
 *
 * @param operand1 Takes first 64-bit signed operand
 * @param operand2 Takes second 64-bit signed operand
 * @return true if the error_code is valid
 * @return false if the erro code is a false positive
 */
bool ec_subtraction64(int64_t operand1, int64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the multiplication operation as well as Debug info.
 *
 * @param operand1 Takes first 64-bit signed operand
 * @param operand2 Takes second 64-bit signed operand
 * @return true if the error_code is valid
 * @return false if the erro code is a false positive
 */
bool ec_multiplication64(int64_t operand1, int64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the division operation as well as Debug info.
 *
 * @param operand1 Takes first 64-bit signed operand
 * @param operand2 Takes second 64-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_division64(int64_t operand1, int64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the modulo operation as well as Debug info.
 *
 * @param operand1 Takes first 64-bit signed operand
 * @param operand2 Takes second 64-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_modulo64(int64_t operand1, int64_t operand2);

#endif