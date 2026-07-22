#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"
#include "test.h"

void test_linked_list_create()
{
    LinkedList *list = linked_list_create();

    assert(list != NULL);
    assert(list->size == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    linked_list_destroy(&list);
}

void test_linked_list_insert()
{
    LinkedList *list = linked_list_create();
    
    linked_list_insert(list, 10);

    int out_value;
    assert(linked_list_get(list, 0, &out_value));
    assert(out_value == 10);
    assert(list->size == 1);

    linked_list_insert(list, 20);
    assert(linked_list_get(list, 1, &out_value));
    assert(out_value == 20);
    assert(list->size == 2);

    // Testing invalid index.
    assert(!linked_list_get(list, 10, &out_value));

    linked_list_destroy(&list);
}


int main(void)
{
    printf("Testing\n");

    RUN_TEST(test_linked_list_create);
    printf("\n");
    RUN_TEST(test_linked_list_insert);
    printf("\n");

    // printf("first insertion 10 to list...");
    // linked_list_insert(list, 10);
    // assert(list->head->value == 10);// head should have 10
    // printf("Passed\n");
    //
    // printf("insert 20 to list............");
    // linked_list_insert(list, 20);
    // assert(list->tail->value == 20);//tail should have 20
    // printf("Passed\n");
    //
    // printf("get the first value.........");
    // int number = linked_list_get(list, 0);
    // assert(number == 10);
    // printf("%d, Passed\n", number);
    //
    // printf("get the second value.........");
    // number = linked_list_get(list, 1);
    // assert(number == 20);
    // printf("%d, Passed\n", number);
    //
    // // printf("get with invalid index.........");
    // // linked_list_get(list, 5);
    // // // printf("Passed\n");
    // //
    // printf("list before........................");
    // Node *temp = list->head;
    // while(temp != NULL)
    // {
    //     printf("%d", temp->value);
    //     if(temp->next != NULL)
    //         printf("->");
    //
    //     temp = temp->next;
    // }
    //
    // printf("\ndelete the first value.......");
    // linked_list_delete(list, 0);
    // printf("Passed\n");
    //
    // printf("list after........................");
    // temp = list->head;
    // while(temp != NULL)
    // {
    //     printf("%d", temp->value);
    //     if(temp->next != NULL)
    //         printf("->");
    //
    //     temp = temp->next;
    // }
    // printf("\tPassed\n");
    //
    // printf("Finding a value that doesn't exists in the list......."); 
    // assert(!linked_list_containes(list, 10));
    // printf("\tPassed\n");
    //
    // printf("Finding a value that does exists......................");
    // assert(linked_list_containes(list, 20));
    // printf("\tPassed\n");
    //
    // printf("printing list.........................................");
    // linked_list_print(list);
    // printf("\n");
    //
    // LinkedList *list2 = linked_list_create();
    // linked_list_insert(list2, 10);
    // linked_list_insert(list2, 20);
    // linked_list_insert(list2, 30);
    // linked_list_insert(list2, 40);
    // printf("printing list2.........................................");
    // linked_list_print(list2);
    // printf("\n");
    //
    // LinkedList *list3 = linked_list_create();
    // printf("printing an empty list.........................................");
    // linked_list_print(list3);
    // printf("Passed\n");
    //
    // list3 = NULL;
    // printf("printing a NULL list.........................................");
    // linked_list_print(list3);
    // printf("Passed\n");
    //
    // printf("destroy list2...........................................");
    // linked_list_destroy(&list2);
    // printf("Passed\n");
    //
    return EXIT_SUCCESS;
}
