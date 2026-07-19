#include "../include/node.h"
#include <stdlib.h>


/**
 * @brief       create a new node.
 *
 * @param value     the value for the new node.
 * @param next      the pointer to the next node.
 */
Node *node_create(int value, Node *next)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        return NULL;

    new_node->next = next;
    new_node->value = value;

    return new_node;
}
