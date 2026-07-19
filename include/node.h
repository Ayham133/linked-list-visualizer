#ifndef NODE_H
#define NODE_H

typedef struct Node{
    struct Node *next;
    int value;
}Node;

/**
 * @brief       create a new node.
 *
 * @param value     the value for the new node.
 * @param next      the pointer to the next node.
 */
Node *node_create(int value, Node *next);

#endif // !NODE_H
