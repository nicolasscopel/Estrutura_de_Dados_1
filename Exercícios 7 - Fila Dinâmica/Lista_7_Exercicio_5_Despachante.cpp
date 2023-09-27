/* 5. O Despachante Passo Fundo � especializado em requerimentos e encaminhamentos na documenta��o de
ve�culos. Quando um cliente chega na empresa, ele deve informar os seguintes dados para a cria��o de uma ficha de
atendimento: nome, idade, sexo, cidade e placa do ve�culo.
Ap�s o preenchido dos dados da ficha, o funcion�rio guarda a ficha em uma pilha, sendo que a ficha cuja a
cidade � Passo Fundo s�o empilhadas em PILHAPF e as fichas de outras cidades s�o empilhadas na pilha PILHAGERAL.
Agora voc� deve escrever um programa que implementa o sistema para controlar tudo que foi descrito:
h) Criar ficha de atendimento - o usu�rio deve informar os dados da ficha de atendimento e, em seguida, a ficha
deve ser empilhada na pilha correspondente;
i) Mostrar os dados das fichas de atendimento de todos os clientes (das duas as pilhas).
j) Listar as fichas da pilha PILHAPF na ordem em que eles foram preenchidas (imprimir a pilha na ordem inversa);
k) Mostrar informa��es dos clientes da pilha PILHAGERAL: n�meros de clientes de cada sexo e m�dia aritm�tica
da idade dos clientes.
l) Mostrar a placa do ve�culo da pessoa mais velha (os dados est�o armazenados nas pilhas PILHAPF e
PILHAGERAL).
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/fila-dinamica.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

}
