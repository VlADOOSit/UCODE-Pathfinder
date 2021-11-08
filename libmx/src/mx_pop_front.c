#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *current = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        current = (*head)->next;
        free(*head);
        *head = current;
    }
}
