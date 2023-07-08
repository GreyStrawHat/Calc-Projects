#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_msg.h"
#include "calc.h"
#include "magic_num.h"
#define SINGLE_BYTE 1

int main(int argc, char ** argv)
{
    char **  end_pp                       = NULL;
    int      error_status                 = 0;
    uint32_t arg1_test                    = strtol(argv[1], end_pp, BASE_TEN);
    uint32_t arg3_test                    = strtol(argv[3], end_pp, BASE_TEN);
    int32_t  arg1_length                  = strlen(argv[1]);
    int32_t  arg3_length                  = strlen(argv[3]);
    char     arg1str[DEFAULT_BUFFER_SIZE] = "0";
    char     arg3str[DEFAULT_BUFFER_SIZE] = "0";
    snprintf(arg1str, sizeof(arg1str), "%d", arg1_test);
    snprintf(arg3str, sizeof(arg3str), "%d", arg3_test);

    if (EQUATION_ARGS != argc)
    {
        fprintf(stderr, "Invalid number of arguments.\n\n");
        usage(argv[0]);
        error_status = ERROR_CODE;
        goto END;
    }

    if (((0 == strtoul(argv[1], end_pp, BASE_TEN)) &&
         (0 != strncmp(argv[1], "0\n", SINGLE_BYTE))) ||
        ((0 == strtoul(argv[3], end_pp, BASE_TEN)) &&
         (0 != strncmp(argv[3],
                       "0\n",
                       1)))) // Checks for non integer characters in operands
    {
        fprintf(stderr, "Integer values only.\n\n");
        usage(argv[0]);
        error_status = ERROR_CODE;
        goto END;
    }

    if ((arg1_length > 1) ||
        (arg3_length > 1)) // Checks if operands contain non integer values.
    {
        if ((strlen(arg1str) != (unsigned long)arg1_length) ||
            (strlen(arg3str)) !=
                (unsigned long)
                    arg3_length) // Print debug info for troubleshooting
        {
            printf("[DEBUG] arg1_test at %p = %d\n",
                   (void *)&arg1_test,
                   arg1_test);
            printf("[DEBUG] arg1_length at %p = %d\n",
                   (void *)&arg1_length,
                   arg1_length);
            printf("[DEBUG] arg3_test at %p = %d\n",
                   (void *)&arg3_test,
                   arg3_test);
            printf("[DEBUG] arg3_length at %p = %d\n\n",
                   (void *)&arg3_length,
                   arg3_length);
            fprintf(stderr, "Integer values only.\n\n");
            usage(argv[0]);
            error_status = ERROR_CODE;
            goto END;
        }
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
