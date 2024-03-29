#define TAM 10

#include <stdio.h>

typedef struct stack {
    int dados[TAM];
    int topo;
} Stack;

void inicializar(Stack* pilha) {
    int i;
    for (i = 0; i < TAM; i++) {
        pilha->dados[i] = 0;
    }
    pilha->topo = -1;
}

void push(Stack* pilha, int valor) { // empilhar
    (pilha->topo)++;
    pilha->dados[pilha->topo] = valor;
}

int pop(Stack* pilha) {  // desempilhar
    //vai retirar o valor do topo e apontar para o valor abaixo dele
    // printf("O elemento a ser tirado eh %d\n", pilha->dados[pilha->topo]);

    (pilha->topo)--;
    return pilha->dados[pilha->topo];


}

int top(Stack pilha) {   // retornar o valor que está no topo
    // em desenvolvimento.....
    return pilha.dados[pilha.topo];

}

int isFull(Stack pilha) {
    if (pilha.topo == TAM - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(Stack pilha) { // checa se a pilha está vazia
    // em desenvolvimento ....
    if(pilha.topo == -1){
        return 0;
    } else {
        //retorna 1 se nao estiver vazio 
        return 1;
    }


}

void exibirOpcoes() {
    printf("Opções: \n");
    printf("1 - Push \n");
    printf("2 - Pop \n");
    printf("3 - Top \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opção desejada: ");
}

int main()
{
    Stack minhaPilha;
    inicializar(&minhaPilha);
    int op, num;
    do {
        exibirOpcoes();
        scanf("%d",&op);
        switch (op) {
        case 1: printf("Informe o valor: ");
            scanf("%d",&num);
            if (isFull(minhaPilha) == 0) {
                push(&minhaPilha, num);
                printf("Valor empilhado!");
            }
            else {
                printf("Stack full\n");
            }
            break;
        case 2: // em desenvolvimento.....
            if (isEmpty(minhaPilha) == 0){
                printf("Pilha vazia. \n");
            } else {
               pop(&minhaPilha);
            }
            break;
        case 3: // em desenvolvimento ....
            printf("Topo da pilha : %d\n", top(minhaPilha));
            break;
        case 0: printf("Fim de programa!");
            break;
        default: printf("Opção inválida!");
        }
    } while (op != 0);
    return 0;
}
