#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (n == 0) {
        return 0;
    }
    const unsigned char *str1 = s1;
    const unsigned char *str2 = s2;
    size_t count = 0;

    while(count != n && str1[count] == str2[count]) {
        if (str1[count] == '\0' && str2[count] == '\0') {
            return 0;
        }
        count++;
    }
    return str1[count] - str2[count];
}
