#include "filecalc_main.h"

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    Unsolved_Equation * Input_Dir;

    // Make a function to open/create an output directory and store the file
    // data there.

    Input_Dir = return_unsolved_struct(argv[1], argv[2]);
    // Output_File = return_solved_struct(Input_Dir, argv[2]);

    if (Input_Dir == NULL)
    {
        printf(RED "Operation Failed\n\n" RESET);
        printf(RED BOLD "Usage: %s <input_dir> <output_dir>\n\n" RESET,
               argv[0]);
        free(Input_Dir);
        return -1;
    }

    printf("\nOperations Successful.\n");

    free(Input_Dir);
    return 0;
}

/*** end of file ***/
