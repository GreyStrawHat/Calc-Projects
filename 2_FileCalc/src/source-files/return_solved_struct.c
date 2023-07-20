#include "return_solved_struct.h"

Solved_Equation *return_solved_struct(Unsolved_Equation *Equation, char *output_dir_arg)
{
    errno = 0;
    Solved_Equation *sequation = (Solved_Equation *)calloc(1, sizeof(Solved_Equation));
    if (sequation == NULL)
    {
        printf("Calloc Error\n");
        return NULL;
    }

    sequation->magic_num = Equation->magic_num;
    sequation->file_id = Equation->file_id;
    sequation->num_of_e = Equation->num_of_e;
    sequation->header_flag = Equation->header_flag;
    sequation->equation_offset = Equation->equation_offset;
    sequation->num_of_opt_headers = Equation->num_of_opt_headers;
    sequation->equation_id = Equation->equation_id;

    if (Equation->operator_value == 1)
    {
        printf("%ld + %ld = %ld\n", Equation->operand1, Equation->operand2, (Equation->operand1 + Equation->operand2));
    }

    // create function that takes Unsolved equation parameter and performs the operation
    // and returns the result to sequation->result

    // sequation->result = Equation->operand1 + Equation->operand2;

    sequation = filecalc(Equation, sequation);

    sequation->data_type = 1;
    /*
        if (sequation->result)
        {
            sequation->header_flag = 1;
            sequation->solved_flag = 1;
        }
    */
    printf("The result of the operation is %ld\n", sequation->result);

    /*
        char inversed_solved_filename[(sizeof(Equation->file_id) * 2 + 5)];

        snprintf(inversed_solved_filename, sizeof(inversed_solved_filename), "%x", sequation->equation_id);

        char solved_filename[25];

        printf("Beginning test - Buffer: %s Filename: %s\n", solved_filename, inversed_solved_filename);
        reverse_string_byte_order(inversed_solved_filename, solved_filename);
        printf("Finishing test - Buffer: %s Filename: %s\n", solved_filename, inversed_solved_filename);

        // printf("Filename : %s\n", inversed_solved_filename);
    */
    if (parse_solved_file(sequation, output_dir_arg) == -1)
    {
        printf("Error Parsing solved File\n");
        free(sequation);
        sequation = NULL;
        errno += 1;
    }

    printf("Errno: %d\n", errno);

    if (errno != 0)
    {
        return NULL;
    }
    
    return sequation;
}

/*** end of file ***/
