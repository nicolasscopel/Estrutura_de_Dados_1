/* 2) Construa um programa que:
a. Aloque dinamicamente um vetor de 10 posições;
b. Gravar as 10 posições do vetor com valores aleatório, intervalo de 20 a 50;
c. Mostre o vetor;
d. Libere a memória alocada.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

main()
{
    srand(time(NULL));

	setlocale (LC_ALL, "Portuguese");

	int *V = new int [10];

	for(int i = 0; i < 10; i++)
	{
        V[i] = rand() % 31 + 20;
	}

	cout << "\nVetor Gerado: [";

	for(int i = 0; i < 10; i++)
	{
        cout << V[i] << " ";
	}

	cout << "]" << endl;

	delete []V;


}
