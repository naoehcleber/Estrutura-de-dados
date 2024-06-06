#include <stdio.h>
#include <stdlib.h>

typedef struct LDENode{
    int numero;
    struct LDENode *prox;
    struct LDENode *ant;
}Node;

typedef struct LDE{
    Node *inicio;
    Node *fim;
    int qtd;
}LDE;

void inicializar(LDE *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty(LDE lista){
    if(lista.qtd == 0){
        return 1;
    } else {
        return 0;
    }
}

void adicionarInicio(LDE *lista, int num){
    Node *aux;
    
    //se a lista estiver vazia
    if(isEmpty(*lista) == 1){
        aux = (Node*)malloc(sizeof(Node));
        aux->numero = num;

        aux->ant = NULL; 
        aux->prox = NULL;
        lista->inicio = aux;
        lista->fim = aux;
        lista->qtd++;
    } else {
        aux = (Node*)malloc(sizeof(Node));
        aux->numero = num;

        aux->ant = NULL;
        aux->prox = lista->inicio;
        lista->inicio->ant = aux;
        lista->inicio = aux;
        lista->qtd++;
    }

}

void separar(LDE *lista,LDE *pares,LDE *impares){
    Node *aux;
    if(lista->qtd == 0){
        printf("Lista vazia \n");
        return ;
    }

    aux = lista->inicio;
    while(aux != NULL){
        
        if(aux->numero % 2 == 0){
            adicionarInicio(pares, aux->numero);
        } else{
            adicionarInicio(impares, aux->numero);
        }
        aux = aux->prox;
    }
}

void list(LDE lista){
    Node *aux;

    aux = lista.inicio; 
   while(aux != NULL){
        printf("%d ", aux->numero);
        aux = aux->prox;
    }
    printf("\n");
}

void main(){
    LDE numeros;
    LDE pares;
    LDE impares;

    inicializar(&numeros);
    inicializar(&pares);
    inicializar(&impares);
    printf("Listas inicializadas \n");
    adicionarInicio(&numeros, 5);
    printf("numero adicionado \n");

    adicionarInicio(&numeros, 6);
    printf("numero adicionado \n");

    adicionarInicio(&numeros, 7);
    printf("numero adicionado \n");

    adicionarInicio(&numeros, 8);
    printf("numero adicionado \n");

    list(numeros);

    separar(&numeros, &pares, &impares);

    list(pares);
    list(impares);


}