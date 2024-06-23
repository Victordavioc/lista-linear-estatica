#include "list.h"
#include <stdio.h>
int main() {
    List * A = list_new(4);

    list_info(A);

    list_insert(A,4);
    list_insert(A,10);
    list_insert(A,2);
    list_insert(A,7);
    list_expand(A, 8);

    list_insert(A,20);

    list_info(A);
    list_insert(A, 23);
    list_remove(A, 4);
    
    list_info(A);
    
    list_reduce(A);
    
    list_info(A);
    list_free(A);
    
    return 0;
}
