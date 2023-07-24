#include "default_case64.h"

Solved_Equation * default_case64(Unsolved_Equation * Equation,
                                 Solved_Equation *   sequation)
{
    Solved_Equation * return_value = sequation;

    if ((NULL == Equation) || (NULL == sequation))
    {
        fprintf(stderr, RED "Error: NULL pointer\n" RESET);
        return_value = NULL;
        goto END;
    }

    switch (Equation->operator_value)
    {
        case LEFT_SHIFT:
            if (true == ec_lshift64(Equation->operand1, Equation->operand2))
            {
                fprintf(stderr, "Left Shift Error\n");
                return_value = NULL;
                goto END;
            }
            sequation->result = Equation->operand1 << Equation->operand2;
            break;
        case RIGHT_SHIFT:
            printf(YELLOW "Operation: %lu >> %lu\n" RESET,
                   Equation->operand1,
                   Equation->operand2);
            sequation->result = Equation->operand1 >> Equation->operand2;
            break;
        case LEFT_ROTATE:
            if (true == ec_rotateLeft64(Equation->operand1, Equation->operand2))
            {
                fprintf(stderr, "Left Rotate Error\n");
                return_value = NULL;
                goto END;
            }
            sequation->result =
                rotateLeft64(Equation->operand1, Equation->operand2);
            break;
        case RIGHT_ROTATE:
            if (true ==
                ec_rotateRight64(Equation->operand1, Equation->operand2))
            {
                fprintf(stderr, "Right Rotate Error\n");
                return_value = NULL;
                goto END;
            }
            sequation->result =
                rotateRight64(Equation->operand1, Equation->operand2);
            break;
        case BITWISE_AND:
            if (true ==
                ec_bitwise_AND64(Equation->operand1, Equation->operand2))
            {
                fprintf(stderr, "Bitwise AND Error\n");
                return_value = NULL;
                goto END;
            }
            sequation->result = Equation->operand1 & Equation->operand2;

            break;
        case BITWISE_OR:
            if (true == ec_bitwise_OR64(Equation->operand1, Equation->operand2))
            {
                fprintf(stderr, "Bitwise OR Error\n");
                return_value = NULL;
                goto END;
            }
            sequation->result = Equation->operand1 | Equation->operand2;

            break;
        case BITWISE_XOR:
            if (true ==
                ec_bitwise_XOR64(Equation->operand1, Equation->operand2))
            {
                fprintf(stderr, "Bitwise XOR Error\n");
                return_value = NULL;
                goto END;
            }
            sequation->result = Equation->operand1 ^ Equation->operand2;

            break;
        default:
            fprintf(stderr, "Invalid Operator\n");
            return_value = NULL;
            goto END;
    }

END:
    if (NULL != return_value)
    {
        sequation->solved_flag = 1;
    }

    return return_value;
}

/*** end of file ***/
