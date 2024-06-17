// реализация функции доступа к функциям из варианта №9

#include "../inc/afunc.h"

#include <stdio.h>

// функции и производные из functions.asm
extern double func_1(double);
extern double func_2(double);
extern double func_3(double);
extern double dfunc_1(double);
extern double dfunc_2(double);
extern double dfunc_3(double);

extern afunc *func(unsigned const num) {
    switch (num) {
        case 1:
            return func_1;
        case 2:
            return func_2;
        case 3:
            return func_3;
        case 11:
            return dfunc_1;
        case 22:
            return dfunc_2;
        case 33:
            return dfunc_3;
        default:
            return NULL;
    }
}