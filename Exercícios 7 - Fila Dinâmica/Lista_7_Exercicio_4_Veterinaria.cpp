/* 4. A Veterin�ria Passo Fundo realiza atendimentos para diferentes tipos de animais. Quando um cliente chega com
seu animal na veterin�ria, ele deve informar os seguintes dados para a cria��o de uma ficha de atendimento:
� Ficha de atendimento: nome, idade, tipo (S-selvagem, D-dom�stico) e quadro cl�nico (E-est�vel, G-grave).
Ap�s o cliente informar os dados ao funcion�rio da empresa, a ficha de atendimento � criada e, com base nos
dados fornecidos, a ficha de atendimento � adicionada em uma das seguintes filas:
� Fila Priorit�ria � animais com quadro cl�nico grave;
� Fila N�o Priorit�ria � animais com quadro cl�nico est�vel.
O atendimento das filas deve seguir a ordem especificada abaixo:
1. Primeiramente, as fichas da Fila Priorit�ria devem ser atendidas com base nas seguintes regras.
a. Quando h� fichas em ambas as filas, no m�ximo tr�s fichas consecutivas da Fila Priorit�ria
podem ser atendidas, ou seja, a cada tr�s fichas atendidas da Fila Priorit�ria, uma ficha da Fila
N�o Priorit�ria deve ser atendida (caso houver);
b. N�o havendo fichas na Fila N�o Priorit�ria, o sistema pode atender mais que tr�s fichas
consecutivas da Fila Priorit�ria.
2. Por fim, quando n�o h� fichas na Fila Priorit�ria, uma ficha da Fila N�o Priorit�ria deve ser atendida.
Quando uma ficha � atendida, o funcion�rio da empresa retira a ficha da fila e guarda em uma pilha, sendo
que as fichas dos animais do tipo S s�o empilhadas na pilha ANIMALS e as fichas dos animais do tipo D s�o empilhadas
na pilha ANIMALD.

Agora voc� deve escrever um programa que implementa o sistema para controlar tudo que foi descrito:
a) Criar ficha de atendimento e adicionar na fila - o usu�rio deve informar os dados da ficha e, em seguida, a ficha
de atendimento deve ser inclu�da na fila correspondente;
b) Atender ficha da fila � atender uma ficha, respeitando a ordem de atendimento;
c) Mostrar os dados das fichas de atendimento das filas (todas as filas);
d) Listar as informa��es sobre as filas de forma unificada: total de fichas, a porcentagem de animais com quadro
cl�nico grave em rela��o ao total e o total de animais dom�sticos;
e) Listar as fichas j� atendidas (as fichas armazenadas nas pilhas);
f) Remover uma ficha da pilha � O usu�rio deve informar a pilha e, em seguida, o sistema remove a ficha do topo
da pilha especificada;
g) Mostrar o nome do animal armazenado nas pilhas que possui a menor idade com o quadro cl�nico grave.
Ent�o m�os � obra! Analise o problema com aten��o e veja quais as funcionalidades que devem ser
implementadas.
Dica: A pilha e fila usam o mesmo tipo de dado, ou seja, tipo Ficha.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

struct Ficha
{
    string nome;
    int idade;
    char tipo;
    char quadro;

    Ficha()
    {
        nome = "";
        idade = 0;
        tipo = '';
        quadro = '';
    }

    Ficha(string n, int i, char t, char q)
    {
        nome = n;
        idade = i;
        tipo = t;
        quadro = q;
    }
};

#include "include/fila-dinamica-veterinaria.hpp"
#include "include/pilha-dinamica-veterinaria.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	Fila p;
	Fila n;
	Pilha s;
	Pilha d;

}
