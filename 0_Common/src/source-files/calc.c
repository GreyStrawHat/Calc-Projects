#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "args.h"
#include "math_operations.h"
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
                error_status++;
            }
            result = sanitize_addition(sanitize_iarg(operand1),
                                       sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '-':
            if (signed_error_checker(operand1, operand2))
            {
                error_status++;
            }
            result = sanitize_subtraction(sanitize_iarg(operand1),
                                          sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '/':
            if (signed_error_checker(operand1, operand2))
            {
                error_status++;
            }
            result = sanitize_division(sanitize_iarg(operand1),
                                       sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '*':
            if (signed_error_checker(operand1, operand2))
            {
                error_status++;
            }
            result = sanitize_multiplication(sanitize_iarg(operand1),
                                             sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '&':
            if (unsigned_error_checker(operand1, operand2))
            {
                error_status++;
            }
            result = (sanitize_uarg(operand1) & sanitize_uarg(operand2));
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        case '|':
            if (unsigned_error_checker(operand1, operand2))
            {
                error_status++;
            }
            result = (sanitize_uarg(operand1) | sanitize_uarg(operand2));
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        case '%':
            if (signed_error_checker(operand1, operand2))
            {
                error_status++;
            }
            result = sanitize_modulo(sanitize_iarg(operand1),
                                     sanitize_iarg(operand2));
            printf("The Result is: %i\n", result);
            break;
        case '^':
            if (unsigned_error_checker(operand1, operand2))
            {
                error_status++;
            }
            result = (sanitize_uarg(operand1) ^ sanitize_uarg(operand2));
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        default:
            if (1 == default_case(operand1, operator_val, operand2))
            {
                error_status++;
            }
    }

    if (0 != error_status)
    {
        error_status = -1;
    }

    return error_status;
}

/*** end of file ***/
