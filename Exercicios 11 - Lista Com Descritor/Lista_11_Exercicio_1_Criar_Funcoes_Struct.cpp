/*
1 - A empresa XYZ possui uma lista com as informações de todos os funcionários. Para cada funcionário, as
informações de código, nome, idade e salário são registradas. Com base nessas informações, crie um programa
em C++ para gerenciar a lista de funcionários como segue:


*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/lista_descritor_funcionario.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Lista lista = Lista();
    Funcionario x;
    float media = 0;

	insereFimL(&lista,Funcionario(1,"Nicolas",20,1000.f));
	insereFimL(&lista,Funcionario(32,"Marcos",15, 599.f));
	insereFimL(&lista,Funcionario(21,"Igor",65, 501.f));
	cout << lista << endl;

    cout << "\n --- LER O INICIO ---" << endl;
	x = lerInicioL(&lista);
	cout << x << endl;


	cout << "\n --- REMOVER O INICIO ---"<< endl;
	x = removeInicio(&lista);
	cout << x;


    cout << "\n";
	x = removeInicio(&lista);
	cout << x;

	cout << "\n";
	x = removeInicio(&lista);
	cout << x;

    cout << "\n";
	cout << lista << endl;
	insereInicioL(&lista,Funcionario(1,"Nicolas",20,1000.f));
	insereFimL(&lista,Funcionario(32,"Marcos",15, 599.f));
	insereFimL(&lista,Funcionario(21,"Igor",65, 501.f));
	cout << lista << endl;

	cout << "\n --- LER FINAL ---"<< endl;
	x = lerFimL(&lista);
	cout << x << endl;

	cout << "\n --- IMPRIMIR A MEDIA SALARIAL DA EMPRESA ---"<< endl;
	cout << lista << endl;
	cout << "Media Salarial: ";
	media =  mediaSalarial(&lista)/lista.tamanho;
	cout << media;
	cout << "\n" << lista << endl;

    cout << "\n --- IMPRIMIR OS FUNCIONARIOS COM SALARIO MENOR QUE A MEDIA SALARIAL DA EMPRESA ---"<< endl;
    cout << lista << endl;
    imprimeMenorMedia(&lista,media);
    cout << "\n " <<lista << endl;

    cout << "\n --- ORDENAR LISTA POR NOME ---"<< endl;
    cout << lista << endl;
    ordenaL(&lista);
    cout << "\n " <<lista << endl;









}
