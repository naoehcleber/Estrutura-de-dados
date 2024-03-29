#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10;

typedef struct queue{
    int dados[10];
    int inicio, fim;
} Queue;

void exibirOpcoes() {
    printf("Opções: \n");
    printf("1 - Enqueue \n");
    printf("2 - Dequeue \n");
    printf("3 - Head \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opção desejada: ");
}

void inicializar(Queue* fila){
    int i;
    fila->inicio = -1;
    fila->fim = -1;
    for(i =0; i < 10; i++){
        fila->dados[i] = 0;
    }
}

int isEmpty(Queue* fila){
    if (fila->inicio == -1){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Queue* fila){
    if(fila->fim == 10 - 1){
        return 1;
    } else{
        return 0;
    }
}

void enqueue(Queue* fila, int valor){
    fila->fim +=1;
    fila->inicio +=1;
    fila->dados[fila->fim] = valor;
}

int dequeue(Queue* fila){
    int item;

    item = fila->dados[fila->inicio];
    fila->inicio += 1;
    if(fila->inicio == fila->fim){
        fila->inicio = -1;
    }
    return item;
}

int head(Queue* fila){
    return fila->dados[fila->fim];
}

void main(){
    int escolha, valor;
    Queue minhaFila;

    inicializar(&minhaFila);

    while(escolha != 0){
        exibirOpcoes();
        printf("Informe a operacao a ser feita: ");
        scanf("%d",&escolha);

        switch(escolha){
            case 1 :
            //desenvolvendo
            if(isFull(&minhaFila) == 1){
                printf("Fila cheia! \n");
            } else {
                printf("Insira o valor a enfileirar: ");
                scanf("%d",&valor);
                enqueue(&minhaFila,valor);
            }
            break;
            case 2 :
            //desenvolvendo
            if(isEmpty(&minhaFila) == 1){
                printf("Fila vazia! \n");
            }else{
                dequeue(&minhaFila);
            }
            break;
            case 3:
            //desenvolvendo
            printf("No final da fila : %d\n",head(&minhaFila));
            break;
            case 0 :
            break;
            default :
            printf("Opção Invalida !\n");
            break;
        }
    }
}