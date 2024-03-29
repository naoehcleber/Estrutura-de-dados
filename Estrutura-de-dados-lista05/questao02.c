#include <stdio.h>
#include <stdlib.h>

typedef struct NoStack {
    int dados;
    TNoStack *prox;
}TNoStack;

typedef TNoStack Stack;

void inicializar(Stack* pilha){
    pilha->prox = NULL;
}

int isEmpty(Stack pilha){
    if(pilha.prox == NULL){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack pilha){
    return 0;
}

void push(Stack* pilha, int valor){
    Stack *novo;
    novo = (TNoStack*) malloc(sizeof(TNoStack));

    novo->dados = valor;
    novo->prox = pilha;
    pilha = (pilha)->prox;
    free(novo);

}

void imprimirPilha(Stack* pilha){
    Stack atual;
    atual = pilha->dados;
}

void divisaoBinario(Stack* pilha, int valor){ // divide o numero e salva cada caractere do binario na stack

    
}

void main(){
    Stack minhaStack;
    int opcao, valor;

    while(opcao != 0){
        printf("Insira o numero a ser transformado em binario :");
        scanf("%d", &valor);
    }
}