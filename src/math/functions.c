#include <stdlib.h>

int mathRand12d() {
    int num;
    num = (int)rand() * RAND_MAX;

    return num;
}