#include "filecalc_main.h"

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    Unsolved_Equation * Input_File;
    // Solved_Equation *Output_File;

    // Make a function to open/create an output directory and store the file
    // data there.

    Input_File = return_unsolved_struct(argv[1], argv[2]);
    // Output_File = return_solved_struct(Input_File, argv[2]);

    if (Input_File == NULL)
    {
        printf("Error Parsing files\n");
        free(Input_File);
        // free(Output_File);
        return -1;
    }

    if (Input_File->magic_num != MAG_NUM)
    {
        printf("Magic Number Error\n");
        free(Input_File);
        // free(Output_File);
        return -1;
    }

    printf("Success.\n");

    free(Input_File);
    // free(Output_File);
    return 0;
}

/*** end of file ***/
