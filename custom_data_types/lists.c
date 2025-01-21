#include "lists.h"

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

void list_print(List_t *head){
    List_t *current = head;
    while (current != NULL) {
        printf(LTYPE_f, current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
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


Text_t *text_append(Text_t **head, const char *word) {
    Text_t *new_node = (Text_t *)malloc(sizeof(Text_t));
    if (new_node == NULL) {
        fprintf(stderr, "Malloc failed, not enough memory: %d %s\n", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->word, word, WORD_LEN - 1);
    new_node->word[WORD_LEN - 1] = '\0';  // Защита от переполнения строки
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Text_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

void text_ini(Text_t **head) {
    *head = NULL;
}

void text_free(Text_t **head) {
    Text_t *current = *head;
    Text_t *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}

void text_sort(Text_t **head, char type_of_sort) {
    if (*head == NULL) return;

    int swapped;
    Text_t *ptr1;
    Text_t *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            int cmp = strcmp(ptr1->word, ptr1->next->word);
            if ((type_of_sort == 'a' && cmp > 0) || (type_of_sort == 'd' && cmp < 0)) {
                text_swap_words(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void text_swap_words(Text_t *a, Text_t *b) {
    char temp[WORD_LEN];
    strncpy(temp, a->word, WORD_LEN);
    strncpy(a->word, b->word, WORD_LEN);
    strncpy(b->word, temp, WORD_LEN);
}

void text_print(Text_t *head){
    Text_t *current = head;
    while (current != NULL) {
        printf("%s", current->word);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void text_get_from(Text_t **head, FILE *input_stream) {
    char input[TEXT_LEN];

    if (fgets(input, sizeof(input), input_stream) != NULL) {
        // TODO Избавиться от этого на релизе
        input[strcspn(input, ".")] = '\0';
        char *word = strtok(input, " ");
        while (word != NULL) {
            TEXT_APPEND_L(*head, word);
            word = strtok(NULL, " ");
        }
    }
}