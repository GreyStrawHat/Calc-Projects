#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "signed_math_operations.h"
#include "magic_num.h"
#include "error_msg.h"

static uint32_t unsigned_return_value = 0;
static int32_t  signed_return_value   = 0;
static bool ec_return_value = false;

uint32_t sanitize_uarg(char * arg)
{
    char *        end_p        = NULL;
    unsigned long argument     = strtoul(arg, &end_p, BASE_TEN);
    //uint32_t      return_value = 0;

    if (argument > UINT32_MAX)
    {
        printf("Unsafe value detected.\n\n");
        unsigned_return_value = 1;
    }
    else
    {
        unsigned_return_value = argument;
    }

    return unsigned_return_value;
}

int32_t sanitize_iarg(char * arg)
{
    char *      end_p        = NULL;
    signed long argument     = strtol(arg, &end_p, BASE_TEN);
    //int32_t     return_value = 0;

    if ((argument < INT32_MIN) || (argument > INT32_MAX))
    {
        printf("Unsafe value detected.\n");
        signed_return_value = ERROR_CODE;
    }
    else
    {
        signed_return_value = argument;
    }

    return signed_return_value;
}

bool unsigned_error_checker(char * operand1, char * operand2)
{
    char * end_p        = NULL;
    //bool   return_value = false;

    if (((1 == sanitize_uarg(operand1)) &&
         (1 != strtoul(operand1, &end_p, BASE_TEN))) ||
        ((1 == sanitize_uarg(operand2)) &&
         (1 != strtoul(operand2, &end_p, BASE_TEN))))
    {
        ec_return_value = true;
    }

    return ec_return_value;
}

bool signed_error_checker(char * operand1, char * operand2)
{
    char * end_p        = NULL;
    //bool   return_value = false;

    if (((ERROR_CODE == sanitize_iarg(operand1)) &&
         (ERROR_CODE != strtol(operand1, &end_p, BASE_TEN))) ||
        ((ERROR_CODE == sanitize_iarg(operand2)) &&
         (ERROR_CODE != strtol(operand2, &end_p, BASE_TEN))))
    {
        ec_return_value = true;
    }

    return ec_return_value;
}

/*** end of file ***/
