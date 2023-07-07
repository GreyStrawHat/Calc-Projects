#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_msg.h"
#include "calc.h"
#include "magic_num.h"

int main(int argc, char ** argv)
{
    char ** end_pp       = NULL;
    int     error_status = 0;
    int32_t arg1_test    = strtol(argv[1], end_pp, BASE_TEN);
    int32_t arg3_test    = strtol(argv[3], end_pp, BASE_TEN);
    int32_t arg1_length  = strlen(argv[1]);
    int32_t arg3_length  = strlen(argv[3]);

    if (EQUATION_COUNT != argc)
    {
        fprintf(stderr, "Invalid number of arguments.\n\n");
        usage(argv[0]);
        error_status = -1;
        goto END;
    }

    if (((0 == strtoul(argv[1], end_pp, BASE_TEN)) &&
         (0 != strncmp(argv[1], "0\n", 1))) ||
        ((0 == strtoul(argv[3], end_pp, BASE_TEN)) &&
         (0 != strncmp(argv[3], "0\n", 1))) || (arg1_test != arg1_length) || (arg3_test != arg3_length))
    {
        fprintf(stderr, "Integer values only.\n\n");
        usage(argv[0]);
        error_status = -1;
        goto END;
    }

    if (-1 == calc(argv[1], argv[2], argv[3]))
    {
        usage(argv[0]);
        error_status = -1;
        goto END;
    }

END:
    return error_status;
}

/*** end of file ***/
