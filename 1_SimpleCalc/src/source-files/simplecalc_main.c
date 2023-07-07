#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_msg.h"
#include "calc.h"
#include "magic_num.h"

int main(int argc, char ** argv)
{
    int error_status = 0;

    if (EQUATION_COUNT != argc)
    {
        fprintf(stderr, "Invalid number of arguments.\n\n");
        usage(argv[0]);
        error_status = 1;
        goto END;
    }

    char ** end_pp = NULL;

    if (((0 == strtoul(argv[1], end_pp, BASE_TEN)) &&
        (0 != strncmp(argv[1], "0\n", 1))) || ((0 == strtoul(argv[3], end_pp, BASE_TEN)) &&
        (0 != strncmp(argv[3], "0\n", 1))))
    {
        fprintf(stderr, "Integer values only.\n\n");
        usage(argv[0]);
        error_status = 1;
        goto END;
    }

    if (-1 == calc(argv[1], argv[2], argv[3]))
    {
        usage(argv[0]);
        error_status = 1;
        goto END;
    }

END:
    return error_status;
}

/*** end of file ***/
