/*
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

	No *l1, *l2, *l3;

	inicializaL(&l1);
	inicializaL(&l2);
	inicializaL(&l3);
	insereInicioL(&l1,80);
	insereInicioL(&l1,70);
	insereInicioL(&l1,60);
    insereInicioL(&l1,50);
	insereInicioL(&l1,40);
	insereInicioL(&l1,30);
	insereInicioL(&l1,20);
	insereInicioL(&l1,10);

	insereInicioL(&l2,900);
	insereInicioL(&l2,800);
	insereInicioL(&l2,700);
	insereInicioL(&l2,600);
	insereInicioL(&l2,500);
	insereInicioL(&l2,400);
	insereInicioL(&l2,300);
	insereInicioL(&l2,200);
	insereInicioL(&l2,100);


	mesclar(&l1,&l2,&l3,5);


	mostraL(&l1,"L1");
	mostraL(&l2,"L2");
	mostraL(&l3,"L3");

	destroiL(&l1);
	destroiL(&l2);

	mostraL(&l3,"L3");




}
