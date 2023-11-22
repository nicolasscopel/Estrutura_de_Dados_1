/*
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/lista_dupla.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

    Lista lista = Lista();
    Lista ret = Lista();

    cout << "\n --- FUNCAO PARA REMOVER AS OCORRENCIAS DE DETERMINADO VALOR --- " << endl;
    insereInicioL(&lista,10);
    insereInicioL(&lista,20);
    insereInicioL(&lista,30);
    insereInicioL(&lista,10);
    insereInicioL(&lista,60);
    insereInicioL(&lista,40);
    insereInicioL(&lista,10);
    mostraL(&lista);

    removeTodos(&lista,10);

    mostraL(&lista);
    mostrarInversoL(&lista);



    cout << "\n --- FUNCAO PARA RETORNAR UMA LISTA COM OS X ELEMENTOS MAIORES DA LISTA --- " << endl;
    mostraL(&lista);

    int x;
    cout << "Informe o valor de X: ";
    cin >> x;

    ret = leMaiores(&lista,x);

    mostraL(&ret);
    mostrarInversoL(&ret);



    cout << "\n\n ----- TESTE FINAL -----" << endl;

    mostraL(&lista);
    insereInicioL(&lista,65);
    insereInicioL(&lista,165);
    insereInicioL(&lista,365);
    insereInicioL(&lista,89);
    insereInicioL(&lista,52);
    insereInicioL(&lista,65);
    mostraL(&lista);
    removeTodos(&lista,65);
    mostraL(&lista);

    cout << "Informe o valor de X: ";
    cin >> x;

    ret = leMaiores(&lista,x);

    mostraL(&ret);
    mostrarInversoL(&ret);







}
