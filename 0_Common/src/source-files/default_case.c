#include "default_case.h"

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

/*** end of file ***/
