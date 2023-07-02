#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include "args.h"
#include "math_operations.h"
#include "error_msg.h"

uint32_t calc(char * operand1,
              char * operator_val,
              char * operand2,
              char * program_name)
{
    static int32_t  signed_result;
    static uint32_t unsigned_result;

    switch (*operator_val)
    {
        case '+':
            signed_result = sanitize_addition(sanitize_iarg(operand1),
                                              sanitize_iarg(operand2));
            printf("The Result is: %i\n", signed_result);
            break;
        case '-':
            signed_result = sanitize_subtraction(sanitize_iarg(operand1),
                                                 sanitize_iarg(operand2));
            printf("The Result is: %i\n", signed_result);
            break;
        case '/':
            signed_result = sanitize_division(sanitize_iarg(operand1),
                                              sanitize_iarg(operand2));
            printf("The Result is: %i\n", signed_result);
            break;
        case '*':
            signed_result = sanitize_multiplication(sanitize_iarg(operand1),
                                                    sanitize_iarg(operand2));
            printf("The Result is: %i\n", signed_result);
            break;
        case '&':
            unsigned_result =
                (sanitize_uarg(operand1) & sanitize_uarg(operand2));
            printf("The Result is: %i\n", unsigned_result);
            break;
        case '|':
            unsigned_result =
                (sanitize_uarg(operand1) | sanitize_uarg(operand2));
            printf("The Result is: %u\n", unsigned_result);
            break;
        case '%':
            signed_result = sanitize_modulo(sanitize_iarg(operand1),
                                            sanitize_iarg(operand2));
            printf("The Result is: %i\n", signed_result);
            break;
        case '^':
            unsigned_result =
                (sanitize_uarg(operand1) ^ sanitize_uarg(operand2));
            printf("The Result is: %u\n", unsigned_result);
            break;
        default:
            if (0 == strncmp(operator_val, "<<<\0", 4))
            {
                printf("The Result is: %u\n",
                       rotateLeft(sanitize_uarg(operand1),
                                  sanitize_uarg(operand2)));
                break;
            }
            else if (0 == strncmp(operator_val, ">>>\0", 4))
            {
                printf("The Result is: %u\n",
                       rotateRight(sanitize_uarg(operand1),
                                   sanitize_uarg(operand2)));
                break;
            }
            else if (0 == strncmp(operator_val, ">>\0", 3))
            {
                unsigned_result =
                    (sanitize_uarg(operand1) >> sanitize_uarg(operand2));
                printf("The Result is: %u\n", unsigned_result);
                break;
            }
            else if (0 == strncmp(operator_val, "<<\0", 3))
            {
                unsigned_result = sanitize_lshift(sanitize_uarg(operand1),
                                                  sanitize_uarg(operand2));
                printf("The Result is: %u\n", unsigned_result);
                break;
            }
            else
            {
                printf("Invalid operator_val.\n");
                usage(program_name);
                goto END;
            }
    }

    goto END;

END:
    return 0;
}

/*** end of file ***/
