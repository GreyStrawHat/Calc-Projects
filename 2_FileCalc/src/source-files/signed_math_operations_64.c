#include "signed_math_operations_64.h"

int64_t addition_64(int64_t arg1, int64_t arg2)
{
    int64_t return_value = 0;

    printf(YELLOW);
    printf("Operation: %ld + %ld\n", arg1, arg2);
    printf(RESET);

    if (((arg2 > 0) && (arg1 > (INT64_MAX - arg2))) ||
        ((arg2 < 0) && (arg1 < (INT64_MIN - arg2))))
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

int64_t subtraction_64(int64_t arg1, int64_t arg2)
{
    int64_t return_value = 0;

    printf(YELLOW);
    printf("Operation: %ld - %ld\n", arg1, arg2);
    printf(RESET);

    if ((((arg2 > 0) && (arg1 < (INT64_MIN + arg2))) ||
         ((arg2 < 0) && (arg1 > (INT64_MAX + arg2)))))
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

int64_t multiplication_64(int64_t arg1, int64_t arg2)
{
    int64_t return_value = 0;

    printf(YELLOW);
    printf("Operation: %ld * %ld\n", arg1, arg2);
    printf(RESET);

    if (arg1 > 0)
    {
        if (((arg2 > 0) && (arg1 > (INT64_MAX / arg2))) ||
            ((arg2 < 0) && (arg2 < (INT64_MIN / arg1))))
        {
            integer_overflow_error();
            return_value = ERROR_CODE;
        }
    }
    else if (arg1 < 0)
    {
        if (((arg2 > 0) && (arg1 < (INT64_MIN / arg2))) ||
            ((arg2 < 0) && (arg1 != 0) && (arg2 < (INT64_MAX / arg1))))
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

int64_t division_64(int64_t arg1, int64_t arg2)
{
    int64_t return_value = 0;

    printf(YELLOW);
    printf("Operation: %ld / %ld\n", arg1, arg2);
    printf(RESET);

    if ((0 == arg2) || ((INT64_MIN == arg1) && (ERROR_CODE == arg2)))
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

int64_t modulo_64(int64_t arg1, int64_t arg2)
{
    int64_t return_value = 0;

    printf(YELLOW);
    printf("Operation: %ld %% %ld\n", arg1, arg2);
    printf(RESET);

    if ((0 == arg2) || ((INT64_MIN == arg1) && (ERROR_CODE == arg2)))
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
