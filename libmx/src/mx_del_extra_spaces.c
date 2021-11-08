#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) {
        return NULL;
    }    
    char *buffer = mx_strnew(mx_strlen(str));
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (!(mx_isspace(str[i]))) {
            buffer[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            buffer[j] = ' ';
            j++;
        }
        i++;
    }
    char *result = mx_strtrim(buffer);
    mx_strdel(&buffer);
    return result;
}
