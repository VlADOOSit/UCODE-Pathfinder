#include "libmx.h"

int mx_count_words(const char *str, char c) {
    bool flag = true;
    unsigned counter = 0;
    int i = 0;
    
    if (str == NULL)
        return -1;
    else {
        while (str[i]) {
            if (str[i] == c)
                flag = true;
            else if (flag == true) {
                flag = false;
                ++counter;
            }
            ++i;
        }
        return counter;
    }
}
