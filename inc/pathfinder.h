#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

void check_error(char *filename);
char **create_vertex_arr(char *str, int size);
int get_index(char **strarr, char *str);
int get_size_from_file(char *str);
int **create_adj_matrix(char *str, char **vert ,int size);
void algorithm(int ***w, int size);
void print_path(int **start_weight, int **end_weight, int *way, int way_count, int size, char **vertex_arr);
void print_all_path(int **start_weight, int **end_weight, int size, char **vertex_arr);

#endif
