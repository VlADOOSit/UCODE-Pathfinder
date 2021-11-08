#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2){
    while( mx_strchr(s1, *s2) != 0) {
        if (mx_strncmp(s1, s2, mx_strlen(s2)) == 0) {
			return (char *)s1;
        }
        s1++;
    }
    return NULL;
}
