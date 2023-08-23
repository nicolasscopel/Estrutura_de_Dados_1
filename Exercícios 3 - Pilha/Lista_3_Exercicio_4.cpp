/* 4. Faça um programa que usa uma pilha para armazenar o código das cidades que fazem parte de um caminho.
• Inicialmente, o usuário deve informar o número de cidades;
• Depois, o usuário deve informar o código de cada cidade e incluir na pilha;
• Criar uma funcionalidade de busca de um código na pilha: para fazer a busca deve usar uma pilha auxiliar;
a cada item verificado na pilha principal que for diferente do código procurado, deve incluir na pilha
auxiliar; após encontrar o valor, deve retornar os valores da pilha auxiliar para a pilha principal.
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



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;
	int tamPilha, valor;
	bool resultado;

	cout << "\nInforme o numero de cidades: ";
	cin >> tamPilha;

	inicializaP(&p1, tamPilha);

	for(int i = 0; i < tamPilha; i++)
    {
        cout << "\nInforme o código da " << i << " cidade: ";
        cin >> valor;

        empilhaP(&p1, valor);
    }

    cout << "\nInforme o código para buscar na pilha: ";
    cin >> valor;

    mostraP(&p1);

    resultado = buscaPAux(&p1, valor, tamPilha);

    if(resultado)
    {
        cout << "\nCódigo encontrado na pilha!";
    }
    else
    {
        cout << "\nCódigo não encontrado na pilha!";
    }


}
