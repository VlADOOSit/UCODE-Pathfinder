#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (*list == NULL || list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    t_list *curr = *list;

    while(curr->next) {
        curr = curr->next;
    }
    curr->next = mx_create_node(data);
}
