#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_info(List * L) {
    printf("Tamanho maximo: %d\n", L->size);
    printf("Quantidade de elementos: %d\n", L->n);
    printf("Ponteiro do vetor: %p\n", L->e);
    list_print(L);
    printf("\n------------------------------------\n");
    
}

List * list_new( int size ) {
    List * L = NULL;
    L = (List *)calloc(1, sizeof(List));
    L->n = 0;
    L->e = (int*)calloc(size, sizeof(int) );
    L->size = size;
    return L;
}

void list_free( List * L ) {
    free(L->e);
    free(L);
}

void list_insert( List * L, int v ) {
    if(L->n < L->size) {
        L->e[L->n] = v;
        (L->n)++;
    }
}

void list_print( List * L ) {
    int i;
    printf("[");
    for(i=0;i<L->n;i++) {
        printf("%d, ", L->e[i]);
    }
    printf("]\n");
}

void list_expand( List * L, int new_size ) {
    L->e = realloc( L->e, sizeof(int) * new_size );
    L->size = new_size;
}

void list_reduce(List *L) {
    if (L->n < L->size) {
        L->e = realloc(L->e, L->n * sizeof(int));
        if (L->e == NULL) {
            printf("Erro ao realocar memória.\n");
            exit(1);
        }
        L->size = L->n;
    }
}
void list_remove(List *L, int pos) {
    // Verificar se a posição é válida
    if (pos < 0 || pos >= L->n) {
        return;
    }
    // Remover o elemento deslocando os subsequentes
    for (int i = pos; i < L->n - 1; i++) {
        L->e[i] = L->e[i + 1];
    }
    // Reduzir o número de elementos
    L->n--;
}


