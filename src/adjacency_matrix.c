#include "pathfinder.h"

int **create_adj_matrix(char *str, char **vertex_arr, int size) {
    int **adj_weight_matrix = (int **) malloc((size + 1) * sizeof(int *));
    for(int i = 0; i < size; i++) {
        adj_weight_matrix[i] = (int*)malloc(size * sizeof(int));
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            adj_weight_matrix[i][j] = 999999;
        }
    }

    int **test_m = (int **) malloc((size + 1) * sizeof(int *));
    for(int i = 0; i < size; i++) {
        test_m[i] = (int*)malloc(size * sizeof(int));
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            test_m[i][j] = 0;
        }
    }

    char **strarr = mx_strsplit(str, '\n');

    for (int i = 1; strarr[i]; i++) {
        char *from = mx_strndup(strarr[i], mx_get_char_index(strarr[i], '-'));
        strarr[i] += mx_get_char_index(strarr[i], '-') + 1;
        
        char *to = mx_strndup(strarr[i], mx_get_char_index(strarr[i], ','));
        strarr[i] += mx_get_char_index(strarr[i], ',') + 1;
        
        char *path = mx_strndup(strarr[i], mx_get_char_index(strarr[i], '\n'));

        if (test_m[get_index(vertex_arr, from)][get_index(vertex_arr, to)] == 1 && test_m[get_index(vertex_arr, to)][get_index(vertex_arr, from)] == 1) {
            mx_printerr("error: duplicate bridges\n");
            exit(-1);
        }

        if (mx_atoi(path) == -1) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(-1);
        }

        adj_weight_matrix[get_index(vertex_arr, from)][get_index(vertex_arr, to)] = mx_atoi(path);
        adj_weight_matrix[get_index(vertex_arr, to)][get_index(vertex_arr, from)] = mx_atoi(path);

        test_m[get_index(vertex_arr, from)][get_index(vertex_arr, to)] = 1;
        test_m[get_index(vertex_arr, to)][get_index(vertex_arr, from)] = 1;

        
        mx_strdel(&from);
        mx_strdel(&to);
        mx_strdel(&path);
    }


    for(int i = 0; i < size; i++){
        free(test_m[i]);
    }
    free(test_m);
    return adj_weight_matrix;
}
