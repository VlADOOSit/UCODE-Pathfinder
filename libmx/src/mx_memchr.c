#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *result = (unsigned char*)s;

    for (size_t i = 0; i < n; i++) {
        if(*result == (unsigned char)c) {
            return result;
        }
        result++;
    }
    return NULL;
}
