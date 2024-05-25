#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noLDE{
    struct noLDE *anterior;
    char nome[50];
    float mediaFinal;
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
    Node *novo, *atual, *proximo;

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
        if(strcmp(nome, lista->inicio->nome) < 0){
            //insercao no inicio
            novo = criarNo(nome, mediaFinal, qtdFaltas);

            novo->prox = lista->inicio->prox;
            novo->anterior = NULL;
            lista->inicio = novo;
            lista->qntd++;

            lista->inicio->anterior = lista->fim;
        }else if (strcmp(nome, lista->inicio->nome) == 0){
            printf("Aluno ja cadastrado, insercao cancelada!\n");
            return;
        } else if (strcmp(nome, lista->fim->nome) > 0){
            //insercao no fim
            novo = criarNo(nome, mediaFinal, qtdFaltas);

            novo->anterior = lista->fim->anterior;
            novo->prox = NULL;
            lista->fim->prox = novo;
            lista->fim = novo;
            
            lista->qntd++;
            lista->fim->prox = lista->inicio;
        }else if (strcmp(nome, lista->fim->nome) == 0){
            printf("Aluno ja cadastrado, insercao cancelada!\n");
            return;
        }else {
            //insercao no meio
            atual = lista->inicio;
            proximo = atual->prox;
            while(proximo != lista->inicio){
                if(strcmp(nome, proximo->nome) < 0){
                    novo = criarNo(nome, mediaFinal, qtdFaltas);
                    atual->prox = novo;
                    novo->anterior = atual;
                    atual = novo;
                    novo->prox = proximo;
                    lista->qntd++;
                    return;
                }else if (strcmp(nome, proximo->nome) == 0){
                    printf("Aluno ja cadastrado, insercao cancelada!\n");
                    return;
                } else {
                    atual = atual->prox;
                }
            }                
        }
    }
}


void listar(LDECircular lista){
    Node *aux;
    aux = lista.inicio;
    for(int i = 0; i < lista.qntd; i++){
        printf("Nome : %s\n",aux->nome);
        printf("Media final : %f\n",aux->mediaFinal);
        printf("Quantidade de faltas : %d\n", aux->qtdFaltas);

        aux = aux->prox;
    }
}

Node* consultar(LDECircular lista, char nome[]){
    Node *aux;
    aux = lista.inicio;

    if(isEmpty(lista) == 1){
        return NULL;
    }

    for(int i = 0; i < lista.qntd; i++){
        if(strcmp(aux->nome, nome) == 0){
            return aux;
        }

        aux = aux->prox;
    }
    return NULL;
}

void alterarMedia(LDECircular *lista, char nome[]){
    Node *aux;
    Node *consulta;
    float novaMedia;

    consulta = consultar(*lista, nome);
    if(isEmpty(*lista) == 1){
        printf("Nenhum aluno cadastrado\n");
    } else {
        aux = lista->inicio;
        for(int i = 0; i < lista->qntd; i++){
            if(aux == consulta){
                printf("Aluno cadastrado, prosseguindo...\n");
                break;
            }
            aux = aux->prox;
        }
        if(aux == consulta){
            printf("Insira a nova media do aluno : ");
            scanf("%f", &novaMedia);

            aux->mediaFinal = novaMedia;
        }   

    }
}

void alterarFaltas(LDECircular *lista, char nome[]){
    Node *aux;
    Node *consulta;
    int faltasNovas, escolha;

    consulta = consultar(*lista, nome);
    if(isEmpty(*lista) == 1){
        printf("Nenhum aluno cadastrado\n");
    } else {
        aux = lista->inicio;
        for(int i = 0; i < lista->qntd; i++){
            if(aux == consulta){
                printf("Aluno cadastrado, prosseguindo...\n");
                break;
            }
            aux = aux->prox;
        }
        if(aux == consulta){
            printf("Deseja adicionar ou abonar faltas ?\n");
            printf("1 - Adicionar \n");
            printf("2 - Abonar\n");
            scanf("%d",&escolha);
            if(escolha == 1){
                printf("Insira quantas faltas adicionar : ");
                scanf("%d", &faltasNovas);
                aux->qtdFaltas = aux->qtdFaltas + faltasNovas;
            } else if (escolha == 2){
                printf("Insira quantas faltas abonar : ");
                scanf("%d", &faltasNovas);
                aux->qtdFaltas = aux->qtdFaltas - faltasNovas;
            }
        }   

    }
}

