#ifndef OPERATION_32_H
#define OPERATION_32_H
#define BIT_WIDTH              32
#define INT32_BIT_MASK 0xFFFFFFFF
#define BASE_TEN               10

#include <string.h>
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

/**
 * @brief Safe addition operation for signed 32-bit integers.
 *
 * This function performs an addition operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the addition if no overflow occurs.
 */
int32_t sanitize_addition(int32_t arg1, int32_t arg2);

/**
 * @brief Safe subtraction operation for signed 32-bit integers.
 *
 * This function performs a subtraction operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the subtraction if no overflow occurs.
 */
int32_t sanitize_subtraction(int32_t arg1, int32_t arg2);

/**
 * @brief Safe multiplication operation for signed 32-bit integers.
 *
 * This function performs a multiplication operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the multiplication if no overflow occurs.
 */
int32_t sanitize_multiplication(int32_t arg1, int32_t arg2);

/**
 * @brief Safe division operation for signed 32-bit integers.
 *
 * This function performs a division operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the division if there is no division by zero or
 * overflows.
 */
int32_t sanitize_division(int32_t arg1, int32_t arg2);

/**
 * @brief Safe modelo operation for signed 32-bit integers.
 *
 * This function performs a modulo operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the modulo operation if there are no overflows.
 */
int32_t sanitize_modulo(int32_t arg1, int32_t arg2);

/**
 * @brief Perform a bitwise left shift on a 32-bit unsigned integer.
 *
 * This function performs a bitwise left shift on the given
 * unsigned integer. The number of positions to shift is specified
 * by the shift parameter.
 *
 * @param value The number to shift.
 * @param shift The number of positions to shift.
 * @return The result of the shift.
 */
uint32_t sanitize_lshift(uint32_t arg1, uint32_t arg2);

/**
 * @brief Perform a left rotation on a 32-bit unsigned integer.
 *
 * This function performs a bitwise left rotation on the given
 * unsigned integer. The number of positions to shift is specified
 * by the shift parameter.
 *
 * @param value The number to rotate.
 * @param shift The number of positions to rotate.
 * @return The result of the rotation.
 */
uint32_t rotateLeft(uint32_t value, uint32_t shift);

/**
 * @brief Perform a right rotation on a 32-bit unsigned integer.
 *
 * This function performs a bitwise right rotation on the given
 * unsigned integer. The number of positions to shift is specified
 * by the shift parameter.
 *
 * @param value The number to rotate.
 * @param shift The number of positions to rotate.
 * @return The result of the rotation.
 */

uint32_t rotateRight(uint32_t value, uint32_t shift);

#endif

/*** end of file ***/
