#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int chave;
    struct item * prox;
} ITEM;

typedef struct fila{
    ITEM* inicio;
    ITEM* fim;
    int tamanho;
} FILA;

FILA* criarFila(){
    FILA* fila = (FILA*)malloc(sizeof(FILA));
    (*fila).tamanho = 0;
    (*fila).inicio = NULL;
    (*fila).fim = NULL;

    return fila;
}

void enfileira(FILA* fila){

    ITEM* item = (ITEM*)malloc(sizeof(ITEM));

    scanf("%d", &((*item).chave));
    (*item).prox = NULL;
    if((*fila).tamanho == 0){
        (*fila).inicio = item;
    }
    else{
        (*((*fila).fim)).prox = item;
    }
    (*fila).fim = item;
    (*fila).tamanho++;
}

int desenfileira(FILA* fila){

    int chaveDoItemDesenfileirado = (*((*fila).inicio)).chave;

    (*fila).inicio = (*((*fila).inicio)).prox;

    printf("\n\t O item com chave %d foi desenfileirado\n", chaveDoItemDesenfileirado);

    return chaveDoItemDesenfileirado;

}

void mostrarFila(FILA* fila){

    ITEM* temp = (*fila).inicio;

    while((*temp).prox != NULL){
        printf("chave %d\n", (*temp).chave);
        temp = (*temp).prox;
    }
    printf("chave %d\n", (*temp).chave);
}

int main(){
    FILA* fila = criarFila();

    enfileira(fila);
    enfileira(fila);
    enfileira(fila);
    desenfileira(fila);
    mostrarFila(fila);

}
