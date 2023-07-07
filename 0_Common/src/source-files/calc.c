#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "error_msg.h"
#include "args.h"
#include "unsigned_math_operations.h"
#include "signed_math_operations.h"
#include "default_case.h"

int calc(char * operand1, char * operator_val, char * operand2)
{
    int32_t result       = 0;
    int     error_status = 0;

    switch (*operator_val)
    {
        case '+':
            if (signed_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = sanitize_addition(sanitize_iarg(operand1),
                                       sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '-':
            if (signed_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = sanitize_subtraction(sanitize_iarg(operand1),
                                          sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '/':
            if (signed_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = sanitize_division(sanitize_iarg(operand1),
                                       sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '*':
            if (signed_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = sanitize_multiplication(sanitize_iarg(operand1),
                                             sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '&':
            if (unsigned_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = (sanitize_uarg(operand1) & sanitize_uarg(operand2));
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        case '|':
            if (unsigned_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = (sanitize_uarg(operand1) | sanitize_uarg(operand2));
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        case '%':
            if (signed_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = sanitize_modulo(sanitize_iarg(operand1),
                                     sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '^':
            if (unsigned_error_checker(operand1, operand2))
            {
                error_status = ERROR_CODE;
            }
            result = (sanitize_uarg(operand1) ^ sanitize_uarg(operand2));
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        default:
            if (UNSIGNED_ERROR_CODE == default_case(operand1, operator_val, operand2))
            {
                error_status = ERROR_CODE;
            }
    }

    return error_status;
}

/*** end of file ***/
