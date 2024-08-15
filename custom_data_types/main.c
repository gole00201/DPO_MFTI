#include "list_ev/list.h"

int
main( void ){
    List_t *list;
    list_ini(&list);
    APPEND_L(list, 10);
    APPEND_L(list, 20);
    printf("%d\n", MAX_L(list));
    FREE_L(list);
    return 0;
}