#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

#define run_test(fn_name)\
    printf(".");\
    fn_name();

void create_linked_list_test() {
    linked_list *l = linked_list_create();
    assert(l != NULL);
}

int main() {
    run_test(create_linked_list_test);
    printf("\n");
    return 0;
}
