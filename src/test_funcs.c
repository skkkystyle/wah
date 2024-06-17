// реализация функции доступа к тест-функциям

#include "../inc/test_funcs.h"

#include <math.h>
#include <stdio.h>

// (e ^ x) + 2
double tfunc_1(double x) {
    return exp(x) + 2;
}

// -2 * x + 8
double tfunc_2(double x) {
    return -2 * x + 8;
}

// -5 / x
double tfunc_3(double x) {
    return -5 / x;
}

// e ^ x
double dtfunc_1(double x) {
    return exp(x);
}

// -2
double dtfunc_2(double x) {
    return -2;
}

// 5 / x ^ 2
double dtfunc_3(double x) {
    return (5 / x) / x;
}

extern afunc *tfunc(unsigned const num) {
    switch (num) {
        case 1:
            return tfunc_1;
        case 2:
            return tfunc_2;
        case 3:
            return tfunc_3;
        case 11:
            return dtfunc_1;
        case 22:
            return dtfunc_2;
        case 33:
            return dtfunc_3;
        default:
            return NULL;
    }
}