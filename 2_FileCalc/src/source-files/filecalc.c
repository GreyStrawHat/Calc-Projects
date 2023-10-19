#include "filecalc.h"

solved_equation_t * filecalc(file_header_t * Header, unsolved_equation_t * Equation,
                           solved_equation_t * sequation)
{
    printf(BLUE "Target Equation: 0x%X\n" RESET, Header->equation_id);

    int error_status = 0;

    if ((NULL == Equation) || (NULL == sequation) || (NULL == Header))
    {
        fprintf(stderr, RED "Error: NULL pointer\n" RESET);
        DEBUG_PRINT(YELLOW "[*] Error %d " RESET, errno);
        goto END;
    }

    switch (Equation->operator_value)
    {
        case ADDITION:
            sequation->data_type = 1;
            if (true == ec_addition64(Equation->operand1, Equation->operand2))
            {
                printf("Addition Error\n");
                error_status = 1;
                goto END;
            }
            sequation->result = Equation->operand1 + Equation->operand2;
            break;
        case SUBTRACTION:
            sequation->data_type = 1;
            if (true ==
                ec_subtraction64(Equation->operand1, Equation->operand2))
            {
                printf("Subtraction Error\n");
                error_status = 1;
                goto END;
            }
            sequation->result = Equation->operand1 - Equation->operand2;
            break;
        case MULTIPLICATION:
            sequation->data_type = 1;
            if (true ==
                ec_multiplication64(Equation->operand1, Equation->operand2))
            {
                printf("Multiplication Error\n");
                error_status = 1;
                goto END;
            }
            sequation->result = Equation->operand1 * Equation->operand2;
            break;
        case DIVISION:
            if (true == ec_division64(Equation->operand1, Equation->operand2))
            {
                printf("Division Error\n");
                error_status = 1;
                goto END;
            }
            sequation->result = Equation->operand1 / Equation->operand2;
            break;
        case MODULUS:
            sequation->data_type = 1;
            if (true == ec_modulo64(Equation->operand1, Equation->operand2))
            {
                printf("Modulus Error\n");
                error_status = 1;
                goto END;
            }
            sequation->result = Equation->operand1 % Equation->operand2;

            break;
        default:
            if (Equation->operator_value > RIGHT_ROTATE)
            {
                fprintf(stderr,
                        RED
                        "[ERROR] - Operation Failed invalid operator "
                        "detected\n" RESET);
                error_status = 1;
                goto END;
            }
            sequation->data_type = 2;
            sequation            = default_case64(Equation, sequation);
            
            if (0 == sequation->solved_flag)
            {
                error_status = 1;
            }
            goto END;
    }

END:
    if (( 0 == error_status) && (NULL != sequation))
    {
        sequation->solved_flag = 1;
    }

    return sequation;
}

/*** end of file ***/
