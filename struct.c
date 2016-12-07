//##Cŕeditos: Victor Hugo (Usori)##

#include <stdlib.h> // para usar free malloc
#include <stdio.h>  // para usar printf e scanf
#include <string.h> // para usar strcmp
#include "livro.c" // para utilizar todas as opções de listas encadeadas
#include "stringOver.c" // para utilizar prints formatados para acentos

#define D_A_ACUTE -63  // Á

void main(){
	struct livro* book1;
	struct livro* book2;
	struct livro* book3;
	struct livro* book4;
	struct livro* book5;
  book1 = create_livro("Harry Potter e a Pedra Filosofal", 1);
	book2 = create_livro("Harry Potter a Câmara Secreta", 2);
	book3 = create_livro("Harry Potter e o Prisioneiro de Askabam", 3);
	book4 = create_livro("Animais Fantásticos e Onde Habitam", 8);
	book5 = create_livro("Harry Potter e as Relíquias da Morte", 7);
	
	struct pilha_livro* pilha;
	pilha = create_pilha_livro();
	pilha_livro_insere(pilha, book5);
	pilha_livro_insere(pilha, book1);
	pilha_livro_insere(pilha, book2);
	pilha_livro_insere(pilha, book3);
	pilha_livro_insere(pilha, book4);

	printf("%2d ", 1); printfOver(pilha->topo->nome, 40, 40, 'l'); printf("%3d\n", pilha->topo->id);
	printf("%2d ", 2); printfOver(pilha->topo->ant->nome, 40, 40, 'l'); printf("%3d\n", pilha->topo->ant->id);
	printf("%2d ", 3); printfOver(pilha->cabeca->prox->nome, 40, 40, 'l'); printf("%3d\n", pilha->cabeca->prox->id);
	printf("%2d ", 4); printfOver(pilha->cabeca->nome, 40, 40, 'l'); printf("%3d\n", pilha->cabeca->id);
	printf("(...)\n");
	printf("%2d ", 12); printfOver(pilha->cabeca->prox->prox->nome, 40, 40, 'l'); printf("%3d\n", pilha->cabeca->prox->prox->id);

	//Tentando acessar um elemento inválido da pilha, ele NÃO TRAVA O PROGRAMA. Resulta em um nó com indíce negativo e valor duvidoso ("Vazio") que pode ser tratado pelo o usuário!
	printf("%2d ", 13); printfOver(pilha_livro_get(pilha,10)->nome, 40, 40, 'l'); printf("%3d\n", pilha_livro_get(pilha,10)->id);
	printf("Segundo livro da lista: %s\n", pilha_livro_get(pilha,1)->nome);	
	printf("Topo da pilha: %s\n", pilha->topo->nome);
	printf("Quantidade de elementos da pilha: %d\n", pilha->elementos);
	pilha_livro_desempilha(pilha);
	printf("Topo da pilha: %s\n", pilha->topo->nome);
	printf("Quantidade de elementos da pilha: %d\n", pilha->elementos);
	pilha_livro_remove(pilha,1);
	printf("Segundo livro da lista: %s\n", pilha_livro_get(pilha,1)->nome);
	printf("Quantidade de elementos da pilha: %d\n", pilha->elementos);


}
