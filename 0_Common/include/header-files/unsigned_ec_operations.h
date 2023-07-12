#ifndef UNSIGNED_EC_OPERATIONS_H
#define UNSIGNED_EC_OPERATIONS_H
#define ERROR_CODE -1
#define UNSIGNED_ERROR_CODE 1
#define BASE_TEN 10

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "error_msg.h"
#include "handle_args.h"
#include "unsigned_math_operations.h"
#include "args.h"


/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation left shift as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_lshift(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation rotate left as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_rotateLeft(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation rotate right as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit usigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_rotateRight(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation AND as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_AND(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation OR as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_OR(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation XOR as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit usigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_XOR(char * operand1, char * operand2);

#endif