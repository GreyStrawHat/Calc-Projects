#ifndef ERROR_HANDLING_32_H
#define ERROR_HANDLING_32_H
#define ERROR_CODE         -1
#define UNSIGNED_ERROR_CODE 1

#include <stdbool.h>
#include <errno.h>

/**
 * @brief Displays SimpleCalc usage information.
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

/**
 * @brief Checks the return value of the sanitize_iargs function for false positives
 * 
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if there is an error
 * @return false if there is a false flag
 */
bool signed_error_checker(char * operand1, char *operand2);

/**
 * @brief Checks the return value of the sanitize_uargs function for false positives
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if there is an error
 * @return false if there is a false flag
 */
bool unsigned_error_checker(char * operand1, char *operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the addition operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_addition(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the subtraction operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the erro code is a false positive
 */
bool ec_subtraction(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the multiplication operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the erro code is a false positive
 */
bool ec_multiplication(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the division operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_division(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of
 * the modulo operation as well as Debug info.
 *
 * @param operand1 Takes first 32-bit signed operand
 * @param operand2 Takes second 32-bit signed operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_modulo(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation left shift as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_lshift(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation rotate left as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_rotateLeft(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation rotate right as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit usigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_rotateRight(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation AND as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_AND(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation OR as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit unsigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_OR(char * operand1, char * operand2);

/**
 * @brief Function that checks and validates errors then outputs the results of the bitwise operation XOR as well as Debug info.
 * 
 * @param operand1 Takes first 32-bit unsigned operand
 * @param operand2 Takes second 32-bit usigned operand
 * @return true if the error_code is valid
 * @return false if the error code is a false positive
 */
bool ec_bitwise_XOR(char * operand1, char * operand2);

#endif

/*** end of file ***/
