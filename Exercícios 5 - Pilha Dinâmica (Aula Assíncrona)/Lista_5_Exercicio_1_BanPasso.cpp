/* O banco BanPasso possui diversos clientes. O cadastro de novos clientes do banco é realizado perante o
preenchimento de uma ficha, a qual possui os seguintes dados: código, nome, idade, saldo em conta (valor do
depósito inicial). Com a ficha de um cliente preenchida, o cadastro é concluído empilhando na pilha CADASTRO.
Não pode haver clientes com o mesmo código cadastrado e a ficha é empilhada sempre mantendo a ordem
alfabética dos clientes como no exemplo baixo: */

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

struct Ficha
{
    int codigo;
    string nome;
    int idade;
    float saldo;

    Ficha ()
    {
        codigo = 0;
        nome = "";
        idade = 0;
        saldo = 0;
    }

    Ficha (int c, string n, int i, float s)
    {
        codigo = c;
        nome = n;
        idade = i;
        saldo = s;
    }
};

#include "include/pilha-dinamica-structficha.hpp"

void insereOrdenadoP(Pilha *p, Ficha f)
{
    Pilha aux;

    if(buscaViaCodigoP(p,f.codigo))
    {
        return;
    }

    while(!vaziaP(p) && p->topo->dado.nome < f.nome)
    {
        Ficha x = desempilhaP(p);
        empilhaP(&aux, x);

    }
    empilhaP(p,f);

    while(!vaziaP(&aux))
    {
        Ficha x = desempilhaP(&aux);
        empilhaP(p, x);

    }

}




main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;

	insereOrdenadoP(&p1, Ficha(1,"Ana",20,3000));
	insereOrdenadoP(&p1, Ficha(2,"Nivaldo",15,1000));
	insereOrdenadoP(&p1, Ficha(3,"Otaviano",16,2000));
	insereOrdenadoP(&p1, Ficha(4,"Maria",60,2000));

	mostraP(&p1);









}
