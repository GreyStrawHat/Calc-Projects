#include "signed_ec_operations_64.h"

bool ec_addition64(int64_t operand1, int64_t operand2)
{
    int64_t result       = 0;
    bool    return_value = false;

    result = addition_64(operand1, operand2);

    if ((ERROR_CODE == result) && (ERROR_CODE != (operand1 + operand2)))
    {
        return_value = true;
        goto END;
    }

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %li\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

END:
    return return_value;
}

bool ec_subtraction64(int64_t operand1, int64_t operand2)
{
    int64_t result       = 0;
    bool    return_value = false;

    result = subtraction_64(operand1, operand2);

    if ((ERROR_CODE == result) && (ERROR_CODE != (operand1 - operand2)))
    {
        return_value = true;
        goto END;
    }

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %li\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

END:
    return return_value;
}

bool ec_multiplication64(int64_t operand1, int64_t operand2)
{
    int64_t result       = 0;
    bool    return_value = false;

    result = multiplication_64(operand1, operand2);

    if ((ERROR_CODE == result) && (ERROR_CODE != (operand1 * operand2)))
    {
        return_value = true;
        goto END;
    }

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %li\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

END:
    return return_value;
}

bool ec_division64(int64_t operand1, int64_t operand2)
{
    int64_t result       = 0;
    bool    return_value = false;

    if (0 == operand2)
    {
        printf("[ERROR] - Cannot Divide by Zero.\n\n");
        return_value = true;
        goto END;
    }

    result = division_64(operand1, operand2);

    if ((ERROR_CODE == result) && (ERROR_CODE != (operand1 + operand2)))
    {
        return_value = true;
        goto END;
    }

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %li\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

END:
    return return_value;
}

bool ec_modulo64(int64_t operand1, int64_t operand2)
{
    int64_t result       = 0;
    bool    return_value = false;

    if (0 == operand2)
    {
        fprintf(stderr, "[Error] - Cannot Divide by Zero.\n\n");
        return_value = true;
        goto END;
    }

    result = modulo_64(operand1, operand2);

    if ((ERROR_CODE == result) && (ERROR_CODE != (operand1 % operand2)))
    {
        return_value = true;
        goto END;
    }

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %li\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

END:
    return return_value;
}

/*** end of file ***/
