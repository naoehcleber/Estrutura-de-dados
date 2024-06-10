/* Arquivo com acesso direto via hashing */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 53
typedef struct carro {
	char placa[8];
	char marca[15];
	char modelo[15];
	char cor[15];
	int status;  // 1 - ativo ou 0 - removido
} CARRO;

typedef struct noTabela {
	char placa[8];
	int posicao;
	struct noTabela* prox;
	struct noTabela* ant;
} NO;

FILE* prepararArquivo(char nome[]);
void fecharArquivo(FILE* arq);
int buscar(NO* tabelaHashing[], char placa[]);
void cadastrar(FILE* arq, NO* tabelaHashing[]);
void consultar(FILE* arq, NO* tabelaHashing[]);
void alterar(FILE* arq, NO* tabelaHashing[]);
void remover(FILE* arq, NO* tabelaHashing[]);
void exibirCadastro(FILE* arq);
void criarIndice(FILE* arq, NO* tabelaHashing[]);
void inserirTabelaHash(NO* tabelaHashing[], char placa[], int pos);
void desalocarIndice(NO* tabelaHashing[]);
int hashing(char placa[]);
void exibirOpcoes();

void inicializarTabelaHashing(NO* tabelaHashing[]);

int main() {
	char nomeArq[] = "carros.dat";
	int op;
	FILE* cadastro;
	NO* tabelaHashing[N];
	cadastro = prepararArquivo(nomeArq);
	if (cadastro == NULL)
		printf("Erro na abertura do arquivo. Programa encerrado \n");
	else {
		
		criarIndice(cadastro, tabelaHashing);
		do {
			exibirOpcoes();
			scanf("%d",&op); fflush(stdin);
			switch (op) {
			case 1: cadastrar(cadastro, tabelaHashing);
				break;
			case 2: consultar(cadastro, tabelaHashing);
				break;
			case 3: alterar(cadastro, tabelaHashing);
				break;
			case 4: remover(cadastro, tabelaHashing);
				break;
			case 5: exibirCadastro(cadastro);
				break;
			case 0: fecharArquivo(cadastro);
			printf("Arquivo fechado\n");
				desalocarIndice(tabelaHashing);
				break;
			default: printf("Opcao invalida \n");
			}
		} while (op != 0);
	}
	return 0;
}

FILE* prepararArquivo(char nome[]) {
	FILE* aux;
	aux = fopen(nome, "r+b");
	if (aux == NULL)
		aux = fopen(nome, "w+b");
	return aux;
}

void inicializarTabelaHashing(NO* tabelaHashing[]){
	for(int i = 0; i < N; i++){
		tabelaHashing[i] = NULL;
	}
}

void fecharArquivo(FILE* arq) {
	/* Apagar, fisicamente, os registros que foram deletados logicamente.
	* 1 - Criar um arquivo novo (vazio).
	* 2 - Copiar todos os registros de STATUS igual a 1 do arquivo de carros para o arquivo novo.
	* 3 - Fechar os dois arquivos.
	* 4 - Remover o arquivo de carros.
	* 5 - Renomear o arquivo novo com o nome "carros.dat".
	*/
	FILE* copia = prepararArquivo("copia.dat");
	CARRO carro;
	fseek(arq, 0, SEEK_SET);
	fseek(copia, 0, SEEK_SET);
	while(fread(&carro, sizeof(CARRO), 1, arq)){
		
		if(carro.status == 1){
			fwrite(&carro, sizeof(CARRO), 1, copia);
		}
	}
	fclose(arq);
	fclose(copia);
	remove("carros.dat");
	rename("copia.dat", "carros.dat");
}

void criarIndice(FILE* arq, NO* tabelaHashing[]) {
	/* preencher a tabela de hashing com as chaves dos registros que est�o armazenados no arquivo
	1 - Ler o arquivo registro a registro at� o final
	2 - Para cada registro lido, aplicar a fun��o de hashing � chave (ou seja, a placa)
	3 - O resultado da fun��o indica a posi��o na tabela onde a chave ser� inserida
	4 - Criar n�, preencher com a chave e a posi��o dela no arquivo e inserir na tabela, 
	na lista encadeada correspondente, de forma que a lista permane�a ordenada.
	*/
	CARRO carro;
	NO* aux;
	int index, pos;
	inicializarTabelaHashing(tabelaHashing);
	
    
    fseek(arq, 0, SEEK_SET); // Move o ponteiro para o inicio,garantindo que a leitura do arquivo comece no comeco
    while (fread(&carro, sizeof(CARRO), 1, arq)) {//enquanto ainda houverem arquivos o fread le eles
        
		if (carro.status == 1) { // Considerar apenas carros ativos
			pos = ftell(arq) - sizeof(CARRO);
            inserirTabelaHash(tabelaHashing, carro.placa, pos);
        }
       
    }
}

