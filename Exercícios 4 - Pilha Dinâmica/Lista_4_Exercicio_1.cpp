/* 1. Desenvolva uma função para retornar a média aritmética dos valores armazenados na pilha.
Observação: Percorrer os elementos da pilha usando um laço de repetição, acessando o primeiro elemento pelo
ponteiro “topo” e os demais elementos com o ponteiro “prox”, semelhante a lógica usada para implementar a
função mostraP.

*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilha-dinamica.hpp"

float calculaMedia(Pilha *p)
{
    float medianotas = 0;
    int cont = 0;


    if(vaziaP(p) == false)
    {

        NoPilha *no = p->topo;
        while (no != NULL)
        {
            medianotas += no->dado;
            cont++;
            no = no->prox;
        }

    }

    return medianotas/cont;
}

main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;

	float media;
	int nota;

	for(int i = 0; i < 10; i++)
    {
        nota = rand() % 10;
        empilhaP(&p1, nota);

    }

    mostraP(&p1);

    media = calculaMedia(&p1);

    cout << "\nMedia das notas: " << media;

    destroiP(&p1);

}
