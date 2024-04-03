#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoQueue{
    char nome[20];
    struct TNoQUeue *prox;
}TNoQueue;

typedef struct fila{
    struct NoQueue* inicio;
    struct NoQueue* fim;
} Fila;

void inicializar(Fila* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int isFull(Fila fila){
    return 0;
}

int isEmpty(Fila fila){
    if(fila.inicio == NULL && fila.fim == NULL){
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Fila* fila, char string[]){
    TNoQueue* novo;
    novo = (TNoQueue*) malloc(sizeof(TNoQueue));

    strcpy(novo->nome, string);
    novo->prox = NULL;

    if(isEmpty(*fila) == 1){
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo ;
        fila->fim = novo ;
    }
}

char * dequeue(Fila* fila){
    static char stringReserva[20];
    TNoQueue* aux;
    

    aux = fila->inicio;
    strcpy(stringReserva, fila->inicio->nome);

    fila->inicio = fila->inicio->prox;
    free(aux);

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return stringReserva;
}

char* head(Fila fila){
    return fila.inicio->nome;
}

void list(Fila* fila){
    TNoQueue* aux;
    
    aux = fila->inicio;

    while(aux != NULL){
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
    free(aux);
}

void cancel(Fila** fila, char string[]){
    TNoQueue* atual;
    TNoQueue* anterior;
    atual = *fila;
    anterior = NULL;
    //vai achar o string
    while(strcmp(atual->nome, string) != 1){
        anterior = atual;
        atual = atual->prox;
        if(strcmp(atual->nome, string) == 1){
            printf("Elemento encontrado\n");
        }
    }
    if(atual != NULL){
        if(anterior == NULL){
            *fila = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
    }
}

void printMenu(){
    printf("1 - Enqueue\n");
    printf("2 - Dequeue\n");
    printf("3 - Head\n");
    printf("4 - List\n");
    printf("5 - Cancel\n");
    printf("0 - Sair do programa\n");
}

void main(){
    char string[20];
    int opcao;
    Fila minhaFila;
    inicializar(&minhaFila);
    while(opcao != 0){
        printf("Escolha o que fazer :\n");
        printMenu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1 :
                printf("Insira o string a ser impresso: ");
                scanf("%s",&string);
                if(isFull(minhaFila) == 1){
                    printf("Fila cheia\n");
                }
                enqueue(&minhaFila,string);
                break;
            case 2 :
                if(isEmpty(minhaFila) == 1){
                    printf("Fila vazia\n");
                } else {
                    dequeue(&minhaFila);
                }
                break;
            case 3:
                if(isEmpty(minhaFila) == 1){
                    printf("Fila vazia\n");
                } else{
                    printf("%s\n",head(minhaFila));
                }
                break;
            case 4 :
                list(&minhaFila);
                break;
            case 5:
                printf("Insira qual elemento remover: ");
                scanf("%s",&string);
                cancel(&minhaFila, string);
                break;
            case 0:
                break;
            default:
                break;
        }
    }
    
}