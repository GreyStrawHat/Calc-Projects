#ifndef _MY_FILE_H
#define _MY_FILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define HDR_MAG_NUM      0xDD77BB55
#define MAX_EQUATIONS    64
#define HDR_MAGIC_LOC    0
#define HDR_FILE_ID_LOC  4
#define HDR_NUM_EQ_LOC   8
#define HDR_FLAGS_LOC    16
#define HDR_OFFSET_LOC   17
#define OPT_HDR_MAG_LOC  21
#define OPT_HDR_LEN_LOC  23
#define OPT_HDR_FLG_LOC  25
#define OPT_HDR_DAT_LOC  26
#define CALCERROR        -1
#define S_IRWOWN         00600
#define PADDING          10 

#define ARG_LIMIT 512

typedef enum operators 
{
	ADDITION = 0x01,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	MODULO,
	LSHIFT,
	RSHIFT,
	AND,
	OR,
	XOR,
	LROT,
	RROT
}operators_t;


/**
 * @brief Manage both input and output file descriptors for a specific file
 *        When you open a file to workon, use this structure as a means of
 *        easily keeping track of the file descriptors
 *
 */
typedef struct file_desc 
{
	int in;
	int out;
}file_desc_t;

/**
 * @brief structs for storing file, header, and equation data
 * 
 *
 */
typedef struct unsolved_eq 
{
	int64_t num_1;
	uint8_t op;
	int64_t num_2;
	int64_t solution;
}unsolved_eq_t;

typedef struct solved_eq 
{
	uint32_t id;
	uint8_t flag;
	int64_t sol;
}solved_eq_t;

typedef enum eq_flags
{
	EQ_SOLVED,
	ERROR
} eq_flags_t;

typedef enum hdr_flags
{ 
	UNSOLVED,
	SOLVED
}hdr_flags_t;

typedef struct eq_hdr 
{
	// All valid magic numbers should be 0xDD77BB55
    uint32_t magic;
    uint64_t file_id;
	uint64_t num_eq;
	uint8_t flags;
	uint32_t offset;
	uint16_t addtl_headers;
}eq_hdr_t;

typedef struct opt_hdr 
{
	// All valid magic numbers should be 0xEE88FF99
	uint32_t magic;

	//[Asymetric Encryption Key | Symetric Encription Key | Securely Signed |
	// Compression Algorithm | Serialization Algorithm]
	uint16_t hdr_len;
	uint8_t flags;
	//data follows
} opt_hdr_t;

typedef struct bin_ser 
{
	uint32_t id;
	uint8_t flags;
} bin_ser_t;

/**
 * @brief reads the contents of a directory and checks if they are valid 
 * 		  equ files
 * 
 * @param in_dir path of directory to be read
 * @return on success returns number of valid equ files, else returns -1 
 *         sets errno
 */
int read_dir(const char *in_dir, const char * out_dir);

/**
 * @brief opens input equation file
 * 
 * @param file_desc the input file descriptor
 * @param out_fd the output file descriptor
 * @return exit code
 */
int handle_files(const int in_fd, int out_fd);

/**
 * @brief parse equation
 * 
 * @param file_desc input file descriptor
 * @param num_eq number of equations in file
 * @param out_fd output file descriptor
 * @param offset offset of where equations begin
 */
int solve_equations(const int in_fd, 
                    uint64_t num_eq, 
                    int out_fd, 
                    uint32_t offset);

/**
 * @brief performs calculation on equations extracted from file
 * 
 * @param num1 operand 1
 * @param oper operator
 * @param num2 opreand 2
 * @return int64_t solution of equation
 */
eq_flags_t math(unsolved_eq_t * unsolved_eq, solved_eq_t * solution);

#endif
