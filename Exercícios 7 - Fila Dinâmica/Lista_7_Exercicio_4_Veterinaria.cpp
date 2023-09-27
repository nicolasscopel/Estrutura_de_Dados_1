/* 4. A Veterinária Passo Fundo realiza atendimentos para diferentes tipos de animais. Quando um cliente chega com
seu animal na veterinária, ele deve informar os seguintes dados para a criação de uma ficha de atendimento:
• Ficha de atendimento: nome, idade, tipo (S-selvagem, D-doméstico) e quadro clínico (E-estável, G-grave).
Após o cliente informar os dados ao funcionário da empresa, a ficha de atendimento é criada e, com base nos
dados fornecidos, a ficha de atendimento é adicionada em uma das seguintes filas:
• Fila Prioritária – animais com quadro clínico grave;
• Fila Não Prioritária – animais com quadro clínico estável.
O atendimento das filas deve seguir a ordem especificada abaixo:
1. Primeiramente, as fichas da Fila Prioritária devem ser atendidas com base nas seguintes regras.
a. Quando há fichas em ambas as filas, no máximo três fichas consecutivas da Fila Prioritária
podem ser atendidas, ou seja, a cada três fichas atendidas da Fila Prioritária, uma ficha da Fila
Não Prioritária deve ser atendida (caso houver);
b. Não havendo fichas na Fila Não Prioritária, o sistema pode atender mais que três fichas
consecutivas da Fila Prioritária.
2. Por fim, quando não há fichas na Fila Prioritária, uma ficha da Fila Não Prioritária deve ser atendida.
Quando uma ficha é atendida, o funcionário da empresa retira a ficha da fila e guarda em uma pilha, sendo
que as fichas dos animais do tipo S são empilhadas na pilha ANIMALS e as fichas dos animais do tipo D são empilhadas
na pilha ANIMALD.

Agora você deve escrever um programa que implementa o sistema para controlar tudo que foi descrito:
a) Criar ficha de atendimento e adicionar na fila - o usuário deve informar os dados da ficha e, em seguida, a ficha
de atendimento deve ser incluída na fila correspondente;
b) Atender ficha da fila – atender uma ficha, respeitando a ordem de atendimento;
c) Mostrar os dados das fichas de atendimento das filas (todas as filas);
d) Listar as informações sobre as filas de forma unificada: total de fichas, a porcentagem de animais com quadro
clínico grave em relação ao total e o total de animais domésticos;
e) Listar as fichas já atendidas (as fichas armazenadas nas pilhas);
f) Remover uma ficha da pilha – O usuário deve informar a pilha e, em seguida, o sistema remove a ficha do topo
da pilha especificada;
g) Mostrar o nome do animal armazenado nas pilhas que possui a menor idade com o quadro clínico grave.
Então mãos à obra! Analise o problema com atenção e veja quais as funcionalidades que devem ser
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
