#include "reverse_byte_string_order.h"
#define TWO_BYTES 2
#define NULL_BYTE '\0'

void reverse_string_byte_order(const char * string, char * buffer)
{
    if (*string == NULL_BYTE)
    {
        return;
    }
    reverse_string_byte_order(string + TWO_BYTES, buffer);
    strncat(buffer, string, TWO_BYTES);
}

/*** end of file ***/
