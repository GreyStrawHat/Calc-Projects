#include "filecalc.h"

Solved_Equation *filecalc(Unsolved_Equation *Equation, Solved_Equation *sequation)
{
    switch (Equation->operator_value)
    {
    case 0x01:
        sequation->result = (Equation->operand1 + Equation->operand2);
        sequation->solved_flag = 1;
        sequation->header_flag = 1;
        break;
    default:
        sequation->solved_flag = 0;
        sequation->header_flag = 0;
    }
    return sequation;
}

/*** end of file ***/
