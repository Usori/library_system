//##Cŕeditos: Victor Hugo (Usori)##

#include <stdio.h> // para usar printf
#include <string.h> // para usar strlen

/*##Função is_nonASCII##
 *
 * Parâmetro: char caracter
 * Resultado: Resulta 1 se caracter não estiver contido na tabela ASCII (não estendida)
							Resulta 0 se o caracter estiver contido na tabela ASCII (não estendida)
 *
*/
int is_nonASCII(char caracter){
	if(caracter<0 || caracter>127) return 1;
	
	return 0;

}

/*##Função count_nonASCII##
 *
 * Parâmetro: char* str
 * Resultado: Retorna a quantidade de carácteres que não estão contidos na tabela ASCII (não estendida)
 * Entrada: coração
 * Saída: 2 (por causa do ç e do ã)
 *
*/
int count_nonASCII(char* str){
	int count = 0;
	int i;
	for(i=0; str[i] != '\0'; i++){
		if(is_nonASCII(str[i])) count++;
	}
	return count/2;
}

/*##Função strlenOver##
 *
 * Parâmetro: char* str
 * Resultado: Retorna a quantidade de LETRAS de uma palavra
 * Entrada: coração
 * Saída: 7
 *
 * Notas: A função strlen original retornaria 9, pois strlen conta a quantidade de carácteres, e uma letra
 * especial(ã, é, ç, ô, ...), i.e., que não está contido na tabela ASCII não estendida, equivale à 2 carácteres.
 *
 */

int strlenOver(char* str){
	return (int)(strlen(str) - count_nonASCII(str));
}

/*##Função printfOver##
 *
 * Parâmetros: char* palavra, int espaco, int caracteres, int alinhamento
 * Resultado: Retorna os primeiros "int caracteres" do array de char palavra,
							que estarão contidos em um espaço espaco, podendo ter
							um alinhamento à direita ou a esquerda.
 * Entrada: "coração", 10, 5, 'l'
 * Saída: "coraç     "
 *
 * Entrada: "coração", 10, 5, 'r'
 * Saída: "     coraç"
 *
 * Entrada: "coração", 0, 7, 'r'
 * Saída: ""
 *
 * Entrada: "coração", 5, 7, 'r'
 * Saída: "coraç"
 *
 * Entrada: "coração", 10, 200, 'r'
 * Saída: "   coração"
 *
 * Entrada: "coração", 10, 200, 'l'
 * Saída: "coração   "
 *
 * Entrada: "coração", 10, 0, 'l'
 * Saída: "          "
 *
 */

void printfOver(char *palavra, int espaco, int caracteres, int alinhamento){
	int i;

	int numCaracteres = 0;	
	if(caracteres<= strlenOver(palavra)){
		numCaracteres = caracteres;
		char str = *(palavra);
	}else{
		numCaracteres = strlenOver(palavra);

	}

	if(numCaracteres > espaco) numCaracteres = espaco;
	
  int blank_space = espaco - numCaracteres;
	if(alinhamento == 'l' || alinhamento == 'L' || alinhamento == -1){
		//imprime a palavra
		for(i = 0; i<numCaracteres;i++){
			printf("%c",palavra[i]);
			
			if(is_nonASCII(palavra[i])){
				printf("%c",palavra[i+1]);
				i++;
				numCaracteres++;
			}
		}
		//imprime os espaços em branco
		for(i = 0; i<blank_space;i++){
				printf(" ");
		}
		
	}else{
		for(i = 0; i<blank_space;i++){
			printf(" ");
		}
		for(i = 0; i<numCaracteres;i++){
			printf("%c",palavra[i]);
			
			if(is_nonASCII(palavra[i])){
				printf("%c",palavra[i+1]);
				i++;
				numCaracteres++;
			}
		}


	}

}
