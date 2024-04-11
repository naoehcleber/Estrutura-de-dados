#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoLSE{
    char nome[20];
    int telefone;
    char email[20];
    TNoLSE* prox;
}TNoLSE;

typedef struct LSEC{
    TNoLSE* inicio;
    TNoLSE* fim;
}LSEContatos;

int isEmpty(LSEContatos lista){
    if(lista.inicio == NULL && lista.fim == NULL){
        return 1;
    } else {
        return 0;
    }
}

int isFull(LSEContatos lista){
    return 0;
}

void push(LSEContatos* lista, char nome[], char email[], int numero){
    TNoLSE* novo, *atual, *anterior;
    if(isEmpty(*lista) == 1){
        //se a lista tiver vazia 
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));
        strcpy(novo->nome, nome);
        strcpy(novo->email, email);
        novo->telefone = numero;
        novo->prox = NULL;

        lista->inicio = novo;
        lista->fim = novo;
        printf("Insercao efetuada\n");
    } else if (strcmp(nome, lista->inicio->nome) < 0){
        //se o valor for menor que o primeiro da fila
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));
        strcpy(novo->nome, nome);
        novo->prox = lista->inicio;
        lista->inicio = novo;
        printf("insercao efetuada \n");
    } else if(strcmp(nome, lista->inicio->nome) == 0){
        //se os valores forem iguais a algum que ja esteja no inicio da fila
        printf("Valor repetido, insercao cancelada \n");
    } else if(strcmp(nome, lista->inicio->nome) > 0){
        //se o valor for maior que o que esta no fim da fila
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));
        strcpy(novo->nome, nome);
        strcpy(novo->email, email);
        novo->telefone = numero;

        lista->fim->prox = novo;
        lista->fim = novo;
        printf("insercao efetuada \n");


    }else if(strcmp(nome, lista->fim->nome) == 0){
        //se o valor for igual a um que ja esteja no final da fila
        printf("Valor repetido, insercao cancelada \n");
    } else {
        anterior = lista->inicio;
        atual = anterior->prox;
        while(1){
            if(strcmp(nome, atual->nome) == 0){
                printf("Valor repetido, insercao cancelada \n");
            } else if (strcmp(nome, atual->nome) > 0) {
                novo = (TNoLSE*)malloc(sizeof(TNoLSE));
                strcpy(novo->nome, nome);
                strcpy(novo->email, email);
                novo->telefone = numero;

                anterior->prox = novo;
                novo->prox = atual;
                printf("Insercao efetuada\n");
                break;

            } else {
                atual = atual->prox;
                anterior = anterior->prox;
            }
        }
    }
}

void remove(LSEContatos* lista, char string[]){
TNoLSE *atual, *anterior;
    atual = lista->inicio->prox;
    anterior = NULL;
    
    while(atual != NULL){
        printf("Iniciando busca \n");
        if(strcmp(atual->nome, string)){
            printf("Elemento achado\n");
            if(anterior == NULL){
                //se estiver no inicio da fila
                lista->inicio = atual->prox;
            }else if (anterior != NULL && atual != NULL){
                lista->inicio->prox = atual->prox;
            }
            printf("email : %s\n",atual->email);
            printf("numero : %d");
            return atual->nome;
        }
        
        //procura o elemento
        anterior = atual;
        atual = atual->prox;


    }
    printf("elemento nao esta na lista\n");
    return -1;
 
}

void list(LSEContatos lista){
    TNoLSE* aux;

    aux = lista.inicio;

    while(aux != NULL){
        printf("%s \n",aux->nome);
        aux = aux->prox;
    }
    printf("\n");
    
}

void* procurar(LSEContatos lista, char nome[]){
    if(){
        //se encontrar o nome
    }
}

void alterar(LSEContatos* lista, char string[]){

}

void exibirMenu(){
    printf("Escolha uma opcao:\n");
    printf("1 - Adicionar \n");
    printf("2 - Remover \n");
    printf("3 - Exibir \n");
    printf("4 - Procurar \n");
    printf("5 - Alterar \n");
    printf("0 - Sair \n");
}

void main(){
    LSEContatos minhaLista;
    int opcao, numero;
    char nome[20], email[20];

    while(opcao != 0){
        exibirMenu();
        scanf("%d", &opcao);

        switch(opcao){
            case 1 :
                if(isFull(minhaLista) == 1){
                    printf("Lista cheia");
                } else {
                    printf("Insira os dados do contato a inserir : \n");
                    printf("Nome : ");
                    scanf("%s", &nome);
                    printf("Email : ");
                    scanf("%s", &email);
                    printf("Numero : ");
                    scanf("%d",&numero);
                    push(&minhaLista, nome, email, numero);

                }

                break;
            case 2:
                if(isEmpty(minhaLista) == 1){
                    printf("Lista vazia !\n");

                } else {
                    printf("Insira o nome do contato a ser removido : ");
                    scanf("%s",&nome);
                    remove(&minhaLista, nome);
                }
                break;
            case 3:
                list(minhaLista);
                break;
            case 4: 
                //em desenvolvimento...
                break;
            case 5 :
                //...
                break;
            case 0:
                break;
        }
    }

}