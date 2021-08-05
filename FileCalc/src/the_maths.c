#include "the_maths.h"

int
addition(int64_t op1, int64_t op2, int64_t *result)
{
    int ret_code = 0;

    *result = (op1 + op2);
    if (INT64_MAX <= *result || INT64_MIN >= *result)
    {
        // perror("ERROR: OUT OF RANGE\n");
        ret_code = 1;
    }

    return ret_code;
}

int
subtraction(int64_t op1, int64_t op2, int64_t *result)
{
    int ret_code = 0;

    *result = (op1 - op2);
    if (INT64_MAX <= *result || INT64_MIN >= *result)
    {
        // perror("ERROR: OUT OF RANGE\n");
        ret_code = 1;
    }

    return ret_code;
}

int
multiplication(int64_t op1, int64_t op2, int64_t *result)
{
    int ret_code = 0;

    *result = (op1 * op2);
    if (INT64_MAX <= *result || INT64_MIN >= *result || op1 != *result / op2)
    {
        // perror("ERROR: OUT OF RANGE\n");
        ret_code = 1;
    }

    return ret_code;
}

int
divide(int64_t op1, int64_t op2, int64_t *result)
{
    int ret_code = 0;
    
    // handle divide by zero.
    if (0 == op2)
    {
        // perror("ERROR: DIVIDE BY ZERO\n");
        ret_code = 1;
    }
    else
    {
        *result = (op1 / op2);
        if (INT64_MAX <= *result || INT64_MIN >= *result || op1 != *result * op2)
        {
            // perror("ERROR: OUT OF RANGE\n");
            ret_code = 1;
        }
    }

    return ret_code;
}

int
modulo(int64_t op1, int64_t op2, int64_t *result)
{
    int ret_code = 0;

    if (0 != op2)
    {
        *result = (op1 % op2);
    }
    else
    {
        // perror("ERROR: DIVIDE BY ZERO\n");
        ret_code = 1;
    }

    return ret_code;
}

int
left_shift(uint64_t op1, uint64_t op2, uint64_t *result)
{
    int ret_code = 0;

    // if op1 or op2 are negative, do not perform bit operation.
    if ((op1 < 0) || (op2 < 0))
    {
        // perror("ENTER A POSITIVE NUMBER FOR BIT OPERATIONS\n");
        ret_code = 1;
    }
    else
    {
        *result = (op1 << op2);
    }

    return ret_code;
}

int
right_shift(uint64_t op1, uint64_t op2, uint64_t *result)
{
    int ret_code = 0;
    
    if ((op1 < 0) || (op2 < 0))
    {
        // perror("ENTER A POSITIVE NUMBER FOR BIT OPERATIONS\n");
        ret_code = 1;
    }
    else
    {
        *result = (op1 >> op2);
    }

    return ret_code;
}

int
bit_and(uint64_t op1, uint64_t op2, uint64_t *result)
{
    int ret_code = 0;
    
    if ((op1 < 0) || (op2 < 0))
    {
        // perror("ENTER A POSITIVE NUMBER FOR BIT OPERATIONS\n");
        ret_code = 1;
    }
    else
    {
        *result = (op1 & op2);
    }

    return ret_code;
}

int
bit_or(uint64_t op1, uint64_t op2, uint64_t *result)
{
    int ret_code = 0;
    
    if ((op1 < 0) || (op2 < 0))
    {
        // perror("ENTER A POSITIVE NUMBER FOR BIT OPERATIONS\n");
        ret_code = 1;
    }
    else
    {
        *result = (op1 | op2);
    }

    return ret_code;
}

int
bit_xor(uint64_t op1, uint64_t op2, uint64_t *result)
{
    int ret_code = 0;
    
    // if op1 or op2 are negative, do not perform bit operation.
    if ((op1 < 0) || (op2 < 0))
    {
        // perror("ENTER A POSITIVE NUMBER FOR BIT OPERATIONS\n");
        ret_code = 1;
    }
    else
    {
        *result = (op1 ^ op2);
    }

    return ret_code;
}

int
rotate_left(uint64_t op1, uint64_t op2, uint64_t *result)
{
    int ret_code = 0;
    
    if ((op1 < 0) || (op2 < 0))
    {
        // perror("ENTER A POSITIVE NUMBER FOR BIT OPERATIONS\n");
        ret_code = 1;
    }
    else
    {
        *result = ((op1 << op2) | (op1 >> (NUM_BITS - op2)));
    }
    return ret_code;
}

int
rotate_right(uint64_t op1, uint64_t op2, uint64_t *result)
{
    int ret_code = 0;
    
    if ((op1 < 0) || (op2 < 0))
    {
        // perror("ENTER A POSITIVE NUMBER FOR BIT OPERATIONS\n");
        ret_code = 1;
    }
    else
    {
        *result = ((op1 << op2) | (op1 >> (NUM_BITS - op2)));
    }
    return ret_code;
}
