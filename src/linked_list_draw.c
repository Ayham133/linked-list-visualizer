#include "../include/linked_list_draw.h"
#include "raylib.h"
#include <stddef.h>


/**
 * @brief       calculate the starting posistion vector for the line.
 *
 * @param center        the center of the circle.
 * @param radius        the radius of the circle.
 * @return [Vector2]    return the starting_position vector of the line.
 */
Vector2 line_start_postion(Vector2 center, size_t radius)
{
    Vector2 starting_position;
    
    starting_position.x = center.x + radius;
    starting_position.y = center.y;

    return starting_position;

}

/**
 * @brief       calculate the end_position.
 *
 * by calculating the absolute value from the result of
 * subtracting the y component of next_center posistion
 * vector from the radius.
 *
 * @param next_center           the next node center posistion vectot.
 * @param radius                the radius of the circles.
 * @return [Vector2]            return the end_position vector of the line.
 */
Vector2 line_end_position(Vector2 next_center, size_t radius)
{
    Vector2 end_position;
    end_position.y = next_center.y;

    float X = next_center.x - radius;
    end_position.x = ( X > 0)? X : -(X);

    return end_position;
}

/**
 * @brief       draw node on the window.
 *
 * @param node          the pointer to the node.
 * @param center        the center vector that tells where to draw the node.
 * @param radius        the radius of each circle that will represent each node.
 * @param line_length   tells how long is the line after the node well be.
 */
void draw_node(Node *node, Vector2 center, size_t raduis, float line_length)
{
    Vector2 starting_position;
    Vector2 end_position;
    // while (!WindowShouldClose()) {
    //     BeginDrawing();
    //     DrawCircleLinesV(center, raduis, GRAY);
    //     int text_width = MeasureText(TextFormat("%d", node->value), 20);
    //     int text_x = (int)(center.x - text_width / 2.0f);
    //     int text_y = (int)(center.y - 20 / 2.0f);
    //     DrawText(TextFormat("%d", node->value), text_x, text_y, 20, BLACK);
    //     EndDrawing();
    // }
}
