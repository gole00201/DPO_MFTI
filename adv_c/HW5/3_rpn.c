#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Необходимо вычислить выражение написанное в обратной польской записи.
На вход подается строка состоящая из целых, не отрицательных чисел и арифметических символов.
В ответ единственное целое число - результат. Более подробно об Обратной польская запись числа можно также почитать тут
Формат ввода:
Строка состоящая из целых чисел и символов '+', '-', '*', '/', ' '.
В конце строки символ '.'. Строка корректная. Длина строки не превосходит 1000 символов.
Все числа и операции разделены ровно одним пробелом. */



#define MAX_STACK_SIZE 1000


int stack[MAX_STACK_SIZE];
int top = -1;


void push(int value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    }
}


int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;
}

/* Какая-то микро ВМ получается =) */
int eval(char *expression) {
    char *token = strtok(expression, " ");

    while (token != NULL && token[0] != '.') {
        if (isdigit(token[0])) {

            push(atoi(token));
        } else {

            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                default:
                    result = 0;
                    break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expression[1001];


    fgets(expression, sizeof(expression), stdin);


    int result = eval(expression);

    printf("%d\n", result);

    return 0;
}
