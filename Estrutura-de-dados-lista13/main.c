#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noLDE{
    struct noLDE *anterior;
    char nome[50];
    int mediaFinal;
    int qtdFaltas;
    struct noLDE *prox;
}Node;

typedef struct lde{
    Node *inicio;
    Node *fim;
    int qntd;
}LDECircular;

void inicializar(LDECircular *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qntd = 0;
}

int isFull(LDECircular lista){
    return 0;
}

int isEmpty(LDECircular lista){
    if(lista.qntd == 0){
        return 1;
    }else {
        return 0;
    }
}

Node *criarNo(char nome[], int mediaFinal, int qtdFaltas){ 
    Node *novo = (Node*)malloc(sizeof(Node)); 
    strcpy(novo->nome, nome);
    novo->mediaFinal = mediaFinal;
    novo->qtdFaltas = qtdFaltas;
    return novo; 
} 

void cadastrar(LDECircular *lista, char nome[], float mediaFinal, int qtdFaltas){
    Node *novo, *atual;

    atual = lista->inicio;

    



    if(isEmpty(*lista) == 1){
        //se a lista estiver vazia
        novo = criarNo(nome, mediaFinal, qtdFaltas);

        novo->anterior = lista->fim;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->fim = novo;

        lista->qntd++;
        lista->fim->prox = lista->inicio;
    } else {
        while(atual != NULL){   
            if(strcmp(nome, lista->inicio->nome) == -1){
                //insercao no inicio
                novo = criarNo(nome, mediaFinal, qtdFaltas);

                novo->prox = lista->inicio->prox;
                novo->anterior = NULL;
                lista->inicio = novo;
                lista->qntd++;

                lista->inicio->anterior = lista->fim;
            } else if (strcmp(nome, lista->fim->nome) == 1){
                //insercao no fim
                novo = criarNo(nome, mediaFinal, qtdFaltas);

                novo->anterior = lista->fim->anterior;
                novo->prox = NULL;
                lista->fim->prox = novo;
                lista->fim = novo;
                
                lista->qntd++;
                lista->fim->prox = lista->inicio;
            } else {
                //insercao no meio
                atual = lista->inicio->prox;
                while(atual != NULL){
                    if(strcmp(nome, atual->nome) == -1){
                        novo = criarNo(nome, mediaFinal, qtdFaltas);

                        novo->prox = atual;
                    } else {
                        atual = atual->prox;
                    }
                }                
            }
        }
    }
}

void listar(LDECircular lista){
    Node *aux;
    aux = lista.inicio;
    for(int i = 0; i < lista.qntd; i++){
        printf("%s\n",aux->nome);
        printf("%f",aux->mediaFinal);
        printf("%d", aux->qtdFaltas);

        aux = aux->prox;
    }
}

void imprimirMenu(){
    printf("1 - Cadastrar \n");
    printf("2 - Listar \n");
    printf("3 - Alterar media \n");
    printf("4 - Alterar quantidade de faltas \n");
    printf("5 - Exibir \n");
    printf("6 - Remover \n");
    printf("7 - Limpar \n");
}

void main(){
    int op, num, escolhaTurma, qtdFaltas;
    char nome[20];
    float mediaFinal;
    LDECircular turmaA, turmaB, turmaC;
    inicializar(&turmaA);
    inicializar(&turmaB);
    inicializar(&turmaC);

    while(op != 0){
        imprimirMenu();
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Escolha qual turma a inserir o aluno : \n");
                printf("1 - Turma A");
                printf("2 - Turma B");
                printf("3 - Turma C");
                scanf("%d", &escolhaTurma);

                printf("Insira o nome do aluno : ");
                gets(nome);
                printf("Insira a media final do aluno : ");
                scanf("%f",&mediaFinal);
                printf("Insira a quantidade de faltas do aluno : ");
                scanf("%d", &qtdFaltas);

                if(escolhaTurma == 1){
                    cadastrar(&turmaA,nome, mediaFinal, qtdFaltas);
                } else if (escolhaTurma == 2){
                    cadastrar(&turmaB,nome, mediaFinal, qtdFaltas);
                } else if (escolhaTurma == 3){
                    cadastrar(&turmaC,nome, mediaFinal, qtdFaltas);
                }
                break;
            case 2 :
                printf("Escolha qual turma a listar : \n");
                printf("1 - Turma A");
                printf("2 - Turma B");
                printf("3 - Turma C");
                scanf("%d", &escolhaTurma);
                if(escolhaTurma == 1){
                    listar(turmaA);
                } else if (escolhaTurma == 2){
                    listar(turmaB);
                } else if (escolhaTurma == 3){
                    listar(turmaC);
                }
                break;
            case 3 :
                //desenvolvendo
                break;
            case 4:
                //desenvolvendo
                break;
            case 5:
                //desenvolvendo
                break;
            case 6:
                //desenvolvendo
                break;
            case 7 :
                //desenvolvendo
                break;
            case 0:
                break;
            default :
                printf("Opcao Invalida\n");
                break;
        }       
    }
    
}