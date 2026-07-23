#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "../include/linked_list.h"
#include "../include/node.h"

Vector2 line_start_postion(Vector2 center, int radius)
{
    Vector2 starting_position;
    
    starting_position.x = center.x + radius;
    starting_position.y = center.y;

    return starting_position;

}

Vector2 line_end_position(Vector2 starting_position, float line_length)
{
    Vector2 end_position;
    end_position.x = starting_position.x + line_length;
    end_position.y = starting_position.y;

    return end_position;
}

int main(void)
{
    printf("Hello from, linked_list_visualizer!\n");

    InitWindow(800, 1000, "Linked List Visualizer");

    LinkedList *list = linked_list_create();
    linked_list_insert(list, 10);
    linked_list_insert(list, 20);
    linked_list_insert(list, 30);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
    
        Node *current = list->head;
        Vector2 init_positoion = {35.0f, 500.0f};
        while(current != NULL)
        {
            DrawCircleLinesV(init_positoion, 25, GRAY);
            Vector2 starting_position = line_start_postion(init_positoion, 25);
            DrawLineV(starting_position, line_end_position(starting_position, 100.0f), BLACK);
            init_positoion.x += 100.0f;
            current = current->next;
        }

        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}
