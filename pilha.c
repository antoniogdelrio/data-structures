#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int chave;
    struct item *prox;
} ITEM;

typedef struct pilha{
    int tamanho;
    ITEM *topo;
} PILHA;

PILHA* criarPilha(){

    PILHA *pilha = (PILHA*)malloc(sizeof(PILHA));
    (*pilha).tamanho = 0;
    (*pilha).topo = NULL;
    return pilha;

}

void empilhar(PILHA **pilha){
    ITEM *novo = (ITEM*)malloc((sizeof(ITEM)));

    scanf("%d", &((*novo).chave));
    (**pilha).tamanho++;
    (*novo).prox = (**pilha).topo;

    (**pilha).topo = novo;
}

int desempilhar(PILHA **pilha){

    puts("...Desempilhando...");

    int chaveItemDesempilhado;

    chaveItemDesempilhado = (*((**pilha).topo)).chave;
    (**pilha).tamanho--;
    (**pilha).topo = (*((**pilha).topo)).prox;

    return chaveItemDesempilhado;

}

void mostrarPilha(PILHA *pilha){

    ITEM *temp = (*pilha).topo;
    printf("\n\n\tMostrando pilha de tamanho %d\n\n", (*pilha).tamanho);
    while((*temp).prox != NULL){
        printf("chave %d\n", (*temp).chave);
        temp = (*temp).prox;
    }
    printf("chave %d", (*temp).chave);

}

int main(){

    PILHA *pilha = criarPilha();

    empilhar(&pilha);
    empilhar(&pilha);
    empilhar(&pilha);
    empilhar(&pilha);
    empilhar(&pilha);
    printf("Chave do item desempilhado: %d\n", desempilhar(&pilha));
    mostrarPilha(pilha);

}
