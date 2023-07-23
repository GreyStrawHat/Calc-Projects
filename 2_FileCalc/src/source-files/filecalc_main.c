#include "filecalc_main.h"

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    Unsolved_Equation * Input_File;

    // Make a function to open/create an output directory and store the file
    // data there.

    Input_File = return_unsolved_struct(argv[1], argv[2]);
    // Output_File = return_solved_struct(Input_File, argv[2]);

    if (Input_File == NULL)
    {
        printf("Error Parsing Unsolved Equation File\n");
        free(Input_File);
        return -1;
    }

    if (Input_File->magic_num != MAG_NUM)
    {
        DEBUG_PRINT("Magic Number: %X\n", Input_File->magic_num);
        free(Input_File);
        return -1;
    }

    printf("\nOperations Successful.\n");

    free(Input_File);
    return 0;
}

/*** end of file ***/
