#ifndef EC_OPERATIONS3_H
#define EC_OPERATIONS3_H
#define ERROR_CODE -1
#define UNSIGNED_ERROR_CODE 1

#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "unsigned_math_operations.h"

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

#endif