#include "linked_list.h"
#define EMPTY 0
#define VALUE_NOT_FOUND (void *)0

void *default_compare(void *value_to_find, void *node)
{
    void *return_value = NULL;

    if (*(int *) value_to_find == *(int *) node)
    {
        return_value = node;
    }

    return return_value;

}

void custom_free(void *allocd_mem_addr)
{
    void **pointer_pp = (void **)allocd_mem_addr;

    if(*pointer_pp)  
    {
        free(allocd_mem_addr);
        allocd_mem_addr = NULL;
        printf("Freed allocated memory\n");
    }
    else 
    {
        printf("Alloc'd memory not found\n");
    }
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

    if (NULL == compare_function)
    {
        compare_function = default_compare;
    }
    else
    {
        newList->compare_function == compare_function;
    }
    
    newList->size == EMPTY;
    newList->head == NULL;
    newList->tail == NULL;
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

    list->head->position = 1;
    new_node->data = data;
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
        list->tail->position = 1;
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

int list_emptycheck(list_t *list)
{
    int return_value = 0;

    if ((EMPTY == list->size) || ((NULL == list->head) && (NULL == list->tail)))
    {
        fprintf(stderr, "List is empty\n");
        return_value = -1;
    }

    return return_value;
}

list_node_t *list_pop_head(list_t *list)
{
    void *return_value = NULL;

    if (-1 == list_emptycheck(list))
    {
        goto END;
    }

    list_node_t *popped_node = (list_node_t *) calloc(1, sizeof(list_node_t));
    if (NULL == popped_node)
    {
        fprintf(stderr,"Failure to allocate memory\n");
    }

    popped_node = list->head;
    list->head = popped_node->next;
    list->size--;
    return_value = popped_node;

END:
    return return_value;
}

list_node_t *list_pop_tail(list_t *list)
{
    list_node_t *return_value = NULL;

    if (-1 == list_emptycheck(list))
    {
        goto END;
    }

    list_node_t *popped_node = (list_node_t *) calloc(1, sizeof(list_node_t));
    if (NULL == popped_node)
    {
        fprintf(stderr,"Failure to allocate memory\n");
    }
    
    popped_node = list->tail;
    list->tail = popped_node->next;
    list->size--;
    return_value = popped_node;

END:
    return return_value;
}

list_node_t *list_peek_head(list_t *list)
{
    list_node_t *return_value = NULL;

    if (-1 == list_emptycheck(list))
    {
        goto END;
    }

    return_value = list->head;

END:
    return return_value;
}

list_node_t *list_peek_tail(list_t *list)
{
    list_node_t *return_value = NULL;

    if (-1 == list_emptycheck(list))
    {
        goto END;
    }

    return_value = list->tail;

END:
    return return_value;
}

int list_remove(list_t *list, void **item_to_remove)
{
    if (list == NULL || item_to_remove == NULL || *item_to_remove == NULL)
    {
        fprintf(stderr, "Null list or null item given as a parameter\n");
        return -1;
    }

    list_node_t *current_node = list->head;

    while (NULL != current_node)
    {
        if (VALUE_NOT_FOUND != list->compare_function(*item_to_remove, current_node->data))
        {
            //Remove head node if value is found
            if (current_node->prev == NULL)
            {
                list->head = current_node->next;
            }
            else
            {
                current_node = current_node->next;
            }
            
            //Remove tail node if value is found
            if (current_node->next == NULL)
            {
                list->tail = current_node->prev;
            }
            
            if (list->customfree != NULL)
            {
                list->customfree(current_node->data);
            }

            custom_free(current_node);

            list->size--;

            return 0;
        }

        current_node = current_node->next;
    }
}

int list_foreach_call(list_t *list, ACT_F action_function)
{
    int return_value = 0;
    list_node_t *current_node;

    for(int i=0;i < list->tail->position;i++)
    {
        //perform action function on node data
    }

    return return_value;
}

list_node_t *list_find_first_occurrence(list_t *list, void **search_data)
{
    list_node_t *return_value = NULL;

    return return_value;
}