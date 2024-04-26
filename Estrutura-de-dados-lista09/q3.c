#include <stdio.h>
#include <stdlib.h>

typedef struct noLDE{
    struct noLDE *anterior;
    int info;
    struct noLDE *prox;
}TNoLDE;

typedef struct lde{
    TNoLDE *inicio;
    TNoLDE *fim;
    int qntd;
}LDE;

void inicializar(LDE *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qntd = 0;
}

int isFull(LDE lista){
    return 0;
}

int isEmpty(LDE lista){
    if(lista.qntd == 0){
        return 1;
    }else {
        return 0;
    }
}

void list(LDE lista){
    TNoLDE* aux;

    aux = lista.inicio;
    if(isEmpty(lista) == 1){
        printf("Lista vazia \n");
    } else {
        while(aux != NULL){
            printf("%d ",aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void inserir(LDE *lista, int valor){
    TNoLDE *novo, *atual;
    if(isEmpty(*lista) == 1){
        //adicionar na lista vazia
        novo = (TNoLDE*) malloc(sizeof(TNoLDE));
        novo->info = valor;
        novo->anterior = lista->inicio;
        novo->prox = lista->fim;

        lista->inicio = novo;
        lista->fim = novo;
        lista->qntd++;
    } else if (valor <= lista->inicio->info){
        //Inserir no inicio da lista nao-vazia
        novo = (TNoLDE*) malloc(sizeof(TNoLDE));
        novo->info = valor;
        novo->anterior = NULL;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->qntd++;
    } else if(valor >= lista->fim->info){
        novo = (TNoLDE*) malloc(sizeof(TNoLDE));
        novo->info = valor;
        novo->prox = NULL;
        novo->anterior = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qntd++; 
    } else {
        atual = lista->inicio->prox;
        while(atual != NULL){
            if(valor < atual->info){
                    novo = (TNoLDE*) malloc(sizeof(TNoLDE));
                    novo->info = valor;
                    novo->prox = atual;
                    novo->anterior = atual->anterior;
                    novo->anterior->prox = novo;
                    atual->anterior = novo;
                    lista->qntd++;
                    break;
            }else{
                atual = atual->prox;
            }
        }
    }
}

void remover(LDE *lista, int valor){
    
}

void main(){
    LDE minhaLista;
    int num;
    inicializar(&minhaLista);
    while(1){
        printf("Insira um numero : ");
        scanf("%d",&num);
        inserir(&minhaLista, num);
        list(minhaLista);
    }


}