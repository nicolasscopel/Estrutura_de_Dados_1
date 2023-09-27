/* 3. Implemente uma função para dividir uma fila dinâmica de valoresinteiros. A função deve receber como parâmetro
uma fila F1 com os valores inteiros, uma fila vazia F2 e um valor inteiro N. A função deve dividir a fila F1 em duas,
de tal forma que F2 comece no primeiro nó (elemento) logo após a primeira ocorrência de N na fila original.
a) Exemplo de declaração da função:
void separaF (int N, Fila *F1, Fila *F2);
a) Exemplo de separação:
F1[1, 2, 3, 4, 5, 6, 7, 8, 9]
F2[]
separaF (5, &F1, &F2);
F1[1, 2, 3, 4, 5]
F2[6, 7, 8, 9]
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/fila-dinamica-separa.hpp"

main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Fila f1;
	Fila f2;

	enfileiraF(&f1,1);
	enfileiraF(&f1,2);
	enfileiraF(&f1,3);
	enfileiraF(&f1,4);
	enfileiraF(&f1,5);
	enfileiraF(&f1,6);
	enfileiraF(&f1,7);
	enfileiraF(&f1,8);
	enfileiraF(&f1,9);
	enfileiraF(&f1,10);
	enfileiraF(&f1,11);

	mostraF(&f1);
	mostraF(&f2);

	separaF(5,&f1,&f2);

    mostraF(&f1);
	mostraF(&f2);

}
