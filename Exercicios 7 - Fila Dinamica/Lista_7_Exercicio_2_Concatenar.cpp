/*  2. Considerando duas filas dinâmicas, implemente uma função para concatenar duas filas, as quais devem ser
recebidas por parâmetro. Exemplos de declaração da função:
Fila concatenaF (Fila *f1, Fila *f2);
void concatenaF (Fila *f1, Fila *f2, Fila *fConcatenada);
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/fila-dinamica-concatena.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Fila f1;
	Fila f2;
	Fila fConcatenada;

	enfileiraF(&f1,1);
	enfileiraF(&f1,2);
	enfileiraF(&f1,3);
	enfileiraF(&f1,4);

	enfileiraF(&f2,5);
	enfileiraF(&f2,6);
	enfileiraF(&f2,7);
	enfileiraF(&f2,8);

	concatenaF(&f1,&f2,&fConcatenada);



}
