#include "filecalc_main.h"

int main(int argc, char ** argv)
{
    int                 return_value = 0;
    unsolved_equation_t * Input_Dir    = NULL;

    if (3 != argc)
    {
        fprintf(stderr, RED "Invalid number of arguments\n" RESET);
        printf(RED BOLD "Usage: %s <input_dir> <output_dir>\n\n" RESET,
               argv[0]);
        return_value = ERROR_CODE;
        goto END;
    }

    Input_Dir = return_unsolved_struct(argv[1], argv[2]);
    if (NULL == Input_Dir)
    {
        fprintf(stderr, RED "Operation Failed\n\n" RESET);
        printf(RED BOLD "Usage: %s <input_dir> <output_dir>\n\n" RESET,
               argv[0]);
        return_value = ERROR_CODE;
        goto END;
    }

    printf("\nOperations Successful.\n");

END:
    free(Input_Dir);
    return return_value;
}

/*** end of file ***/
