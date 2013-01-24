struct linked_list_node {
   int value;
   struct linked_list_node *next;
};
typedef struct linked_list_node linked_list_node;

struct linked_list {
    int count;
    linked_list_node *head;
    linked_list_node *tail;
};
typedef struct linked_list linked_list;

linked_list *linked_list_create();
linked_list_node *linked_list_node_create();
void linked_list_append_value(linked_list *l, int v);
void linked_list_append_node(linked_list *l, linked_list_node *n);
void linked_list_append_node_after(linked_list *l, linked_list_node *n, linked_list_node *a);
void linked_list_remove_value(linked_list *l, int v);
linked_list_node *linked_list_find_node_for_value(linked_list *l, int v);
void linked_list_remove_node(linked_list *l, linked_list_node *n);
linked_list_node *linked_list_find_previous_node(linked_list *l, linked_list_node *n);
void linked_list_free(linked_list *l);
void linked_list_node_free(linked_list_node *n);
