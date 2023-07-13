#include "handle_args.h"

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
