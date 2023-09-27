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
        tipo = ' ';
        quadro = ' ';
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

    Fila P; // PRIORITARIO ESTADO GRAVE
    Fila N;  //N PRIORITARIO ESTADO ESTÁVEL
    Pilha ANIMALS; //SELVAGEM
    Pilha ANIMALD; //DOMESTICO
    char menu;

    string nome;
    int idade, cont = 0;
    char tipo, quadro;
    Ficha x;


    do
    {
        system("cls");

        cout << "------------------- MENU -------------------" << endl;
        cout << "a - Criar ficha                            -" << endl;
        cout << "b - Atender ficha da fila                  -" << endl;
        cout << "c - Mostrar os dados das fichas            -" << endl;
        cout << "d - Listar as informações sobre as filas   -" << endl;
        cout << "e - Listar as fichas já atendidas          -" << endl;
        cout << "f - Remover uma ficha da pilha             -" << endl;
        cout << "g - Mostrar o nome do animal               -" << endl;
        cout << "h - Sair do Programa                       -" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Sua escolha: ";
        cin >> menu;


        switch(menu)
        {

        case 'a':
        {
            system("cls");

            cout << "Informe o nome do animal: ";
            cin >> nome;
            fflush(stdin);

            cout << "Informe a idade do animal: ";
            cin >> idade;
            fflush(stdin);

            cout << "Informe o tipo do animal(S - Selvagem, D - Domestico): ";
            cin >> tipo;
            fflush(stdin);

            cout << "Informe o quadro do animal(G - Grave, E - Estavel): ";
            cin >> quadro;
            fflush(stdin);

            if(quadro == 'G') ///FILA PRIORITÁRIA
            {
                enfileiraF(&P, Ficha(nome,idade,tipo,quadro));
            }

            if(quadro == 'E') ///FILA NÃO-PRIORITÁRIA
            {
                enfileiraF(&N, Ficha(nome,idade,tipo,quadro));
            }

            cout << nome <<" adicionado a fila de atendimento!\n";



            system("pause");
            break;

        }

        case 'b':
        {
            system("cls");

            if(vaziaF(&P) && vaziaF(&N))
            {
                cout << "\nAmbas as filas estão vazias!\n";
                system("pause");
                continue;
            }

           if(!vaziaF(&P))
           {
               if(cont != 3)
               {
                   x = desenfileiraF(&P);
                   cout << "\nO animal " << x.nome << " entrou para antendimento!\n";
                   cont++;
               }

              if(cont == 3 && !vaziaF(&P))
               {
                   x = desenfileiraF(&N);
                   cout << "\nO animal " << x.nome << " entrou para antendimento!\n";
                   cont = 0;
               }

               if(cont == 3 && vaziaF(&N))
               {
                   x = desenfileiraF(&P);
                   cout << "\nO animal " << x.nome << " entrou para antendimento!\n";

               }


           }
           else if(!vaziaF(&N))
           {
               x = desenfileiraF(&N);
               cout << "\nO animal " << x.nome << " entrou para antendimento!\n";

           }

           if(x.tipo == 'S')
           {
               cout << "cacete";
           }
           else
           {
               cout << "buas";
           }



            system("pause");
            break;

        }

        case 'c':
        {
            system("cls");
            cout << "\nFila Prioritaria\n";
            mostraF(&P);
            cout << "\nFila Nao-Prioritaria\n";
            mostraF(&N);




            system("pause");
            break;

        }

        case 'd':
        {
            system("cls");




            system("pause");
            break;

        }

        case 'e':
        {
            system("cls");



            system("pause");
            break;

        }

        case 'f':
        {
            system("cls");



            system("pause");
            break;

        }

        case 'g':
        {
            system("cls");



            system("pause");
            break;

        }

        case 'h':
        {
            system("cls");

            cout << "\nPrograma Finalizado!\n";


            system("pause");
            break;

        }

        default:
        {
            system("cls");

            cout << "\nOpcao Incorreta!\n";

            system("pause");
            break;

        }

        }

    }
    while(menu != 'h');








}
