#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

#define run_test(fn_name)\
    printf(".");\
    fn_name();

void create_linked_list_test() {
    linked_list *l = linked_list_create();
    assert(l != NULL);
    assert(l->count == 0);
    assert(l->head == NULL);
    assert(l->tail == NULL);
}

void create_linked_list_node_test() {
    linked_list_node *n = linked_list_node_create();
    assert(n != NULL);
    assert(n->value == 0);
    assert(n->next == NULL);
}

void append_node_to_empty_list() {
    linked_list *l = linked_list_create();
    linked_list_node *n = linked_list_node_create();
    linked_list_append_node(l, n);
    assert(l->head == n);
    assert(l->tail == n);
    assert(l->count == 1);
}

void append_node_to_list_with_at_least_one_element() {
    linked_list *l = linked_list_create();
    linked_list_node *n1 = linked_list_node_create();
    linked_list_node *n2 = linked_list_node_create();
    linked_list_append_node(l, n1);
    linked_list_append_node(l, n2);
    assert(l->head == n1);
    assert(l->tail == n2);
    assert(l->count == 2);
    assert(l->head->next == n2);
}

void append_node_after_node() {
    linked_list *l = linked_list_create();
    linked_list_node *n1 = linked_list_node_create();
    linked_list_node *n2 = linked_list_node_create();
    linked_list_node *n3 = linked_list_node_create();
    linked_list_append_node(l, n1);
    linked_list_append_node(l, n3);
    linked_list_append_node_after(l, n2, n1);
    assert(n1->next == n2);
    assert(n2->next == n3);
    assert(l->count == 3);
}

void append_node_after_tail() {
    linked_list *l = linked_list_create();
    linked_list_node *n1 = linked_list_node_create();
    linked_list_node *n2 = linked_list_node_create();
    linked_list_append_node(l, n1);
    linked_list_append_node_after(l, n2, n1);
    assert(n1->next == n2);
    assert(n2->next == NULL);
    assert(l->tail == n2);
    assert(l->count == 2);
}

int main() {
    run_test(create_linked_list_test);
    run_test(create_linked_list_node_test);
    run_test(append_node_to_empty_list);
    run_test(append_node_to_list_with_at_least_one_element);
    run_test(append_node_after_node);
    run_test(append_node_after_tail);
    printf("\n");
    return 0;
}
