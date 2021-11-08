#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *result = NULL;
    if (!str || !sub || !replace) {
        return NULL;
    }

    int len = mx_strlen(str) - (mx_count_substr(str, sub) * mx_strlen(sub)) + (mx_count_substr(str, sub) * mx_strlen(replace));
    result = mx_strnew(len);

    int i = 0;
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&result[i], replace);
            i += mx_strlen(replace);
            str += mx_strlen(sub);
        }
        else{
            result[i++] = *str++;
        }       
    }
    result[i] = '\0';
    return result;
}
