#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "handle_args.h"
#include "error_msg.h"
#include "calc.h"
#include <errno.h>
#define SINGLE_BYTE   1
#define EQUATION_ARGS 4
#define BASE_TEN      10

int main(int argc, char ** argv)
{
    int error_status = 0;
    errno            = 0;

    if (EQUATION_ARGS != argc)
    {
        fprintf(stderr, "[Error] - Invalid number of arguments.\n\n");
        usage(argv[0]);
        error_status = ERROR_CODE;
        goto END;
    }

    if ((ERROR_CODE == handle_int_args(argv[1], argv[3])) ||
        (ERROR_CODE == handle_uint_args(argv[1], argv[3])))
    {
        fprintf(stderr,
                "32-bit Signed or 32-bit Unsigned Integer values "
                "only.\n\n");
        error_status = ERROR_CODE;
        goto END;
    }

    if (ERROR_CODE == calc(argv[1], argv[2], argv[3]))
    {
        usage(argv[0]);
        error_status = ERROR_CODE;
        goto END;
    }

END:
    return error_status;
}

/*** end of file ***/
