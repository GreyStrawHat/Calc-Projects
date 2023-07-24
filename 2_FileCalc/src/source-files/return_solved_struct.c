#include "return_solved_struct.h"

Solved_Equation * return_solved_struct(Unsolved_Equation * Equation,
                                       char *              output_dir_arg)
{
    errno = 0;
    Solved_Equation * sequation =
        (Solved_Equation *)calloc(1, sizeof(Solved_Equation));
    if (NULL == sequation)
    {
        printf("Calloc Error\n");
        return NULL;
    }

    sequation->magic_num          = Equation->magic_num;
    sequation->file_id            = Equation->file_id;
    sequation->num_of_e           = Equation->num_of_e;
    sequation->header_flag        = 1;
    sequation->equation_offset    = Equation->equation_offset;
    sequation->num_of_opt_headers = Equation->num_of_opt_headers;
    sequation->equation_id        = Equation->equation_id;

    // create function that takes Unsolved equation and
    // returns the result to sequation->result

    sequation = filecalc(Equation, sequation);

    if (true == sequation->solved_flag)
    {
        printf(BOLD "Sucessfully solved equation\n" RESET);
    }
    else
    {
        printf("Error solving equation\n");
        free(sequation);
        sequation = NULL;
        return NULL;
    }

    if (ERROR_CODE == parse_solved_file(sequation, output_dir_arg))
    {
        printf("Error parsing solved file\n");
        free(sequation);
        sequation = NULL;
        return NULL;
    }

    if (0 != errno)
    {
        DEBUG_PRINT("Errno: %d\n", errno);
        free(sequation);
        sequation = NULL;
        return NULL;
    }

    return sequation;
}

/*** end of file ***/
