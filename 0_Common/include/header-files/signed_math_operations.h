#ifndef SIGNED_MATHOP_H
#define SIGNED_MATHOP_H
#define BIT_WIDTH 32

#include <stdint.h>

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

#endif