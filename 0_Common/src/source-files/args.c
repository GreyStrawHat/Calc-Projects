#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "magic_num.h"

uint32_t sanitize_uarg(char * arg)
{
    char *        end_p        = NULL;
    unsigned long argument     = strtoul(arg, &end_p, BASE_TEN);
    uint32_t      return_value = 0;

    if (argument > UINT32_MAX)
    {
        printf("Unsafe value detected.\n\n");
        return_value = 1;
    }
    else
    {
        return_value = argument;
    }

    return return_value;
}

int32_t sanitize_iarg(char * arg)
{
    char *      end_p        = NULL;
    signed long argument     = strtol(arg, &end_p, BASE_TEN);
    int32_t     return_value = 0;

    if ((argument < INT32_MIN) || (argument > INT32_MAX))
    {
        printf("Unsafe value detected.\n");
        return_value = -1;
    }
    else
    {
        return_value = argument;
    }

    return return_value;
}

int sanitize_two_uargs(char *     arg1,
                       char *     arg2,
                       uint32_t * san_out1,
                       uint32_t * san_out2)
{
    char * end_p        = NULL;
    int    return_value = 0;
    if (((1 == sanitize_uarg(arg1)) &&
         (1 != strtoul(arg1, &end_p, BASE_TEN))) ||
        ((1 == sanitize_uarg(arg2)) && (1 != strtoul(arg2, &end_p, BASE_TEN))))
    {
        return_value++;
    }

    if (return_value != 0)
    {
        return_value = 1;
    }

    *san_out1 = sanitize_uarg(arg1);
    *san_out2 = sanitize_uarg(arg2);

    return return_value;
}

int sanitize_two_iargs(char *    arg1,
                       char *    arg2,
                       int32_t * san_out1,
                       int32_t * san_out2)
{
    char * end_p        = NULL;
    int    return_value = 0;
    if (((-1 == sanitize_iarg(arg1)) &&
         (-1 != strtol(arg1, &end_p, BASE_TEN))) ||
        ((-1 == sanitize_iarg(arg2)) && (-1 != strtol(arg2, &end_p, BASE_TEN))))
    {
        return_value++;
    }
    if (return_value != 0)
    {
        return_value = -1;
    }

    *san_out1 = sanitize_iarg(arg1);
    *san_out2 = sanitize_iarg(arg2);

    return return_value;
}

/*** end of file ***/
