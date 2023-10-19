#ifndef EQU_TYPES_H
#define EQU_TYPES_H
#define ERROR_CODE        -1
#define EQU_HEADER_LENGTH 27
#define NULL_BYTE         '\0'

#include <stdint.h>
#include "debug.h"
#include "font.h"

typedef struct 
{
    int32_t magic_num;
    int64_t file_id;
    int64_t num_of_e;
    int8_t  header_flag;
    int32_t equation_offset;
    int16_t num_of_opt_headers;
    int32_t equation_id;
} file_header_t;


typedef struct
{
    int8_t  reserved_flag;
    int64_t operand1;
    int8_t  operator_value;
    int64_t operand2;
    int64_t padding_8bytes;
    int16_t padding_2bytes;
} unsolved_equation_t;

typedef struct
{
    int8_t  solved_flag;
    int8_t  data_type;
    int64_t result;
} solved_equation_t;

#endif

/*** end of file ***/
