/*3.
Crie uma função recursiva para imprimir uma lista encadeada na ordem inversa.
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

void inverte(No *n)
{
    if(!n) /// ==NULL
    {
        return;
    }
    inverte(n->prox);
    cout << n->dado << ", ";
}


main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	No *lista;
	inicializaL(&lista);

	insereInicioL(&lista,10);
	insereInicioL(&lista,20);
	insereInicioL(&lista,30);
	insereInicioL(&lista,40);
	insereInicioL(&lista,50);

	mostraL(&lista);

	cout << "\n --- Lista Invertida --- \n";

	inverte(lista);

}
