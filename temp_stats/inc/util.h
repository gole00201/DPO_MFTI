#ifndef UTIL
#define UTIL

#include <stdio.h>
#include <string.h>
#include <temp_functions.h>
#define FILE_PATH "-f"
#define MOUNTH    "-m"
#define HELP      "-h"


/**
 * @brief Струткутра сосстояния программы
 */
typedef struct SCOPE_t
{
    /**
     * @brief Путь к файлу с данными
     */
    char** csv_path;
    /**
     * @brief Необходимый месяц для рассчета
     */
    int need_mouth;

    /**
     * @brief Прочитанные данные (массив)
     */
    DATA_ROW_t* data;

    /**
     * @brief Количество записей
     */
    int data_cnt;

}SCOPE_t;

/**
 * @brief Парсер аргументов командной строки
 * @param argc
 * @param argv
 * @param state структура хронящая состояние программы на инициации
 * @return int 0 - файл найден , 1 - не найден файл
 */
int parse_args(int argc, char** argv, SCOPE_t* state);

/**
 * @brief Вывод использования программы
 */
void usage();


#endif