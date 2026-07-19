#include <stdlib.h>
#include <stdint.h>
#include "../include/linked_list.h"

/**
 * @brief   create a new linked list
 *
 * @return  return the pointer of the new linked list.
 */
LinkedList *linked_list_create()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

    if(list == NULL)
        return NULL;

    list->size = 0;
    list->head = node_create(0, NULL); 
    return list;
}
