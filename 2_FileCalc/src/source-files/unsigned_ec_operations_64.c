#include "unsigned_ec_operations_64.h"

bool ec_bitwise_AND64(uint64_t operand1, uint64_t operand2)
{
    uint64_t result       = 0;
    bool     return_value = false;

    result = (operand1 & operand2);

    printf(YELLOW);
    printf("Operation: %lu & %lu\n", operand1, operand2);
    printf(RESET);

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %lu\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

    return return_value;
}

bool ec_bitwise_OR64(uint64_t operand1, uint64_t operand2)
{
    uint64_t result       = 0;
    bool     return_value = false;

    result = (operand1 | operand2);

    printf(YELLOW);
    printf("Operation: %lu | %lu\n", operand1, operand2);
    printf(RESET);

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %lu\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

    return return_value;
}

bool ec_bitwise_XOR64(uint64_t operand1, uint64_t operand2)
{
    uint64_t result       = 0;
    bool     return_value = false;

    printf(YELLOW);
    printf("Operation: %lu ^ %lu\n", operand1, operand2);
    printf(RESET);

    result = (operand1 ^ operand2);
    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %lu\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

    return return_value;
}

bool ec_lshift64(uint64_t operand1, uint64_t operand2)
{
    uint64_t result       = 0;
    bool     return_value = false;

    printf(YELLOW);
    printf("Operation: %lu << %lu\n", operand1, operand2);
    printf(RESET);

    if (UNSIGNED_ERROR_CODE == lshift64(operand1, operand2) &&
        UNSIGNED_ERROR_CODE != (operand1 << operand2))
    {
        return_value = true;
        goto END;
    }

    result = lshift64(operand1, operand2);

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %lu\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

END:
    return return_value;
}

bool ec_rotateLeft64(uint64_t operand1, uint64_t operand2)
{
    uint64_t result       = 0;
    bool     return_value = false;

    result = rotateLeft64(operand1, operand2);

    printf(YELLOW);
    printf("Operation: %lu <<< %lu\n", operand1, operand2);
    printf(RESET);

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %lu\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

    return return_value;
}

bool ec_rotateRight64(uint64_t operand1, uint64_t operand2)
{
    uint64_t result       = 0;
    bool     return_value = false;

    result = rotateRight64(operand1, operand2);

    printf(YELLOW);
    printf("Operation: %lu >>> %lu\n", operand1, operand2);
    printf(RESET);

    DEBUG_PRINT("operand1 at memory address [ %p ] = [ %016lX ]\n",
                (void *)&operand1,
                operand1);
    DEBUG_PRINT("operand2 at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&operand2,
                operand2);
    printf(GREEN);
    printf("Result: %lu\n", result);
    DEBUG_PRINT("result at memory address [ %p ] = [ %016lX ]\n\n",
                (void *)&result,
                result);
    printf(RESET);

    return return_value;
}

/*** end of file ***/
