#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoPilha{
    char caractere;
    struct NoPilha *prox;
}TNoPilha;

typedef TNoPilha* Stack;

void inicializar(Stack* pilha){
    *pilha = NULL;
}

int isEmpty(Stack pilha){
    if (pilha == NULL){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack pilha){
    return 0;
}

void push(Stack* pilha, char string){//vai receber uma elemento da string e jogar na stack
    Stack novo;
    novo = (TNoPilha*) malloc(sizeof(TNoPilha));

    novo->caractere = string;
    novo->prox = *pilha;
    *pilha = novo;

}

char pop(Stack* pilha){
    Stack aux;
    char caractere;

    aux = *pilha;
    caractere = aux->caractere;
    *pilha = (*pilha)->prox;
    free(aux);

    return caractere;
}



int main(){
    char string[20], comparacao[20], comparacao2[20];
    Stack minhaPilha, outraPilha;
    int i, contadorIguais = 0, j =0;
    //inicializar duas pilhas
    inicializar(&minhaPilha);
    inicializar(&outraPilha);
    

    printf("Insira a palavra : ");
    scanf("%s", string);
    //empurrar os caracteres pra ambas
    for(i = 0; i < strlen(string); i++){
        push(&minhaPilha, string[i]);
        push(&outraPilha, string[strlen(string) - i]);
    }
    //dar pop nas duas e ver se os caracteres popados sao os mesmos
    while(isEmpty(minhaPilha) == 0 && isEmpty(outraPilha) == 0){
        comparacao[j] = pop(&minhaPilha);
        comparacao2[j] = pop(&outraPilha);
        j++;
    }
    if(strcmp(comparacao,comparacao2) == 0){
            printf("Nao palindromo");
            return 0;
    }else {
        printf("Palindromo !\n");
        return 0;
    }
}