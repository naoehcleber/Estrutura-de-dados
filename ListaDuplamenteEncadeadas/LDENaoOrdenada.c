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


void inserirInicio(LDE *lista, int valor){
    TNoLDE *novo;
    TNoLDE* retorno;
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
        novo->anterior = NULL;
        novo->prox = lista->inicio;

        lista->inicio->anterior = novo;
        lista->inicio = novo;
        lista->qntd++; 
        } else {
            printf("Elemento repetido !\n");
        }
    }
    

}

void inserirFinal(LDE *lista, int valor){

}



void list(LDE lista){
    TNoLDE* aux;

    aux = lista.inicio;

    while(aux != NULL){
        printf("%d \n",aux->info);
        aux = aux->prox;
    }
    printf("\n");
    
}

void listInversa(LDE lista){
    TNoLDE* aux;

    aux = lista.fim;

    while(aux != NULL){
        printf("%d \n",aux->info);
        aux = aux->anterior;
    }
    printf("\n");
    
}

void removerEspecifico(LDE *lista, int valor){
    TNoLDE *aux;
    aux = buscar(*lista, valor);
    if(aux == NULL){
        printf("Valor nao esta na lista \n");
    
    }else {
        if(aux == lista->inicio && lista->inicio == lista->fim){
            aux = buscar(*lista,valor);
            lista->inicio = NULL;
            lista->fim = NULL;
            free(aux);
            lista->qntd--;
        }
        else if(aux == lista->inicio){
            lista->inicio = lista->inicio->prox;
            lista->inicio->anterior = NULL;
            free(aux);

            lista->qntd--;
        } else if (aux == lista->fim){
            lista->fim = lista->fim->anterior;
            lista->fim->prox = NULL;
            free(aux);
            lista->qntd--;
        } else {
            aux = buscar(*lista, valor);
            aux->prox->anterior = aux->anterior;
            aux->anterior->prox = aux->prox;
            free(aux);
            lista->qntd--;

        }
    }
}

void exibirOpcoes() {
    printf("Opções: \n");
    printf("1 - Inserir valor no início da lista \n");
    printf("2 - Inserir valor no final da lista \n");
    printf("3 - Remover primeiro da lista \n");
    printf("4 - Remover último da lista \n");
    printf("5 - Exibir lista do início para o final \n");
    printf("6 - Exibir lista do final para o início \n");
    printf("7 - Remover valor especifico \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opção desejada: ");
}


void main(){
    LDE minhaLista;
    int valor, op;

    inicializar(&minhaLista);

    do {
        exibirOpcoes();
        scanf("%d",&op);
        switch (op) {
        case 1: printf("Informe o valor a ser inserido: ");
            scanf("%d",&valor);
            inserirInicio(&minhaLista, valor);
            break;
        case 2: // em desenvolvimento
            break;
        case 3: // em desenvolvimento
            break;
        case 4: // em desenvolvimento
            break;
        case 5: list(minhaLista);
            break;
        case 6: listInversa(minhaLista);
            break;
        case 7:
            printf("Informe o valor a ser removido \n");
            scanf("%d", &valor);
            removerEspecifico(&minhaLista, valor);
            break;
        case 0: printf("Fim de programa! \n");
            break;
        default: printf("Opção inválida! \n");
        }
    } while (op != 0);
}