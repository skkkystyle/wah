// header функции вычисления корня методом касательных

#ifndef ROOT_H
#define ROOT_H

#include "afunc.h"

extern unsigned iter; // счетчик количества итераций
double root(afunc *f, afunc *g, afunc *ff, afunc *gg, double a, double b, double eps1);

#endif //ROOT_H
