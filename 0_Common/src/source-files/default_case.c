#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "args.h"
#include "unsigned_math_operations.h"
#include "signed_math_operations.h"

int default_case(char * operand1, char * operator_val, char * operand2)
{
    uint32_t unsigned_result = 0;
    int      error_status    = 0;

    if (0 == strncmp(operator_val, "<<<\0", 4))
    {
        if (unsigned_error_checker(operand1, operand2))
        {
            error_status++;
            goto END;
        }
        printf("The Result is: %u\n",
               rotateLeft(sanitize_uarg(operand1), sanitize_uarg(operand2)));
    }
    else if (0 == strncmp(operator_val, ">>>\0", 4))
    {
        if (unsigned_error_checker(operand1, operand2))
        {
            error_status++;
            goto END;
        }
        printf("The Result is: %u\n",
               rotateRight(sanitize_uarg(operand1), sanitize_uarg(operand2)));
    }
    else if (0 == strncmp(operator_val, ">>\0", 3))
    {
        if (unsigned_error_checker(operand1, operand2))
        {
            error_status++;
            goto END;
        }
        unsigned_result = (sanitize_uarg(operand1) >> sanitize_uarg(operand2));
        printf("The Result is: %u\n", unsigned_result);
    }
    else if (0 == strncmp(operator_val, "<<\0", 3))
    {
        if (unsigned_error_checker(operand1, operand2))
        {
            error_status++;
            goto END;
        }
        unsigned_result =
            sanitize_lshift(sanitize_uarg(operand1), sanitize_uarg(operand2));
        printf("The Result is: %u\n", unsigned_result);
    }
    else
    {
        printf("Invalid operator_val.\n");
        error_status++;
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
