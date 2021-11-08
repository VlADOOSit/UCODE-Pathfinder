#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) {
        return -2;
    }

    for (int i = 0; *str; i++) {
        
        if (str == mx_strstr(str, sub)) {
            return i;
        }
        str++;
    }
    return -1;

}
