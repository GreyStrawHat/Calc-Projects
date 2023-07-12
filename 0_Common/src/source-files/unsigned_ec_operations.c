#include "unsigned_ec_operations.h"

bool ec_bitwise_AND(char * operand1, char * operand2)
{
    uint32_t result       = 0;
    bool     return_value = false;

    if (unsigned_error_checker(operand1, operand2))
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

    if (unsigned_error_checker(operand1, operand2))
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

    if (unsigned_error_checker(operand1, operand2))
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

    if (unsigned_error_checker(operand1, operand2))
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

    if (unsigned_error_checker(operand1, operand2))
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

    if (unsigned_error_checker(operand1, operand2))
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
