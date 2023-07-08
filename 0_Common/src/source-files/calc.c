#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "error_msg.h"
#include "ec_operations1.h"
#include "unsigned_math_operations.h"
#include "ec_operations2.h"
#include "ec_operations4.h"
#include "default_case.h"

int calc(char * operand1, char * operator_val, char * operand2)
{
    //int32_t result       = 0;
    int     error_status = 0;

    switch (*operator_val)
    {
        case '+':
            if (ec_addition(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '-':
            if (ec_subtraction(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '/':
            if (ec_division(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '*':
            if (ec_multiplication(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '&':
            if (ec_bitwise_AND(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '|':
            if (ec_bitwise_OR(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '%':
            if (ec_modulo(operand1, operand2))
            {
                error_status = ERROR_CODE;
                goto END;
            }
            break;
        case '^':
            if (ec_bitwise_XOR(operand1, operand2))
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

/*** end of file ***/
