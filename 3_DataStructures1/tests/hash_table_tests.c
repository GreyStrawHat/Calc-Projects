#include <stdlib.h>
#include <stdio.h>
#include <CUnit/CUnit.h>
#include <string.h>
#include <CUnit/Basic.h>

#include "hash_table.h"

#define SIZE 10
hash_table_t * hash_table = NULL;
int data[10] = {0,1,2,3,4,5,6,7,8,9};

int init_suite1(void)
{
    return 0;
}

int clean_suite1(void)
{
    return 0;
}

void test_hash_table_init()
{
    int exit_code        = 1;

    //Verify hash_table was created correctly
    hash_table = hash_table_init(SIZE);
    CU_ASSERT_FATAL(NULL != hash_table);
    CU_ASSERT(NULL != hash_table->table)
    CU_ASSERT(SIZE == hash_table->size);
    //Ensure that free is substituted in the event that a custom 
    //free function isnt supplied
    CU_ASSERT(free == hash_table->customfree);
}
//////////////////////////////////
//TODO: FINISH REFACTORING BELOW//
//////////////////////////////////

void test_hash_table_add()
{
    int exit_code = 1;
    hash_table_t * invalid_table = NULL;

    
    //Should catch if create is called on an invalid pointer
    exit_code = hash_table_add(&invalid_table, (void *)&data[3], (unsigned char *)"asdgasga", 8);
    CU_ASSERT(TABLE_INVALID == exit_code);

    exit_code = hash_table_add(&hash_table, (void *)&data[0], (unsigned char *)"Item one", 9);
    exit_code = hash_table_add(&hash_table, (void *)&data[1], (unsigned char *)"Item two", 9);
    exit_code = hash_table_add(&hash_table, (void *)&data[2], (unsigned char *)"Item three", 11);
    exit_code = hash_table_add(&hash_table, (void *)&data[3], (unsigned char *)"Item four", 10);
    exit_code = hash_table_add(&hash_table, (void *)&data[4], (unsigned char *)"Item five", 10);
    exit_code = hash_table_add(&hash_table, (void *)&data[5], (unsigned char *)"Item six", 9);
    exit_code = hash_table_add(&hash_table, (void *)&data[6], (unsigned char *)"Item seven", 11);
    exit_code = hash_table_add(&hash_table, (void *)&data[7], (unsigned char *)"Item eight", 11);
    exit_code = hash_table_add(&hash_table, (void *)&data[8], (unsigned char *)"Item nine", 10);
    exit_code = hash_table_add(&hash_table, (void *)&data[9], (unsigned char *)"Item ten", 9);
    
    CU_ASSERT(TABLE_SUCCESS == exit_code); 
}

void test_hash_table_lookup()
{
    int exit_code = 1;
    hash_table_t * invalid_table = NULL;
    int * receiving_object = NULL;

    //Should catch if create is called on an invalid pointer
    exit_code = hash_table_lookup(&invalid_table, (unsigned char *)"Item three", 11, (void *)&receiving_object);
    CU_ASSERT(TABLE_INVALID == exit_code);

    //Should catch if create is called on an invalid pointer
    exit_code = hash_table_lookup(&hash_table, (unsigned char *)"Item two", 9, (void *)&receiving_object);
    CU_ASSERT(TABLE_SUCCESS == exit_code);
    CU_ASSERT(data[1] == *receiving_object);

    //Should catch if create is called on an invalid pointer
    exit_code = hash_table_lookup(&hash_table, (unsigned char *)"Item three", 11, (void *)&receiving_object);
    CU_ASSERT(TABLE_SUCCESS == exit_code);
    CU_ASSERT(data[2] == *receiving_object);

    //exit_code = hash_table_lookup(&hash_table, (unsigned char *)"Item ten", 9, (void *)&receiving_object);
}

void test_hash_table_remove()
{
    int exit_code = 1;
    hash_table_t * invalid_table = NULL;
    int * receiving_object = NULL;

    exit_code = hash_table_remove(&invalid_table, (unsigned char *)"Item three", 11);
    CU_ASSERT(TABLE_INVALID == exit_code);

    exit_code = hash_table_remove(&hash_table, (unsigned char *)"Item three", 11);
    CU_ASSERT(TABLE_SUCCESS == exit_code);
    
    exit_code = hash_table_lookup(&hash_table, (unsigned char *)"Item three", 11, (void *)&receiving_object);
    CU_ASSERT(TABLE_DATA_NOT_FOUND == exit_code);

    exit_code = hash_table_remove(&hash_table, (unsigned char *)"Item three", 11);
    CU_ASSERT(TABLE_DATA_NOT_FOUND == exit_code);
}

void test_hash_table_clear()
{
    int exit_code = 1;
    hash_table_t * invalid_table = NULL;

    exit_code = hash_table_clear(&invalid_table);
    CU_ASSERT(TABLE_INVALID == exit_code);

    exit_code = hash_table_clear(&hash_table);
    CU_ASSERT(TABLE_SUCCESS == exit_code);

}

void test_hash_table_destroy()
{
    int exit_code = 1;
    hash_table_t * invalid_table = NULL;

    exit_code = hash_table_destroy(&invalid_table);
    CU_ASSERT(TABLE_INVALID == exit_code);

    exit_code = hash_table_destroy(&hash_table);
    CU_ASSERT(TABLE_SUCCESS == exit_code);

    exit_code = hash_table_destroy(&hash_table);
    CU_ASSERT(TABLE_INVALID == exit_code);

}

void test_hash_function_effectiveness()
{
    ssize_t read;
    char * line = NULL;
    size_t len = 0;
    FILE * dict_pointer = NULL;
    hash_table_t * dict_table = NULL;
    void * nullval = NULL;
    int num_entries = 0;

    dict_table = calloc(1, sizeof(hash_table_t));

    hash_table_init(400000, &dict_table);

    dict_pointer = fopen("/usr/share/dict/american-english", "r");

    while ((read = getline(&line, &len, dict_pointer)) != -1)
    {
        hash_table_add(&dict_table, &nullval, (unsigned char *)line, strlen(line));
        num_entries++;
    }
    printf("Total entries: %d\n", num_entries);
}

int main(void)
{
    CU_TestInfo suite1_tests[] = 
    {
        {"Testing hash_table_init():", test_hash_table_init},

        {"Testing hash_table_add():", test_hash_table_add},

        {"Testing hash_table_lookup():", test_hash_table_lookup},

        {"Testing hash_table_remove():", test_hash_table_remove},

        {"Testing hash_table_clear():", test_hash_table_clear},

        {"Testing hash_table_destroy():", test_hash_table_destroy},

        {"Testing hash_function_effectiveness():", test_hash_function_effectiveness},

        CU_TEST_INFO_NULL
    };

    CU_SuiteInfo suites[] = {
        {"Suite-1:", init_suite1, clean_suite1, .pTests = suite1_tests},
        CU_SUITE_INFO_NULL
    };

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    if (0 != CU_register_suites(suites))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_basic_show_failures(CU_get_failure_list());
    int num_failed = CU_get_number_of_failures(); 
    CU_cleanup_registry();
    puts("\n");
    return num_failed;
}
