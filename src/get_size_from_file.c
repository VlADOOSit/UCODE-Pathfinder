#include "pathfinder.h"

int get_size_from_file(char *str) {
    int size;
    
    char **arr = mx_strsplit(str, '\n');

    size = mx_atoi(arr[0]);

    mx_del_strarr(&arr);

    return size;
}
