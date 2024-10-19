#include "io_32.h"
#include "operations_32.h"
#include "error_handling.h"

uint32_t sanitize_uarg(char * arg)
{
    char *        end_p                 = NULL;
    uint32_t      unsigned_return_value = 0;
    unsigned long argument              = strtoul(arg, &end_p, BASE_TEN);

    if (argument > UINT32_MAX)
    {
        printf("[Error] - Unsafe value detected.\n\n");
        unsigned_return_value = 1;
    }
    else
    {
        unsigned_return_value = argument;
    }

    return unsigned_return_value;
}

int32_t sanitize_iarg(char * arg)
{
    char *      end_p               = NULL;
    int32_t     signed_return_value = 0;
    signed long argument            = strtol(arg, &end_p, BASE_TEN);

    if ((argument < INT32_MIN) || (argument > INT32_MAX))
    {
        printf("[Error] - Unsafe value detected.\n");
        signed_return_value = ERROR_CODE;
    }
    else
    {
        signed_return_value = argument;
    }

    return signed_return_value;
}

int handle_int_args(char * operand1, char * operand2)
{
    char * arg1_p          = operand1;
    char * arg2_p          = operand2;
    char * error_tracker_p = NULL;
    errno                  = 0;
    int return_value       = 0;

    int32_t int_arg1_tracker = strtol(arg1_p, &error_tracker_p, BASE_TEN);

    if ((0 != errno) || (NULL == arg1_p) || (NULL_BYTE != *error_tracker_p))
    {
        printf("[ERROR] - Invalid character(s)s found in Operand 1.\n");
        printf("[DEBUG] - The value at memory address [ %p ] is [ %d ]\n",
               (void *)&int_arg1_tracker,
               int_arg1_tracker);
        printf("[DEBUG] - errno: %d, arg1_p: %s, Found Invalid Character(s): %s\n",
               errno,
               *&arg1_p,
               error_tracker_p);
        return_value = ERROR_CODE;
        goto END;
    }

    int32_t int_arg2_tracker = strtol(arg2_p, &error_tracker_p, BASE_TEN);

    if ((0 != errno) || (NULL == arg2_p) || (NULL_BYTE != *error_tracker_p))
    {
        printf("[ERROR] - Invalid character(s)s found in Operand 2.\n");
        printf("[DEBUG] - The value at memory address [ %p ] is [ %d ]\n",
               (void *)&int_arg2_tracker,
               int_arg2_tracker);
        printf("[DEBUG] - errno: %d, arg1_p: %s, Found Invalid Character(s): %s\n",
               errno,
               *&arg1_p,
               error_tracker_p);
        return_value = ERROR_CODE;
        goto END;
    }

END:
    return return_value;
}

int handle_uint_args(char * operand1, char * operand2)
{
    char * arg1_p          = operand1;
    char * arg2_p          = operand2;
    char * error_tracker_p = NULL;
    errno                  = 0;
    int return_value       = 0;

    uint32_t uint_arg1_tracker = strtoul(arg1_p, &error_tracker_p, BASE_TEN);

    if ((0 != errno) || (NULL == arg1_p) || (NULL_BYTE != *error_tracker_p))
    {
        printf("[ERROR] - Invalid character(s)s found in Operand 1.\n");
        printf("[DEBUG] - The value at memory address [ %p ] is [ %d ]\n",
               (void *)&uint_arg1_tracker,
               uint_arg1_tracker);
        printf("[DEBUG] - errno: %d, arg1_p: %s, Found Invalid Character(s): %s\n",
               errno,
               *&arg1_p,
               error_tracker_p);
        return_value = ERROR_CODE;
        goto END;
    }

    uint32_t uint_arg2_tracker = strtoul(arg2_p, &error_tracker_p, BASE_TEN);

    if ((0 != errno) || (NULL == arg2_p) || (NULL_BYTE != *error_tracker_p)) //Checks for invalid character(s)s in operands 1 or 2
    {
        printf("[ERROR] - Invalid character(s)s found in Operand 2.\n");
        printf("[DEBUG] - The value at memory address [ %p ] is [ %d ]\n",
               (void *)&uint_arg2_tracker,
               uint_arg2_tracker);
        printf("[DEBUG] - errno: %d, arg1_p: %s, Found Invalid Character(s): %s\n",
               errno,
               *&arg1_p,
               error_tracker_p);
        return_value = ERROR_CODE;
        goto END;
    }

END:
    return return_value;
}

/*** end of file ***/
