/* 3. Implemente uma fun��o para dividir uma fila din�mica de valoresinteiros. A fun��o deve receber como par�metro
uma fila F1 com os valores inteiros, uma fila vazia F2 e um valor inteiro N. A fun��o deve dividir a fila F1 em duas,
de tal forma que F2 comece no primeiro n� (elemento) logo ap�s a primeira ocorr�ncia de N na fila original.
a) Exemplo de declara��o da fun��o:
void separaF (int N, Fila *F1, Fila *F2);
a) Exemplo de separa��o:
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
