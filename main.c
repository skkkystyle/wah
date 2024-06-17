#include <stdio.h>
#include <getopt.h>
#include <math.h>

#include "inc/root.h" // функция подсчета корня методом касательных
#include "inc/integral.h" // функция подсчета интеграла по формуле трапеций


void help() { // функция отображения текстового окна помощи
    printf("Usage: ./integral [options]\n");
    printf("Options:\n");
    printf("  --help, -h            Show this help message\n");
    printf("  --root, -r            Print the roots of the equations\n");
    printf("  --iterations, -i      Print the number of iterations needed\n");
    printf("  --test-root, -R arg   Test the root function with parameters F1:F2:A:B:E:R\n");
    printf("  --test-integral, -I arg Test the integral function with parameters F:A:B:E:R\n");
}


int main(int argc, char *argv[]) {
    int opt, opt_i = 0;
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"root", no_argument, 0, 'r'},
        {"iterations", no_argument, 0, 'i'},
        {"test-root", required_argument, 0, 'R'},
        {"test-integral", required_argument, 0, 'I'},
        {0, 0, 0, 0}
    };

    double eps1 = 0.000034, r1_2, r1_3, r2_3, a, b;

    while ((opt = getopt_long(argc, argv, "hriR:I:", long_options, &opt_i)) != -1) {
        switch (opt) {
            case 'h':
                help();
                return 0;
            case 'r':
                r1_2 = root(func(1), func(2), func(11), func(22), 0, 3, eps1);
                r1_3 = root(func(1), func(3), func(11), func(33), -0.5, 1, eps1);
                r2_3 = root(func(2), func(3), func(22), func(33), 0.1, 0.3, eps1);
                printf("%f %f %f\n", r1_2, r1_3, r2_3);
                return 0;
            case 'i':
                r1_2 = root(func(1), func(2), func(11), func(22), 0, 3, eps1);
                r1_3 = root(func(1), func(3), func(11), func(33), -0.5, 1, eps1);
                r2_3 = root(func(2), func(3), func(22), func(33), 0.1, 0.3, eps1);
                printf("%u\n", iter);
                return 0;
            case 'R': {
                unsigned f, g;
                double ans, res, abs_err, rel_err;
                sscanf(optarg, "%u:%u:%lf:%lf:%lf:%lf", &f, &g, &a, &b, &eps1, &ans);
                res = root(func(f), func(g), func(f * 11), func(g * 11), a, b, eps1);
                abs_err = fabs(res - ans);
                rel_err = fabs(abs_err / ans);
                printf("%f %f %f\n", res, abs_err, rel_err);
                return 0;
            }
            case 'I': {
                unsigned f;
                double eps2, ans, res, abs_err, rel_err;
                sscanf(optarg, "%u:%lf:%lf:%lf:%lf", &f, &a, &b, &eps2, &ans);
                res = integral(func(f), a, b, eps2);
                abs_err = fabs(res - ans);
                rel_err = fabs(abs_err / ans);
                printf("%f %f %f\n", res, abs_err, rel_err);
                return 0;
            }
            default:
                printf("Wrong command, let's see what you can use:\n");
                help();
                return 0;
        }
    }

    r1_2 = root(func(1), func(2), func(11), func(22), 0, 3, eps1);
    r1_3 = root(func(1), func(3), func(11), func(33), -0.5, 1, eps1);
    r2_3 = root(func(2), func(3), func(22), func(33), 0.1, 0.3, eps1);
    double res = integral(func(1), r1_3, r1_2, eps1) - integral(func(3), r1_3, r2_3, eps1) - integral(func(2), r2_3, r1_2, eps1);
    printf("%f\n", res);
    return 0;
}
