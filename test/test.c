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
    assert(linked_list_get(list, 10, &out_value) == false);

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

void test_linked_list_delete_null_list()
{
    LinkedList *list = NULL;

    int out_value;
    assert(linked_list_delete(list, 0, &out_value) == false);
   
    linked_list_destroy(&list);
}

void test_linked_list_delete_empty_list()
{
    LinkedList *list = linked_list_create();

    int out_value;
    assert(linked_list_delete(list, 0, &out_value) == false);

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
    assert(linked_list_empty(list) == false);
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
    assert(linked_list_empty(list) == false);
    assert(out_value == 20);

    linked_list_destroy(&list);
}

void test_linked_list_contains_null_list()
{
    LinkedList *list = NULL;

    assert(linked_list_contains(list, 1) == false);
    linked_list_destroy(&list);
}

void test_linked_list_contains_empty_list()
{
    LinkedList *list = linked_list_create();

    assert(linked_list_contains(list, 1) == false);
    linked_list_destroy(&list);
}

void test_linked_list_contains_all_positions()
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

void test_linked_list_contains_not_existing_value()
{
    LinkedList *list = linked_list_create();
    linked_list_insert(list, 10);

    assert(linked_list_empty(list) == false);
    assert(linked_list_contains(list, 999) == false);

    linked_list_destroy(&list);
}

void test_linked_list_is_empty_null_list()
{
    LinkedList *list = NULL;

    assert(linked_list_empty(list));

    linked_list_destroy(&list);
}

void test_linked_list_is_empty_not_empty_list()
{
    LinkedList *list = linked_list_create();
    linked_list_insert(list, 10);

    assert(linked_list_empty(list) == false);

    linked_list_destroy(&list);
}

void test_linked_list_is_empty()
{
    LinkedList *list = linked_list_create();

    assert(linked_list_empty(list));

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
    RUN_TEST(test_linked_list_delete_null_list);
    RUN_TEST(test_linked_list_delete_empty_list);
    RUN_TEST(test_linked_list_delete_first_node);
    RUN_TEST(test_linked_list_delete_last_node);
    RUN_TEST(test_linked_list_delete_mid_node);
    RUN_TEST(test_linked_list_contains_empty_list);
    RUN_TEST(test_linked_list_contains_null_list);
    RUN_TEST(test_linked_list_contains_all_positions);
    RUN_TEST(test_linked_list_contains_not_existing_value);
    RUN_TEST(test_linked_list_is_empty);
    RUN_TEST(test_linked_list_is_empty_not_empty_list);
    RUN_TEST(test_linked_list_is_empty_null_list);

    return EXIT_SUCCESS;
}
