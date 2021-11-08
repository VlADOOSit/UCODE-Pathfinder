#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *current = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        current = *head;
        while (current && current->next->next != NULL)
            current = current->next;
        free(current->next);
        current->next = NULL;
    }
}
