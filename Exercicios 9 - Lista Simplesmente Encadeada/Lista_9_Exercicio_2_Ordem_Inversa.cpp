/*
2.
Considere uma lista encadeada L1 representando uma sequência de caracteres.
Construa uma função para imprimir a sequência de caracteres da lista L1 na ordem inversa.
Exemplo: para a lista L1={A,E,I,O,U}, a função deve imprimir “UOIEA”.
Observação: faça uso de uma lista auxiliar e as funções removeFinalL e insereFinalL do exercício anterior.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/listachar.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	No *lista;
	No *listainversa;
	inicializaL(&lista);
	inicializaL(&listainversa);

	char valor;

	insereFinalL(&lista,'A');
	insereFinalL(&lista,'E');
	insereFinalL(&lista,'I');
	insereFinalL(&lista,'O');
	insereFinalL(&lista,'U');

	mostraL(&lista);

	while(!vaziaL(&lista))
    {
        valor = removeFinalL(&lista);
        insereFinalL(&listainversa,valor);

    }
    mostraL(&listainversa);
}
