#include <stdio.h>
#include <stdlib.h>

typedef struct noLDE{
    struct noLDE *anterior;
    int info;
    struct noLDE *prox;
}TNoLDE;

typedef struct lde{
    TNoLDE *inicio;
    TNoLDE *fim;
    int qntd;
}LDE;

void inicializar(LDE *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qntd = 0;
}

int isFull(LDE lista){
    return 0;
}

int isEmpty(LDE lista){
    if(lista.qntd == 0){
        return 1;
    }else {
        return 0;
    }
}

void list(LDE lista){
    TNoLDE* aux;

    aux = lista.inicio;
    if(isEmpty(lista) == 1){
        printf("Lista vazia \n");
    } else {
        while(aux != NULL){
            printf("%d ",aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void inserir(LDE *lista, int valor){
    
}

void main(){
    LDE minhaLista;
    int num;
    inicializar(&minhaLista);

}


