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

    linked_list_destroy(&list);
}

void test_linked_list_get()
{
    LinkedList *list = linked_list_create();
    int out_value;

    linked_list_insert(list, 10);
    assert(linked_list_get(list, 0, &out_value));
    assert(out_value == 10);

    linked_list_insert(list, 20);
    linked_list_insert(list, 30);
    assert(linked_list_get(list, 1, &out_value));
    assert(out_value == 20);

    assert(linked_list_get(list, 2, &out_value));
    assert(out_value == 30);
    
    linked_list_destroy(&list);
}

void test_linked_list_get_invalid_index()
{
    LinkedList *list = linked_list_create();
    int out_value;
    assert(!linked_list_get(list, 10, &out_value));

    linked_list_destroy(&list);

}

void test_linked_list_find()
{
    LinkedList *list = linked_list_create();
    linked_list_insert(list, 10);
    linked_list_insert(list, 20);
    linked_list_insert(list, 30);
    assert(linked_list_contains(list, 10));
    assert(linked_list_contains(list, 20));
    assert(linked_list_contains(list, 30));

    linked_list_destroy(&list);
}

void test_linked_list_delete_first_node()
{
    LinkedList *list = linked_list_create();
    linked_list_insert(list, 10);
    int out_value;
    assert(linked_list_delete(list, 0, &out_value));
   
    assert(list->head == NULL);
    assert(list->size == 0);
    assert(linked_list_empty(list));
    assert(out_value == 10);

    linked_list_destroy(&list);
}

void test_linked_list_delete_last_node()
{
    LinkedList *list = linked_list_create();
    linked_list_insert(list, 10);
    linked_list_insert(list, 20);
   
    int out_value;
    linked_list_delete(list, 1, &out_value);

    assert(list->head != NULL);
    assert(list->size == 1);
    assert(!linked_list_empty(list));
    assert(out_value == 20);

    linked_list_destroy(&list);
}

void test_linked_list_delete_mid_node()
{
    LinkedList *list = linked_list_create();
    linked_list_insert(list, 10);
    linked_list_insert(list, 20);
    linked_list_insert(list, 30);

    int out_value;
    linked_list_delete(list, 1, &out_value);

    assert(list->head != NULL);
    assert(list->size == 2);
    assert(!linked_list_empty(list));
    assert(out_value == 20);

    linked_list_destroy(&list);

}

int main(void)
{
    printf("Testing\n");

    RUN_TEST(test_linked_list_create);
    RUN_TEST(test_linked_list_insert);
    RUN_TEST(test_linked_list_get);
    RUN_TEST(test_linked_list_get_invalid_index);
    RUN_TEST(test_linked_list_find);
    RUN_TEST(test_linked_list_delete_first_node);
    RUN_TEST(test_linked_list_delete_last_node);
    RUN_TEST(test_linked_list_delete_mid_node);


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
