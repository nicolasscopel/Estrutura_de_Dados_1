/*7. Dados duas listas L1 e L2, crie uma função para computar a lista L3 que é a intersecção de L1 e L2.
Exemplo:
L1: 2 5 3 9 9 8 7 6 2 1
L2: 20 30 100 6 1 5 9
L3: 5 9 6 1
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

	No *lista1;
	No *lista2;
	No *listaintersec;

	inicializaL(&lista1);
	inicializaL(&lista2);
	inicializaL(&listaintersec);

	insereInicioL(&lista1,1);
	insereInicioL(&lista1,2);
	insereInicioL(&lista1,6);
	insereInicioL(&lista1,7);
	insereInicioL(&lista1,8);
	insereInicioL(&lista1,9);
	insereInicioL(&lista1,9);
	insereInicioL(&lista1,3);
	insereInicioL(&lista1,5);
	insereInicioL(&lista1,2);
	cout << "\nLista 1: ";
	mostraL(&lista1);



	insereInicioL(&lista2,9);
	insereInicioL(&lista2,5);
	insereInicioL(&lista2,1);
	insereInicioL(&lista2,6);
	insereInicioL(&lista2,100);
	insereInicioL(&lista2,30);
	insereInicioL(&lista2,20);
    cout << "\nLista 2: ";
	mostraL(&lista2);

    interseccaoListas(&lista1,&lista2,&listaintersec);

    cout << "\nLista Intersecao: ";
    mostraL(&listaintersec);

    cout << "\nLista 1: ";
	mostraL(&lista1);
	cout << "\nLista 2: ";
	mostraL(&lista2);



}
