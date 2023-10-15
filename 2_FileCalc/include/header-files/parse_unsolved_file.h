#ifndef PARSE_UNSOLVED_H
#define PARSE_UNSOLVED_H
#define EQU_HEADER_LENGTH        27
#define UNSOLVED_EQUATION_LENGTH 32
#define NULL_BYTE_SIZE           1
#define MAG_NUM                  (int32_t)0xDD77BB55

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "equation_types.h"
#include "return_solved_struct.h"

/**
 * @brief Parse an unsolved equation file and generate solved equations.
 *
 * This function takes an Unsolved_Equation structure and
 * information about a directory entry
 * (`directory_entry`) corresponding to an unsolved equation file. The function
 * opens the file and parses its header to extract metadata about the unsolved
 * equations. It then proceeds to read and parse the unsolved equations,
 * generating corresponding solved equations and storing them in files in the
 * specified output directory.
 *
 * @param uequation Pointer to the Unsolved_Equation structure to store the
 * parsed header data and where the generated solved equations will be stored.
 * @param directory_entry Pointer to the directory entry information for the
 * unsolved equation file.
 * @param input_dir_arg The path to the input directory containing the unsolved
 * equation files.
 * @param output_dir_arg The path to the output directory where the generated
 * solved equations will be stored.
 * @return 0 on success, or an error code on failure.
 */
int parse_unsolved_file(Unsolved_Equation * uequation,
                        struct dirent *     directory_entry,
                        char *              input_dir_arg,
                        char *              output_dir_arg);

/**
 * @brief Parse the header of an unsolved equation file.
 *
 * This function reads the header information of an unsolved equation file from
 * the given file descriptor (`fd`) and populates the corresponding fields in
 * the provided Unsolved_Equation structure. The header contains
 * metadata about the file including the magic number, file ID, number of
 * unsolved equations, header flags, equation offset, and the number of optional
 * headers.
 *
 * @param fd The file descriptor of the unsolved equation file.
 * @param uequation Pointer to the Unsolved_Equation structure to store the
 * parsed header data.
 * @return Pointer to the same Unsolved_Equation structure.
 */
Unsolved_Equation * parse_unsolved_header(int                 fd,
                                          Unsolved_Equation * uequation);

/**
 * @brief Read unsolved equations from a file and generate solved equations.
 *
 * This function reads unsolved equations from a file descriptor (`fd`) and
 * generates corresponding solved equations. The solved equations are stored in
 * separate files in the specified output directory. The number of unsolved
 * equations to read is determined by the `num_of_e` field in the `uequation`
 * structure.
 *
 * @param fd The file descriptor from which to read unsolved equations.
 * @param uequation Pointer to the Unsolved_Equation structure to store the read
 * data.
 * @param output_dir_arg The path to the output directory where the generated
 * solved equations will be stored.
 * @return 0 on success, or an error code on failure.
 */
int read_unsolved_equations(int                 fd,
                            Unsolved_Equation * uequation,
                            char *              output_dir_arg);

#endif

/*** end of file ***/
