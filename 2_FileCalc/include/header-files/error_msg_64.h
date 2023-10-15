#ifndef ERROR_MSG_64_H
#define ERROR_MSG_64_H
#define ERROR_CODE          -1
#define UNSIGNED_ERROR_CODE 1

/**
 * @brief Displays FileCalc usage information.
 *
 * @param program_name Name of program
 */
void usage(char * program_name);

/**
 * @brief Prints error message when integer wrapping is detected.
 *
 * @return int returns a negative value to indicate an error.
 */
int unsigned_int_error();

/**
 * @brief Prints error message when integer wrapping is detected.
 *
 * @return int returns a negative value to indicate an error.
 */
int integer_overflow_error();

#endif

/*** end of file ***/
