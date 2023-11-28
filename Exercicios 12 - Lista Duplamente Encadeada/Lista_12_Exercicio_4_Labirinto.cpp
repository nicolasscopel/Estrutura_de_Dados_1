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

#include "include/lista_duplastring.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Lista lista = Lista();

	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"baixo");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"cima");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"baixo");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"cima");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"cima");
	insereFinalL(&lista,"cima");
	insereFinalL(&lista,"cima");
	insereFinalL(&lista,"cima");
	insereFinalL(&lista,"esquerda");
	insereFinalL(&lista,"cima");
	insereFinalL(&lista,"direita");
	insereFinalL(&lista,"direita");

	mostraL(&lista);

	mostraCaminhoVoltaL(&lista);


}
