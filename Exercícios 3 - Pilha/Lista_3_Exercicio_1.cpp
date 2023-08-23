/* 1. Faça um programa para ler uma string e após empilhar os caracteres que são letras em uma pilha P1 e empilhar
os que são dígitos em outra pilha P2. Ao final, desempilhe os dados de P2 e em seguida, os de P1, imprimindo-os
na tela.
Dicas:
− Use as funções isdigit e isalpha da biblioteca
− A pilha P1 deve armazenar letras. Dessa forma, altere o arquivo para atender esta
necessidade.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

#include "include/pilhachar.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

    Pilha p1;
    Pilha p2;
	string leitura;
	int tam;


	cout << "\nInforme uma string para ser lida: ";
	getline(cin,leitura);

	cout << leitura;

	tam = leitura.size();

	cout << tam;

	for(int i = 0; i < tam; i++)

}
