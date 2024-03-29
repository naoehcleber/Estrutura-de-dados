#include <stdio.h>
#include <stdlib.h>

typedef struct noPilha {
    int info;
    struct noPilha* prox;
} TNoPilha;
typedef TNoPilha* Stack;

void inicializar(Stack* pilha) {
    *pilha = NULL;
}

void push(Stack* pilha, int valor) { // empilhar
   Stack novo;
   novo = (TNoPilha*) malloc(sizeof(TNoPilha));

   novo->info = valor;
   novo->prox = *pilha;
   *pilha = novo;


}

int pop(Stack* pilha) {  // desempilhar
    Stack aux;
    int num;
    
    aux = *pilha;
    num = aux->info;
    *pilha = (*pilha)->prox;
    free(aux);

    return num;
}

int top(Stack pilha) {   // retornar o valor que está no topo
    return pilha->info;
  
}

int isFull(Stack pilha) {  // checa se a pilha está cheia
    return 0;
    
}

int isEmpty(Stack pilha) { // checa se a pilha está vazia
    if (pilha == NULL){
        return 1;
    } else{
        return 0;
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
        scanf("%d", &op);
        switch (op) {
        case 1: printf("Informe o valor: ");
            scanf("%d", &num);
            if (isFull(minhaPilha) == 0) {
                push(&minhaPilha, num);
                printf("Valor empilhado!");
            }
            else {
                printf("Stack full\n");
            }
            break;
        case 2: // em desenvolvimento.....
            if(isEmpty(minhaPilha) == 0){
                pop(&minhaPilha);
            } else {
                printf("Pilha vazia\n");
            }
            break;
        case 3: // em desenvolvimento ....
            printf("O elemento no topo da pilha eh : %d\n",top(minhaPilha));
            break;
        case 0: printf("Fim de programa!");
            break;
        default: printf("Opção inválida!");
        }
    } while (op != 0);
    return 0;
}