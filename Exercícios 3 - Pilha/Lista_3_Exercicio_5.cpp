/* 5. Uma transportadora precisa de um sistema para gerenciar o carregamento de caixas nos caminhões da empresa.
Implemente um programa que atenda a necessidade da empresa, empregando uma pilha para definir a ordem do
carregamento e descarregamento das caixas em um caminhão.
• O programa deve possuir um menu com as opções:
o Definir quantidade de caixa – Criar uma pilha que suporte a quantidade de caixas informada.
o Carregar caixa - empilhar
o Descarregar caixa - desempilhar
o Mostar carga – mostrar pilha
o Sair do programa
• Cada caixa possui um código e peso;
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/pilha.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

}
