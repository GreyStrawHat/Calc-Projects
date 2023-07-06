#include <stdio.h>
#include <stdlib.h>

void usage(char * program_name)
{
    printf("Simple Calculator in C Usage Menu.\n\n");
    printf("List of Operators:\n\n");
    printf("For Addition:\t\t\t( + )\n");
    printf("For Subtraction:\t\t( - )\n");
    printf("For Division:\t\t\t( / )\n");
    printf("For Multiplication:\t\t( * )*\n");
    printf("For Modulus:\t\t\t( %% )*\n");
    printf("For Bitwise OR:\t\t\t( | )*\n");
    printf("For Bitwise XOR:\t\t( ^ )*\n");
    printf("For Bitwise AND:\t\t( & )*\n");
    printf("For Bitwise Shift Right:\t( >> )*\n");
    printf("For Bitwise Shift Left:\t\t( << )*\n");
    printf("For Bitwise Rotate Right:\t( >>> )*\n");
    printf("For Bitwise Rotate Left:\t( <<< )*\n\n");
    printf(
        "Operators with an asterisk require single quotes or escape markers "
        "to function.\n\n");
    printf(
        "Negative numbers not accepted for bit related equations (<<, >>, &, "
        "|, ^, <<<, >>>)\n\n");
    printf("Usage: ./%s operand1 \'operator\' operand2 \n\n", program_name);
}

int unsigned_int_error()
{
    printf(
        "Operation Failed. \nPotential unsigned integer wrapping detected.\n");
    return -1;
}

int integer_overflow_error()
{
    printf("Operation Failed. \nPotential integer overflow detected.\n");
    return -1;
}

/*** end of file ***/
