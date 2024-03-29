#include <stdio.h>
#include <stdlib.h>

typedef struct noQueue{
    int info;
    struct noQueue* prox;
} TNoQueue;

typedef struct queue{
    TNoQueue* inicio;
    TNoQueue* fim;
} Queue;

void inicializar(Queue* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int isFull(Queue fila){
    return 0;
    //uma fila encadeada nunca fica cheia
}

int isEmpty(Queue fila){
    if (fila.inicio == NULL && fila.fim == NULL){
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue* fila, int valor){
    TNoQueue* novo;
    TNoQueue* aux;
    novo = (TNoQueue*) malloc(sizeof(TNoQueue));

    novo->info = valor;
    novo->prox = NULL;

    if(isEmpty(*fila) == 1){
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

int dequeue(Queue* fila){
    int valor;
    TNoQueue* aux;

    valor = fila->inicio->info;
    aux  = fila->inicio;

    fila->inicio = fila->inicio->prox;
    free(aux);

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return valor;
}

int head(Queue fila){
    return fila.inicio->info;
}

void exibirMenu(){
    printf("1 - Enqueue \n");
    printf("2 - Dequeue \n");
    printf("3 - Head \n");
    printf("0 - Encerrar programa \n");
    printf("Insira a opcao que deseja : \n");
}

void main(){
    int escolha, valor;
    Queue minhaFila;
    inicializar(&minhaFila);
    while(escolha != 0){
        exibirMenu();
        scanf("%d",&escolha);

        switch(escolha){
            case 1 :
                //desenvolvendo
                printf("Insira o valor a ser enfileirado: ");
                scanf("%d",valor);
                enqueue(&minhaFila, valor);
                break;
            case 2 :
                //desenvolvendo
                if(isEmpty(minhaFila) == 1){
                    printf("Fila vazia ! \n");
                } else {
                    dequeue(&minhaFila);
                }
                break;
            case 3 :
                //desenvolvendo
                printf("Cabeça da fila : %d",head(minhaFila));
                break;
            case 0 :
                //desenvolvendo
                break;
        }
    }
}