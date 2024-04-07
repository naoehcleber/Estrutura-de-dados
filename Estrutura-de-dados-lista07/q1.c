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
    lista->qtd = 0;
}

int isFull(LSEInteiros lista){
    return 0;
}

int isEmpty(LSEInteiros lista){
    if(lista.qtd == 0){
        return 1;
    }else {
        return 0;
    }
}

void inserir(LSEInteiros* lista, int valor){
    TNoLSE* novo , *atual, *anterior;
    
    if(isEmpty(*lista) == 1){
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));

        novo->info = valor;
        novo->prox = NULL;

        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd = 1;
    } else if (valor< lista->inicio->info){
        //inserçao no inicio
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));

        novo->info = valor;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->qtd++;

    }else if(valor == lista->inicio->info){
        //valor repetido
        printf("Valor repetido ! Insercao nao efetuada! \n");
    }else if (valor > lista->fim->info){
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));

        novo->info = valor;
        novo->prox = NULL;
        lista->fim->prox = novo;
        lista->fim = novo;
        //lista->qtd += 1;

    } else if (valor == lista->fim->info){
        printf("Valor repetido ! Insercao nao efetuada! \n");
    } else {
        anterior = lista->inicio;
        atual = anterior->prox;
        while(1){
            if(valor == atual->info){
                printf("Valor repetido ! Insercao nao efetuada \n");
                break;
            }else if (atual->info > valor){
                novo = (TNoLSE*)malloc(sizeof(TNoLSE));
                novo->info = valor;

                anterior->prox - novo;
                novo->prox = atual;
                printf("Insercaoefetuada");
                break;
            } else {
                atual = atual->prox;
                anterior = anterior->prox;
                
            }
        }
    }
    
}

int remover(LSEInteiros* lista, int valor){
    TNoLSE *atual, *anterior;
    atual = lista;
    anterior = NULL;
    while(atual->info <= valor){
        anterior = atual;
        atual = atual->prox;
        if(atual->info == valor ){
            printf("Valor encontrado !\n");
        }
    
    }
    if(atual != NULL){
        if(anterior == NULL){
            lista = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
    }
    
  
    
    
}


void list(LSEInteiros lista){
    TNoLSE* aux;

    aux = lista.inicio;

    while(aux != NULL){
        printf("%d \n",aux->info);
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
            printf("Insira um numero para remover : ");
            scanf("%d",&num);
            remover(&listaInteiros, num);
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