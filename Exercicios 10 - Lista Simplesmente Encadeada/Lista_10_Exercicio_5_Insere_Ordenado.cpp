/*5. Implemente uma função e inserir de forma ordenada em uma lista encadeada.
void insereOrdenado(No** lista, int valor);
Observação:
• É proibido o uso de listas auxiliares, percorrer os nós da lista e ajustar os ponteiros;
• Considere que a lista está inicialmente vazia.
Dicas:
• Use como base a função removeValor, ajustando os ponteiros dos nós e levando em
consideração se o elemento será inserido no início da lista, no meio ou no final.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/lista.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	No *lista;
	inicializaL(&lista);


	insereOrdenado(&lista,5);
	mostraL(&lista);

	insereOrdenado(&lista,0);
	mostraL(&lista);

	insereOrdenado(&lista,8);
	mostraL(&lista);

	insereOrdenado(&lista,2);
	mostraL(&lista);

	insereOrdenado(&lista,4);
	mostraL(&lista);

	insereOrdenado(&lista,9);
	mostraL(&lista);

	insereOrdenado(&lista,1);
	mostraL(&lista);

	insereOrdenado(&lista,105);
	mostraL(&lista);

	insereOrdenado(&lista,-10);
	mostraL(&lista);

}
