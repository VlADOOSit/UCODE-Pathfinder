#include "pathfinder.h"

static int file_len(const char *file) {
    short fl = open(file, O_RDONLY);
    short sz = 0;
    int len = 0;
    char buf;
    sz = read(fl, &buf, 1);
    while (sz > 0) {
        sz = read(fl, &buf, 1);
        len++;
    }
    close(fl);
    return len;
}

int size_strarr(char **strarr) {
    int size = 0;
    for (int i = 0; strarr[i]; i++) {
        size++;
    }
    return size;
}

void check_line(char *str, int index, int fd) {
    for (int i = 0; i < mx_strlen(str); i++) {
        if (!mx_isalpha(str[i])) {
            close(fd);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(index + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }
    }
}

void check_error(char *filename) {
    int fd = open(filename, O_RDONLY);
    
    if (fd == -1) {
        close(fd);
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(-1);
    }

    int size = file_len(filename);

    if (size <= 0) {
        close(fd);
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(-1);
    }

    char *temp_str = mx_file_to_str(filename);
    char **strarr = mx_strsplit(temp_str, '\n');

    int strarr_size = 0;

    for (int i = 0; strarr[i]; i++) {
        strarr_size++;
    }

    for (int i = 0; i < mx_strlen(strarr[0]); i++) {
        if (!mx_isdigit(strarr[0][i])) {
            close(fd);
            mx_printerr("error: line 1 is not valid\n");
            exit(-1);
        }
    }
    if (mx_atoi(strarr[0]) <= 0) {
        close(fd);
        mx_printerr("error: line 1 is not valid\n");
        exit(-1); 
    }

    for (int i = 1; strarr[i]; i++) {
        if (mx_get_char_index(strarr[i], '-') < 0 || mx_get_char_index(strarr[i], ',') < 0) {
            close(fd);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }
        if (mx_count_substr(strarr[i], "-") > 1 || mx_count_substr(strarr[i], ",") > 1) {
            close(fd);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }

        char **temp_str_arr = mx_strsplit(strarr[i], '-');

        check_line(temp_str_arr[0], i, fd);
        
        check_line(mx_strndup(temp_str_arr[1], mx_get_char_index(temp_str_arr[1] ,',')), i, fd);

        for (int j = mx_get_char_index(temp_str_arr[1] ,',') + 1; j < mx_strlen(temp_str_arr[1]); j++) {
            if(!mx_isdigit(temp_str_arr[1][j])) {
                close(fd);
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        }

        if (mx_strcmp(temp_str_arr[0], mx_strndup(temp_str_arr[1], mx_get_char_index(temp_str_arr[1] ,','))) == 0) {
            close(fd);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }

        mx_del_strarr(&temp_str_arr);
    }

    char **check_arr = create_vertex_arr(temp_str, (size_strarr(strarr) * 2));

    if (size_strarr(check_arr) != mx_atoi(strarr[0])) {
        close(fd);
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }

    mx_strdel(&temp_str);
    mx_del_strarr(&strarr);
    mx_del_strarr(&check_arr);
    
    close(fd);
}
