#include "filecalc.h"

Solved_Equation *filecalc(Unsolved_Equation *Equation, Solved_Equation *sequation)
{

    sequation->solved_flag = 0;
    sequation->header_flag = 0;

    switch (Equation->operator_value)
    {
    case 0x01:
        sequation->result = (Equation->operand1 + Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x02:
        sequation->result = (Equation->operand1 - Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x03:
        sequation->result = (Equation->operand1 * Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x04:
        sequation->result = (Equation->operand1 / Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x05:
        sequation->result = (Equation->operand1 % Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x06:
        sequation->result = (Equation->operand1 << Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x07:
        sequation->result = (Equation->operand1 >> Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x08:
        sequation->result = (Equation->operand1 & Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x09:
        sequation->result = (Equation->operand1 | Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x0a:
        sequation->result = (Equation->operand1 ^ Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x0b:
        sequation->result = ((Equation->operand1 << Equation->operand2) | (Equation->operand1 >> Equation->operand2));
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    case 0x0c:
        sequation->result = ((Equation->operand1 >> Equation->operand2) | (Equation->operand1 << Equation->operand2));
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    default:
        printf("Invalid Operator\n");
    }
    return sequation;
}

/*** end of file ***/
