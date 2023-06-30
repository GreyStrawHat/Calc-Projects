#include <stdint.h>
#include <limits.h>
#include "error_msg.h"
#include "math_operations.h"

uint32_t rotateLeft(uint32_t value, uint32_t shift)
{
    uint32_t rotated_value = (sanitize_lshift(value, shift) | (value >> (32 - shift)));
    return rotated_value;
}

uint32_t rotateRight(uint32_t value, uint32_t shift)
{
    //uint32_t rotated_value = ((value >> shift) | sanitize_lshift(value, (32 - shift)));
    uint32_t rotated_value = ((value >> shift) | sanitize_lshift(value, (32 - shift)));
    return rotated_value;
}

int32_t sanitize_addition(int32_t arg1, int32_t arg2)
{
    if (((arg2 > 0) && (arg1 > (INT32_MAX - arg2))) || ((arg2 < 0) && (arg1 < (INT32_MIN - arg2))))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 + arg2);
    }
}

int32_t sanitize_subtraction(int32_t arg1, int32_t arg2)
{
    if (((arg2 > 0 && arg1 < INT32_MIN + arg2) || (arg2 < 0 && arg1 > INT32_MAX + arg2)))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 - arg2);
    }
}

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

int32_t sanitize_division(int32_t arg1, int32_t arg2)
{
    if (((arg1 == LONG_MIN) && (arg2 == -1)))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 / arg2);
    }
}

int32_t sanitize_modulo(int32_t arg1, int32_t arg2)
{
    if ((arg2 == 0) || ((arg1 == LONG_MIN) && (arg2 == -1)))
    {
        integer_overflow_error();
    }
    else
    {
        return (arg1 % arg2);
    }
}

uint32_t sanitize_lshift(uint32_t arg1, uint32_t arg2)
{
    if (((long long)arg1 << (long long)arg2) > UINT32_MAX)
    {
        unsigned_int_error();
    }
    return (arg1 << arg2);
}