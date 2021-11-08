#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) 
        return NULL;
    while(mx_isspace(*str)) {
        str++;
    }
    int len_of_result = mx_strlen(str);
    while(mx_isspace(str[len_of_result -1])) {
        len_of_result--;
    }
    return mx_strndup(str, len_of_result);
}
