#ifndef UNSIGNED_EC_OPERATIONS64_H
#define UNSIGNED_EC_OPERATIONS64_H
#define ERROR_CODE          -1
#define UNSIGNED_ERROR_CODE 1
#define BASE_TEN            10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "error_msg.h"
#include "unsigned_math_operations_64.h"
#include "debug.h"
#include "font.h"

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the bitwise operation left shift as well as Debug info.
 *
 * @param operand1 Takes first 64-bit unsigned operand
 * @param operand2 Takes second 64-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_lshift64(uint64_t operand1, uint64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the bitwise operation rotate left as well as Debug info.
 *
 * @param operand1 Takes first 64-bit unsigned operand
 * @param operand2 Takes second 64-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_rotateLeft64(uint64_t operand1, uint64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the bitwise operation rotate right as well as Debug info.
 *
 * @param operand1 Takes first 64-bit unsigned operand
 * @param operand2 Takes second 64-bit usigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_rotateRight64(uint64_t operand1, uint64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the bitwise operation AND as well as Debug info.
 *
 * @param operand1 Takes first 64-bit unsigned operand
 * @param operand2 Takes second 64-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_AND64(uint64_t operand1, uint64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the bitwise operation OR as well as Debug info.
 *
 * @param operand1 Takes first 64-bit unsigned operand
 * @param operand2 Takes second 64-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_OR64(uint64_t operand1, uint64_t operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the bitwise operation XOR as well as Debug info.
 *
 * @param operand1 Takes first 64-bit unsigned operand
 * @param operand2 Takes second 64-bit usigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_XOR64(uint64_t operand1, uint64_t operand2);

#endif

/*** end of file ***/
