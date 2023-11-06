/*1. Construa uma função que recebe como parâmetros uma Lista L de valores inteiros e um valor X. A
função deve retirar os primeiros X valores da lista L, inserindo-os no fim de L. Use as funções de
inserção e remoção separadas.
Exemplo:
L: [3,5,8,9,12,11,7,10]
x: 4
L após a função: [12,11,7,10,3,5,8,9]
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

void alteraLista (No **l, int qtd)
{
    int cont = 0;
    int valor;

    while(cont != qtd)
    {
       valor = removeInicioL(l);


       insereFinalL(l,valor);


        cont++;
    }
    return;

}



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	No *lista;
	int qtd;
	inicializaL(&lista);

	insereFinalL(&lista,3);
	insereFinalL(&lista,5);
	insereFinalL(&lista,8);
	insereFinalL(&lista,9);
	insereFinalL(&lista,12);
	insereFinalL(&lista,11);
	insereFinalL(&lista,7);
	insereFinalL(&lista,10);

	mostraL(&lista);

	cout << "\nInforme a quantidade de elementos que desejar retirar do inicio e adicionar ao final: ";
	cin >> qtd;

	alteraLista(&lista,qtd);

	mostraL(&lista);



}
