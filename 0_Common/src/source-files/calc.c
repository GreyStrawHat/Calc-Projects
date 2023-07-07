#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "args.h"
#include "math_operations.h"
#include "default_case.h"

int calc(char * operand1, char * operator_val, char * operand2)
{
    int32_t  result       = 0;
    int      error_status = 0;
    int32_t  iarg_1       = 0;
    int32_t  iarg_2       = 0;
    uint32_t uarg_1       = 0;
    uint32_t uarg_2       = 0;

    switch (*operator_val)
    {
        case '+':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            result = sanitize_addition(iarg_1, iarg_2);
            printf("The Result is: %i\n", result);
            break;
        case '-':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            result = sanitize_subtraction(iarg_1, iarg_2);
            printf("The Result is: %i\n", result);
            break;
        case '/':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            result = sanitize_division(iarg_1, iarg_2);
            printf("The Result is: %i\n", result);
            break;
        case '*':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            result = sanitize_multiplication(iarg_1, iarg_2);
            printf("The Result is: %i\n", result);
            break;
        case '&':
            if ((1 == sanitize_two_uargs(operand1, operand2, &uarg_1, &uarg_2)))
            {
                error_status++;
                goto END;
            }
            result = (uarg_1 & uarg_2);
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        case '|':
            if ((1 == sanitize_two_uargs(operand1, operand2, &uarg_1, &uarg_2)))
            {
                error_status++;
                goto END;
            }
            result = (uarg_1 | uarg_2);
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        case '%':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            result = sanitize_modulo(iarg_1, iarg_2);
            printf("The Result is: %i\n", result);
            break;
        case '^':
            if ((1 == sanitize_two_uargs(operand1, operand2, &uarg_1, &uarg_2)))
            {
                error_status++;
                goto END;
            }
            result = (uarg_1 ^ uarg_2);
            printf("The Result is: %u\n", (uint32_t)result);
            break;
        default:
            if (1 == default_case(
                         operand1, operator_val, operand2, &uarg_1, &uarg_2))
            {
                error_status++;
                goto END;
            }
    }

END:
    if (0 != error_status)
    {
        error_status = -1;
    }

    return error_status;
}

/*** end of file ***/
