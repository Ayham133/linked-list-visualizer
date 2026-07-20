#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct LinkedList{
    struct Node *head;
    struct Node *tail;
    uint16_t size;
}LinkedList;


/**
 * @brief   create a new linked list
 *
 * @return  return the pointer of the new linked list.
 */
LinkedList *linked_list_create();

/**
 * @brief   check if the linked list is empty or not.
 *
 * @param list      the pointer to the linked list.
 * @return          true if the linked list is empty, false other wise.
 */
bool linked_list_empty(LinkedList *list);

/**
 * @brief   add new value to the linked list.
 *
 * @param list      pointer to the list.
 * @param value     the new value to add in this linked list.
 */
void linked_list_insert(LinkedList *list,int value);

/**
 * @brief    get the value in the given index.
 *
 * @param list      pointer to the list.
 * @param index     the index to get the value from.
 * @return          return the value that has the addrese index.
 */
int linked_list_get(LinkedList *list, int index);

/**
 * @brief   deletes the node at the index, and returns it's value.
 *
 * @param list      pointer to the list.
 * @param index     the index of the node, that is going to get deleted.
 * @return          return the value of the deleted node.
 */
int linked_list_delete(LinkedList *list, int index);

#endif // !LINKED_LIST_H

