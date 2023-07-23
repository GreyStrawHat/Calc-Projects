#ifndef UNSIGNED_MATHOP64_H
#define UNSIGNED_MATHOP64_H
#define BIT_WIDTH 64

#include <stdint.h>
#include <stdio.h>
#include "error_msg.h"
#include "font.h"

/**
 * @brief Perform a bitwise left shift on a 64-bit unsigned integer.
 *
 * This function performs a bitwise left shift on the given
 * unsigned integer. The number of positions to shift is specified
 * by the shift parameter.
 *
 * @param value The number to shift.
 * @param shift The number of positions to shift.
 * @return The result of the shift.
 */
uint64_t lshift64(uint64_t arg1, uint64_t arg2);

/**
 * @brief Perform a left rotation on a 64-bit unsigned integer.
 *
 * This function performs a bitwise left rotation on the given
 * unsigned integer. The number of positions to shift is specified
 * by the shift parameter.
 *
 * @param value The number to rotate.
 * @param shift The number of positions to rotate.
 * @return The result of the rotation.
 */
uint64_t rotateLeft64(uint64_t value, uint64_t shift);

/**
 * @brief Perform a right rotation on a 64-bit unsigned integer.
 *
 * This function performs a bitwise right rotation on the given
 * unsigned integer. The number of positions to shift is specified
 * by the shift parameter.
 *
 * @param value The number to rotate.
 * @param shift The number of positions to rotate.
 * @return The result of the rotation.
 */

uint64_t rotateRight64(uint64_t value, uint64_t shift);

#endif