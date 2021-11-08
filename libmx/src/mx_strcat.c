#include "libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    for (int i = mx_strlen(s1), j = 0; i < mx_strlen(s1)+ mx_strlen(s2); i++, j++) {
        s1[i] = s2[j];
    }
    return s1;
}
