#include <args.h>

uint32_t sanitize_uarg(char * arg)
{
    char *        end_p        = NULL;
    uint32_t unsigned_return_value = 0;
    unsigned long argument     = strtoul(arg, &end_p, BASE_TEN);

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
    int32_t  signed_return_value   = 0;
    signed long argument     = strtol(arg, &end_p, BASE_TEN);

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
    bool ec_return_value = false;

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
    bool ec_return_value = false;

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
