#include "libmx.h"

char *mx_strdup(const char *str) {
    char *temp = mx_strnew(mx_strlen(str));
    mx_strcpy(temp, str);
    return temp;
}
