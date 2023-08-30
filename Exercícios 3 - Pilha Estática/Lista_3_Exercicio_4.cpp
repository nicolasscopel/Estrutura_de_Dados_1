/* 4. Fa�a um programa que usa uma pilha para armazenar o c�digo das cidades que fazem parte de um caminho.
� Inicialmente, o usu�rio deve informar o n�mero de cidades;
� Depois, o usu�rio deve informar o c�digo de cada cidade e incluir na pilha;
� Criar uma funcionalidade de busca de um c�digo na pilha: para fazer a busca deve usar uma pilha auxiliar;
a cada item verificado na pilha principal que for diferente do c�digo procurado, deve incluir na pilha
auxiliar; ap�s encontrar o valor, deve retornar os valores da pilha auxiliar para a pilha principal.
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
        cout << "\nInforme o c�digo da " << i << " cidade: ";
        cin >> valor;

        empilhaP(&p1, valor);
    }

    cout << "\nInforme o c�digo para buscar na pilha: ";
    cin >> valor;

    mostraP(&p1);

    resultado = buscaPAux(&p1, valor, tamPilha);

    if(resultado)
    {
        cout << "\nC�digo encontrado na pilha!";
    }
    else
    {
        cout << "\nC�digo n�o encontrado na pilha!";
    }


}
