#include "libmx.h"

char *mx_itoa(int number) {
    char *result = NULL;
    int len = 0;
    int flag = 0;

    if (number == 0) {
        return "0";
    }
    if (number == -2147483648) {
        return "-2147483648";
    }
    if (number < 0) {
        number *= -1;
        flag = 1;
    }

    int temp_number = number;

    while (temp_number != 0) {
        temp_number /= 10;
        len++;
    }

    if (flag == 0) {
        result = mx_strnew(len);
        
    }
    else {
        result = mx_strnew(len + 1);
    }
    
    for (int i = 0; i < len; i++) {
        result[i] = (number % 10) + 48;
        number /= 10;
    }
    if (flag == 1) {
        result[len] = '-';
    }

    mx_str_reverse(result);
    return result;
}
