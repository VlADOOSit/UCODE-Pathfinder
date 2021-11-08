#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int counter = 0;

    if (!str || !sub) {
        return -1;
    }

    for (int i = 0; *str; i++) {
        
        if (str == mx_strstr(str, sub)) {
            counter++;
        }
        str++;
    }
    return counter;
}
