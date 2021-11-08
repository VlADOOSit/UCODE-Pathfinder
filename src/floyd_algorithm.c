#include "pathfinder.h"

void algorithm(int ***w, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((*w)[i][j] != 999999) {
                for (int k = 0; k < size; k++) {
                    if (((*w)[i][k] > (*w)[i][j] + (*w)[j][k] || (*w)[i][k] == 999999) && (*w)[j][k] != 999999 && (i != k)) {
                        (*w)[i][k] = (*w)[i][j] + (*w)[j][k];
                    }
                }      
            }
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if ((*w)[i][j] == 999999) {
                (*w)[i][j] = 0;
            }
        }
    }
}
