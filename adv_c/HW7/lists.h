/**
 * @file lists.h
 * @author Volkov Egor
 * @brief Библиотека односвязных списков и текста на односвязном списке.
 * Посчитал что нужно просто сделать это один раз и больше не возиться с этим в будущем.
 * @version 0.1
 * @date 2024-08-25
 * @copyright Copyright (c) 2024
 */

#ifndef LIST_H
#define LIST_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef LTYPE
    #define LTYPE int
#endif

#ifndef LTYPE_f
    #define LTYPE_f "%d"
#endif

#define TEXT_LEN 1000
#define WORD_LEN 30
typedef struct Text_t{
    char word[WORD_LEN];
    struct Text_t *next;
} Text_t;


typedef struct List_t{
    LTYPE data;
    struct List_t *next;
} List_t;

List_t *list_get_last(List_t **head);
void list_append(List_t **head, LTYPE data);
void list_ini(List_t **head);
void free_list(List_t **head);
void list_insert(List_t **head, LTYPE data);
LTYPE list_get(List_t **head, size_t pos);
LTYPE list_pop(List_t **head);
LTYPE list_min(List_t **head);
LTYPE list_max(List_t **head);
void list_print(List_t *head);

void text_get_from(Text_t **head, FILE *input_stream);
/**
 * @brief Добавляем слово в конец списка
 * @param head
 * @param word
 * @return Text_t* указатель на добавленный нод
 */
Text_t *text_append(Text_t **head, const char *word);
void text_ini(Text_t **head);
/**
 * @brief Освобождаем текст
 * @param head
 */
void text_free(Text_t **head);
/**
 * @brief Функция сортировки текста
 * @param head список - текст
 * @param type_of_sort 'a' - алфовитный порядок, 'd' - обратный алфовитный порядок
 */
void text_sort(Text_t **head, char type_of_sort);
/**
 * @brief Функция что меняет местами слова в нодах текста
 * @param a первый нод
 * @param b второй нод
 */
void text_swap_words(Text_t *a, Text_t *b);
/**
 * @brief Выводит на экран текст
 * @param head
 */
void text_print(Text_t *head);

#define APPEND_L(list, val) list_append(&(list), (val))

#define POP_L(list) list_pop(&(list))

#define MAX_L(list) list_max(&(list))

#define MIN_L(list) list_min(&(list))

#define FREE_L(list) free_list(&(list))

/**
 * @brief [Макрос] Аппенда слова в текст
 */
#define TEXT_APPEND_L(list, val) text_append(&(list), (val))

/**
 * @brief [Макрос] Получение текста из файла
 */
#define TEXT_GET_FROM(list, input_stream) text_get_from(&(list), (input_stream))

/**
 * @brief [Макрос] Сортировка текста 'a'- алфовитный порядок, 'd' - обратный алфовитный порядок
 */
#define TEXT_SORT_L(list, sort_type) text_sort(&(list), (sort_type))

/**
 * @brief [Макрос] Осовобождение памяти текста
 */
#define TEXT_FREE_L(list) text_free(&(list))


/**
 * @brief [Макрос] Свап слов в тексте
 */
#define TEXT_SWAP_L(a, b) text_swap_words((a), (b))

/**
 * @brief [Макрос] Вывод текста на экран
 */
#define TEXT_PRINT_L(list) text_print((list))


#endif // LIST_H