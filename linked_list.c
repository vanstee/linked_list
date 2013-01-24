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

void linked_list_remove_value(linked_list *l, int v) {
    linked_list_node *n = linked_list_find_node_for_value(l, v);

    if (n) {
        linked_list_remove_node(l, n);
    }
}

linked_list_node *linked_list_find_node_for_value(linked_list *l, int v) {
    linked_list_node *n = l->head;

    while (n) {
        if (n->value == v) {
            return n;
        }
        n = n->next;
    }

    return NULL;
}

void linked_list_remove_node(linked_list *l, linked_list_node *n) {
    linked_list_node *p = linked_list_find_previous_node(l, n);

    if (p && n->next) {
        p->next = n->next;
    } else {
        if (!p) {
          l->head = n->next;
        }

        if (!n->next) {
          l->tail = p;
        }
    }

    n->next = NULL;
    l->count--;
}

linked_list_node *linked_list_find_previous_node(linked_list *l, linked_list_node *n) {
    linked_list_node *p = l->head;

    while (p) {
        if (p->next == n) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}
