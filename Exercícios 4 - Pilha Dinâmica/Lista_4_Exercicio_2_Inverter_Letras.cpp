/* 2. Empregando pilha, implemente um programa para inverter a ordem das letras nas palavras em uma frase. Por
exemplo, na frase “teste de pilha”, o programa deverá exibir “etset ed ahlip”.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilha-dinamicachar.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;

	string texto;
	int tam;

	cout << "\nInforme um texto para ser invertido: ";
	getline(cin, texto);

	tam = texto.size();

	//cout << texto;

	for(int i = 0; i < tam; i++)
    {
        if(texto[i] != ' ')
        {
            empilhaP(&p1, texto[i]);
        }

        if(texto[i] == ' ' || i == tam -1)
        {
            while(!vaziaP(&p1))
            {
               cout << desempilhaP(&p1);
            }
            cout << " ";

        }

    }

}