void desalocarIndice(NO* tabelaHashing[]) {
	/* Desalocar os n�s que comp�em as listas da tabela de hashing.
	*/
	
	for(int i = 0; i < N; i++){
		NO* atual = tabelaHashing[i];
		while(atual!= NULL){
			NO* aux;
			aux = atual;
			atual = atual->prox;
			free(aux);
		}
		tabelaHashing[i] = NULL;
	}

}

void exibirOpcoes() {
	printf("Op��es \n");
	printf("1 - Cadastrar um carro \n");
	printf("2 - Consultar carro \n");
	printf("3 - Alterar dados do carro \n");
	printf("4 - Remover carro \n");
	printf("5 - Exibir carros cadastrados \n");
	printf("0 - Encerrar programa \n");
	printf("Informe a opcao: ");
}

int buscar(NO* tabelaHashing[], char placa[]) {
	/* procurar na tabela de hashing a placa desejada e retornar a posi��o da placa no arquivo
	   1 - aplicar a fun��o de hashing na chave (ou seja, na placa)
	   2 - procurar a chave na lista indicada pelo resultado da fun��o (usar busca sequencial melhorada)
	   3 - caso encontre, retornar a posi��o da chave no arquivo
	   4 - caso n�o encontre, retornar -1 */
	int index = hashing(placa);
	NO* atual;
	
	atual = tabelaHashing[index];
	while(atual != NULL){
		if(strcmp(atual->placa, placa) == 0){
			return atual->posicao;
		} else if(strcmp(atual->placa, placa) > 0){
			return -1;
		}
		atual = atual->prox;
	}

	return -1;
}

void inserirTabelaHash(NO* tabelaHashing[], char placa[], int pos) {
	/* Inserir na tabela hashing, na lista encadeada indicada pela fun��o de hashing, 
	* uma chave e sua posi��o no arquivo.
	* 1 - Aplicar a fun��o de hashing � chave (ou seja, a placa)
	* 2 - O resultado da fun��o indica a posi��o na tabela onde a chave ser� inserida
	* 3 - Criar n�, preencher com a chave e a posi��o dela no arquivo e inserir na tabela, 
	* na lista encadeada correspondente, de forma que a lista permane�a ordenada.
	*/
	
	int index;
	NO* novo, *atual;

	novo = (NO*) malloc(sizeof(NO));

	index = hashing(placa);

	strcpy(novo->placa, placa);
	novo->posicao = pos;
	novo->prox = NULL;
	novo->ant = NULL;
	
	if(tabelaHashing[index] == NULL){
		tabelaHashing[index] = novo;
		
	} else {
		atual = tabelaHashing[index];
		if(strcmp(atual->placa, placa) == 0){
			printf("Placa ja registrada, insercao cancelada!\n");
			return;
		}
		if(strcmp(atual->placa, placa) < 0){
			atual->prox = novo;
			novo->ant = atual;
			atual = novo;
			novo->prox = atual->prox;
		} else if (strcmp(atual->placa, placa) > 0){
			atual->ant = novo;
			novo->prox = atual;
			atual = novo;
			novo->ant = atual->ant;
		}
	}
}

void removerTabelaHash(NO* tabelaHashing[], char placa[], int posTabela) {
	/* Remover da tabela de hashing o n� que contem a placa passada como par�metro. 
	* Recebe como par�metro tamb�m a posi��o na tabela onde a chave se encontra.
	*/
	
    NO* atual = tabelaHashing[posTabela];
    NO* anterior = NULL;

    while (atual != NULL && strcmp(atual->placa, placa) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Placa não encontrada na tabela de hashing.\n");
        return;
    }

    if (anterior == NULL) { // Remover o primeiro nó da lista
        tabelaHashing[posTabela] = atual->prox;
    } else { // Remover um nó no meio ou no final da lista
        anterior->prox = atual->prox;
    }

    free(atual);
	
}

int hashing(char placa[]) {
	/* A fun��o �hashing� recebe com par�metro a chave (ou seja, a placa) e 
	* retorna o valor calculado segundo o m�todo da permuta��o para chaves alfanum�ricas 
	* (visto em sala).
	*/
	int placaCodigo = 0;
	for(int i = 0; i < strlen(placa); i++){
		placaCodigo += placa[i]; 
	}
	return placaCodigo % N;
}

