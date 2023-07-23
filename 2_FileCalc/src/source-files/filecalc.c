#include "filecalc.h"

Solved_Equation * filecalc(Unsolved_Equation * Equation,
                           Solved_Equation *   sequation)
{

    int error_status = 0;

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
            sequation->data_type = 2;
            default_case64(Equation, sequation);
            goto END;
    }

END:
    if (error_status == 0)
    {
        sequation->solved_flag = 1;
    }
    else
    {
        sequation->solved_flag = 0;
    }
    return sequation;
}

/*** end of file ***/
