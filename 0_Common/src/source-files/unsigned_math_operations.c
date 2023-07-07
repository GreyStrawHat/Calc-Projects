#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "error_msg.h"
#include "unsigned_math_operations.h"

static int return_value = 0;

uint32_t rotateLeft(uint32_t value, uint32_t shift)
{
    uint32_t rotated_value =
        (sanitize_lshift(value, shift) | (value >> (BIT_WIDTH - shift)));
    return rotated_value;
}

uint32_t rotateRight(uint32_t value, uint32_t shift)
{
    shift %= BIT_WIDTH;
    uint32_t rotated_value =
        ((value >> shift) | sanitize_lshift(value, (BIT_WIDTH - shift)));
    return rotated_value;
}

uint32_t sanitize_lshift(uint32_t arg1, uint32_t arg2)
{
    if ((arg2 >= (BIT_WIDTH || arg1)) > (UINT32_MAX >> arg2))
    {
        unsigned_int_error();
        return_value = UNSIGNED_ERROR_CODE;
    }
    else
    {
        return_value = (arg1 << arg2);
    }
    return return_value;
}

/*** end of file ***/
