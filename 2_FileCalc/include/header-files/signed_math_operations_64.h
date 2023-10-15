#ifndef SIGNED_MATHOP64_H
#define SIGNED_MATHOP64_H
#define BIT_WIDTH 64

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "error_msg.h"
#include "font.h"

/**
 * @brief Safe addition operation for signed 64-bit integers.
 *
 * This function performs an addition operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the addition if no overflow occurs.
 */
int64_t addition_64(int64_t arg1, int64_t arg2);

/**
 * @brief Safe subtraction operation for signed 64-bit integers.
 *
 * This function performs a subtraction operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the subtraction if no overflow occurs.
 */
int64_t subtraction_64(int64_t arg1, int64_t arg2);

/**
 * @brief Safe multiplication operation for signed 64-bit integers.
 *
 * This function performs a multiplication operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the multiplication if no overflow occurs.
 */
int64_t multiplication_64(int64_t arg1, int64_t arg2);

/**
 * @brief Safe division operation for signed 64-bit integers.
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
int64_t division_64(int64_t arg1, int64_t arg2);

/**
 * @brief Safe modelo operation for signed 64-bit integers.
 *
 * This function performs a modulo operation and checks for overflow.
 * If overflow would occur, an error message is printed and the program is
 * aborted.
 *
 * @param arg1 First operand.
 * @param arg2 Second operand.
 * @return The result of the modulo operation if there are no overflows.
 */
int64_t modulo_64(int64_t arg1, int64_t arg2);

#endif

/*** end of file ***/
