#include <stdio.h>
#include <stdlib.h>

typedef struct NoQueue{
    int senha;
    struct NoQueue *prox;
} TNoQueue;

typedef struct Queue{
    struct NoQueue *inicio;
    struct NoQueue *fim;
} Fila;

void inicializar(Fila* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int isEmpty(Fila fila){
    if(fila.inicio == NULL && fila.fim == NULL){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Fila fila){
    return 0;
}

void enqueue(Fila* fila, int valor){
    TNoQueue* novo;
    novo = (TNoQueue*) malloc(sizeof(TNoQueue));

    novo->senha = valor;
    novo->prox = NULL;

    if(isEmpty(*fila) == 1){
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

int dequeue(Fila* fila){
    int valor;
    TNoQueue* aux;
    aux = (TNoQueue*)malloc(sizeof(TNoQueue));

    valor = fila->inicio->senha;
    aux = fila->inicio;

    fila->inicio = fila->inicio->prox;
    free(aux);

    if(fila->inicio == NULL){
        fila->fim == NULL;
    }

    return valor;
}

int head(Fila fila){
    return fila.inicio->senha;
}

void main(){
    int opcao, i= 1;
    Fila minhaFila;
    inicializar(&minhaFila);

    while(opcao != 0){
        printf("Deseja entrar na fila ?\n");
        printf("1 - Sim\n2 - Nao");
        scanf("%d",&opcao);
        if(isFull(minhaFila) == 0){
            enqueue(&minhaFila, i);
            i++;
        }
        if(isEmpty(minhaFila) == 0){
            printf("Proximo na fila : %d\n", head(minhaFila));
            printf("Senha %d por favor venha ao guiche\n",dequeue(&minhaFila));
        } else {
            printf("Fila vazia !\n");
        }
    }
}