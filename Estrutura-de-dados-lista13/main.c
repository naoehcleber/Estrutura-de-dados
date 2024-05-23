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

    if(isEmpty(*lista) == 1){
        printf("Lista vazia, inserindo primeira entrada\n");
        novo = criarNo(nome, mediaFinal, qtdFaltas);

        novo->anterior = lista->fim;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->fim = novo;
        
        lista->qntd++;
        lista->inicio->anterior = lista->fim;
    } else {
        while(atual != NULL){
            atual = lista->inicio;
            if(strcmp(nome, atual->nome) == 0){
                //se o nome a ser inserido e o no na lista for igual
                printf("Nome identico encontrado, insercao cancelada\n");
                return;
            } else if(strcmp(nome, lista->inicio->nome) == -1){
                //nome vier antes do primeiro / insercao no inicio
                novo = criarNo(nome, mediaFinal, qtdFaltas);
                
                novo->prox = lista->inicio->prox;
                novo->anterior = NULL;
                lista->inicio = novo;

                lista->qntd++;
                //retomar a circularidade
                lista->inicio->anterior = lista->fim;
            } else if(strcmp(nome, lista->fim->nome) == 1){
                //depois do ultimo / insercao no fim
                novo = criarNo(nome, mediaFinal, qtdFaltas);
                
                novo->prox = NULL;
                novo->anterior =lista->fim;
                lista->fim = novo;

                lista->qntd++;
                lista->fim->prox = lista->inicio;
            } else {
                //insercao no meio
                if(strcmp(nome, atual->nome) == -1){
                    novo = criarNo(nome,mediaFinal, qtdFaltas);

                    novo->prox = atual;
                }   
            }
            atual = atual->prox;
        }
    }
}

void listar(LDECircular lista){
    Node *aux;
    aux = lista.inicio;
    for(int i = 0; i < lista.qntd; i++){
        printf("Nome : %s\n", aux->nome);
        printf("Quantidade de faltas : %d\n", aux->qtdFaltas);
        printf("Media Final : %2.f\n", aux->mediaFinal);
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
    int op, num, escolhaTurma, qntdFaltas;
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
                printf("Escolha a turma a qual o aluno pertence: \n");
                printf("1 - Turma A\n");
                printf("2 - Turma B\n");
                printf("3 - Turma C\n");
                scanf("%d", &escolhaTurma);
                printf("Insira o nome do aluno : \n");
                scanf("%s", &nome);
                printf("Insira o media final do aluno : \n");
                scanf("%f",&mediaFinal);
                printf("Insira o qntd de faltas do aluno : \n");
                scanf("%d",&qntdFaltas);
                if(escolhaTurma == 1){
                    cadastrar(&turmaA, nome, mediaFinal, qntdFaltas);
                }else if(escolhaTurma == 2){
                    cadastrar(&turmaB, nome, mediaFinal, qntdFaltas);
                }else if (escolhaTurma == 3){
                    cadastrar(&turmaC, nome, mediaFinal, qntdFaltas);
                }
                break;
            case 2 :
                printf("Escolha a turma a qual exibir: \n");
                printf("1 - Turma A\n");
                printf("2 - Turma B\n");
                printf("3 - Turma C\n");
                scanf("%d", &escolhaTurma);

                if(escolhaTurma == 1){
                    if(isEmpty(turmaA) == 1){
                        printf("Lista Vazia\n");
                    }
                    listar(turmaA);
                }else if(escolhaTurma == 2){
                    if(isEmpty(turmaB) == 1){
                        printf("Lista Vazia\n");
                    }
                    listar(turmaB);
                }else if (escolhaTurma == 3){
                    if(isEmpty(turmaC) == 1){
                        printf("Lista Vazia\n");
                    }
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