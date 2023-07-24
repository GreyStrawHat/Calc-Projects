#include "filecalc_main.h"

int main(int argc, char ** argv)
{
    if (3 != argc)
    {
        printf(RED "Invalid number of arguments\n" RESET);
        return ERROR_CODE;
    }

    Unsolved_Equation * Input_Dir;

    Input_Dir = return_unsolved_struct(argv[1], argv[2]);
    if (NULL == Input_Dir)
    {
        printf(RED "Operation Failed\n\n" RESET);
        printf(RED BOLD "Usage: %s <input_dir> <output_dir>\n\n" RESET,
               argv[0]);
        free(Input_Dir);
        return ERROR_CODE;
    }

    printf("\nOperations Successful.\n");

    free(Input_Dir);
    return 0;
}

/*** end of file ***/
