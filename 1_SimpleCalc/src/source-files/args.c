#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t sanitize_uarg(char *arg)
{
    char *end_p;
    unsigned long long argument = strtoull(arg, &end_p, 10);

    if ((argument < 0) || (argument > UINT32_MAX))
    {
        printf("Unsafe value detected.\n");
        exit(1);
    }
    else
    {
        return (uint32_t) argument;
    }
}

int32_t sanitize_iarg(char *arg)
{
    char *end_p;
    signed long long argument = strtoll(arg, &end_p, 10);

    if ((argument < INT32_MIN) || (argument > INT32_MAX))
    {
        printf("Unsafe value detected.\n");
        exit(1);
    }
    else
    {
        return (int32_t) argument;
    }
}

/*** end of file ***/
