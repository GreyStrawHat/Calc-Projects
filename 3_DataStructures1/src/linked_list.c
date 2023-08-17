#include "linked_list.h"
#define EMPTY 0

void *default_compare(void *value_to_find, void *node)
{
    void *return_value = NULL;

    if (*(int *) value_to_find == *(int *) node)
    {
        return_value = node;
    }

    return return_value;

}

list_t *list_new(FREE_F custom_free, CMP_F compare_function)
{
    list_t *return_value = NULL;

    list_t *newList = (list_t *) calloc(1, sizeof(list_t));
    if (NULL == newList)
    {
        fprintf(stderr, "Failed to allocated memory.\n");
        goto END;
    }
    else
    {
        return_value = newList;
    }
    
    newList->size == EMPTY;
    newList->head == NULL;
    newList->tail == NULL;
    newList->compare_function == compare_function;
    newList->customfree == custom_free; 

END:
    return return_value;
}

int list_push_head(list_t *list, void *data)
{
    int return_value = -1;

    if ((NULL == list) || (NULL == data))
    {
        fprintf(stderr, "Null value given as a parameter\n");
        goto END;
    }

    list_node_t *new_node = calloc(1,sizeof(list_node_t));
    if (NULL == new_node)
    {
        fprintf(stderr, "Could not allocate memory for new node\n");
        goto END;
    }

    new_node->data = data;
    new_node->position = 1;
    new_node->next = list->head;
    new_node->next->prev = new_node;

    list->head = new_node;

    if (list->size == EMPTY)
    {
        list->tail = new_node;
    }

    list->size++; 

    if (NULL != new_node->next) 
    {
        new_node->next->position++;
    }

    return_value = 0;

END:
    return return_value;
}

int list_push_tail(list_t *list, void *data)
{
    int return_value = -1;

    if ((NULL == list) || (NULL == data))
    {
        fprintf(stderr, "Null value given as a parameter\n");
        goto END;
    }

    list_node_t *new_node = calloc(1,sizeof(list_node_t));
    if (NULL == new_node)
    {
        fprintf(stderr, "Could not allocate memory for new node\n");
        goto END;
    }

    if (list->size == EMPTY)
    {
        list->head = new_node;
    }

    new_node->data = data;
    new_node->position = list->tail->position++;
    new_node->next = NULL;
    new_node->prev = list->tail;

    list->tail = new_node;

    list->size++; 

    if (NULL != new_node->next) 
    {
        new_node->next->position++;
    }

    return_value = 0;

END:
    return return_value;
}

