#include "operations_32.h"
#include "io_32.h"
#include "error_handling.h"

int calc(char * operand1, char * operator_val, char * operand2)
{
    int error_status = 0;

    switch (*operator_val)
    {
        case '+':
            if (true == ec_addition(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '-':
            if (true == ec_subtraction(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '/':
            if (true == ec_division(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '*':
            if (true == ec_multiplication(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '&':
            if (true == ec_bitwise_AND(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '|':
            if (true == ec_bitwise_OR(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '%':
            if (true == ec_modulo(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '^':
            if (true == ec_bitwise_XOR(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        default:
            if (UNSIGNED_ERROR_CODE ==
                default_case(operand1, operator_val, operand2))
            {
                error_status = ERROR_CODE;
            }
    }

END:
    return error_status;
}

int default_case(char * operand1, char * operator_val, char * operand2)
{
    uint32_t unsigned_result = 0;
    int      error_status    = 0;

    if (0 == strncmp(operator_val, "<<<\0", 4))
    {
        if (ec_rotateLeft(operand1, operand2))
        {
            error_status = ERROR_CODE;
            goto END;
        }
    }
    else if (0 == strncmp(operator_val, ">>>\0", 4))
    {
        if (ec_rotateRight(operand1, operand2))
        {
            error_status = ERROR_CODE;
            goto END;
        }
    }
    else if (0 == strncmp(operator_val, ">>\0", 3))
    {
        if (unsigned_error_checker(operand1, operand2))
        {
            error_status = ERROR_CODE;
            goto END;
        }
        unsigned_result = (sanitize_uarg(operand1) >> sanitize_uarg(operand2));
        printf("The Result is: %u\n", unsigned_result);
    }
    else if (0 == strncmp(operator_val, "<<\0", 3))
    {
        if (ec_lshift(operand1, operand2))
        {
            error_status = ERROR_CODE;
            goto END;
        }
    }
    else
    {
        printf("Invalid operator_val.\n");
        error_status = ERROR_CODE;
        goto END;
    }

END:
    if (0 != error_status)
    {
        error_status = 1;
    }

    return error_status;
}

int32_t sanitize_addition(int32_t arg1, int32_t arg2)
{
    int return_value = 0;

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
    int return_value = 0;

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
    int return_value = 0;

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
    int return_value = 0;

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
    int return_value = 0;

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

uint32_t rotateLeft(uint32_t value, uint32_t shift)
{
    shift %= BIT_WIDTH;
    uint32_t rotated_value = (sanitize_lshift(value, shift) & INT32_BIT_MASK);
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
    uint32_t return_value = 0;

    if ((arg2 > BIT_WIDTH) || (arg1 >= UINT32_MAX))
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
