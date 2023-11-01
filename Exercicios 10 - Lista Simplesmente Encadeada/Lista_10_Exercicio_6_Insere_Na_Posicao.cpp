/*6. Crie uma função parar inserir em uma lista encadeada com base em uma posição/índice.
bool inserePosicao(No** lista, int pos, int valor);
L1: 2 5 3 9 9 8 7 6 2 1
inserePosicao(L1, 0, 100); //returna true
L1: 100 2 5 3 9 9 8 7 6 2 1
inserePosicao(L1, 3, 200); //returna true
L1: 100 2 5 200 3 9 9 8 7 6 2 1
inserePosicao(L1, 11, 300); //returna true
L1: 100 2 5 200 3 9 9 8 7 6 2 300 1 = 12
inserePosicao(L1, 13, 1000); //returna false, pois pos é inválido
L1: 100 2 5 200 3 9 9 8 7 6 2 300 1
inserePosicao(L1, -1, 1000); //returna false, pois pos é inválido
L1: 100 2 5 200 3 9 9 8 7 6 2 300 1
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
	bool teste;
	inicializaL(&lista);

	insereInicioL(&lista,1);
	insereInicioL(&lista,2);
	insereInicioL(&lista,6);
	insereInicioL(&lista,7);
	insereInicioL(&lista,8);
	insereInicioL(&lista,9);
	insereInicioL(&lista,9);
	insereInicioL(&lista,3);
	insereInicioL(&lista,5);
	insereInicioL(&lista,2);
	cout << "\nLista : ";
	mostraL(&lista);

    inserePosicao(&lista,0,100);
	mostraL(&lista);


	inserePosicao(&lista,3,200);
	mostraL(&lista);


    inserePosicao(&lista,11,300);
	mostraL(&lista);


	inserePosicao(&lista,13,1000);
	mostraL(&lista);


	inserePosicao(&lista,-1,1000);
	mostraL(&lista);






}
