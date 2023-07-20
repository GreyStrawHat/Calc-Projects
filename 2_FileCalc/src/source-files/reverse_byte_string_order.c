#include "reverse_byte_string_order.h"

void reverse_string_byte_order(const char *string, char *buffer)
{
    if (*string == '\0')
    {
        return;   
    }
    reverse_string_byte_order(string + 2, buffer);
    strncat(buffer, string, 2);
}

/*** end of file ***/
