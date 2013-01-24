#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

linked_list *linked_list_create() {
    linked_list *l = (linked_list *)malloc(sizeof(linked_list));
    l = memset(l, 0, sizeof(linked_list));
    return l;
}
