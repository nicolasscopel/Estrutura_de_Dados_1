/*
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include <time.h>

using namespace std;

#include "include/lista.hpp"


main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");



	int valor; //valor deve ser do mesmo tipo de DadoNoLista (lista.hpp)
    No* aux; //usado na busca
    No* lista; //evite usar "list", pois é uma palavra reservada
    No* lista2; //evite usar "list", pois é uma palavra reservada


    inicializaL(&lista);
    inicializaL(&lista2);


    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 40);
    insereInicioL(&lista, 50);
    insereInicioL(&lista, 60);
    mostraL(&lista);

    insereInicioL(&lista2, 10);
    insereInicioL(&lista2, 20);
    insereInicioL(&lista2, 30);
    insereInicioL(&lista2, 40);
    insereInicioL(&lista2, 50);
    insereInicioL(&lista2, 60);
    mostraL(&lista2);


    cout << "\nFunção de Contar elementos da Lista \nTotal de elementos: " << totalL(&lista);

    cout << "\n";  mostraL(&lista);

    cout << "\nFunção de Verificar se duas Listas são iguais";
    if(igualL(&lista, &lista2))
    {
        cout << "\nSão iguais!\n";
    }
    else
    {
        cout << "\nNão são iguais!\n";
    }

    mostraL(&lista);
    mostraL(&lista2);


    cout << "\nFuncao de inserir um valor no final da Lista:";
    cout << "\n";
    mostraL(&lista);

    insereFinalL(&lista,5);

    mostraL(&lista);

    cout << "\nFuncao de remover o último elemento da Lista: " << endl;
    mostraL(&lista);


    char dateStr [9];

char timeStr [9];

_strdate(dateStr);

cout<<"Data"<<dateStr<<endl;

_strtime(timeStr);

cout << "Hora" << timeStr;









}
