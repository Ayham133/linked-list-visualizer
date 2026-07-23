#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

int main(void)
{
    printf("Hello from, linked_list_visualizer!\n");

    InitWindow(800, 1000, "Linked List Visualizer");

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}
