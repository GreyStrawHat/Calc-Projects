#include "reverse_byte_string_order.h"
#define HALF_WORD 2
#define NULL_BYTE '\0'

void reverse_string_byte_order(const char * string, char * buffer)
{
    if (*string == NULL_BYTE)
    {
        return;
    }
    reverse_string_byte_order(string + HALF_WORD, buffer);
    strncat(buffer, string, HALF_WORD);
}

/*** end of file ***/
