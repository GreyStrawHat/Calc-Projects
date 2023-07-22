#include "filecalc.h"

Solved_Equation * filecalc(Unsolved_Equation * Equation,
                           Solved_Equation *   sequation)
{

    int error_status = 0;

    switch (Equation->operator_value)
    {
        case ADDITION:
            if (true == ec_addition64(Equation->operand1, Equation->operand2))
            {
                printf("Addition Error\n");
                error_status = 1;
                goto END;
            }
            sequation->result = Equation->operand1 + Equation->operand2;
            break;
        case SUBTRACTION:
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
            if (true == ec_modulo64(Equation->operand1, Equation->operand2))
            {
                printf("Modulus Error\n");
                error_status = 1;
                goto END;
            }
            sequation->result = Equation->operand1 % Equation->operand2;

            break;
        default:
            printf("Invalid Operator\n");
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
