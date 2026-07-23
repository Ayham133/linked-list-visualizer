#ifndef LINKED_LIST_DRAW_H
#define LINKED_LIST_DRAW_H

#include "linked_list.h"
#include "node.h"
#include "raylib.h"
#include <stddef.h>

/**
 * @brief       calculate the starting posistion vector for the line.
 *
 * @param center        the center of the circle.
 * @param radius        the radius of the circle.
 * @return [Vector2]    return the starting_position vector of the line.
 */
Vector2 line_start_postion(Vector2 center, size_t radius);

/**
 * @brief       calculate the end_position.
 *
 * by calculating the absolute value from the result of
 * subtracting the y component of next_center posistion
 * vector from the radius.
 *
 * @param next_center           the next node center posistion vectot.
 * @param raduis                the radius of the circles.
 * @return [Vector2]            return the end_position vector of the line.
 */
Vector2 line_end_position(Vector2 next_center, size_t raduis);

/**
 * @brief       draw node on the window.
 *
 * @param node          the pointer to the node.
 * @param center        the center vector that tells where to draw the node.
 * @param raduis        the radius of each circle that will represent each node.
 * @param line_length   tells how long is the line after the node well be.
 */
void draw_node(Node *node, Vector2 center, size_t raduis, float space_between_nodes);

/**
 * @brief       draw linked list with all of it's node, and draw a line connect each node with it's next node.
 *
 * @param list      the pointer to the linked list.
 * @param starting_position     the posistion vector, that gives the x, y coordenate to where the drawing will start.
 * @param radius        the radius of each circle that will represent each node.
 * @param line_length   tells how long is the line after the node well be.
 */
void draw_linked_list(LinkedList *list, Vector2 starting_center, size_t radius, float space_between_nodes);

#endif // !LINKED_LIST_DRAW_H
