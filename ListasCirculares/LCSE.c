#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
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

void inserirInicio(LSEcircular *lista, int valor){
    
}

void removerUltimo(LSEcircular *lista){
    Node *aux;

    if(isEmpty(*lista) == 1){
        printf("Lista vazia \n");
        return;
    }else if (lista->qtd == 1){
        //se tiver so 1 elemento
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->qtd = 0;
    } else {
        aux = lista->inicio;
        while(aux->prox != lista->fim){
            aux = aux->prox;
        }
        lista->fim = aux;
        free(aux->prox);
        lista->fim->prox = lista->inicio;
    }
}

void exibirDoWhile(LSEcircular lista){
    if(isEmpty(lista) == 1){
        printf("Lista vazia \n");
        return;
    }
    Node *aux = lista.inicio;
    do{
        printf("%d ", aux->info);
        aux = aux->prox;
    }while(aux != lista.inicio);
}

void exibirFor(LSEcircular lista){
    if(isEmpty(lista) == 1){
        printf("Lista vazia \n");
        return;
    }
    Node *aux;
    aux = lista.inicio;
    
    for(int i = 0; i < lista.qtd; i++){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

void exibirOpcoes() {printf("Opções: \n");printf("1 - Inserir valor no início da lista \n");printf("2 - Inserir valor no final da lista \n");printf("3 - Remover primeiro da lista \n");printf("4 - Remover último da lista \n");printf("5 - Exibir a lista \n");printf("0 -Encerrar programa \n");printf("Informe a opção desejada: ");}

void main(){
   LSEcircular listaInteiros;
   inicializar(&listaInteiros);
   int op, num;
   while(op!= 0){
    exibirOpcoes();
    scanf("%d",&num);
    switch(op){
        case 1 : printf("Insira o valor a ser inserido: ");
            scanf("&d",&num);
            inserirInicio(&listaInteiros, num);
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