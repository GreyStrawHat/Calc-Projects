#include "error_handling.h"
#include "io_32.h"

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
        "[Error] - Operation Failed potential unsigned integer wrapping "
        "detected.\n\n");
    return ERROR_CODE;
}

int integer_overflow_error()
{
    printf(
        "[Error] - Operation Failed. Potential Integer Overflow "
        "detected.\n\n");
    return ERROR_CODE;
}

bool unsigned_error_checker(char * operand1, char * operand2)
{
    char * end_p           = NULL;
    bool   ec_return_value = false;

    if (((1 == sanitize_uarg(operand1)) &&
         (1 != strtoul(operand1, &end_p, BASE_TEN))) ||
        ((1 == sanitize_uarg(operand2)) &&
         (1 != strtoul(operand2, &end_p, BASE_TEN))))
    {
        ec_return_value = true;
    }

    return ec_return_value;
}

bool signed_error_checker(char * operand1, char * operand2)
{
    char * end_p           = NULL;
    bool   ec_return_value = false;

    if (((ERROR_CODE == sanitize_iarg(operand1)) &&
         (ERROR_CODE != strtol(operand1, &end_p, BASE_TEN))) ||
        ((ERROR_CODE == sanitize_iarg(operand2)) &&
         (ERROR_CODE != strtol(operand2, &end_p, BASE_TEN))))
    {
        ec_return_value = true;
    }

    return ec_return_value;
}

bool ec_addition(char * operand1, char * operand2)
{
    int32_t result       = 0;
    bool    return_value = false;

    if (true == signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if (ERROR_CODE == handle_int_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }

    result =
        sanitize_addition(sanitize_iarg(operand1), sanitize_iarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %i\n", result);

END:
    return return_value;
}

bool ec_subtraction(char * operand1, char * operand2)
{
    int32_t result       = 0;
    bool    return_value = false;

    if (true == signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if (ERROR_CODE == handle_int_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }

    result =
        sanitize_subtraction(sanitize_iarg(operand1), sanitize_iarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %i\n", result);

END:
    return return_value;
}

bool ec_multiplication(char * operand1, char * operand2)
{
    int32_t result       = 0;
    bool    return_value = false;

    if (true == signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if (ERROR_CODE == handle_int_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }

    result = sanitize_multiplication(sanitize_iarg(operand1),
                                     sanitize_iarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %i\n", result);

END:
    return return_value;
}

bool ec_division(char * operand1, char * operand2)
{
    int32_t result       = 0;
    bool    return_value = false;

    if (true == signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }

    if (0 == sanitize_iarg(operand2))
    {
        printf("[ERROR] - Cannot Divide by Zero.\n\n");
        return_value = true;
        goto END;
    }

    if (ERROR_CODE == handle_int_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result =
        sanitize_division(sanitize_iarg(operand1), sanitize_iarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %i\n", result);

END:
    return return_value;
}

bool ec_modulo(char * operand1, char * operand2)
{
    int32_t result       = 0;
    bool    return_value = false;

    if (true == signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }

    if (0 == sanitize_iarg(operand2))
    {
        fprintf(stderr, "[Error] - Cannot Divide by Zero.\n\n");
        return_value = true;
        goto END;
    }

    if (ERROR_CODE == handle_int_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result = sanitize_modulo(sanitize_iarg(operand1), sanitize_iarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %i\n", result);

END:
    return return_value;
}

bool ec_bitwise_AND(char * operand1, char * operand2)
{
    uint32_t result       = 0;
    bool     return_value = false;

    if (true == unsigned_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result = sanitize_uarg(operand1) & sanitize_uarg(operand2);
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %u\n", result);

END:
    return return_value;
}

bool ec_bitwise_OR(char * operand1, char * operand2)
{
    uint32_t result       = 0;
    bool     return_value = false;

    if (true == unsigned_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result = sanitize_uarg(operand1) | sanitize_uarg(operand2);
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %u\n", result);

END:
    return return_value;
}

bool ec_bitwise_XOR(char * operand1, char * operand2)
{
    uint32_t result       = 0;
    bool     return_value = false;

    if (true == unsigned_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result = sanitize_uarg(operand1) ^ sanitize_uarg(operand2);
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %u\n", result);

END:
    return return_value;
}

bool ec_lshift(char * operand1, char * operand2)
{
    uint32_t result       = 0;
    bool     return_value = false;

    if (UNSIGNED_ERROR_CODE == sanitize_lshift(sanitize_uarg(operand1), sanitize_uarg(operand2)))
    {
        return_value = true;
        goto END;
    }
    if (ERROR_CODE == handle_uint_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result = sanitize_lshift(sanitize_uarg(operand1), sanitize_uarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %u\n", result);

END:
    return return_value;
}

bool ec_rotateLeft(char * operand1, char * operand2)
{
    uint32_t result       = 0;
    bool     return_value = false;

    if (true == unsigned_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if (ERROR_CODE == handle_uint_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result = rotateLeft(sanitize_uarg(operand1), sanitize_uarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %u\n", result);

END:
    return return_value;
}

bool ec_rotateRight(char * operand1, char * operand2)
{
    uint32_t result       = 0;
    bool     return_value = false;

    if (true == unsigned_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if (ERROR_CODE == handle_uint_args(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    result = rotateRight(sanitize_uarg(operand1), sanitize_uarg(operand2));
    printf("[DEBUG] - operand1 at memory address [ %p ] = [ %s ]\n",
           (void *)operand1,
           operand1);
    printf("[DEBUG] - operand2 at memory address [ %p ] = [ %s ]\n\n",
           (void *)operand2,
           operand2);
    printf("The Result is: %u\n", result);

END:
    return return_value;
}

/*** end of file ***/
