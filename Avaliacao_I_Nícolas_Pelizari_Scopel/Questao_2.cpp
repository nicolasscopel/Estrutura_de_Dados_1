/*

ENCONTRAR VALORES REPETIDOS DE UMA PILHA
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilha.hpp"

int buscaPRepetidos(Pilha *p, int valor)
{
    int cont = 0;

   for(int i = p->topo ; i > p->base; i--)
   {
       if (valor == p->dados[i])
       {
           cont++;
       }

   }
   return cont;

}


void repetidos(Pilha *P, Pilha *R)
{
    Pilha aux;
    Pilha auxcopia;
    Pilha auxcopiarealiza;
    Pilha semrepetidos;
    inicializaP(&aux,15);
    inicializaP(&auxcopia,15);
    inicializaP(&auxcopiarealiza,15);
    inicializaP(&semrepetidos,15);

    int valor, cont = 0;
    int chave;

    while(!vaziaP(P))
    {
        valor = desempilhaP(P);
        empilhaP(&aux,valor);
        empilhaP(&auxcopia,valor);
        empilhaP(&auxcopiarealiza,valor);

    }

    while(!vaziaP(&auxcopiarealiza))
    {
        valor = desempilhaP(&auxcopiarealiza);
        empilhaP(P,valor);
    }

    while(!vaziaP(&auxcopia))
    {
        cont = 0;
        valor = desempilhaP(&auxcopia);
        cont = buscaPRepetidos(&aux,valor);

        if(cont >= 2)
        {
            if(buscaP(R,valor) == false)
            {
                empilhaP(R,valor);
            }

        }
    }

}


main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha P;
	Pilha R;

	inicializaP(&P,15);
	inicializaP(&R,15);

	empilhaP(&P,8);
	empilhaP(&P,9);
	empilhaP(&P,7);
	empilhaP(&P,5);
	empilhaP(&P,7);
	empilhaP(&P,6);
	empilhaP(&P,7);
	empilhaP(&P,0);
	empilhaP(&P,4);
	empilhaP(&P,8);
	empilhaP(&P,3);
	empilhaP(&P,4);
	empilhaP(&P,1);

	mostraP(&P);
	repetidos(&P,&R);
	mostraP(&R);
	mostraP(&P);


}
