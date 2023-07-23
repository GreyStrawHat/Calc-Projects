#include "unsigned_math_operations_64.h"

uint64_t rotateLeft64(uint64_t value, uint64_t shift)
{
    shift %= BIT_WIDTH;
    uint64_t rotated_value = (lshift64(value, shift)) & INT64_BIT_MASK;
    return rotated_value;
}

uint64_t rotateRight64(uint64_t value, uint64_t shift)
{
    shift %= BIT_WIDTH;
    uint64_t rotated_value =
        ((value >> shift) | lshift64(value, (BIT_WIDTH - shift)));
    return rotated_value;
}

uint64_t lshift64(uint64_t arg1, uint64_t arg2)
{
    uint64_t return_value = 0;

    if ((arg2 > BIT_WIDTH) || (arg1 == UINT64_MAX))
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
