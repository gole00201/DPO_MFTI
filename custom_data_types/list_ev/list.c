#include "list.h"

List_t *list_get_last(List_t **head){
    if (head == NULL || *head == NULL) {
        return NULL; // Список пуст
    }
    List_t *current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}

void list_ini(List_t **head){
    *head = NULL;
}

void list_append(List_t **head, LTYPE data){
    List_t *node = malloc(sizeof(List_t));
    if(node == NULL){
        fprintf(stderr, "Malloc fail, buy more RAM: %d %s\n", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    if(*head == NULL){
        *head = node;
    } else {
        List_t *last = list_get_last(head);
        last->next = node;
    }
}

void list_insert(List_t **head, LTYPE data){
    List_t *node = malloc(sizeof(List_t));
    if(node == NULL){
        fprintf(stderr, "Malloc fail, buy more RAM: %d %s\n", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = *head;
    *head = node;
}

LTYPE list_pop(List_t **head) {
    if (head == NULL || *head == NULL) {
        return (LTYPE)0;
    }

    List_t *current = *head;
    List_t *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    LTYPE data = current->data;
    free(current);

    return data;
}

LTYPE list_get(List_t **head, size_t pos){
    if (head == NULL || *head == NULL){
        fprintf(stderr, "List is empty: %d %s\n", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    List_t *current = *head;
    for (size_t i = 0; i < pos; i++){
        if (current == NULL){
            fprintf(stderr, "List out of bounds: %d %s\n", __LINE__, __FILE__);
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }
    if (current == NULL){
        fprintf(stderr, "List out of bounds: %d %s\n", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    return current->data;
}

LTYPE list_max(List_t **head){
    if (head == NULL || *head == NULL){
        fprintf(stderr, "List is empty: %d %s\n", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    List_t *current = *head;
    LTYPE max = current->data;
    while(current->next != NULL){
        current = current->next;
        if(current->data > max){
            max = current->data;
        }
    }
    return max;
}

LTYPE list_min(List_t **head){
    if (head == NULL || *head == NULL){
        fprintf(stderr, "List is empty: %d %s\n", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    List_t *current = *head;
    LTYPE min = current->data;
    while(current->next != NULL){
        current = current->next;
        if(current->data < min){
            min = current->data;
        }
    }
    return min;
}

void free_list(List_t **head){
    if (head == NULL || *head == NULL) {
        return;
    }
    List_t *current = *head;
    List_t *next_node = NULL;
    while(current != NULL){
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}