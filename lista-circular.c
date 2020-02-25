#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int chave;
    struct item * prox;
} ITEM;

typedef struct listaCircular{
    int tamanho;
    ITEM * inicio;
    ITEM * fim;
} LISTACIRCULAR;

LISTACIRCULAR* criarLista(){

    LISTACIRCULAR* listaCircular = (LISTACIRCULAR*) malloc(sizeof(LISTACIRCULAR));
    (*listaCircular).tamanho = 0;
    (*listaCircular).inicio = NULL;
    (*listaCircular).fim = NULL;

    return listaCircular;
}

void inserirListaInicio(LISTACIRCULAR* listaCircular){

    ITEM* novoItem = (ITEM*)malloc(sizeof(ITEM));
    scanf("%d", &((*novoItem).chave));

    if((*listaCircular).tamanho == 0){
        (*listaCircular).tamanho++;
        (*listaCircular).inicio = novoItem;
        (*listaCircular).fim = novoItem;
        (*novoItem).prox = novoItem;
    }
    else{
        (*listaCircular).tamanho++;
        (*novoItem).prox = (*listaCircular).inicio;
        (*((*listaCircular).fim)).prox = novoItem;
        (*listaCircular).inicio = novoItem;
    }
}

void inserirListaFinal(LISTACIRCULAR* listaCircular){

    ITEM* novoItem = (ITEM*)malloc(sizeof(ITEM));
    scanf("%d", &((*novoItem).chave));

    if((*listaCircular).tamanho == 0){
        (*listaCircular).tamanho++;
        (*listaCircular).inicio = novoItem;
        (*listaCircular).fim = novoItem;
        (*novoItem).prox = novoItem;
    }
    else{
        (*listaCircular).tamanho++;
        (*novoItem).prox = (*listaCircular).inicio;
        (*((*listaCircular).fim)).prox = novoItem;
        (*listaCircular).fim = novoItem;
    }
}

int removerListaInicio(LISTACIRCULAR* listaCircular){

    int chaveDoItemRemovido;

    if((*listaCircular).tamanho == 0){
        printf("\nLista vazia, nao ha o que remover\n");
        return -1;
    }
    else if((*listaCircular).tamanho == 1){

        chaveDoItemRemovido = (*((*listaCircular).inicio)).chave;

        (*listaCircular).inicio = NULL;
        (*listaCircular).fim = NULL;

        (*listaCircular).tamanho--;

        return chaveDoItemRemovido;
    }
    else{
        chaveDoItemRemovido = (*((*listaCircular).inicio)).chave;

        (*listaCircular).inicio = (*((*listaCircular).inicio)).prox;
        (*((*listaCircular).fim)).prox = (*listaCircular).inicio;

        (*listaCircular).tamanho--;
        chaveDoItemRemovido = (*((*listaCircular).fim)).chave;

        return chaveDoItemRemovido;
    }
}

int removerListaFinal(LISTACIRCULAR* listaCircular){

    int chaveDoItemRemovido;
    ITEM* enderecoItemRemovido;
    ITEM* temp;
    ITEM* aux;

        if((*listaCircular).tamanho == 0){
        printf("Lista vazia, nao ha o que remover");
        return -1;
    }
    else if((*listaCircular).tamanho == 1){

        chaveDoItemRemovido = (*((*listaCircular).fim)).chave;

        (*listaCircular).inicio = NULL;
        (*listaCircular).fim = NULL;

        (*listaCircular).tamanho--;

        return chaveDoItemRemovido;
    }
    else{

        chaveDoItemRemovido = (*((*listaCircular).fim)).chave;

        ITEM* enderecoItemRemovido = (*listaCircular).fim;

        temp = (*listaCircular).inicio;

        while(temp != enderecoItemRemovido){
            aux = temp;
            temp = (*temp).prox;
        }

        (*aux).prox = (*listaCircular).inicio;
        (*listaCircular).fim = aux;

        return chaveDoItemRemovido;

    }
}

void percorrerListaCircular(LISTACIRCULAR* listaCircular){
    ITEM* temp = (*listaCircular).inicio;

    int contador = 1;

    while(contador < 20){
        printf("a chave%d\n", (*temp).chave);
        temp = (*temp).prox;
        contador++;
    }
}

int main(){
    LISTACIRCULAR* listaCircular = criarLista();

    inserirListaFinal(listaCircular);
    inserirListaInicio(listaCircular);
    inserirListaInicio(listaCircular);
    inserirListaFinal(listaCircular);
    inserirListaFinal(listaCircular);

    removerListaInicio(listaCircular);
    removerListaFinal(listaCircular);

    percorrerListaCircular(listaCircular);
}
