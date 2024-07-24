#include <stdio.h>
#include <stddef.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

/*
 * Функция total_memory_usage вычисляет общее количество
 * используемой памяти в списке.
 * Если список пуст, возвращает 0.
 */
size_t total_memory_usage(list *head) {
    size_t total_size = 0;
    list *current = head;

    while (current != NULL) {
        total_size += current->size;
        current = current->next;
    }

    return total_size;
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

    size_t total_memory = total_memory_usage(head);
    printf("Total memory usage: %zu bytes\n", total_memory);


    list *current = head;
    while (current != NULL) {
        list *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
