#ifndef REVERSE_BYTE_H
#define REVERSE_BYTE_H

#include <string.h>

/**
 * @brief Reverse the byte order of a string.
 *
 * This function takes a null-terminated string (`string`) as input and reverses
 * its byte order, storing the result in the `buffer`. The function uses a
 * recursive approach to reverse the byte order of the string. It processes the
 * string from the end, two bytes at a time, and appends the bytes to the
 * `buffer` in reverse order. The `buffer` should have enough space to store the
 * reversed byte order of the string.
 *
 * @param string The null-terminated string whose byte order needs to be
 * reversed.
 * @param buffer A buffer to store the reversed byte order of the string.
 */
void reverse_string_byte_order(const char * string, char * buffer);

#endif