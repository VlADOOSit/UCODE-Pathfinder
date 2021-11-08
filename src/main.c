#include "pathfinder.h"

int main(int argc, char *argv[]) {

    if(argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }

    check_error(argv[1]);

    char *str = mx_file_to_str(argv[1]);

    int size = get_size_from_file(str);
    char **islands = create_vertex_arr(str, size);

    int **start_weight = create_adj_matrix(str, islands ,size);
    int **end_weight = create_adj_matrix(str, islands ,size);
   

    algorithm(&end_weight, size);
    
    print_all_path(start_weight, end_weight, size, islands);

    mx_strdel(&str);
    mx_del_strarr(&islands);
    for(int i = 0; i < size; i++){
        free(start_weight[i]);
        free(end_weight[i]);
    }
    free(start_weight);
    free(end_weight);
    
    return 0;
}
