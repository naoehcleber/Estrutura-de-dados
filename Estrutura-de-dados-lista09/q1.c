#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noLDE{
    struct noLDE *anterior;
    int info;
    char descricao[20];
    struct noLDE *prox;
}TNoLDE;

typedef struct lde{
    TNoLDE *inicio;
    TNoLDE *fim;
    int qntd;
}LDE;

void inicializar(LDE *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qntd = 0;
}

int isFull(LDE lista){
    return 0;
}

int isEmpty(LDE lista){
    if(lista.qntd == 0){
        return 1;
    }else {
        return 0;
    }
}

TNoLDE* buscar(LDE lista, char string[]){
    //buscar que busque por string
    TNoLDE* aux;
    if(isEmpty(lista) == 1){
        return NULL;
    } else{
        if(strcmp(lista.inicio->descricao , string) == 1){
            return lista.inicio;
        } else if (strcmp(lista.fim->descricao , string) == 1){
            return lista.fim;
        } else{
            aux = lista.inicio->prox;
            while(aux != NULL){
                if(strcmp(aux->descricao ,string) == 1){
                    //se eh igual
                    return aux;
                } else {
                    aux = aux->prox;
                }
            }
        }
    }
}


void inserirTarefa(LDE *lista, int valor, char string[]){
    //inseirir ordenadamente
    TNoLDE *novo;
    TNoLDE* retorno;
    TNoLDE *atual;
    retorno = buscar(*lista, string);
    if(retorno != NULL){
        printf("Valor repetido. cancelando insercao \n");
    }
    else if(isEmpty(*lista) == 1){
        //se a lista estiver vazia
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
        strcpy(novo->descricao, string);

        novo->anterior = lista->fim;
        novo->prox = lista->inicio;

        lista->inicio = novo;
        lista->fim = novo;
        lista->qntd++;
    }else if(valor < lista->inicio->info){
        //se o valor a ser inserido for menor que do inicio da fila
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
        strcpy(novo->descricao, string);
        novo->prox = lista->inicio->prox;
        novo->anterior = NULL;
        lista->inicio = novo;
        lista->qntd ++;
    } else if (valor > lista->fim->info){
        //valor for maior que o ultimo
        novo = (TNoLDE*)malloc(sizeof(TNoLDE));
        novo->info = valor;
        strcpy(novo->descricao, string);
        novo->prox = NULL;
        novo->anterior = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qntd++;
    } else {
        atual = lista->inicio->prox;
        while(1){
            if(valor < atual->info){
                novo = (TNoLDE*)malloc(sizeof(TNoLDE));
                novo->info = valor;
                strcpy(novo->descricao, string);
                novo->prox = atual;
                break;
            } else{
                atual = atual->prox;
            }
        }
    }

}

void buscarTarefa(LDE lista, char string[]){
    //
}

void executarTarefa(LDE *lista){
    //remover a tarefa com maior prioridade
    //a tarefa de maior prioridade sempre vai ser a primeira
    //remover do inicio da lista
    TNoLDE *aux;

    if(isEmpty(*lista) == 1){
         printf("Lista vazia \n");
    }
    else if(lista->inicio == lista->fim){
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->inicio->anterior = NULL;
        lista->qntd--;
        free(aux);
    }
}


void list(LDE lista){
    TNoLDE* aux;

    aux = lista.inicio;

    while(aux != NULL){
        printf("%d) %s\n",aux->info, aux->descricao);
        aux = aux->prox;
    }
    printf("\n");
    
}



void cancelarTarefa(LDE *lista, char string[]){
    TNoLDE *aux;
    aux = buscar(*lista, string);
    if(aux == NULL){
        printf("Valor nao esta na lista \n");
    
    }else {
        if(aux == lista->inicio && lista->inicio == lista->fim){
            aux = buscar(*lista,string);
            lista->inicio = NULL;
            lista->fim = NULL;
            free(aux);
            lista->qntd--;
        }
        else if(aux == lista->inicio){
            lista->inicio = lista->inicio->prox;
            lista->inicio->anterior = NULL;
            free(aux);

            lista->qntd--;
        } else if (aux == lista->fim){
            lista->fim = lista->fim->anterior;
            lista->fim->prox = NULL;
            free(aux);
            lista->qntd--;
        } else {
            aux = buscar(*lista, string);
            aux->prox->anterior = aux->anterior;
            aux->anterior->prox = aux->prox;
            free(aux);
            lista->qntd--;

        }
    }
}

void alterarPrioridade(LDE *lista){
    
}

void exibirOpcoes() {
    printf("Opcoes: \n");
    printf("1 - Inserir valor ordenado na lista \n");
    printf("2 - Procurar tarefa na lista \n");
    printf("3 - Executar tarefa \n");
    printf("4 - Cancelar tarefa \n");
    printf("5 - Exibir descricao + prioridade \n");
    printf("6 - Alterar prioridade \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opção desejada: ");
}


void main(){
    LDE minhaLista;
    int valor, op;
    char desc[20];

    inicializar(&minhaLista);

    do {
        exibirOpcoes();
        scanf("%d",&op);
        switch (op) {
        case 1: printf("Informe o a prioridade da tarefa: ");
            scanf("%d",&valor);
            printf("Informe a descricao da tarefa: ");
            scanf("%s", &desc);
            inserirTarefa(&minhaLista, valor,desc);
            break;
        case 2: printf("Informe o elemento a ser buscado: ");
            scanf("%s",&desc);
            buscar(minhaLista, desc);
            break;
        case 3: 
            ExecutarTarefa(&minhaLista);
            break;
        case 4: 
            printf("Insira o valor que deseja cancelar : ");
            scanf("%s",&desc);
            cancelarTarefa(&minhaLista, desc);
            break;
        case 5: list(minhaLista);
            break;
        case 6: //alterarPrioridade(&minhaLista);
            break;
        case 0: printf("Fim de programa! \n");
            break;
        default: printf("Opção inválida! \n");
        }
    } while (op != 0);
}