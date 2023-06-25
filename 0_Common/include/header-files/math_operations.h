#ifndef MATHOP_H
#define MATHOP_H

#include <stdint.h>

int32_t sanitize_addition(int32_t arg1, int32_t arg2);
int32_t sanitize_subtraction(int32_t arg1, int32_t arg2);
int32_t sanitize_multiplication(int32_t arg1, int32_t arg2);
int32_t sanitize_division(int32_t arg1, int32_t arg2);
int32_t sanitize_modulo(int32_t arg1, int32_t arg2);
uint32_t sanitize_lshift(uint32_t arg1, uint32_t arg2);
uint32_t rotateLeft(uint32_t value, uint32_t shift);
uint32_t rotateRight(uint32_t value, uint32_t shift);

int32_t signed_result;
uint32_t unsigned_result;

#endif