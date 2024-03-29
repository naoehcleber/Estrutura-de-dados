// Código desenvolvido na aula do dia 15-03-2024
// Implementação do método de enfileirar (inserção no final) em uma fila de inteiros definido com segue abaixo.


#include <stdio.h> 
#include <stdlib.h> // biblioteca para utilizar as funções malloc e free

// O código do ENQUEUE implementado em sala na aula do dia 15-03-2024
//  é para uma fila com a seguinte definição:

typedef struct NoQueue {
    int info;
    struct NoQueue* prox;
}TNoQueue;

typedef TNoQueue* Queue;

void inicializar(Queue* fila) {
    *fila = NULL;
}

int isEmpty(Queue fila) { // checa se a fila está vazia
    // Em desenvolvimento ....
    if(fila->prox == NULL){
        return 1;
    } else {
        return 0;
    }

}

// Implementado em sala na aula do dia 15-03-2024
void enqueue(Queue* fila, int valor) { // enfileirar - inserir no final da fila
    TNoQueue* novo;
    TNoQueue* aux;
    novo = (TNoQueue*)malloc(sizeof(TNoQueue));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*fila) == 1) {
        *fila = novo;
    }
    else {
        aux = *fila;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int dequeue(Queue* fila) {  // desenfileirar - remover o primeiro da fila
    // Em desenvolvimento ....
    TNoQueue* aux;
    aux = (TNoQueue*) malloc(sizeof(TNoQueue));
    aux = (*fila)->prox;
    aux->prox = (*fila)->prox;

    free(aux);

}

int head(Queue fila) {   // retornar o valor que está no início da fila
    // Em desenvolvimento ....
    return fila->info;

}

int isFull(Queue fila) { // checa se a fila está cheia
    // Em desenvolvimento ....
    return 0;
}

void exibirOpcoes() {
    printf("Opções: \n");
    printf("1 - Enqueue \n");
    printf("2 - Dequeue \n");
    printf("3 - Head \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opção desejada: ");
}

int main()
{
    Queue minhaFila;
    inicializar(&minhaFila);
    int op, num;
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
        case 1: printf("Informe o valor: ");
            scanf("%d", &num);
            if (isFull(minhaFila) == 0) {
                enqueue(&minhaFila, num);
                printf("Valor enfileirado! \n");
            }
            else {
                printf("Queue full!\n");
            }
            break;
        case 2: if (isEmpty(minhaFila) == 0) {
                    num = dequeue(&minhaFila);
                    printf("Valor desenfileirado: %d \n", num);
                }
                else {
                    printf("Queue empty! \n");
                }
                break;
        case 3: if (isEmpty(minhaFila) == 0) {
                      num = head(minhaFila);
                      printf("Valor no início da fila: %d \n", num);
                }
                else {
                      printf("Queue empty! \n");
                }
                break;
        case 0: printf("Fim de programa! \n");
            break;
        default: printf("Opção inválida! \n");
        }
    } while (op != 0);
    return 0;
}