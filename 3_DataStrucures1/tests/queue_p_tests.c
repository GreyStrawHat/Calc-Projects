#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "queue.h"

#define CAPACITY 5

//The queue to be used by all the tests
queue_t * queue = NULL;
//The integer all node data[5] pointers point to
int data[5]     = {1, 2, 3, 4, 5};

//"User defined" free function
void free_node(void * node)
{
    free(node);
}

//"User defined" compare function
void * compare_node(const void * value_to_find, const void * node)
{   
    void * retval = NULL;

    if (*(int *)node->data == *(int *)value_to_find)
    {
        retval = node;
    }

    return retval;
}

int init_suite1(void)
{
    return 0;
}

int clean_suite1(void)
{
    return 0;
}

void test_queue_init()
{

}

void test_queue_enqueue()
{

}

void test_queue_dequeue()
{

}

void test_queue_peek()
{

}

void test_queue_clear()
{

}

void test_queue_destroy()
{

}

int main(void)
{
    CU_TestInfo suite1_tests[] = 
    {
        {"Testing queue_init():", test_queue_init},

        {"Testing queue_enqueue():", test_queue_enqueue},

        {"Testing queue_dequeue():", test_queue_dequeue},

        {"Testing queue_peek():", test_queue_peek},
        
        {"Testing queue_clear():", test_queue_clear},
        
        {"Testing queue_destroy():", test_queue_destroy},
        CU_TEST_INFO_NULL
    };

    CU_SuiteInfo suites[] = {
        {"Suite-1:", init_suite1, clean_suite1, .pTests = suite1_tests},
        CU_SUITE_INFO_NULL
    };

    if (CUE_0 != CU_initialize_registry())
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
    printf("\n");
    return num_failed;
}
