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

void linked_list_append_value(linked_list *l, int v) {
    linked_list_node *n = linked_list_node_create();
    n->value = v;
    linked_list_append_node(l, n);
}

void linked_list_append_node(linked_list *l, linked_list_node *n) {
    if (l->tail) {
        linked_list_append_node_after(l, n, l->tail);
    } else {
        l->head = n;
        l->tail = n;
        l->count++;
    }
}

void linked_list_append_node_after(linked_list *l, linked_list_node *n, linked_list_node *a) {
    n->next = a->next;
    a->next = n;

    if (l->tail == a) {
        l->tail = n;
    }

    l->count++;
}
