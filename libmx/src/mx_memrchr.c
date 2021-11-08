#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *result = (unsigned char*)s + mx_strlen(s);

    for (size_t i = n; i > 0; i--) {
        if(*result == (unsigned char)c) {
            return result;
        }
        result--;
    }
    return NULL;
}
