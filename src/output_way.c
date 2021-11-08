#include "pathfinder.h"

void print_path(int **start_weight, int **end_weight, int *way, int way_count, int size, char **vertex_arr) {
    int from = way[0];
    int to = way[way_count];
    int path_dist = 0;

    for (int i = 0; i < size; i++){
        if ((start_weight[to][i] == end_weight[to][from] - end_weight[i][from]) && i != way[way_count]) {
            way_count += 1;
            way[way_count] = i;
            
            print_path(start_weight, end_weight, way, way_count ,size, vertex_arr);
            
            way_count -= 1;
        }
    }

    if (way[way_count] != from) {
        return;
    } 

    for (int i = 0; i < 40; i++) {
        mx_printchar('=');
    }
    
    mx_printstr("\nPath: ");
    mx_printstr(vertex_arr[way[1]]);
    mx_printstr(" -> ");
    mx_printstr(vertex_arr[way[0]]);
    mx_printchar('\n');
    mx_printstr("Route: ");

    for (int i = 1; i < way_count + 1; i++) {
        
        mx_printstr(vertex_arr[way[i]]);
        
        if (i < way_count) {
            mx_printstr(" -> ");
        }
    }

    mx_printstr("\nDistance: ");

    for (int i = 1; i < way_count; i++) {
        int between = start_weight[way[i]][way[i + 1]];

        mx_printint(between);
        path_dist += between;

        if (i < way_count - 1) {
            mx_printstr(" + ");
        }
    }

    if (way_count != 2) {
        mx_printstr(" = ");
        mx_printint(path_dist);
    }

    mx_printchar('\n');

    for (int i = 0; i < 40; i++) {
        mx_printchar('=');
    }

    mx_printchar('\n');
}

void print_all_path(int **start_weight, int **end_weight, int size, char **vertex_arr){

    int *way = (int*)malloc((size + 1) * sizeof(int));
    int way_count = 1;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++){

            way[1] = i;
            way[0] = j;

            print_path(start_weight, end_weight, way, way_count ,size, vertex_arr);
        }
    }

    free(way);
}
