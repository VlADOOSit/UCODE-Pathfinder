#include "libmx.h"

char *mx_strnew(const int size) {
    char *str = NULL;
    int i = 0;

    if (size < 0) {
        return NULL;
    }
    
    str = (char *)malloc((size + 1) * sizeof(char));

    while (i < size) {
        str[i] = '\0';
        i++;
    }
    str[i] = '\0';
    return str;
}