void cadastrar(FILE* arq, NO* tabelaHashing[]) {
	/* Cadastrar o registro do carro no arquivo e inserir a chave (placa) na tabela de hashing.
	* 1 - Solicita a placa do carro a ser cadastrado.
	* 2 - Procura pela placa na tabela de hashing.
	* 3 - Caso encontre, informa que o carro j� est� no cadastro.
	* 4 - Caso n�o encontre, solicita os demais dados do carro, o insere no final do arquivo.
	* 5 - Insere a chave, juntamente com sua posi��o no arquivo, na tabela de hashing.
	*     Utilize para isso o procedimento "inserirTabelaHash".
	*/
	CARRO carro;
	int resultadoBusca, estado;
	printf("Informe a placa a ser buscada : ");
	scanf("%s",&carro.placa);
	
	resultadoBusca = buscar(tabelaHashing, carro.placa);
	printf("%d\n", resultadoBusca);
	
	if(resultadoBusca != -1){
		printf("Carro já cadastrado! \n");
		return;
	} else {
		printf("Insira a marca do carro : ");
		scanf("%s", &carro.marca);
		printf("Insira o modelo do carro : ");
		scanf("%s", &carro.modelo);
		printf("Insira a cor do carro : ");
		scanf("%s", &carro.cor);
		carro.status = 1;

		//insercao no final do arquivo
		fseek(arq, 0, SEEK_END);
		int pos = ftell(arq);
		estado = fwrite(&carro, sizeof(CARRO), 1, arq);
		if(estado == 1){
			printf("Gravacao bem sucedida\n");
		} else {
			printf("Gravacao mal sucedida\n");
		}

		inserirTabelaHash(tabelaHashing, carro.placa, pos);
		printf("Insercao na tabela hashing efetuada\n");

		
	}


}

void consultar(FILE* arq, NO* tabelaHashing[]) {
	/* Consultar o registro do carro no arquivo
     * 1 - Solicita a placa do carro a ser consultado.
     * 2 - Procura pela placa na tabela de hashing.
     * 3 - Caso n�o encontre, informa que o carro n�o est� no cadastro.
     * 4 - Caso encontre, vai ao arquivo, na posi��o indicada, 
	 *     l� o registro do carro e exibe seus dados.
    */
   	CARRO carro;
	int index;
	int posicaoHashing;
	int posicao;
   	printf("Insira a placa que deseja consultar : ");
   	scanf("%s", &carro.placa);

	// index = hashing(carro.placa);
	posicaoHashing = buscar(tabelaHashing, carro.placa);
	printf("%d\n", posicaoHashing);

	if(posicaoHashing == -1){
		printf("Nao achado \n");
		return;
	}
	
	fseek(arq, posicaoHashing, SEEK_SET);
	//ele está sempre lendo o segundo registro do arquivo

	fread(&carro, sizeof(CARRO), 1 , arq);
	printf("%d\n", carro.status);
	if(carro.status == 1){
		printf("Placa : %s\n", carro.placa);
		printf("Marca : %s\n", carro.marca);
		printf("Modelo : %s\n", carro.modelo);
		printf("Cor : %s\n",carro.cor);
	} else {
		printf("O registro foi deletado\n");
	}
}

