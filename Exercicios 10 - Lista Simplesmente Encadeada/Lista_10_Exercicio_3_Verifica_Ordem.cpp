/*3. Faça uma função que verifica se uma lista encadeada está ordenada:
int verificaOrdem(No** lista);
Retorno da função:
0 – Ordem crescente
1 – Ordem decrescente;
2 – Não está ordenada.
Observação: É proibido o uso de listas auxiliares, percorrer os nós da lista
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/lista.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

    int valor;

	No *listacres;
	No *listadecres;
	No *listadesordenada;
	inicializaL(&listacres);
	inicializaL(&listadecres);
	inicializaL(&listadesordenada);

	insereFinalL(&listacres,1);
	insereFinalL(&listacres,2);
	insereFinalL(&listacres,3);
	insereFinalL(&listacres,4);

	insereFinalL(&listadecres,4);
	insereFinalL(&listadecres,3);
	insereFinalL(&listadecres,2);
	insereFinalL(&listadecres,1);

	insereFinalL(&listadesordenada,1);
	insereFinalL(&listadesordenada,5);
	insereFinalL(&listadesordenada,2);
	insereFinalL(&listadesordenada,4);

	mostraL(&listacres);
	mostraL(&listadecres);
	mostraL(&listadesordenada);


    valor =  verificaOrdem(&listacres);
    if(valor == 0)
    {
        cout << "\nOrdem Crescente";
    }
    else if(valor == 1)
    {
        cout << "\nOrdem Decrescente";
    }
    else
    {
        cout << "\nNão está ordenado";
    }


    valor = verificaOrdem(&listadecres);
    if(valor == 0)
    {
        cout << "\nOrdem Crescente";
    }
    else if(valor == 1)
    {
        cout << "\nOrdem Decrescente";
    }
    else
    {
        cout << "\nNão está ordenado";
    }


    valor = verificaOrdem(&listadesordenada);
    if(valor == 0)
    {
        cout << "\nOrdem Crescente";
    }
    else if(valor == 1)
    {
        cout << "\nOrdem Decrescente";
    }
    else
    {
        cout << "\nNão está ordenado";
    }

    cout << "\n";
    mostraL(&listacres);
	mostraL(&listadecres);
	mostraL(&listadesordenada);


}
