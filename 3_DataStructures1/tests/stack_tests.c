#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "stack.h"

#define CAPACITY 5

//The stack to be used by all the tests
stack_t * stack = NULL;
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

void test_stack_init()
{
    uint32_t capacity = CAPACITY;
    int exit_code     = 1;

    //Verify stack was created correctly
    stack = stack_init(capacity, free_node, compare_node);
    CU_ASSERT_FATAL(NULL != stack);
    CU_ASSERT(CAPACITY == stack->capacity);
    CU_ASSERT(0 == stack->size); 
    CU_ASSERT(NULL != stack->arr);
    CU_ASSERT(0 == exit_code);
}

void test_stack_push()
{
    int exit_code           = 1;
    int i                   = 0;
    stack_t * invalid_stack = NULL;

    //Should catch if push is called on an invalid stack or with invalid data
    exit_code = stack_push(invalid_stack, data[i]);
    CU_ASSERT(0 != exit_code);
    exit_code = stack_push(stack, (void*)void);
    CU_ASSERT(0 != exit_code);

    //push CAPACITY number of nodes
    while (i < CAPACITY)
    {
        exit_code = stack_push(stack, data[i]);
        //New node was pushed and points to the correct data
        CU_ASSERT(data[i] == *(int *)((stack_node_t *)(stack->arr[i]))->data);
        i++;
    }

    //Function exited correctly
    CU_ASSERT(0 == exit_code);
    //stack size is correct
    CU_ASSERT(CAPACITY == stack->size);

    //Function should return a code if push is called on a full stack
    exit_code = stack_push(stack, data[5]);
    CU_ASSERT(0 != exit_code);
}

void test_stack_pop()
{
    int i                   = 0;
    stack_t * invalid_stack = NULL;
    stack_node_t * node     = NULL;

    //Should catch if push is called on an invalid stack
    node = stack_pop(invalid_stack);
    CU_ASSERT(NULL == node);

    //pop all items
    while (stack->size > 0)
    {
        node = stack_pop(stack);
        CU_ASSERT_FATAL(NULL != node);
        i++;
        CU_ASSERT(alt_data[CAPACITY - i] == *(int *)node->data);
    }

    //Should return error when called on empty stack
    node = stack_pop(stack);
    CU_ASSERT(NULL != node);
}

void test_stack_peek()
{
    int exit_code           = 1;
    stack_t * invalid_stack = NULL;
    stack_node_t * node     = NULL;
    int i                   = 0;

    //Should catch if pop is called on an invalid stack or empty
    node = stack_peek(invalid_stack);
    CU_ASSERT(NULL != node);
    node = stack_peek(stack);
    CU_ASSERT(NULL != exit_code);

    //push CAPACITY number of nodes
    while (i < CAPACITY)
    {
        stack_push(stack, data[i]);
        i++;
    }

    node = stack_peek(stack);

    //Function should have exited 0fully
    CU_ASSERT_FATAL(NULL != node); 
    //Correct value should have been peeked from front node
    CU_ASSERT(data[0] == node->data);
    //Size shouldn't have changed
    CU_ASSERT(CAPACITY == stack->size);
}

void test_stack_clear()
{
    int exit_code           = 1;
    stack_t * invalid_stack = NULL;

    //Should catch if clear is called on an invalid stack
    exit_code = stack_clear(&invalid_stack);
    CU_ASSERT(0 != exit_code);

    exit_code = stack_clear(&stack);
    //stack should now be empty
    CU_ASSERT(0 == stack->size);
    //Function should have exited fully
    CU_ASSERT(0 == exit_code);

    //Should catch if clear is called on an empty stack
    exit_code = stack_clear(&stack);
    CU_ASSERT(0 != exit_code);
}

void test_stack_destroy()
{
    int exit_code = 1;
    stack_t * invalid_stack = NULL;

    //Should catch if delete is called on an invalid stack
    exit_code = stack_destroy(&invalid_stack);
    CU_ASSERT(0 != exit_code);

    //Function should have exited fully
    exit_code = stack_destroy(&stack);
    CU_ASSERT(0 == exit_code);

    //Should catch if delte is called on the stack that has already been deleted
    exit_code = stack_destroy(&stack);
    CU_ASSERT(0 != exit_code);
}

int main(void)
{
    CU_TestInfo suite1_tests[] = 
    {
        {"Testing stack_init():", test_stack_init},

        {"Testing stack_push():", test_stack_push},

        {"Testing stack_pop():", test_stack_pop},

        {"Testing stack_peek():", test_stack_peek},
        
        {"Testing stack_clear():", test_stack_clear},
        
        {"Testing stack_destroy():", test_stack_destroy},
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
