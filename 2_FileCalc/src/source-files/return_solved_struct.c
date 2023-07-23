#include "return_solved_struct.h"

Solved_Equation * return_solved_struct(Unsolved_Equation * Equation,
                                       char *              output_dir_arg)
{
    errno = 0;
    Solved_Equation * sequation =
        (Solved_Equation *)calloc(1, sizeof(Solved_Equation));
    if (sequation == NULL)
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
    // eturns the result to sequation->result

    sequation = filecalc(Equation, sequation);

    if (parse_solved_file(sequation, output_dir_arg) == -1)
    {
        printf("Error parsing solved file\n");
        free(sequation);
        sequation = NULL;
        return NULL;
    }

    if (errno != 0)
    {
        DEBUG_PRINT("Errno: %d\n", errno);
        free(sequation);
        sequation = NULL;
        return NULL;
    }

    return sequation;
}

/*** end of file ***/
