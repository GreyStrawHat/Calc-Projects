#ifndef ERROR_MSG_H
#define ERROR_MSG_H

/**
 * @brief Displays SimpleCalc usage information.
 * 
 * @param program_name Name of program
 */
void usage(char *program_name);

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