#include "calc.h"

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

/*** end of file ***/
