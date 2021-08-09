#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief structure of a stack node
 * 
 * @param data void pointer to whatever data that stack points to
 */
typedef struct stack_node_t 
{
    void * data;
} stack_node_t;

/**
 * @brief A pointer to a user-defined free function.  This is used to free
 *        memory allocated for stack data.  For simple data types, this is
 *        just a pointer to the standard free function.  More complex structs
 *        stored in stacks may require a function that calls free on multiple
 *        components.
 * 
 */
typedef void (*FREE_F)(void*);

/**
 * @brief A pointer to a user-defined function for comparing que values to a 
 *        search value and returning the pointer to that node if found
 * 
 */
typedef void * (*CMP_F)(void *, void *);

/**
 * @brief structure of a stack object
 * 
 * @param capacity is the number of nodes the stack can hold
 * @param currentsz is the number of nodes the stack is currently storing
 * @param arr is the array containing the stack node pointers
 * @param customfree pointer to the user defined free function
 * @param compare_function pointer to the user defined compare function
 */
typedef struct stack_t 
{
    uint32_t capacity;
    uint32_t currentsz;
	void **  arr;
    FREE_F   customfree;
    CMP_F    compare_function;
} stack_t;

/**
 * @brief creates a new stack
 * 
 * @param capacity max number of nodes the stack will hold
 * @param pointer to where the stack will be created
 * @param customfree pointer to the free function to be used with that list
 * @param compare_function pointer to the compare function to be used with that 
 *        list
 * @returns the int exit code of the function
 */
 stack_t * stack_init(uint32_t capacity, 
					  FREE_F customfree, 
					  CMP_F compare_function);

/**
 * @brief verifies that stack isn't full
 * 
 * @param stack pointer stack object
 * @return int exit code of the function
 */
int stack_fullcheck(stack_t * stack);

/**
 * @brief verifies that stack isn't empty
 * 
 * @param stack pointer stack object
 * @return int exit code of the function
 */
int stack_emptycheck(stack_t * stack);

/**
 * @brief pushes a new node into the stack
 * 
 * @param stack pointer to stack pointer to push the node into
 * @param data data to be pushed into node
 * @param priority of data
 * @return the int exit code of the function
 */
int stack_push(stack_t * stack, void * data);

/**
 * @brief pops the front node out of the stack
 * 
 * @param stack pointer to stack pointer to pop the node off of
 * @param receiving_object object to store the node's data
 * @return the int exit code of the function
 */
stack_node_t * stack_pop(stack_t * stack);

/**
 * @brief get the data from the node at the front of the stack without popping
 * 
 * @param stack pointer to stack pointer to peek
 * @param receiving_object object to store the node's data
 * @return the int exit code of the function
 */
void * stack_peek(stack_t * stack);

/**
 * @brief clear all nodes out of a stack
 * 
 * @param stack pointer to stack pointer to clear out
 * @return the int exit code of the function
 */
int stack_clear(stack_t ** stack);

/**
 * @brief delete a stack
 * 
 * @param stack pointer to stack pointer to be destroyed
 * @return the int exit code of the function
 */
int stack_destroy(stack_t ** stack);

#endif
