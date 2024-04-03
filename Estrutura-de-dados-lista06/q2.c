#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NoQueue{
    char nome[20];
    int numero;
    struct TNoQUeue *prox;
}TNoQueue;

typedef struct fila{
    struct NoQueue* inicio;
    struct NoQueue* fim;
} Fila;

void inicializar(Fila* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int isFull(Fila fila){
    return 0;
}

int isEmpty(Fila fila){
    if(fila.inicio == NULL && fila.fim == NULL){
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Fila* fila, char string[]){
    TNoQueue* novo;
    novo = (TNoQueue*) malloc(sizeof(TNoQueue));

    strcpy(novo->nome, string);
    novo->numero += 1;
    novo->prox = NULL;

    if(isEmpty(*fila) == 1){
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo ;
        fila->fim = novo ;
    }
    
}

char * dequeue(Fila* fila){
    static char stringReserva[20];
    TNoQueue* aux;
    

    aux = fila->inicio;
    strcpy(stringReserva, fila->inicio->nome);

    fila->inicio = fila->inicio->prox;
    free(aux);

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return stringReserva;
}



void printMenu(){
    printf("1 - Adicionar pedido\n");
    printf("2 - Pedido pronto\n");
    printf("0 - Sair do programa\n");
}

void main(){
    Fila minhaFila;
    int opcao = -1;
    char string[20];
    inicializar(&minhaFila);

    while(opcao != 0){
        printMenu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Descricao do pedido :");
            scanf("%s", &string);
            enqueue(&minhaFila,string);
            break;
        case 2:
            printf("Pedido pronto : %s\n", dequeue(&minhaFila));
            break;
        case 0:
            break;
        default:
            break;
        }
    }


    
}