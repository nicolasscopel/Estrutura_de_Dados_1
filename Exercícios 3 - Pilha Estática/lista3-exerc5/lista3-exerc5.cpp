#include <iostream>
#include <string>
using namespace std;

struct Caixa{
	int codigo;
	float peso;

	Caixa()
	{
		codigo=0;
		peso=0;
	}

	Caixa(int c, float p)
	{
		codigo=c;
		peso=p;
	}
};


#include "pilha-caixa.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    Pilha p1;
    inicializaP(&p1, 10);

    //Caixa cx;
    //cx.codigo=10;
    //cx.peso=20.5;
    empilhaP(&p1, Caixa(10, 20.5));
    empilhaP(&p1, Caixa(5, 100.5));
    empilhaP(&p1, Caixa(2, 50.5));

    cout << buscaP(&p1, 5) << endl;
    cout << buscaP(&p1, 200) << endl;

    mostraP(&p1);


    //desalocar memória
    destroiP(&p1);



    return EXIT_SUCCESS;

}//final do main

