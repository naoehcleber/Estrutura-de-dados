#include <stdio.h>
#include <stdlib.h>

typedef struct NoLSE {
 int info;
 struct NoLSE* prox;
} TNoLSE;

typedef struct LseInt {
 TNoLSE* inicio;
 TNoLSE* fim;
 int qtd;
} LSEInteiros;

void exibirOpcoes() {
 printf("Opções: \n");
 printf("1 - Inserir valor \n");
 printf("2 - Remover valor \n");
 printf("3 - Exibir lista \n");
 printf("0 - Encerrar programa \n");
 printf("Informe a opção desejada: ");
}

void inicializar(LSEInteiros* lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

int isFull(LSEInteiros lista){
    return 0;
}

int isEmpty(LSEInteiros lista){
    if(lista.inicio == NULL && lista.fim == NULL){
        return 1;
    }else {
        return 0;
    }
}

void inserir(LSEInteiros* lista, int valor){
    TNoLSE* novo = (TNoLSE*)malloc(sizeof(TNoLSE));

    novo->info = valor;
    novo->prox = NULL;
    

    if(isEmpty(*lista) == 1){
        lista->inicio = novo;
        lista->fim = novo;
        //lista->qtd += 1;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
        //lista->qtd += 1;

    }
    lista->qtd++;
}

int remover(LSEInteiros* lista){
    int num;
    TNoLSE* aux;

    aux = lista->inicio;
    num = aux->info;

    lista->inicio = lista->inicio->prox;

    if(lista->inicio == NULL){
        lista->fim = NULL;
    }

    free(aux);
    return num;
}


void list(LSEInteiros lista){
    TNoLSE* aux;

    aux = lista.inicio;

    while(aux != NULL){
        printf("%d) %d \n",lista.qtd,aux->info);
        aux = aux->prox;
    }
    printf("\n");
    
}

int main() {
 LSEInteiros listaInteiros;
 inicializar(&listaInteiros);
 int op, num;
 do {
    exibirOpcoes();
    scanf("%d", &op);
    switch (op) {
    case 1: 
        if(isFull(listaInteiros) == 1){
            printf("Lista cheia");
        } else {
            printf("Insira um numero pra adicionar : ");
            scanf("%d",&num);
            inserir(&listaInteiros, num);
        }
    break;
    case 2: 
        if(isEmpty(listaInteiros) == 1){
            printf("Lista vazia! \n");

        }else{
            remover(&listaInteiros);
        }
    break;
    case 3: 
        list(listaInteiros);
        //ordernar(&listaInteiros);
        //list(listaInteiros);

    break;
    case 0: printf("Fim de programa! \n");
    break;
    default: printf("Opção inválida! \n");
    }
 } while (op != 0);
 return 0;
}