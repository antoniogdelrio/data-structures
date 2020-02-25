#include <stdio.h>
#include <stdlib.h>

struct item{
    int chave;
    struct item *prox;
};

void inserirDados(struct item **lista){

    struct item *novoItem = (struct item*)malloc(sizeof(struct item));

    scanf("%d", &((*novoItem).chave));

    (*novoItem).prox = *lista;
    *lista = novoItem;

}

void percorreLista(struct item *lista){

    struct item *temp = lista;

    while((*temp).prox != NULL){
        printf("chave %d\n", (*temp).chave);
        temp = (*temp).prox;
    }
    printf("chave %d\n", (*temp).chave);

}

int main(){

    struct item *lista = NULL;

    inserirDados(&lista);
    inserirDados(&lista);
    inserirDados(&lista);
    inserirDados(&lista);

    percorreLista(lista);

}
