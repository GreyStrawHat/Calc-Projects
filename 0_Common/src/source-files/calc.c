#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "args.h"
#include "math_operations.h"
#include "magic_num.h"
#include "default_case.h"

int calc(char * operand1,
         char * operator_val,
         char * operand2)
{
    static int32_t  signed_result   = 0;
    static uint32_t unsigned_result = 0;
    static int      error_status = 0;
    int32_t         iarg_1 = 0;
    int32_t         iarg_2 = 0;
    uint32_t        uarg_1 = 0;
    uint32_t        uarg_2 = 0;

    switch (*operator_val)
    {
        case '+':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            signed_result = sanitize_addition(iarg_1, iarg_2);
            printf("The Result is: %i\n", signed_result);
            break;
        case '-':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            signed_result = sanitize_subtraction(iarg_1, iarg_2);
            printf("The Result is: %i\n", signed_result);
            break;
        case '/':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            signed_result = sanitize_division(iarg_1, iarg_2);
            printf("The Result is: %i\n", signed_result);
            break;
        case '*':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            signed_result = sanitize_multiplication(iarg_1, iarg_2);
            printf("The Result is: %i\n", signed_result);
            break;
        case '&':
            if ((1 == sanitize_two_uargs(operand1, operand2, &uarg_1, &uarg_2)))
            {
                error_status++;
                goto END;
            }
            unsigned_result = (uarg_1 & uarg_2);
            printf("The Result is: %u\n", unsigned_result);
            break;
        case '|':
            if ((1 == sanitize_two_uargs(operand1, operand2, &uarg_1, &uarg_2)))
            {
                error_status++;
                goto END;
            }
            unsigned_result = (uarg_1 | uarg_2);
            printf("The Result is: %u\n", unsigned_result);
            break;
        case '%':
            if ((-1 ==
                 sanitize_two_iargs(operand1, operand2, &iarg_1, &iarg_2)))
            {
                error_status++;
                goto END;
            }
            signed_result = sanitize_modulo(iarg_1, iarg_2);
            printf("The Result is: %i\n", signed_result);
            break;
        case '^':
            if ((1 == sanitize_two_uargs(operand1, operand2, &uarg_1, &uarg_2)))
            {
                error_status++;
                goto END;
            }
            unsigned_result = (uarg_1 ^ uarg_2);
            printf("The Result is: %u\n", unsigned_result);
            break;
        default:
            if (1 == default_case(operand1, operator_val, operand2, &uarg_1, &uarg_2))
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
