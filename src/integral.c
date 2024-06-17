// реализация функции вычисления интеграла по формуле трапеций

#include "../inc/integral.h"

#include <math.h>

double integral(afunc f, double a, double b, double eps2) {
    int n = 2;
    double h = (b - a) / n, sum = (f(a) + f(b)) / 2, res = h, oldres;

    for (int i = 1; i < n; i++) {
        sum = sum + f(a + i * h);
    }

    res = res * sum;

    do {
        oldres = res;
        n = n * 2;
        h = h / 2;
        double delta = 0;

        for (int i = 1; i < n; i = i + 2) {
            delta = delta + f(a + i * h);
        }

        sum = sum + delta;
        res = sum * h;
    } while (fabs(res - oldres) / 3 >= eps2); // условие остановки и гарантия точности вычислений

    return res;
}