//##Cŕeditos: Victor Hugo (Usori)##

#include <stdlib.h> // para usar free e malloc
#include <string.h> // para usar strcat

struct livro{
	int id;
	char* nome;
	struct livro* ant;
	struct livro* prox;

};

struct livro* create_livro(char* nome, int id){
	FILE *log;
	log = fopen("logerror.txt", "a+");

	struct livro* book = (struct livro*) malloc (sizeof(struct livro));
  if(book == NULL){
		if(log != NULL){
			fprintf(log, "Erro ao alocar memória para a criação do livro\n");
			fclose(log);
		}
		return NULL;
	}
	book->nome = nome;
	book->id = id;
}

struct pilha_livro{
	struct livro* topo;
	int elementos;
	struct livro* cabeca;

};

struct pilha_livro* create_pilha_livro(){
	FILE *log;
	log = fopen("logerror.txt", "a+");

	struct pilha_livro* pilha = (struct pilha_livro*) malloc (sizeof(struct pilha_livro));
	if(pilha == NULL){
		if(log != NULL){
			fprintf(log, "Erro ao alocar memória para a pilha de livros");
			fclose(log);
		}
		return NULL;
	}
	pilha->topo = NULL;
	pilha->cabeca = NULL;
	pilha->elementos = 0;
}

void pilha_livro_insere(struct pilha_livro* pilha, struct livro* book){
	FILE *log;
	log = fopen("logerror.txt", "a+");

	if(pilha == NULL){
		if(log != NULL){
			fprintf(log, "Null pointer exception - Erro ao tentar utilizar a pilha fornecida\nCertifique-se que tenha usado a função create_pilha_livro() antes\n");
			fclose(log);
		}
		return;
	}

  if(book == NULL){
		if(log != NULL){
			fprintf(log, "Null pointer exception - Ponteiro inválido para inserir o livro");
			fclose(log);
		}
		return;
	}

	if(pilha->elementos == 0){
		pilha->topo = book; // faz o topo ser o livro inserido
		pilha->cabeca = book; // faz o topo ser a cabeca
		pilha->elementos++; // incrementa a quantidade de elementos
	}else{
		book->ant = pilha->topo; // faz o livro anterior ao livro inserido ser o topo
		pilha->topo->prox = book; // o próximo livro do topo é o livro inserido
		pilha->topo = book; // o topo agora é o livro inserido
		pilha->elementos++; // incrementa a quantidade de elementos
	}

}

struct livro* pilha_livro_get(struct pilha_livro* pilha, int index){
	FILE *log;
	log = fopen("logerror.txt", "a+");
	struct livro* temp = (struct livro*) malloc (sizeof(struct livro));

	if(pilha == NULL){
		if(log != NULL){
			fprintf(log, "Null pointer exception - Ponteiro inválido para acessar uma pilha\n");
			fclose(log);
		}
		temp->nome = "Vazio"; // para evitar que o programa pare
		temp->id = -1;	// para evitar que o programa pare
		return temp; // retorna um objeto com nome Vazio e índice -1, para o usuário tratar a excessão, evitando assim que o programa trave
	}

	if(index>pilha->elementos-1){
		
		if(log != NULL){
			fprintf(log, "Array index out of bounds exception - Erro ao tentar acessar o elemento %d da pilha\n", index); // acessando uma posição inválida
			fclose(log);
		}
		temp->nome = "Vazio"; // para evitar que o programa pare
		temp->id = -1; // para evitar que o programa pare
		return temp; // retorna um objeto com nome Vazio e índice -1, para o usuário tratar a excessão, evitando assim que o programa trave
	}
	int i;

	temp = pilha->cabeca;
	for(i = 1; i<=index; i++){
	temp = temp->prox;

	}
	return temp;
}

void pilha_livro_remove(struct pilha_livro* pilha, int index){
	FILE *log;
	log = fopen("logerror.txt", "a+");
	if(pilha == NULL){
		if(log != NULL){
			fprintf(log, "Erro ao tentar utilizar a pilha fornecida\nCertifique-se que tenha usado a função create_pilha_livro() antes\n");
			fclose(log);
		}
		return;
	}


	if(index>pilha->elementos-1){
		
		if(log != NULL){
			fprintf(log, "Array index out of bounds exception - Erro ao tentar acessar o elemento %d da pilha\n", index); // acessando uma posição inválida
			fclose(log);
		}
		return;
	}
	
	struct livro *book = pilha_livro_get(pilha, index);

	if(book->ant == NULL && book->prox == NULL){
		pilha->cabeca = NULL;
		pilha->topo = NULL;
		free(book);
		pilha->elementos--;		

	}else{
		if(book->ant == NULL || book->prox == NULL){
			if(book->ant == NULL){
					book->prox->ant = NULL;
					pilha->cabeca = book->prox;
					free(book);
					pilha->elementos--;					

			}else{
				book->ant->prox = NULL;
				pilha->topo = book->ant;
				free(book);
				pilha->elementos--;				

			}
		}else{
			book->ant->prox = book->prox;
			book->prox->ant = book->ant;
			free(book);
			pilha->elementos--;			

		}		


	}

	
}

void pilha_livro_desempilha(struct pilha_livro* pilha){
	FILE *log;
	log = fopen("logerror.txt", "a+");

	if(pilha == NULL){
		if(log != NULL){
			fprintf(log, "Null pointer exception - Erro ao tentar utilizar a pilha fornecida\nCertifique-se que tenha usado a função create_pilha_livro() antes\n");
			fclose(log);
		}
		return;
	}

	if(pilha->elementos == 0) return;

	if(pilha->elementos == 1){
		pilha->cabeca = NULL; // redundância proposital para evitar qualquer tipo de falha miraculosa do usuário
		free(pilha->topo);
		pilha->topo = NULL;
		pilha->elementos--;
		return;
	}

	// poderíamos chamar a função pilha_livro_remove, mas para uma maior consistência do programa não deixaremos essa função MUITO IMPORTANTE em função de outra
	
	pilha->topo->ant->prox = NULL;
	pilha->topo = pilha->topo->ant;
	free(pilha->topo);
	pilha->elementos--;

	

}


