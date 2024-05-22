#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noLDE{
    struct noLDE *anterior;
    char nome[50];
    int mediaFinal;
    int qtdFaltas;
    struct noLDE *prox;
}Node;

typedef struct lde{
    Node *inicio;
    Node *fim;
    int qntd;
}LDECircular;

void inicializar(LDECircular *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qntd = 0;
}

int isFull(LDECircular lista){
    return 0;
}

int isEmpty(LDECircular lista){
    if(lista.qntd == 0){
        return 1;
    }else {
        return 0;
    }
}

Node *criarNo(char nome[], int mediaFinal, int qtdFaltas){ 
    Node *novo = (Node*)malloc(sizeof(Node)); 
    strcpy(novo->nome, nome);
    novo->mediaFinal = mediaFinal;
    novo->qtdFaltas = qtdFaltas;
    return novo; 
} 

void cadastrar(LDECircular *lista, char nome[], int mediaFinal, int qtdFaltas){
    Node *novo, *atual;
    if(isEmpty(*lista) == 1){
        criarNo(nome, mediaFinal, qtdFaltas);

        novo->anterior = lista->fim;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->fim = novo;
        lista->qntd++;
        lista->fim->prox = lista->inicio;

    }else if (strcmp(nome, lista->inicio) < 0){
        //se o valor a ser inserido for menor que o do inicio da fila
        criarNo(nome, mediaFinal, qtdFaltas);
        novo->nome = nome;
        novo->prox = lista->inicio->prox;
    }
}

void imprimirMenu(){
    printf("1 - Cadastrar \n");
    printf("2 - Listar \n");
    printf("3 - Alterar media \n");
    printf("4 - Alterar quantidade de faltas \n");
    printf("5 - Exibir \n");
    printf("6 - Remover \n");
    printf("7 - Limpar \n");
}

void main(){
    int op, num;
    LDECircular turmaA, turmaB, turmaC;
    inicializar(&turmaA);
    inicializar(&turmaB);
    inicializar(&turmaC);

    while(op != 0){
        imprimirMenu();
        scanf("%d",&op);
        switch(op){
            case 1:
                //desenvolvendo
                break;
            case 2 :
                //desenvolvendo
                break;
            case 3 :
                //desenvolvendo
                break;
            case 4:
                //desenvolvendo
                break;
            case 5:
                //desenvolvendo
                break;
            case 6:
                //desenvolvendo
                break;
            case 7 :
                //desenvolvendo
                break;
            case 0:
                break;
            default :
                printf("Opcao Invalida\n");
                break;
        }       
    }
    
}