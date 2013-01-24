#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

linked_list *linked_list_create() {
    linked_list *l = (linked_list *)malloc(sizeof(linked_list));
    l = memset(l, 0, sizeof(linked_list));
    l->count = 0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

linked_list_node *linked_list_node_create() {
    linked_list_node *n = (linked_list_node *)malloc(sizeof(linked_list_node));
    n = memset(n, 0, sizeof(linked_list_node));
    n->value = 0;
    n->next = NULL;
    return n;
}
