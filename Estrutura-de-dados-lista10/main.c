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

void inserirOrdenado(LDE *lista, int valor){
    //inseirir ordenadamente
    TNoLDE *novo;
  
    TNoLDE *atual;
   
    
    if(isEmpty(*lista) == 1){
        //se a lista estiver vazia
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
         

        novo->anterior = lista->fim;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->fim = novo;
        lista->qntd++;
    }else if(valor < lista->inicio->info){
        //se o valor a ser inserido for menor que do inicio da fila
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
         
        novo->prox = lista->inicio->prox;
        novo->anterior = NULL;
        lista->inicio = novo;
        lista->qntd ++;
    } else if (valor > lista->fim->info){
        //valor for maior que o ultimo
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
         
        novo->prox = NULL;
        novo->anterior = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qntd++;
    } else {
        atual = lista->inicio->prox;
        while(1){
            if(valor < atual->info){
                novo = (TNoLDE*)malloc(sizeof(TNoLDE));
                novo->info = valor;
                 
                novo->prox = atual;
                return;
            } else{
                atual = atual->prox;
            }
        }
    }

}



TNoLDE* buscar(LDE lista, int valor){
    TNoLDE* aux;
    if(isEmpty(lista) == 1){
        return NULL;
    } else{
        if(lista.inicio->info == valor){
            return lista.inicio;
        } else if (lista.fim->info == valor){
            return lista.fim;
        } else{
            aux = lista.inicio->prox;
            while(aux != NULL){
                if(aux->info == valor){
                    //se eh igual
                    return aux;
                } else {
                    aux = aux->prox;
                }
            }
        }
    }
}

void inserirFinal(LDE *lista, int valor){
    TNoLDE *novo;
    TNoLDE *retorno;
    if(isEmpty(*lista) == 1){
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
        novo->anterior = lista->fim;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->fim = novo;
        lista->qntd++;
    } else {
        retorno = buscar(*lista, valor);
        if(retorno == NULL) { 
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
        novo->anterior = lista->fim;
        novo->prox = NULL;

        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qntd++; 
        } else {
            printf("Elemento repetido !\n");
        }
    }
}

void preencherIntersecao(LDE A, LDE B, LDE *intersecao){
    //ve se o valor em A == B e se for bota na nova lista
    TNoLDE *aux, *retorno;
    int num;
    aux = A.inicio;

    while(aux != NULL){
        num = aux->info;
        retorno = buscar(B, num);
        if(retorno != NULL){
            inserirOrdenado(intersecao, num);
        }
        aux = aux->prox;
    }
}

void preencherUniao(LDE A, LDE B, LDE *uniao){
    //junta os valores de A e B em uma lista so
    TNoLDE *aux;
    int num;
    aux = A.inicio;

    while(aux != NULL){
        num = aux->info;
        //inserirOrdenado(uniao, num);
        inserirFinal(uniao, num);
        aux = aux->prox;
    }
    printf("preenchido lista A \n");
    aux = B.inicio;
    while(aux != NULL){
        num = aux->info;
        inserirOrdenado(uniao, num);
        aux = aux->prox;
    }
    printf("Preenchido lista B \n");
}

void preencherDiferenca(LDE A, LDE B, LDE *diferenca) {
    TNoLDE *aux, *retorno;
    int num;
    aux = A.inicio;
    while(aux != NULL){
        num = aux->info;
        retorno = buscar(B, num);
        if(retorno == NULL){
            inserirOrdenado(diferenca, num);
        }
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


void main(){
    LDE A, B, intersecao, uniao, diferenca;
    int valor;
    inicializar(&A);
    inicializar(&B);
    inicializar(&intersecao);
    inicializar(&uniao);
    inicializar(&diferenca);


    //preecnhe a lisat A
    for(int i = 1; i <= 10; i++){
        inserirOrdenado(&A, i);
    }
    list(A);
    //preenche a lista B
    for(int i = 5; i <=15; i++){
        inserirOrdenado(&B, i);
    }
    list(B);
    
    preencherIntersecao(A, B, &intersecao);
    list(intersecao);
    /***nao esta exibindo a uniao
    preencherUniao(A, B, &uniao);
    printf("\n Uniao : ");
    list(uniao);
    ***/
    //diferença nao esta sendo exibida
    printf("Diferenca : ");
    preencherDiferenca(A,B,&diferenca);
    list(diferenca);
}