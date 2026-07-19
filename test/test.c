#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"
int main(void)
{
    printf("Testing\n");

    printf("creating linked list.......");
    LinkedList *list = linked_list_create();
    assert(list != NULL);
    printf("Passed\n");

    printf("list head value is 0.......");
    assert(list->head->value == 0);
    printf("Passed\n");

    printf("head.next should be null...");
    assert(list->head->next == NULL);
    printf("Passed\n");

    return EXIT_SUCCESS;
}