void exibir(LDECircular lista, char nome[]){
    Node *aux;
    Node *consulta;
    int faltasNovas, escolha;

    consulta = consultar(lista, nome);
    if(isEmpty(lista) == 1){
        printf("Nenhum aluno cadastrado\n");
    } else {
        aux = lista.inicio;
        for(int i = 0; i < lista.qntd; i++){
            if(aux == consulta){
                printf("Aluno cadastrado, prosseguindo...\n");
                break;
            }else if (i == lista.qntd && aux != consulta){
                printf("Aluno nao encontrado, cancelando operacao...\n");
                return;
            }
            aux = aux->prox;
        }
        if(aux == consulta){
            printf("Media Final : %f\n", aux->mediaFinal);
            printf("Quantidade de faltas : %d\n", aux->qtdFaltas);
        }   

    }
}

void remover(LDECircular *lista, char nome[]){
    Node *aux;
    Node* consulta;

    consulta = consultar(*lista, nome);
    if(isEmpty(*lista)){
        printf("Nenhum aluno cadastrado \n");
    } else {
        aux = lista->inicio;
        for(int i = 0; i < lista->qntd; i++){
            if(aux == consulta){
                printf("Aluno cadastrado, prosseguindo...\n");
                break;
            }else if (i == lista->qntd && aux != consulta){
                printf("Aluno nao encontrado, cancelando operacao...\n");
                return;
            }
            aux = aux->prox;
        }
        if(aux == consulta){
            if(aux == lista->inicio){
                //remocao no inicio
                lista->inicio = lista->inicio->prox;
                lista->fim->prox = lista->inicio;
                lista->qntd--;
                free(aux);
            } else if (aux == lista->fim){
                //remocao no final
                lista->fim = lista->fim->anterior;
                lista->fim->prox = lista->inicio;
                lista->qntd--;
                free(aux);
            } else {
                //remocao no meio
                
            }
        }
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
                printf("1 - Turma A\n");
                printf("2 - Turma B\n");
                printf("3 - Turma C\n");
                scanf("%d", &escolhaTurma);

                printf("Insira o nome do aluno : ");
                scanf("%s",nome);
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
                printf("1 - Turma A\n");
                printf("2 - Turma B\n");
                printf("3 - Turma C\n");
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
                printf("Escolha qual turma : \n");
                printf("1 - Turma A\n");
                printf("2 - Turma B\n");
                printf("3 - Turma C\n");
                scanf("%d", &escolhaTurma);
                printf("Digite o nome do aluno o qual deseja alterar a media : ");
                scanf("%s",nome);
                if(escolhaTurma == 1){    
                    alterarMedia(&turmaA, nome);
                } else if (escolhaTurma == 2){
                    alterarMedia(&turmaB, nome);
                } else if (escolhaTurma == 3){
                   alterarMedia(&turmaC, nome);
                }
                break;
            case 4:
                printf("Escolha qual turma : \n");
                printf("1 - Turma A\n");
                printf("2 - Turma B\n");
                printf("3 - Turma C\n");
                scanf("%d", &escolhaTurma);
                printf("Digite o nome do aluno o qual deseja alterar a media : ");
                scanf("%s",nome);
                if(escolhaTurma == 1){    
                    alterarFaltas(&turmaA, nome);
                } else if (escolhaTurma == 2){
                    alterarFaltas(&turmaB, nome);
                } else if (escolhaTurma == 3){
                   alterarFaltas(&turmaC, nome);
                }
                break;
            case 5:
                printf("Escolha qual turma : \n");
                printf("1 - Turma A\n");
                printf("2 - Turma B\n");
                printf("3 - Turma C\n");
                scanf("%d", &escolhaTurma);
                printf("Digite o nome do aluno o qual deseja consultar : ");
                scanf("%s",nome);
                if(escolhaTurma == 1){    
                    exibir(turmaA, nome);
                } else if (escolhaTurma == 2){
                    exibir(turmaB, nome);
                } else if (escolhaTurma == 3){
                   exibir(turmaC, nome);
                }
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