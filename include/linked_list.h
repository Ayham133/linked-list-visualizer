#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <stdlib.h>
#include <stdint.h>

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


#endif // !LINKED_LIST_H

