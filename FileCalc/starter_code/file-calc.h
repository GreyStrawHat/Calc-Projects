/*
Header file that contain prototypes of functions to implement for the file-calc project
@AUTHOR: Lord Larsen
*/

#ifndef _FILE_CALC
#define _FILE_CALC

#include <stdint.h>
#include <stdbool.h>
// This module cotains basic headers for all Calc Projects
/*
 * NOTE TO AUTHOR
 * PERHAPS #PRAGMA PACK CAN BE USED INSTEAD OF ATTRIBUTE
 */

//Manage both input and output file descriptors for a specific file
//When you open a file to workon, use this structure as a means of
//easily keeping track of the file descriptors
struct file_desc {
	int in;
	int out;
};

/*
 * Purpose:
 * 	Reads the contents of a directory.
 * Args:
 * 	in_dir (const char *): Directory name or path of directory to be read.
 * 	out_dir (const char *): Directory name or path of directory where
 * 				solutions will be written.
 * Returns:
 * 	bool: If contents are successfully read returns true. Else false.
 */
bool read_dir(const char *in_dir, const char *out_dir);

// Define is used since enum has size limit of int
#define HDR_MAG_NUM 0xDD77BB55
#define OPT_MAG_NUM 0xEE88FF99 

/*
 * Overall file header
 */
enum hdr_equ_notation{ PREFIX = 1, POSTFIX = 2, STANDARD = 4};

enum hdr_flags{ SOLVED = 16, ENCRYPTED = 32, SERIALIZED = 64,
		COMPRESSED = 128};

typedef struct __attribute__((__packed__)) _eq_hdr {
	// All valid magic numbers should be 0xDD77BB55
    uint32_t magic;
    uint32_t file_id;
	uint64_t num_eq;
	uint8_t notation_eq;
	uint8_t flags;
	uint32_t offset;
	uint16_t addtl_headers;
}eq_hdr;

/*
 * Optional file header
 */
enum opt_flags{ SER_ALG = 8, COMPR_ALG = 16, SEC_SIGNED = 32, SYMM_E_KEY = 64,
		ASYM_E_KEY = 128};
typedef struct __attribute__((__packed__)) _opt_hdr {
	// All valid magic numbers should be 0xEE88FF99
	uint32_t magic;

	//[Asymetric Encryption Key | Symetric Encription Key | Securely Signed |
	// Compression Algorithm | Serialization Algorithm]
	uint16_t hdr_len;
	uint8_t flags;
} opt_hdr;

enum operations { ADD = 1, SUB, MULT, DIV, MOD, LEFT, RIGHT, AND, OR, XOR,
		  ROTR, ROTL };
typedef struct __attribute__((__packed__)) _unsolved_eq {
	int64_t num_1;
	uint8_t op;
	int64_t num_2;
}unsolved_eq;

typedef struct __attribute__((__packed__)) _solved_eq {
	uint32_t id;
	int64_t sol;
}solved_eq;

typedef struct __attribute__((__packed__)) _bin_ser {
	uint32_t id;
	uint8_t flags;
	union {
		struct unsolved_eq ueq;
		struct solved_eq seq;
	};
	char pad[10];
} bin_ser;

/*
 * Purpose:
 *	Parses equation files and writes solution to the specified
 *	output directory.
 * Args:
 * 	in_path (const char *): directory where equations are located.
 * 	out_path (const char *): directory where solution will be written.
 * Returns:
 * 	bool: If file is successfully parsed returns true. Else false.
 */
static bool parse_file(const char *in_path, const char *out_path);
/*
 * Purpose:
 *	Opens input equation file.
 * Args:
 * 	fname (const char *): file that will be opened to be read.
 * Returns:
 * 	int: If file is successfully opened, file descriptor is returned.
 * 	     Else returns a negative number.
 */
static int open_in_file(const char *fname);
/*
 * Purpose:
 *	Opens output equation file.
 * Args:
 * 	fname (const char *): file that will be opened to be written.
 * Returns:
 * 	int: If file is successfully opened, file descriptor is returned.
 * 	     Else returns a negative number.
 */
static int open_out_file(const char *fname);
/*
 * Purpose:
 *	Reads header of an equation file.
 * Args:
 * 	in_fd (int): file descriptor of the file to be read.
 * 	buff (void *): buffer that will store read data from the file.
 * 	buff_sz (uint16_t): number of bytes to be read from the file into buff.
 * Returns:
 * 	bool: If file is successfully read, returns true. Else false.
 */
