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

int main() {
    run_test(create_linked_list_test);
    run_test(create_linked_list_node_test);
    printf("\n");
    return 0;
}
