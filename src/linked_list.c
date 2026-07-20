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
 * @return          return the value that has the addrese index.
 */
int linked_list_get(LinkedList *list, int index)
{
    if(list == NULL || linked_list_empty(list))
        exit(EXIT_FAILURE);

    if(index < 0 || index >= list->size)
        exit(EXIT_FAILURE);

    Node *temp = list->head;
    while(temp != NULL && index > 0)
    {
        temp = temp->next;
        index--;
    }

    if(temp == NULL)
        exit(EXIT_FAILURE);

    return temp->value;
}

/**
 * @brief   deletes the node at the index, and returns it's value.
 *
 * @param list      pointer to the list.
 * @param index     the index of the node, that is going to get deleted.
 * @return          return the value of the deleted node.
 */
int linked_list_delete(LinkedList *list, int index)
{
    if(list == NULL || linked_list_empty(list))
        exit(EXIT_FAILURE);

    if(index < 0 || index >= list->size)
        exit(EXIT_FAILURE);

    int value;
    // if the list has one node.
    if(list->size == 1){
        value = list->head->value;
        free(list);
        return value;
    }

    // if the deleted node is the head.
    if(index == 0)
    {
        value = list->head->value;
        list->head = list->head->next;
        return value;
    }

    Node *temp = list->head;
    while(temp != NULL && index > 1)
    {
        temp = temp->next;
        index--;
    }

    value = temp->value;
    temp->next = temp->next->next;

    return value;
}
