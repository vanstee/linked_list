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
