#include "lists.h"


int main(int argc, char *argv[]) {
    Text_t *head;
    text_ini(&head);
    TEXT_GET_FROM(head, stdin);
    TEXT_SORT_L(head, 'a');
    TEXT_PRINT_L(head);
    TEXT_FREE_L(head);
    return 0;
}
