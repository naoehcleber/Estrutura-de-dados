// Exemplo de lista simplesmente encadeada circular
// Código desenvolvido na aula do dia 30-04-2024
// Os procedimentos de inserção no final, remoção do primeiro, remoção do último e exibir a lista
// ficaram como exercícios para os alunos.


#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* prox;
} Node;

typedef struct lseCircular {
    Node* inicio;
    Node* fim;
    int qtd;
}LSECircular;

int isEmpty(LSECircular lista) {
    if (lista.qtd == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void inicializar(LSECircular * lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

void inserirInicio(LSECircular* lista, int valor) { // inserção no início, aceita repetidos
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->info = valor;
    if (isEmpty(*lista) == TRUE) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd++;
        lista->fim->prox = lista->inicio;
    }
    else {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->qtd++;
        lista->fim->prox = lista->inicio;
    }

}

void inserirFinal(LSECircular *lista, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->info = valor;
    if (isEmpty(*lista) == TRUE) {
        //se a lista estiver vazia
        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd++;
        lista->fim->prox = lista->inicio;
    } else {
        novo->prox = lista->inicio;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qtd++;
        
    }
}

void removerInicio(LSECircular *lista){
    Node *aux;
    aux = lista->inicio;
    lista->inicio = lista->inicio->prox;
    lista->fim->prox = lista->inicio;
    lista->qtd--;
    free(aux);
}

void removerFinal(LSECircular *lista){
    Node *aux;
    aux = lista->fim;
    while(aux->prox != lista->fim){
        aux = aux->prox;
    }
    aux = lista->fim;
    lista->fim->prox = lista->inicio;
    lista->qtd--;
    free(aux);
}


void exibir(LSECircular lista){
    Node *aux;
    aux = lista.inicio;
    for(int i = 0; i < lista.qtd; i++){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}


void exibirOpcoes() {
    printf("Opções: \n");
    printf("1 - Inserir valor no início da lista \n");
    printf("2 - Inserir valor no final da lista \n");
    printf("3 - Remover primeiro da lista \n");
    printf("4 - Remover último da lista \n");
    printf("5 - Exibir a lista \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opção desejada: ");
}



int main() {
    LSECircular listaInteiros;
    inicializar(&listaInteiros);
    int op, num;
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
        case 1: printf("Informe o valor a ser inserido: ");
            scanf("%d", &num);
            inserirInicio(&listaInteiros, num);
            break;
        case 2: printf("Informe o valor a ser inserido: ");
            scanf("%d",&num);
            inserirFinal(&listaInteiros, num);
            break;
        case 3: removerInicio(&listaInteiros);
            break;
        case 4: removerFinal(&listaInteiros);
            break;
        case 5: exibir(listaInteiros);
            break;
        case 0: printf("Fim de programa! \n");
            break;
        default: printf("Opção inválida! \n");
        }
    } while (op != 0);
    return 0;
}