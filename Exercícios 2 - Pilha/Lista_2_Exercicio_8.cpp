/*8. Fa�a um programa que leia uma string e verifica se o texto � um pal�ndromo, ou seja, se a string �
escrita da mesma maneira de frente para tr�s e de tr�s para frente. Ignore espa�os e pontos. Exemplos: Osso, Radar, Ovo, Arara
Observa��es:
- Modificar a estrutura da Pilha para armazenas dados do tipo char.
- Use uma pilha para realizar a verifica��o do pal�ndromo, n�o � permitido o uso de vetores auxiliares. */

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilhachar.hpp"

bool palindromo(Pilha *p1, Pilha *pAux, int tamPilha);

main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;
	Pilha pAux;
    int tamPilha, menu;
    bool resultado;
    string valor;



	cout << "\nInforme um texto para ver se ele e palindromo: ";
	getline(cin, valor);

	tamPilha = valor.size();

	char palavraChar[tamPilha + 1];

	strcpy(palavraChar, valor.c_str());



	inicializaP(&p1, tamPilha);
    for (int i = 0; i < tamPilha; i++)
    {
        empilhaP(&p1, palavraChar[i]);
    }
    mostraP(&p1);

    inicializaP(&pAux, tamPilha);
    for (int i = tamPilha-1; i >= 0; i--)
    {
        empilhaP(&pAux, palavraChar[i]);
    }
    mostraP(&pAux);


    if (palindromo(&p1, &pAux, tamPilha))
    {
        cout << "\nEssa palavra � um pal�ndromo.";
    }
    else
        cout << "\nEssa palavra n�o � um pal�ndromo.";
}

bool palindromo(Pilha *p1, Pilha *pAux, int tamPilha)
{
    for (int i = 0; i < tamPilha; i++)
    {
        if (desempilhaP(p1) != desempilhaP(pAux))
        {
            return false;
        }
        return true;
    }
}










