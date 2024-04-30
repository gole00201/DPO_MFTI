/**
 * @file 7_num_sys.c
 * @author Volkov Egor
 * @brief Перевод чисел в систему счисления
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void decimalToBase(int N, int P) {
    // Базовый случай: если число N равно 0, завершаем рекурсию
    if (N == 0) {
        return;
    }

    int remainder = N % P;
    // Рекурсивный вызов для оставшейся части числа N
    decimalToBase(N / P, P);

    // Вывод текущей цифры
    printf("%c", (remainder < 10) ? remainder + '0' : remainder - 10 + 'A');
}

int main() {
    int N, P;
    // Ввод чисел N и P
    scanf("%d %d", &N, &P);

    // Проверка на корректность ввода
    if (N < 0 || P < 2 || P > 9) {
        printf("Invalid input\n");
        return 1; // Возвращаем код ошибки
    }

    // Обработка случая, когда N равно 0 (вывод "0")
    if (N == 0) {
        printf("0\n");
    } else {
        // Перевод числа N из десятичной системы в P-ичную
        decimalToBase(N, P);
    }

    return 0; // Успешное завершение программы
}
