#ifndef HANDLE_ARGS_H
#define HANDLE_ARGS_H
#define BASE_TEN   10
#define ERROR_CODE -1
#define NULL_BYTE '\0'

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>

/**
 * @brief This function handles integer arguments by converting character values to actual integer values.
 * If non digits are detected during the conversion, an error code is returned and the function execution ends.
 *
 * @param operand1 The first string representing an integer.
 * @param operand2 The second string representing an integer.
 * 
 * @return An integer indicating the status of the function. It returns zero if the function runs successfully, 
 * or an error code otherwise. The error code is defined as a constant ERROR_CODE in the code.
 */
int handle_int_args(char *operand1, char *operand2);

/**
 * @brief This function handles integer arguments by converting character values to actual integer values.
 * If non digits are detected during the conversion, an error code is returned and the function execution ends.
 *
 * @param operand1 The first string representing an integer.
 * @param operand2 The second string representing an integer.
 * 
 * @return An integer indicating the status of the function. It returns zero if the function runs successfully, 
 * or an error code otherwise. The error code is defined as a constant ERROR_CODE in the code.
 */
int handle_uint_args(char *operand1, char *operand2);

#endif