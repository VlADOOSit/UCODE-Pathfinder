#include "pathfinder.h"

char** create_vertex_arr(char *str, int size) {
    char *buff = mx_strnew(200);

    int i = 0;
    while (str[i] != '\n') {
        i++;
    }

    char **v_arr = (char**) malloc((size * sizeof(char*)) + 1);
    for(int i = 0; i < size; i++) {
        v_arr[i] = NULL;
    }


    int counter = 0;
    int buff_counter = 0;
    int flag = 0;

    for (; i < mx_strlen(str); i++) {
        if (str[i] != '-' && str[i] != ',' && str[i] != '\n' && !mx_isdigit(str[i])) {
            buff[buff_counter] = str[i];
            buff_counter++;
        }
        if (str[i] == '-') {
            for (int j = 0; j < counter; j++) {
                if (mx_strcmp(v_arr[j], mx_strdup(buff))==0) {
                    flag = 1;
                    for (int j = 0; j < buff_counter; j++) {
                        buff[j] = '\0';
                    }
                    buff_counter = 0;
                }
                
            }
            if (flag != 1) {
                v_arr[counter] = mx_strdup(buff);
                for (int j = 0; j < buff_counter; j++) {
                    buff[j] = '\0';
                }
                buff_counter = 0;
                counter++;
            }
        }
        if (str[i] == ',') {
            for (int j = 0; j < counter; j++) {
                if (mx_strcmp(v_arr[j], mx_strdup(buff)) == 0) {
                    flag = 1;
                    for (int j = 0; j < buff_counter; j++) {
                        buff[j] = '\0';
                    }
                    buff_counter = 0;
                }
            }
            if (flag != 1) {
                v_arr[counter] = mx_strdup(buff);
                for (int j = 0; j < buff_counter; j++) {
                    buff[j] = '\0';
                }
                buff_counter = 0;
                counter++;
            }
        }
        flag = 0;
    }
    mx_strdel(&buff);

    return v_arr;
}
