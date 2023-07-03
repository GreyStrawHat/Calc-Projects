#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints usage information for SimpleCalc prgram.
 * 
 * This function displays the list of operators supported by SimpleCalc
 * and provides an example of how to use the program.
 * 
 * @param program_name Name of program.
 */

void usage(char * program_name)
{
    printf("Simple Calculator in C\n");
    printf("List of Operators:\n");
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
    printf("For Bitwise Rotate Left:\t( <<< )*\n");
    printf(
        "\nOperators with an asterisk require single quotes or escape markers "
        "to function.\n\n");
    printf(
        "Negative numbers not accepted for bit related equations (<<, >>, &, "
        "|, ^, <<<, >>>)");
    printf("Usage: ./%s operand1 \'operator\' operand2 \n\n", program_name);
}

/**
 * @brief Handles unsigned integer wrapping errors.
 *
 * This function prints an error message indicating that a potential
 * unsigned integer wrapping error has been detected, and returns a
 * failure status code.
 *
 * @return The status code -1 indicating failure.
 */

int unsigned_int_error()
{
    printf(
        "Operation Failed. \nPotential unsigned integer wrapping detected.\n");
    return -1;
}

/**
 * @brief Handles integer overflow errors.
 *
 * This function prints an error message indicating that a potential
 * integer overflow error has been detected, and returns a failure
 * status code.
 *
 * @return The status code -1 indicating failure.
 */

int integer_overflow_error()
{
    printf("Operation Failed. \nPotential integer overflow detected.\n");
    return -1;
}

/*** end of file ***/
