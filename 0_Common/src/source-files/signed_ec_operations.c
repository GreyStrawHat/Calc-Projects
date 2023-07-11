#include "signed_ec_operations.h"

bool ec_addition(char * operand1, char * operand2)
{
    int32_t result       = 0;
    char ** end_pp       = NULL;
    bool    return_value = false;

    if (signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if ((ERROR_CODE ==
         sanitize_addition(sanitize_iarg(operand1), sanitize_iarg(operand2))) &&
        (ERROR_CODE != ((strtol(operand1, end_pp, BASE_TEN)) +
                        (strtol(operand2, end_pp, BASE_TEN)))))
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
    char ** end_pp       = NULL;
    bool    return_value = false;

    if (signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if ((ERROR_CODE == sanitize_subtraction(sanitize_iarg(operand1),
                                            sanitize_iarg(operand2))) &&
        (ERROR_CODE != ((strtol(operand1, end_pp, BASE_TEN)) -
                        (strtol(operand2, end_pp, BASE_TEN)))))
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
    char ** end_pp       = NULL;
    bool    return_value = false;

    if (signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }
    if ((ERROR_CODE == sanitize_multiplication(sanitize_iarg(operand1),
                                               sanitize_iarg(operand2))) &&
        (ERROR_CODE != ((strtol(operand1, end_pp, BASE_TEN)) *
                        (strtol(operand2, end_pp, BASE_TEN)))))
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
    char ** end_pp       = NULL;
    bool    return_value = false;

    if (signed_error_checker(operand1, operand2))
    {
        return_value = true;
        goto END;
    }

    if (0 == sanitize_iarg(operand2))
    {
        printf("[Error] - Cannot Divide by Zero.\n\n");
        return_value = true;
        goto END;
    }

    if ((ERROR_CODE ==
         sanitize_division(sanitize_iarg(operand1), sanitize_iarg(operand2))) &&
        (ERROR_CODE != ((strtol(operand1, end_pp, BASE_TEN)) /
                        (strtol(operand2, end_pp, BASE_TEN)))))
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
    char ** end_pp       = NULL;
    bool    return_value = false;

    if (signed_error_checker(operand1, operand2))
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

    if ((ERROR_CODE ==
         sanitize_modulo(sanitize_iarg(operand1), sanitize_iarg(operand2))) &&
        (ERROR_CODE != ((strtol(operand1, end_pp, BASE_TEN)) %
                        (strtol(operand2, end_pp, BASE_TEN)))))
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

/*** end of file ***/
