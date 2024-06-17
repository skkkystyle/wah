// реализация функции вычисления корня методом касательных

#include "../inc/root.h"

#include <math.h>
#include <stdio.h>

unsigned iter = 0; // счетчик количества итераций
double root(afunc *f, afunc *g, afunc *ff, afunc *gg, double a, double b, double eps1) {
    double x0 = (a + b) / 2, delta = f(x0) - g(x0), ddelta = ff(x0) - gg(x0), x1;

    while (fabs(delta > eps1)) {
        iter++;
        // возврат ошибки если происходит деление на ноль
        if (fabs(ddelta) < eps1) {
            printf("Error zero division\n");
            return NAN;
        }

        x1 = x0 - delta / ddelta;
        // возврат ошибки если произошел выход за границы отрезка
        if (x1 < a || x1 > b) {
            printf("Error out of bounds\n");
            return NAN;
        }
        // условие выхода и возврата корня
        if (fabs(x1 - x0) < eps1) {
            return x1;
        }

        x0 = x1;
        delta = f(x0) - g(x0);
        ddelta = ff(x0) - gg(x0);
    }
    return x0;
}