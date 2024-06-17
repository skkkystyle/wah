#include <stdio.h>

#include "inc/test_funcs.h" // тест-функции
#include "inc/root.h" // функция подсчета корня методом касательных
#include "inc/integral.h" // функция подсчета интеграла по формуле трапеций

unsigned counter = 0; // счетчик количества тестов
void checker(float computed, float real) { // функция-чекер, сравнивает два флота от начала и до 0.001
    printf("::::::TEST_%u::::::", counter);
    counter++;

    char comp_str[10], real_str[10];
    sprintf(comp_str, "%.3f", computed);
    sprintf(real_str, "%.3f", real);

    unsigned i = 0;
    while (comp_str[i] != '.') {
        if (comp_str[i] != real_str[i]) {
            printf(" NON-LEGIT\n");
            return;
        }
        i++;
    }

    for (int j = 1; j < 4; j++) {
        if (comp_str[i + j] != real_str[i + j]) {
            printf(" NON-LEGIT\n");
            return;
        }
    }
    printf(" LEGIT\n");
}


int main(void) {
    double eps1 = 0.0001, r12, r13, r23, i1, i2, i3, res; // вычисляемые программой значения
    double rr12 = 1.25175793, rr13 = -2.3905367, rr23 = -0.54950975; // значения из MathWay
    double ri1 = 10.68941649, ri2 = 13.14519805, ri3 = 7.35116337, rres = 9.80694493;

    r12 = root(tfunc(1), tfunc(2), tfunc(11), tfunc(22), 1, 2, eps1);
    r13 = root(tfunc(1), tfunc(3), tfunc(11), tfunc(33), -2.7, -2.1, eps1);
    r23 = root(tfunc(2), tfunc(3), tfunc(22), tfunc(33), -1, -0.1, eps1);

    i1 = integral(tfunc(1), r13, r12, eps1);
    i2 = integral(tfunc(2), r23, r12, eps1);
    i3 = integral(tfunc(3), r13, r23, eps1);

    res = i3 + i2 - i1;

    checker(r12, rr12);
    checker(r13, rr13);
    checker(r23, rr23);
    checker(i1, ri1);
    checker(i2, ri2);
    checker(i3, ri3);
    checker(res, rres);
}