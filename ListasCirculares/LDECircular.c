#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node {
    struct noLDE *anterior;
    int info;
    struct noLDE *prox;
}Node;

typedef struct lseCircular{
    Node *inicio;
    Node *fim;
    int qtd;
}LSEcircular;

void inicializar(LSEcircular *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isFull(LSEcircular lista){
    return 0;
}

int isEmpty(LSEcircular lista){
    if(lista.qtd == 0){
        return 1;
    }else {
        return 0;
    }
}

Node *criarNo(int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->info = valor;
    return novo;
}

void inserirOrdenado(LSEcircular *lista, int valor){
    //inseirir ordenadamente
    Node *novo;
  
    Node *atual;
   
    
    if(isEmpty(*lista) == 1){
        //se a lista estiver vazia
        novo = criarNo(valor);
         

        novo->anterior = lista->fim;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd++;
        lista->inicio->anterior = lista->fim;
    }else if(valor < lista->inicio->info){
        //se o valor a ser inserido for menor que do inicio da fila
        novo = criarNo(valor);
         
        novo->prox = lista->inicio->prox;
        novo->anterior = NULL;
        lista->inicio = novo;
        lista->qtd ++;
        lista->inicio->anterior = lista->fim;

    } else if (valor > lista->fim->info){
        //valor for maior que o ultimo
        novo = criarNo(valor);
         
        novo->prox = NULL;
        novo->anterior = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qtd++;
        lista->fim->prox = lista->inicio;
    } else {
        atual = lista->inicio->prox;
        while(1){
            if(valor < atual->info){
                novo = criarNo(valor);
                 
                novo->prox = atual;
                return;
            } else{
                atual = atual->prox;
            }
        }
    }
}
void exibirOpcoes() {printf("Opções: \n");printf("1 - Inserir valor no início da lista \n");printf("2 - Inserir valor no final da lista \n");printf("3 - Remover primeiro da lista \n");printf("4 - Remover último da lista \n");printf("5 - Exibir a lista \n");printf("0 -Encerrar programa \n");printf("Informe a opção desejada: ");}

void main(){
   LSEcircular listaInteiros;
   inicializar(&listaInteiros);
   int op, num;
   while(op!= 0){
    exibirOpcoes();
    scanf("%d",&op);
    switch(op){
        case 1 : printf("Insira o valor a ser inserido: ");
            scanf("&d",&num);
            inserirOrdenado(&listaInteiros, num);
            break;
        case 2 :
            break;
        case 3 :
            break;
        case 4 :
        break;
        case 5 :
            break;
    }
    
   } 
}