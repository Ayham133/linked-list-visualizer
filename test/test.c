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

    printf("list size is 0.......");
    assert(list->size == 0);
    printf("Passed\n");

    printf("first insertion 10 to list...");
    linked_list_insert(list, 10);
    assert(list->head->value == 10);// head should have 10
    printf("Passed\n");

    printf("insert 20 to list............");
    linked_list_insert(list, 20);
    assert(list->tail->value == 20);//tail should have 20
    printf("Passed\n");

    return EXIT_SUCCESS;
}
