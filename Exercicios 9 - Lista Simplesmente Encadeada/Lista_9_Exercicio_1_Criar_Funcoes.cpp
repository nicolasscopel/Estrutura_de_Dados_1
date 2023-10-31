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
    No* lista; //evite usar "list", pois � uma palavra reservada
    No* lista2; //evite usar "list", pois � uma palavra reservada
    No *listauniao;


    inicializaL(&lista);
    inicializaL(&lista2);
    inicializaL(&listauniao);


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


    cout << "\n --- Fun��o de Contar elementos da Lista \nTotal de elementos: " << totalL(&lista);

    cout << "\n";  mostraL(&lista);

    cout << "\n --- Fun��o de Verificar se duas Listas s�o iguais";
    if(igualL(&lista, &lista2))
    {
        cout << "\nS�o iguais!\n";
    }
    else
    {
        cout << "\nN�o s�o iguais!\n";
    }

    mostraL(&lista);
    mostraL(&lista2);


    cout << "\n --- Funcao de inserir um valor no final da Lista:";
    cout << "\n";
    mostraL(&lista);

    insereFinalL(&lista,5);

    mostraL(&lista);

    cout << "\n --- Funcao de retornar o �ltimo elemento da Lista: " << endl;
    mostraL(&lista);

    int dado = leFinalL(&lista);

    cout << "Valor do ultimo elemento: "<< dado << endl;

    mostraL(&lista);

    cout << "\n --- Funcao de remover o �ltimo elemento da Lista: " << endl;
    mostraL(&lista);
    cout << "Elemento removido do fim da lista: " << removeFinalL(&lista) << endl;
    cout << "Elemento removido do fim da lista: " << removeFinalL(&lista) << endl;

    mostraL(&lista);


    cout << "\n --- Funcao de ler o valor de uma posi��o do elemento da Lista: " << endl;
    mostraL(&lista);

    valor = lePosicao(&lista,3);

    cout << "\nValor do elemento da posicao 3 da lista: " << valor << endl;

    mostraL(&lista);

    cout << "\n --- Funcao para realizar a UNIAO DE DUAS LISTAS " << endl;


    cout << "Lista 1: "; mostraL(&lista);
    cout << "Lista 2: "; mostraL(&lista2);

    uniao(&lista,&lista2,&listauniao);

    cout << "\nLista Uniao: " << endl;

    mostraL(&listauniao);
    cout << "\n";

    cout << " --- Lista Uniao com o primeiro elemento retirado: " << endl;

    removeInicioL(&listauniao);
    mostraL(&listauniao);

    cout << "\nLista 1: "; mostraL(&lista);
    cout << "Lista 2: "; mostraL(&lista2);


















}