static bool read_hdr(int in_fd, void *buff, size_t buff_sz);
/*
 * Purpose:
 *	Reads optional headers of an equation file.
 * Args:
 * 	fds (struct file_desc): struct containing input and output file
 * 				descriptors.
 * 	num_hdrs (uint16_t): number of optional headers to be read.
 * 	len (uint16_t *): pointer to the length of the sum total of all optional headers
 * Returns:
 * 	uint8_t: If hdrs are successfully read, returns true. Else false.
 */
static bool read_opt_hdrs(file_desc fds, uint16_t num_hdrs, uint16_t *len);
/*
 * Purpose:
 *	Checks if the equation header is valid.
 * Args:
 * 	hdr (struct eq_hdr): struct containing the equation header.
 * Returns:
 * 	bool: If header is valid returns true. Else false.
 */
static bool valid_eq_hdr(eq_hdr hdr);
/*
 * Purpose:
 *	Displays the header flag to the terminal.
 * Args:
 * 	flags (uint8_t): Flag of header.
 */
static void display_hdr_flag(uint8_t flags);
/*
 * Purpose:
 *	Checks if the optional header is valid.
 * Args:
 * 	opt (struct opt_hdr): struct containing the optional header.
 * Returns:
 * 	bool: If the optional header is valid, returns true. Else false.
 */
static bool valid_opt_hdr(opt_hdr opt);
/*
 * Purpose:
 *	Displays the optional header flag to the terminal.
 * Args:
 * 	flags (uint8_t): Flag of header.
 */
static void display_opt_flag(uint8_t flags);
/*
 * Purpose:
 *	Writes the equation header to a file.
 * Args:
 * 	out_fd (int): file descriptor to output file.
 * 	hdr (struct eq_hdr): struct containing the equation header.
 * Returns:
 * 	bool: If the equation header is successfully written to the output
 * 	      file, returns true. Else false.
 */
static bool write_eq_hdr_to_file(int out_fd, eq_hdr hdr);
/*
 * Purpose:
 *	Writes the optional header to a file.
 * Args:
 * 	out_fd (int): file descriptor to output file.
 * 	opt (struct opt_hdr): struct containing the optional header.
 * Returns:
 * 	bool: If the optional header is successfully written to the output
 * 	      file, returns true. Else false.
 */
static bool write_opt_hdr_to_file(int out_fd, opt_hdr opt);
/*
 * Purpose:
 *	Reads an equation from an equation file.
 * Args:
 * 	fds (struct file_desc): struct containing input and output file
 * 				descriptors.
 * 	buff_sz (uint16_t): size of equation to be read.
 * 	flag (uint8_t): optional header flag of the equation.
 * 	num_eq (uint64_t): number of equation to be read.
 * Returns:
 * 	uint64_t: Number of equations successfully read.
 */
static uint64_t read_eqn(file_desc fds, uint16_t buff_sz, uint8_t flag, uint64_t num_eq);
/*
 * Purpose:
 *	Reads an algorithm type of an equation from an equation file.
 * Args:
 * 	in_fd (int): file descriptor of file to be read.
 * Returns:
 * 	uint8_t: Algorithm read from equation file.
 */
static uint8_t read_alg(int in_fd);
/*
 * Purpose:
 *	Reads binary serialization portion of an equation from a file.
 * Args:
 * 	fds (struct file_desc): struct containing input and output file
 * 				descriptors.
 * 	num_eq (uint64_t): number of equation to be read from a file.
 * Returns:
 * 	uint64_t: Number of equations successfully read.
 */
static uint64_t read_bin_ser(file_desc fds, uint64_t num_eq);
/*
 * Purpose:
 *	Solves an equation in binary serialization form from an equation
 *	from a file.
 * Args:
 * 	ser (struct bin_ser *): struct containing binary serialization format
 * 				of an equation.
 * Returns:
 * 	bool: True if equation was successfully solved. Else false.
 */
static bool solve_eqn(bin_ser *ser);
/*
 * Purpose:
 *	Appends the solution of an equation to an output file.
 * Args:
 * 	out_fd (int): file descriptor of output file.
 * 	ser (struct bin_ser *): struct containing binary serialization format
 * 				of an equation.
 * Returns:
 * 	bool: True if equation was successfully appended to the file.
 *	      Else false.
 */
static bool append_answr_file(int out_fd, bin_ser ser); 
/*
 * Purpose:
 * 	Closes open file descriptors
 * Args:
 * 	fds (struct file_desc): struct containing file descriptors.
 */
static void close_files(file_desc fds);

#endif