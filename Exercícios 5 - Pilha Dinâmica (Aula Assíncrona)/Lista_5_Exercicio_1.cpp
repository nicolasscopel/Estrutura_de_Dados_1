/* O banco BanPasso possui diversos clientes. O cadastro de novos clientes do banco � realizado perante o
preenchimento de uma ficha, a qual possui os seguintes dados: c�digo, nome, idade, saldo em conta (valor do
dep�sito inicial). Com a ficha de um cliente preenchida, o cadastro � conclu�do empilhando na pilha CADASTRO.
N�o pode haver clientes com o mesmo c�digo cadastrado e a ficha � empilhada sempre mantendo a ordem
alfab�tica dos clientes como no exemplo baixo: */

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

struct Cadastro
{
    int codigo;
    string nome;
    int idade;
    float saldo;
};

#include "include/pilha-dinamica-struct.hpp"




main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Pilha p1;

	empilhaP(&p1, Cadastro(1,"Nicolas",20,1500));








}
