#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "error_msg.h"
#include "math_operations.h"

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

uint32_t rotateLeft(uint32_t value, uint32_t shift)
{
    uint32_t rotated_value =
        (sanitize_lshift(value, shift) | (value >> (32 - shift)));
    return rotated_value;
}

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

uint32_t rotateRight(uint32_t value, uint32_t shift)
{
    shift %= 32;
    uint32_t rotated_value =
        ((value >> shift) | sanitize_lshift(value, (32 - shift)));
    return rotated_value;
}

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

int32_t sanitize_addition(int32_t arg1, int32_t arg2)
{
    if (((arg2 > 0) && (arg1 > (INT32_MAX - arg2))) ||
        ((arg2 < 0) && (arg1 < (INT32_MIN - arg2))))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 + arg2);
    }
}

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

int32_t sanitize_subtraction(int32_t arg1, int32_t arg2)
{
    if (((arg2 > 0 && arg1 < INT32_MIN + arg2) ||
         (arg2 < 0 && arg1 > INT32_MAX + arg2)))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 - arg2);
    }
}

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

int32_t sanitize_multiplication(int32_t arg1, int32_t arg2)
{
    if (arg1 > 0)
    {
        if (arg2 > 0)
        {
            if (arg1 > (INT32_MAX / arg2))
            {
                integer_overflow_error();
            }
        }
        else
        {
            if (arg2 < (INT32_MIN / arg1))
            {
                integer_overflow_error();
            }
        }
    }
    else
    {
        if (arg2 > 0)
        {
            if (arg1 < (INT32_MIN / arg2))
            {
                integer_overflow_error();
            }
        }
        else
        {
            if (arg1 != 0 && arg2 < (INT32_MAX / arg1))
            {
                integer_overflow_error();
            }
        }
    }

    return (arg1 * arg2);
}

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

int32_t sanitize_division(int32_t arg1, int32_t arg2)
{
    if (0 == arg2)
    {
        printf("Cannot divide by zero.\n");
        return -1;
    }
    if (((LONG_MIN == arg1) && (-1 == arg2)))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 / arg2);
    }
}

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

int32_t sanitize_modulo(int32_t arg1, int32_t arg2)
{
    if ((0 == arg2) || ((LONG_MIN == arg1) && (-1 == arg2)))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 % arg2);
    }
}

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

uint32_t sanitize_lshift(uint32_t arg1, uint32_t arg2)
{
    if ((arg2 >= 32 || arg1) > (UINT32_MAX >> arg2))
    {
        unsigned_int_error();
    }
    return (arg1 << arg2);
}

/*** end of file ***/
