#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_msg.h"
#include "calc.h"

int main(int argc, char ** argv)
{
    if (4 != argc)
    {
        fprintf(stderr, "Invalid number of arguments.\n");
        usage(argv[0]);
        goto END;
    }

    char ** end_pp = NULL;

    if ((0 == strtoull(argv[1], end_pp, 10)) &&
        (0 != strncmp(argv[1], "0\n", 1)))
    {
        fprintf(stderr, "Integer values only.\n");
        usage(argv[0]);
        goto END;
    }

    calc(argv[1], argv[2], argv[3], argv[0]);

    return 0;

END:
    printf("Exiting program..\n");
    return -1;
}

/*** end of file ***/
