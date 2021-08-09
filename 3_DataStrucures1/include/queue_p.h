#ifndef _QUEUE_P_H
#define _QUEUE_P_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief structure of a queue node
 * 
 * @param data void pointer to whatever data that queue points to
 */
typedef struct queue_p_node_t 
{
    void * data;
    int    priority;
} queue_p_node_t;

/**
 * @brief A pointer to a user-defined free function.  This is used to free
 *        memory allocated for queue data.  For simple data types, this is
 *        just a pointer to the standard free function.  More complex structs
 *        stored in queues may require a function that calls free on multiple
 *        components.
 * 
 */
typedef void (*FREE_F)(void*);

/**
 * @brief A pointer to a user-defined function for comparing queue values to a 
 *        search value and returning the pointer to that node
 * 
 */
typedef void * (*CMP_F)(void *, void *);

/**
 * @brief structure of a queue object
 * 
 * @param capacity is the number of nodes the queue can hold
 * @param currentsz is the number of nodes the queue is currently storing
 * @param arr is the array containing the queue node pointers
 * @param customfree pointer to the user defined free function
 * @param compare_function pointer to the user defined compare function
 */
typedef struct queue_t 
{
    uint32_t capacity;
    uint32_t currentsz;
	void **  arr;
    FREE_F   customfree;
    CMP_F    compare_function;
} queue_t;

/**
 * @brief creates a new queue
 * 
 * @param capacity max number of nodes the queue will hold
 * @param pointer to where the queue will be created
 * @param customfree pointer to the free function to be used with that list
 * @param compare_function pointer to the compare function to be used with that 
 *        list
 * @returns the int exit code of the function
 */
 queue_t * queue_p_init(uint32_t capacity, 
						FREE_F customfree, 
						CMP_F compare_function);

/**
 * @brief verifies that queue isn't full
 * 
 * @param queue pointer queue object
 * @return int exit code of the function
 */
int queue_p_fullcheck(queue_t * queue);

/**
 * @brief verifies that queue isn't empty
 * 
 * @param queue pointer queue object
 * @return int exit code of the function
 */
int queue_p_emptycheck(queue_t * queue);

/**
 * @brief pushes a new node into the queue
 * 
 * @param queue pointer to queue pointer to push the node into
 * @param data data to be pushed into node
 * @param priority of data
 * @return the int exit code of the function
 */
int queue_p_enqueue(queue_t * queue, void * data, int priority);

/**
 * @brief pops the front node out of the queue
 * 
 * @param queue pointer to queue pointer to pop the node off of
 * @param receiving_object object to store the node's data
 * @return the int exit code of the function
 */
queue_p_node_t * queue_p_dequeue(queue_t * queue);

/**
 * @brief get the data from the node at the front of the queue without popping
 * 
 * @param queue pointer to queue pointer to peek
 * @param receiving_object object to store the node's data
 * @return the int exit code of the function
 */
void * queue_p_peek(queue_t * queue);

/**
 * @brief clear all nodes out of a queue
 * 
 * @param queue pointer to queue pointer to clear out
 * @return the int exit code of the function
 */
int queue_p_clear(queue_t ** queue);

/**
 * @brief delete a queue
 * 
 * @param queue pointer to queue pointer to be destroyed
 * @return the int exit code of the function
 */
int queue_p_destroy(queue_t ** queue);

#endif
