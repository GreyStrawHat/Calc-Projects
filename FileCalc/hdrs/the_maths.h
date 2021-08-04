#ifndef _THE_MATHS_H
#define _THE_MATHS_H

#include <stdio.h>
#include <float.h>
#include <stdint.h>

#define NUM_BITS 64
#define FLOAT_PRECISION 0.1

int addition(int64_t op1, int64_t op2, int64_t *result);

int subtraction(int64_t op1, int64_t op2, int64_t *result);

int multiplication(int64_t op1, int64_t op2, int64_t *result);

int divide(int64_t op1, int64_t op2, int64_t *result);

int modulo(int64_t op1, int64_t op2, int64_t *result);

int left_shift(uint64_t op1, uint64_t op2, uint64_t *result);

int right_shift(uint64_t op1, uint64_t op2, uint64_t *result);

int bit_and(uint64_t op1, uint64_t op2, uint64_t *result);

int bit_or(uint64_t op1, uint64_t op2, uint64_t *result);

int bit_xor(uint64_t op1, uint64_t op2, uint64_t *result);

int rotate_left(uint64_t op1, uint64_t op2, uint64_t *result);

int rotate_right(uint64_t op1, uint64_t op2, uint64_t *result);

#endif