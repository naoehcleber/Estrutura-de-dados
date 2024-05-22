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

void inserir(LSEcircular* lista, int valor) {
    Node* novo, *atual, *anterior;
    if (isEmpty(*lista)) {
        novo = (Node*)malloc(sizeof(Node));
        novo->info = valor;
        novo->prox = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd = 1;
        printf("Inserção efetuada. \n");
    }
    else if (valor < lista->inicio->info) {
        novo = (Node*)malloc(sizeof(Node));
        novo->info = valor;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->qtd++;
        printf("Inserção efetuada. \n");
    }
    else if (valor > lista->fim->info) {
        novo = (Node*)malloc(sizeof(Node));
        novo->info = valor;
        novo->prox = NULL;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qtd++;
        printf("Inserção efetuada. \n");
    }
    else {
        anterior = lista->inicio;
        atual = anterior->prox;
        while (1) {

            if (atual->info > valor) {
                novo = (Node*)malloc(sizeof(Node));
                novo->info = valor;
                anterior->prox = novo;
                novo->prox = atual;
                printf("Inserção efetuada. \n");
                break;
            }
            else {
                atual = atual->prox;
                anterior = anterior->prox;
            }
        }
    }
}


int remover(LSEcircular* lista, int valor){
    Node *aux, *anterior;
    int contador;

    aux = lista->inicio;
    anterior = NULL;

    if(isEmpty(*lista) == 1){
        return 0;
    }


    if(lista->inicio->info == valor){
        while(isEmpty(*lista) == 0 && lista->inicio->info == aux->info){
            //remover no inicio
            contador+=1;
            aux = lista->inicio; 
            lista->inicio = lista->inicio->prox;
            lista->qtd--;
            if(lista->inicio->prox == lista->fim){
                //condicao especial
                lista->inicio = NULL;
                lista->fim = NULL;
            }
        }
    }
    else {
        while(aux != lista->inicio){
            if(aux->info == valor && aux->prox->info == aux->info){
                //remover no meio
                contador+=1;
                aux = aux->prox;
                anterior->prox = aux;
                lista->qtd--;
                if(aux->prox == lista->fim ){
                    //remocao no fim
                    anterior->prox = lista->inicio;
                }
            }
        }
    }

    return contador;
}   

void main(){
    LSEcircular *minhaLista;
    inicializar(minhaLista);


}