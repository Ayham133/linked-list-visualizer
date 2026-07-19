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
    list->tail = NULL;
    list->head = NULL;
    return list;
}

/**
 * @brief   add new value to the linked list.
 *
 * @param value     the new value to add in this linked list.
 */
void linked_list_insert(LinkedList *list, int value)
{
    if(list == NULL)
        exit(EXIT_FAILURE);

    Node *node = node_create(value, NULL);
    if(list->size == 0)
    {
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }
    list->tail->next = node;
    list->tail = node;

    list->size++;
}
