#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) {
        return -1;
    }
    
    int l = left;
    int r = right;
    int counter = 0;
    char *piv = arr[(l + r) / 2];

    while (l <= r) {
        while (mx_strlen(arr[l]) < mx_strlen(piv)) {
            l++;
        }
        while (mx_strlen(arr[r]) > mx_strlen(piv)) {
            r--;
        }
        if (l <= r) {
            if (mx_strlen(arr[r]) != mx_strlen(arr[l])) {
                char *temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                counter++;
            }
            l++;
            r--;
        }
    }
    if (left < r) {
        counter += mx_quicksort(arr, left, r);
    }
    if (right > l) {
        counter += mx_quicksort(arr, l, right);
    }
    return counter;
}
