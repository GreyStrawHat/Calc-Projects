#ifndef ARGS_H
#define ARGS_H

#include <stdint.h>

/**
 * @brief Checks that the supplied value falls within the range of 32-bit
 * unsigned integers.
 *
 * @param arg expects 32-bit unsigned operand
 * @return uint32_t
 */
uint32_t sanitize_uarg(char * arg);

/**
 * @brief Checks that the supplied value falls within the range of 32-bit signed
 * integers.
 *
 * @param arg expects 32-bit signed operand
 * @return int32_t
 */
int32_t sanitize_iarg(char * arg);

/**
 * @brief Checks that arguments 1 and 2 fall within the range of 32-bit
 * unsigned integers then updates those values by reference.
 * 
 * @param arg1 expects first 32-bit signed operand
 * @param arg2 expects second 32-bit signed operand
 * @param out1 takes memory address to store the santized value of operand 1
 * @param out2 takes memory address to store the santized value of operand 2
 */
int sanitize_two_uargs(char *     arg1,
                        char *     arg2,
                        uint32_t * san_out1,
                        uint32_t * san_out2);

/**
 * @brief Checks that arguments 1 and 2 fall within the range of 32-bit
 * signed integers then updates those values by reference.
 * 
 * @param arg1 expects first 32-bit unsigned operand
 * @param arg2 expects second 32-bit unsigned operand
 * @param out1 takes memory address to store the santized value of operand 1
 * @param out2 takes memory address to store the santized value of operand 2
 */
int sanitize_two_iargs(char *     arg1,
                        char *     arg2,
                        int32_t * san_out1,
                        int32_t * san_out2);
#endif