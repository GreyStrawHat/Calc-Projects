#include "return_solved_struct.h"
#define SOLVED 0x01

Solved_Equation * return_solved_struct(Unsolved_Equation * Equation,
                                       char *              output_dir_arg)
{
    Solved_Equation * return_value = NULL;
    errno                          = 0;
    Solved_Equation * sequation_p =
        (Solved_Equation *)calloc(1, sizeof(Solved_Equation));
    if (NULL == sequation_p)
    {
        fprintf(stderr, "Calloc Error\n");
        return_value = NULL;
        goto END;
    }

    if ((NULL == Equation) || (NULL == output_dir_arg))
    {
        fprintf(stderr, RED "Error: NULL pointer\n");
        return_value = NULL;
        goto END;
    }

    sequation_p->magic_num          = Equation->magic_num;
    sequation_p->file_id            = Equation->file_id;
    sequation_p->num_of_e           = Equation->num_of_e;
    sequation_p->header_flag        = SOLVED;
    sequation_p->equation_offset    = Equation->equation_offset;
    sequation_p->num_of_opt_headers = Equation->num_of_opt_headers;
    sequation_p->equation_id        = Equation->equation_id;

    // create function that takes Unsolved equation and
    // returns the result to sequation_p->result

    sequation_p = filecalc(Equation, sequation_p);

    if (true == sequation_p->solved_flag)
    {
        printf(BOLD "Sucessfully solved equation\n" RESET);
    }
    else
    {
        fprintf(stderr, RED "Error solving equation\n" RESET);
        return_value = NULL;
        goto END;
    }

    if (ERROR_CODE == parse_solved_file(sequation_p, output_dir_arg))
    {
        fprintf(stderr, "Error parsing solved file\n");
        return_value = NULL;
        goto END;
    }

    if (0 != errno)
    {
        DEBUG_PRINT("Errno: %d\n", errno);
        return_value = NULL;
        goto END;
    }

    return_value = sequation_p;
END:
    if (NULL == return_value)
    {
        free(sequation_p);
        sequation_p = NULL;
    }
    return return_value;
}

/*** end of file ***/
