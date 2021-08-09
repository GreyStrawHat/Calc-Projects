#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
 * @brief A function pointer to a custom-defined delete function 
 *        required to support deletion/memory deallocation of
 *        arbitrary data types. For simple data types, this function
 *        pointer can simply point to the free function.
 * 
 */
typedef void (*FREE_F)(void *data);

/**
 * @brief structure of a hash_table_t object
 * 
 * @param size uint32_t number of indices supported by table
 * @param table void ** array of pointers
 * @param customfree pointer to the user defined free function
 */
typedef struct hash_table_t
{
    uint32_t      size;
    void **       table;
    FREE_F *      customfree;
} hash_table_t;

/**
 * @brief initializes weighed graph as adjacency matrix
 * 
 * @param size number indexes in the table
 * 
 * @return hash_table_t pointer to allocated table
 */
hash_table_t * hash_table_init(uint32_t size, FREE_F * customfree);

/**
 * @brief adds an item to the table
 * 
 * @param table pointer to table address
 * @param data data to be stored at that key value
 * @param key key for data to be stored at
 * 
 * @return int exit code
 */
int hash_table_add(hash_table_t * table, 
                   void * data, 
                   char * key);

/**
 * @brief looks up an item in the table by key
 * 
 * @param table pointer to table address
 * @param key key for data being searched for
 * @param len length of key
 * @param rcv_ptr pointer for object data will be passed out to
 * 
 * @return int exit code
 */
int hash_table_lookup(hash_table_t * table, 
                      char * key, 
                      uint32_t len, 
                      void ** rcv_ptr);

/**
 * @brief removes an item from the hash table
 * 
 * @param table pointer to table address
 * @param key key of data to be removed
 * @param len length of key
 * @return int 
 */
int hash_table_remove(hash_table_t * table, char * key);

/**
 * @brief clears all data from hash table
 * 
 * @param table_addr pointer to address of table to be cleared out
 * @return int 
 */
int hash_table_clear(hash_table_t ** table_addr);

/**
 * @brief destroys hash table
 * 
 * @param table_addr pointer to table address
 * @return int 
 */
int hash_table_destroy(hash_table_t ** table_addr);

#endif
