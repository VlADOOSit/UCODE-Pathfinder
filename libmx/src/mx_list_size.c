#include "libmx.h"

int mx_list_size(t_list *list) {
    if (!list) 
        return 0;
    int counter = 0;

    while(list) {
        list = list->next;
        counter++;
    }
    
    return counter;
}
