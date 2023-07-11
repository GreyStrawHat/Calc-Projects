#ifndef UNSIGNED_MATHOP_H
#define UNSIGNED_MATHOP_H
#define BIT_WIDTH 32

#include <stdint.h>
#include "error_msg.h"

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