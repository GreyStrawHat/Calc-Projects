#include "default_case64.h"

Solved_Equation * default_case64(Unsolved_Equation * Equation,
                                 Solved_Equation *   sequation)
{
    int error_status = 0;

    switch (Equation->operator_value)
    {
        case LEFT_SHIFT:
            if (true == ec_lshift64(Equation->operand1, Equation->operand2))
            {
                printf("Left Shift Error\n");
                error_status = ERROR_CODE;
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
                printf("Left Rotate Error\n");
                error_status = ERROR_CODE;
                goto END;
            }
            sequation->result =
                rotateLeft64(Equation->operand1, Equation->operand2);
            break;
        case RIGHT_ROTATE:
            if (true ==
                ec_rotateRight64(Equation->operand1, Equation->operand2))
            {
                printf("Right Rotate Error\n");
                error_status = ERROR_CODE;
                goto END;
            }
            sequation->result =
                rotateRight64(Equation->operand1, Equation->operand2);
            break;
        case BITWISE_AND:
            if (true ==
                ec_bitwise_AND64(Equation->operand1, Equation->operand2))
            {
                printf("Bitwise AND Error\n");
                error_status = ERROR_CODE;
                goto END;
            }
            sequation->result = Equation->operand1 & Equation->operand2;

            break;
        case BITWISE_OR:
            if (true == ec_bitwise_OR64(Equation->operand1, Equation->operand2))
            {
                printf("Bitwise OR Error\n");
                error_status = ERROR_CODE;
                goto END;
            }
            sequation->result = Equation->operand1 | Equation->operand2;

            break;
        case BITWISE_XOR:
            if (true ==
                ec_bitwise_XOR64(Equation->operand1, Equation->operand2))
            {
                printf("Bitwise XOR Error\n");
                error_status = ERROR_CODE;
                goto END;
            }
            sequation->result = Equation->operand1 ^ Equation->operand2;

            break;
        default:
            printf("Invalid Operator\n");
            error_status = ERROR_CODE;
            goto END;
    }

END:
    if (ERROR_CODE == error_status)
    {
        sequation->solved_flag = 0;
    }
    else
    {
        sequation->solved_flag = 1;
    }
    return sequation;
}

/*** end of file ***/
