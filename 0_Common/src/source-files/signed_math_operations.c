#include "signed_math_operations.h"

static int return_value = 0;

int32_t sanitize_addition(int32_t arg1, int32_t arg2)
{
    if (((arg2 > 0) && (arg1 > (INT32_MAX - arg2))) ||
        ((arg2 < 0) && (arg1 < (INT32_MIN - arg2))))
    {
        integer_overflow_error();
        return_value = ERROR_CODE;
    }
    else
    {
        return_value = (arg1 + arg2);
    }

    return return_value;
}

int32_t sanitize_subtraction(int32_t arg1, int32_t arg2)
{
    if ((((arg2 > 0) && (arg1 < (INT32_MIN + arg2))) ||
         ((arg2 < 0) && (arg1 > (INT32_MAX + arg2)))))
    {
        integer_overflow_error();
        return_value = ERROR_CODE;
    }
    else
    {
        return_value = (arg1 - arg2);
    }

    return return_value;
}

int32_t sanitize_multiplication(int32_t arg1, int32_t arg2)
{
    if (arg1 > 0)
    {
        if (((arg2 > 0) && (arg1 > (INT32_MAX / arg2))) ||
            ((arg2 < 0) && (arg2 < (INT32_MIN / arg1))))
        {
            integer_overflow_error();
            return_value = ERROR_CODE;
        }
    }
    else if (arg1 < 0)
    {
        if (((arg2 > 0) && (arg1 < (INT32_MIN / arg2))) ||
            ((arg2 < 0) && (arg1 != 0) && (arg2 < (INT32_MAX / arg1))))
        {
            integer_overflow_error();
            return_value = ERROR_CODE;
        }
    }
    if (0 == return_value)
    {
        return_value = (arg1 * arg2);
    }

    return return_value;
}

int32_t sanitize_division(int32_t arg1, int32_t arg2)
{
    if ((0 == arg2) || ((INT32_MIN == arg1) && (ERROR_CODE == arg2)))
    {
        integer_overflow_error();
        return_value = ERROR_CODE;
    }
    else
    {
        return_value = (arg1 / arg2);
    }

    return return_value;
}

int32_t sanitize_modulo(int32_t arg1, int32_t arg2)
{
    if ((0 == arg2) || ((INT32_MIN == arg1) && (ERROR_CODE == arg2)))
    {
        integer_overflow_error();
        return_value = ERROR_CODE;
    }
    else
    {
        return_value = (arg1 % arg2);
    }

    return return_value;
}

/*** end of file ***/
