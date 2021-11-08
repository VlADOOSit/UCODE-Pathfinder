#include "libmx.h"

t_list *mx_create_node(void *data) {
    if (!data) {
        return NULL;
    }
    t_list *node = (t_list*)malloc(sizeof(t_list));
    node->next = NULL;
    node->data = data;
    return node;
}
