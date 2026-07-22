#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
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
 * @brief   check if the linked list is empty or not.
 *
 * @param list      the pointer to the linked list.
 * @return          true if the linked list is empty, false other wise.
 */
bool linked_list_empty(LinkedList *list)
{
    return list->size == 0;
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
    if(linked_list_empty(list))
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

/**
 * @brief    get the value in the given index.
 *
 * @param list      pointer to the list.
 * @param index     the index to get the value from.
 * @param out_value     pointer to the addrese of the out_value, used to put the data in that addrese.
 * @return          return true if the function execute successfuly, false other wise.
 */
bool linked_list_get(LinkedList *list, size_t index, int *out_value)
{
    if (list == NULL || index >= list->size)
        return false;

    Node *temp = list->head;

    while (temp != NULL && index > 0)
    {
        temp = temp->next;
        index--;
    }

    if (temp == NULL)
        return false;

    *out_value = temp->value;
    return true;
}

/**
 * @brief   deletes the node at the index, and returns it's value.
 *
 * @param list      pointer to the list.
 * @param index     the index of the node, that is going to get deleted.
 * @param out_value     pointer to the addrese where the value of the deleted node will go to.
 * @return [bool]          return true if there were no errors, false otherwise.
 */
bool linked_list_delete(LinkedList *list, size_t index, int *out_value)
{
    if(list == NULL || linked_list_empty(list) || index >= list->size)
        return false;

    list->size--;

    // if the list has one node.
    if(index == 0 && list->size == 1){
        *out_value = list->head->value;
        list->head = NULL; 
        return true;
    }

    // if the deleted node is the head.
    if(index == 0)
    {
        *out_value = list->head->value;
        list->head = list->head->next;
        return true;
    }

    // in the mid of the linked list.
    Node *temp = list->head;
    while(temp != NULL && index > 1)
    {
        temp = temp->next;
        index--;
    }

    *out_value = temp->next->value;
    temp->next = temp->next->next;

    return true;
}

/**
 * @brief   check if the list contains the passed value.
 *
 * @param list      pointer to the list.
 * @param value     the value to search for in the list.
 * @return          return true if the valuse was found in the list, false other wise.
 */
bool linked_list_contains(LinkedList *list, int value)
{
    if(list == NULL || linked_list_empty(list))
        exit(EXIT_FAILURE);
    
    Node *temp = list->head;
    while (temp != NULL && temp->value != value)
        temp = temp->next;

    return temp != NULL;
}

/**
 * @brief   print the list in this form '1->2->3->n', this function doesn't end with "\n" opertator.
 *
 * @param list      pointer to the list.
 * return [void]
 */
void linked_list_print(LinkedList *list)
{
    if(list == NULL || linked_list_empty(list))
        return;

    Node *temp = list->head;
    while(temp != NULL)
    {
        printf("%d", temp->value);
        if(temp->next != NULL)
            printf("->");

        temp = temp->next;
    }
}

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
void linked_list_destroy(LinkedList **list)
{
    if(list == NULL || *list == NULL)
        return;

    Node *current = (*list)->head;

    while(current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(*list);
    *list = NULL;
}
