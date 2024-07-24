#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

/*
 * Функция find_max_block находит адрес блока памяти,
 * занимающего наибольшее количество места в списке.
 * Если список пуст, возвращает NULL.
 */
void *find_max_block(list *head) {
    if (head == NULL) {
        return NULL;
    }

    void *max_address = head->address;
    size_t max_size = head->size;
    list *current = head->next;

    while (current != NULL) {
        if (current->size > max_size) {
            max_size = current->size;
            max_address = current->address;
        }
        current = current->next;
    }

    return max_address;
}

/*
 * Функция append добавляет новый элемент в конец списка.
 * Возвращает новый узел или NULL в случае ошибки.
 */
list *append(list **head, void *address, size_t size, const char *comment) {
    list *new_node = malloc(sizeof(list));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->address = address;
    new_node->size = size;
    strncpy(new_node->comment, comment, sizeof(new_node->comment) - 1);
    new_node->comment[sizeof(new_node->comment) - 1] = '\0';
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        list *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

int main() {
    list *head = NULL;

    append(&head, (void *)1000, 10, "Block 1");
    append(&head, (void *)2000, 50, "Block 2");
    append(&head, (void *)3000, 20, "Block 3");

    void *max_block = find_max_block(head);
    if (max_block != NULL) {
        printf("Address of the largest block: %p\n", max_block);
    } else {
        printf("The list is empty.\n");
    }

    list *current = head;
    while (current != NULL) {
        list *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
