#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (4 != argc)
    {
        fprintf(stderr, "Argc error.\n");
        goto END;
    }

    char **end = NULL;

    if ((0 == strtoull(argv[1], end, 10)) && (strncmp(argv[1], "0\n", 1) != 0))
    {
        fprintf(stderr, "Argv[1] error.\n");
        goto END;
    }
    else
    {
        printf("Success.\n");
    }

    calc(argv[1], argv[2], argv[3], argv[0]);

    return 0;

    END:
        printf("Exiting program..\n");
        return -1;
}