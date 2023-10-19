#include "return_solved_struct.h"
#define SOLVED 0x01

solved_equation_t * return_solved_struct(file_header_t * equation_file_header,
                                         unsolved_equation_t * Equation,
                                         char *                output_dir_arg)
{
    solved_equation_t * return_value = NULL;
    errno                            = 0;
    solved_equation_t * sequation_p =
        (solved_equation_t *)calloc(1, sizeof(solved_equation_t));

    file_header_t * solved_file_header =
        (file_header_t *)calloc(1, sizeof(file_header_t));

    if (NULL == sequation_p)
    {
        fprintf(stderr, "Calloc Error\n");
        return_value = NULL;
        goto END;
    }

    if (NULL == solved_file_header)
    {
        fprintf(stderr, "Calloc Error\n");
        return_value = NULL;
        goto END;
    }

    if ((NULL == equation_file_header) || (NULL == output_dir_arg))
    {
        fprintf(stderr, RED "Error: NULL pointer\n");
        DEBUG_PRINT(YELLOW "[*] Error %d " RESET, errno);
        return_value = NULL;
        goto END;
    }

    solved_file_header->magic_num       = equation_file_header->magic_num;
    solved_file_header->file_id         = equation_file_header->file_id;
    solved_file_header->num_of_e        = equation_file_header->num_of_e;
    solved_file_header->header_flag     = SOLVED;
    solved_file_header->equation_offset = equation_file_header->equation_offset;
    solved_file_header->num_of_opt_headers =
        equation_file_header->num_of_opt_headers;
    solved_file_header->equation_id = equation_file_header->equation_id;

    // create function that takes Unsolved equation and
    // returns the result to sequation_p->result

    sequation_p = filecalc(equation_file_header, Equation, sequation_p);
    if (NULL == sequation_p)
    {
        fprintf(stderr, "NULL value found.\n");
        DEBUG_PRINT(YELLOW "[*] Error %d " RESET, errno);
        return_value = NULL;
        goto END;
    }

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

    if (ERROR_CODE == parse_solved_file(solved_file_header, sequation_p, output_dir_arg))
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
    free(solved_file_header);
    solved_file_header = NULL;

    if (NULL == return_value)
    {
        free(sequation_p);
        sequation_p = NULL;
    }
    
    return return_value;
}

/*** end of file ***/
