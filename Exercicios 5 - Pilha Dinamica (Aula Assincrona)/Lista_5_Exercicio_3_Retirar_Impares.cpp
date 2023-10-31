/* 3. Crie uma função para remover todos os elementos ímpares de uma pilha P, mantendo a mesma ordem relativa
dos elementos remanescentes. Exemplo:*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

#include "include/pilha-dinamica.hpp"

void retiraimparesP(Pilha *p1)
{
    Pilha aux;
    int valor;

    while(!vaziaP(p1))
    {
        valor = espiaP(p1);


        if(valor % 2 == 0)
        {
            valor = desempilhaP(p1);
            empilhaP(&aux,valor);
        }
        else
        {
            desempilhaP(p1);
        }
    }

    while(!vaziaP(&aux))
    {
        valor = desempilhaP(&aux);
        empilhaP(p1,valor);
    }

    destroiP(&aux);

}

main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;
	int tam;


	cout << "\nInforme quantos elementos deseja ter na pilha: ";
	cin >> tam;

	for(int i = 0; i < tam; i++)
    {
        empilhaP(&p1, rand() % 20);
    }

    mostraP(&p1);

    retiraimparesP(&p1);

    mostraP(&p1);


}
