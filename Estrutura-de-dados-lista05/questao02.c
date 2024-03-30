#include <stdio.h>
#include <stdlib.h>

typedef struct NoStack {
    int dados;
    struct NoStack *prox;
}TNoStack;

typedef TNoStack* Stack;

void inicializar(Stack* pilha){
    *pilha = NULL;
}

int isEmpty(Stack pilha){
    if(pilha == NULL){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack pilha){
    return 0;
}

void push(Stack* pilha, int valor){
    Stack novo;
   novo = (TNoStack*) malloc(sizeof(TNoStack));

   novo->dados = valor;
   novo->prox = *pilha;
   *pilha = novo;
}

int pop(Stack* pilha){
    

    Stack aux;
    int num;
    aux = *pilha;
    num = aux->dados;
    *pilha = (*pilha)->prox;
    free(aux);
    return num;
}

void popTudo(Stack* pilha){
    
    while(isEmpty(*pilha) == 0){
        pop(pilha);
    }    
}

void imprimirPilha(Stack* pilha){
    Stack aux;
    aux = *pilha;

    while(aux != NULL){
        printf("%d",pop(pilha));
        aux = aux->prox;
    }
}

void divisaoBinario(Stack* pilha, int valor){ // divide o numero e salva cada caractere do binario na stack
    int resto;
    while(valor != 0){
        resto = valor%2;
        valor = valor/2;
        push(pilha, resto);
    }
    
}

void main(){
    Stack minhaStack;
    int opcao, valor;
    inicializar(&minhaStack);

    
    printf("Insira o numero a ser transformado em binario :");
    scanf("%d", &valor);
    divisaoBinario(&minhaStack, valor);
    imprimirPilha(&minhaStack);
    if(isEmpty(minhaStack) == 0){
        popTudo(&minhaStack);
    }
    
}