void alterar(FILE* arq, NO* tabelaHashing[]) {
	/* Alterar o registro do carro no arquivo
	 * 1 - Solicita a placa do carro a ser alterado.
	 * 2 - Procura pela placa na tabela de hashing.
	 * 3 - Caso n�o encontre, informa que o carro n�o est� no cadastro.
	 * 4 - Caso encontre, vai ao arquivo, na posi��o indicada, l� o registro do carro e exibe seus dados.
	 *     Pergunta ao usu�rio quais dados deseja alterar. Efetiva a altera��o dos dados no arquivo.
	*/
	CARRO carro, carroConsulta;
	FILE* copia = prepararArquivo("copia.dat");
	int posicaoHashing;
	int escolha;
	
	printf("Insira a placa do carro : ");
	scanf("%s", &carro.placa);

	posicaoHashing = buscar(tabelaHashing, carro.placa);
	
	if(posicaoHashing == -1){
		printf("Carro nao presente no cadastro\n");
		return;
	}

	fseek(arq, posicaoHashing, SEEK_SET);
	fread(&carro, sizeof(CARRO), 1 , arq);
	if(carro.status == 1){
		printf("Placa : %s\n", carro.placa);
		printf("Marca : %s\n", carro.marca);
		printf("Modelo : %s\n", carro.modelo);
		printf("Cor : %s\n",carro.cor);

		

		while(escolha != 0){
			printf("Qual dado deseja alterar ?\n");
			printf("1 - Marca\n");
			printf("2 - Modelo\n");
			printf("3 - Cor\n");
			printf("0 - Terminar alteracoes\n");
			scanf("%d", &escolha);
			switch (escolha)
			{
			case 1:// em desenvolvimento
				printf("Insira a marca do carro : ");
				scanf("%s", &carro.marca);
				break;
			case 2: // em desenvolvimento
				printf("Insira o modelo do carro : ");
				scanf("%s", &carro.modelo);
				break;
			case 3:// em desenvolvimento
				printf("Insira a cor do carro : ");
				scanf("%s", &carro.cor);
				break;
			case 0: 
				break;
			default:
				break;
			}
		}

		fseek(arq, 0, SEEK_SET);
		while(fread(&carroConsulta, sizeof(CARRO), 1 , arq)){
			if(strcmp(carroConsulta.placa, carro.placa) == 0){
				//em desenvolvimento
				fwrite(&carro, sizeof(CARRO), 1, copia);
				continue;
			}else {
				fwrite(&carroConsulta, sizeof(CARRO), 1 ,copia);
			}
		}

		fclose(arq);
		fclose(copia);
		remove("carros.dat");
		rename("copia.dat", "carros.dat");
		prepararArquivo("carros.dat");
		criarIndice(arq, tabelaHashing);
	} else {
		printf("O registro foi deletado\n");
	}
}

void remover(FILE* arq, NO* tabelaHashing[]) {
	/* Remover o registro do carro do arquivo
	 * 1 - Solicita a placa do carro a ser removido.
	 * 2 - Procura pela placa na tabela de hashing.
	 * 3 - Caso n�o encontre, informa que o carro n�o est� no cadastro.
	 * 4 - Caso encontre, vai ao arquivo, na posi��o indicada, l� o registro do carro e exibe seus dados.
	 *     Pergunta ao usu�rio se deseja realmente remov�-lo. 
	 *     Efetiva a remo��o que consiste em alterando no arquivo o STATUS 
	       do registro do carro para 0 (removido).
	 * 5 - Remove o n� que cont�m a chave, juntamente com sua posi��o no arquivo, da tabela de hashing.
	*      Utilize para isso o procedimento "removerTabelaHash".
	*/
	CARRO carro, carroConsulta;
	FILE* copia = prepararArquivo("copia.dat");
	int posicaoHashing, posTabela;
	int escolha;
	
	printf("Insira a placa do carro : ");
	scanf("%s", &carro.placa);

	posicaoHashing = buscar(tabelaHashing, carro.placa);
	posTabela = hashing(carro.placa);

	if(posicaoHashing == -1){
		printf("Carro nao presente no cadastro\n");
		return;
	}
	
	fseek(arq, posicaoHashing, SEEK_SET);
	fread(&carro, sizeof(CARRO), 1 , arq);

	if(carro.status == 0){
		printf("Carro ja removido !\n");
		return;
	}

	printf("Placa : %s\n", carro.placa);
	printf("Marca : %s\n", carro.marca);
	printf("Modelo : %s\n", carro.modelo);
	printf("Cor : %s\n",carro.cor);

	printf("REALMENTE DESEJA REMOVER ESTE REGISTRO ?\n");
	printf("1 - SIM\n");
	printf("2 - NAO\n");
	scanf("%d", &escolha);
	if(escolha == 2){
		printf("Remocao cancelada\n");
		return;
	} else {
		carro.status = 0;
		printf("Status alterado \n");

		removerTabelaHash(tabelaHashing, carro.placa, posTabela);

		printf("Remocao realizada com sucesso");

		
	}

		

}

void exibirCadastro(FILE* arq) {
	/* Exibe todos os registros de carros ATIVOS constantes no arquivo. */
	CARRO carro;

	fseek(arq, 0, SEEK_SET);
	while(fread(&carro, sizeof(CARRO), 1, arq)){
		
		if(carro.status == 1){
			printf("Placa : %s\n",carro.placa);
			printf("Marca : %s\n",carro.marca);
			printf("Modelo: %s\n",carro.modelo);
			printf("Cor : %s\n",carro.cor);
		}
	}
}