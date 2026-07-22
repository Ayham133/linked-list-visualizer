#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct LinkedList{
    struct Node *head;
    struct Node *tail;
    size_t size;
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
 * @param out_value     pointer to the addrese of the out_value, used to put the data in that addrese.
 * @return          return true if the function execute successfuly, false other wise.
 */
bool linked_list_get(LinkedList *list, size_t index, int *out_value);

/**
 * @brief   deletes the node at the index, and returns it's value.
 *
 * @param list      pointer to the list.
 * @param index     the index of the node, that is going to get deleted.
 * @param out_value     pointer to the addrese where the value of the deleted node will go to.
 * @return [bool]          return true if there were no errors, false otherwise.
 */
bool linked_list_delete(LinkedList *list, size_t index, int *out_value);

/**
 * @brief   check if the list containes the passed value.
 *
 * @param list      pointer to the list.
 * @param value     the value to search for in the list.
 * @return          return true if the valuse was found in the list, false other wise.
 */
bool linked_list_contains(LinkedList *list, int value);

/**
 * @brief   print the list in this form 1->2->3->n
 *
 * @param list      pointer to the list.
 * return [void]
 */
void linked_list_print(LinkedList *list);

/**
 * @brief Destroys a linked list and releases all allocated memory.
 *
 * Frees every node contained in the linked list and then frees the
 * linked list structure itself. The pointer is set to NULL after
 * successful destruction to prevent dangling pointer access.
 *
 * @param list A pointer to the linked list pointer to be destroyed.
 *
 * @note The function does nothing if the provided pointer or list is NULL.
 */
void linked_list_destroy(LinkedList **list);

#endif // !LINKED_LIST_H

