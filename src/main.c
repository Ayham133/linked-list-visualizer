#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "../include/linked_list.h"
#include "../include/node.h"
#include "../include/linked_list_draw.h"


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
        int raduis = 25;
        int line_length = abs(raduis*2 - 100);
        while(current != NULL)
        {
            DrawCircleLinesV(init_positoion, raduis, GRAY);
            int text_width = MeasureText(TextFormat("%d", current->value), 20);
            int text_x = (int)(init_positoion.x - text_width / 2.0f);
            int text_y = (int)(init_positoion.y - 20 / 2.0f);
            DrawText(TextFormat("%d", current->value), text_x, text_y, 20, BLACK);

            if(current->next != NULL)
            {
                Vector2 starting_position = line_start_postion(init_positoion, raduis);
                Vector2 next_center = {init_positoion.x +100.0f, init_positoion.y};
                Vector2 end_position = line_end_position(next_center, raduis);
                DrawLineV(starting_position, end_position, BLACK);
            }
            init_positoion.x += 100.0f;
            current = current->next;
        }

        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}
