#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Определение типа для функций
typedef double (*func)(double);

// Уравнения
double f1(double x) { return 0.6 * x + 3; }
double f2(double x) { return pow(x - 2, 3) - 1; }
double f3(double x) { return 3 / x; }

// Функция нахождения корня уравнения f(x) = g(x) на отрезке [a, b]
int find_root(func f, func g, double a, double b, double eps, double *root, int *iterations) {
    double fa = f(a) - g(a);
    double fb = f(b) - g(b);

    if (fa * fb > 0) {
        return -1; // Нет корней или корни вне отрезка
    }

    *iterations = 0; // Инициализируем количество итераций

    while ((b - a) / 2 > eps) {
        (*iterations)++;
        double c = (a + b) / 2;
        double fc = f(c) - g(c);

        if (fabs(fc) < eps) {
            *root = c;
            return 0;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    *root = (a + b) / 2;
    return 0;
}

// Функция нахождения интеграла от функции f(x) на отрезке [a, b]
double integral(func f, double a, double b, double eps) {
    double sum = 0.0;
    int n = 1;
    double h = (b - a) / n;
    double prev_sum = 0.0;

    do {
        prev_sum = sum;
        sum = 0.0;
        for (int i = 0; i < n; i++) {
            double x1 = a + i * h;
            double x2 = x1 + h;
            sum += (f(x1) + f(x2)) * h / 2;
        }
        n *= 2;
        h = (b - a) / n;
    } while (fabs(sum - prev_sum) > eps);

    return sum;
}

// Функция обработки командной строки
void print_help() {
    printf("Usage: program [options]\n");
    printf("Options:\n");
    printf("  --help               Show help\n");
    printf("  --intersections      Print coordinates of intersection\n");
    printf("  --iterations         Print number of iterations\n");
    printf("  --test               Run tests for root and integral functions\n");
}

int main(int argc, char *argv[]) {
    double a = 0, b = 100.0; // Диапазон для поиска корней и интегралов
    double eps1 = 1e-6, eps2 = 1e-6; // Точности

    if (argc < 2) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "--intersections") == 0) {
        double root;
        int iterations;

        printf("Finding intersections...\n");

        if (find_root(f1, f2, a, b, eps1, &root, &iterations) == 0) {
            printf("Intersection of f1 and f2 at x = %f\n", root);
        } else {
            printf("No intersection found for f1 and f2 in the interval [%f, %f]\n", a, b);
        }

        if (find_root(f1, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Intersection of f1 and f3 at x = %f\n", root);
        } else {
            printf("No intersection found for f1 and f3 in the interval [%f, %f]\n", a, b);
        }

        if (find_root(f2, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Intersection of f2 and f3 at x = %f\n", root);
        } else {
            printf("No intersection found for f2 and f3 in the interval [%f, %f]\n", a, b);
        }
    } else if (strcmp(argv[1], "--iterations") == 0) {
        double root;
        int iterations;

        if (find_root(f1, f2, a, b, eps1, &root, &iterations) == 0) {
            printf("Iterations to find intersection of f1 and f2: %d\n", iterations);
        } else {
            printf("Failed to find intersection of f1 and f2 in the interval [%f, %f]\n", a, b);
        }

        if (find_root(f1, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Iterations to find intersection of f1 and f3: %d\n", iterations);
        } else {
            printf("Failed to find intersection of f1 and f3 in the interval [%f, %f]\n", a, b);
        }

        if (find_root(f2, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Iterations to find intersection of f2 and f3: %d\n", iterations);
        } else {
            printf("Failed to find intersection of f2 and f3 in the interval [%f, %f]\n", a, b);
        }
    } else if (strcmp(argv[1], "--test") == 0) {
        double root;
        int iterations;

        if (find_root(f1, f2, a, b, eps1, &root, &iterations) == 0) {
            printf("Intersection of f1 and f2 at x = %f\n", root);
        } else {
            printf("No intersection of f1 and f2 found\n");
        }

        if (find_root(f1, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Intersection of f1 and f3 at x = %f\n", root);
        } else {
            printf("No intersection of f1 and f3 found\n");
        }

        if (find_root(f2, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Intersection of f2 and f3 at x = %f\n", root);
        } else {
            printf("No intersection of f2 and f3 found\n");
        }

        printf("Integral of f1 from %f to %f: %f\n", a, b, integral(f1, a, b, eps2));
        printf("Integral of f2 from %f to %f: %f\n", a, b, integral(f2, a, b, eps2));
        printf("Integral of f3 from %f to %f: %f\n", a, b, integral(f3, a, b, eps2));
    } else {
        print_help();
        return 1;
    }

    return 0;
}
