# library_system

Deixe os arquivos "stringOver.c", "struct.c" e "livro.c" na mesma pasta.

A biblioteca "struct.c" ainda está em teste, mas até o momento não apresentou nenhum erro. Qualquer anomalia da mais absurda
possível (como falta de memória do computador) pode ser tratada pelo usuário, pois o programa imprime o erro em um arquivo
"logerror.txt" e oferece opções que evite que o mesmo pare. Por exemplo, você nunca terá um nó NULL, todo nó terá pelo menos um
ID negativo e um dado "estranho" que no caso está sendo escrito "Vazio", além de ter sua referência ao elemento anterior e
sucessor inicializadas como NULL por garantia.

As funções "stringOver.c" lhe trará grandes vantagens com a estrutura dinâmica encadeada de "livro.c", pois você não terá que
tratar nenhum problema com acentuação, ainda mais em conjunto com a lista encadeada.

Por fim, o arquivo struct.c dá apenas uma prévia do que essas duas bibliotecas juntas aplicadas corretamente são capazes, 
mostrando que você poderá trabalhar tanto com listas buscando elementos por índices, obtendo facilmente a quantidade de
elementos, inserindo e removendo os elementos por índices e é claro, com as funções básicas de toda lista, insere e desempilha!


Notas adicionais: A última função que é a "arquivo.c" está sendo trabalhada ainda, ela fechar o conjunto, lhe dando a
oportunidade de trabalhar com abertura, escrita e fechamento de arquivo das mais diversas formas possíveis.
