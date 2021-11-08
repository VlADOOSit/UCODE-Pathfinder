#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int midd = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        *count = *count + 1;
        midd = left + (right - left) / 2;
        if(mx_strcmp(arr[midd], s) == 0)
            return midd;
        if(mx_strcmp(s, arr[midd]) > 0) {
            left = midd + 1;
        }
        if(mx_strcmp(s, arr[midd]) < 0) {
            right = midd -1;
        }
    }
    *count = 0;
    return -1;
}
