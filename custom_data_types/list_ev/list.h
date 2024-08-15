#ifndef LIST_H
#define LIST_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LTYPE
    #define LTYPE int
#endif

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



#define APPEND_L(list, val) list_append(&(list), (val))

#define POP_L(list) list_pop(&(list))

#define MAX_L(list) list_max(&(list))

#define MIN_L(list) list_min(&(list))

#define FREE_L(list) free_list(&(list))

#endif // LIST_H