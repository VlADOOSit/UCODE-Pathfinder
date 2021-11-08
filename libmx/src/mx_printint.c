#include "libmx.h"

void mx_printint(int n) {
    int flag = 1;
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (n == 0) {
        mx_printchar('0');
        return;
    }
    if (n < 0) {
        flag = 0;
        n *= -1;
    }
    int temp = n;
    int counter = 0;
    while(temp != 0) {
        temp = temp / 10;
        counter++;
    }
    int array[counter];
    int count_mass = 0;
    while(n != 0) { 
        array[count_mass] = n % 10;
        n /= 10;
        count_mass++;
    }
    if (flag == 0) {
        mx_printchar('-');
    }
    for(int j = count_mass - 1; j >= 0; j--) {
        mx_printchar(array[j] + 48);
    }
}
