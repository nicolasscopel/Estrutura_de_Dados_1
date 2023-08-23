/* 7 - Crie uma pilha que permita armazenar dados do tipo string. Para isso, deve-se modificar a estrutura da Pilha, “int
*dados;” para “string *dados;”. Além disso, as demais funções que recebem o valor do tipo inteiro devem ser
alteradas para o tipo string. Exemplos:
void inicializaP(Pilha *p, int tam)
{
 .
 .
 .
 p->dados = new string[tam];///aloca memória dinamicamente
}
bool empilhaP(Pilha *p, string valor)
string desempilhaP(Pilha *p)
string espiaP(Pilha *p)
bool buscaP(Pilha *p, string valor).*/


#include <iostream>
#include <cstring>



using namespace std;

#include "include/pilhastring.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int tamPilha, menu;
    bool resultado;
    string valor;




    do
    {
        system("cls");

        cout << "\n----- MEUNU -----";
        cout << "\n0 - Sair        -";
        cout << "\n1 - Criar       -";
        cout << "\n2 - Inserir     -";
        cout << "\n3 - Desempilhar -";
        cout << "\n4 - Mostrar     -";
        cout << "\n-----------------";
        cout << "\nSua escolha: ";
        cin >> menu;

        switch(menu)
        {

        case 0:
        {
            system("cls");
            cout << "\nO Programa sera encerrado! ";
            system("pause");
            break;
        }

        case 1:
        {

           system("cls");

            cout << "\nInforme o tamanho da pilha: ";
            cin >> tamPilha;

            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {

                inicializaP(&p1, tamPilha);
                cout << "\nPilha Criada." << endl;


            }
            else
            {
                destroiP(&p1);
                inicializaP(&p1, tamPilha);
                cout << "\nNova Pilha Criada." << endl;


            }

            system("pause");
            break;
        }

        case 2:
        {
            system("cls");


            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            cout << "\nInforme uma palavra para inserir na pilha: ";
            cin >> valor;



            resultado = empilhaP(&p1, valor);
            if(resultado == true)
            {
                cout << "A palavra " << valor << " foi empilhada com sucesso!\n";
            }
            else
            {
                cout << "Não foi possível empilhar a palavra " << valor <<"!\n";
                system("pause");
                break;
            }



            system("pause");
            break;

        }
        case 3:
        {
             system("cls");

            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            if(vaziaP(&p1) == true)
            {
                cout << "A pilha está vazia!\n";
                system("pause");
                break;
            }

            if(vaziaP(&p1)== false)
            {
                valor = desempilhaP(&p1);
                cout << "A palavra desempilhada é " << valor << endl;
            }


            system("pause");
            break;


        }
         case 4:
        {
            system("cls");

            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            mostraP(&p1);


            system("pause");
            break;

        }

        default:
        {
            system("cls");
            cout << "\nOpcao Invalida!";

            system("pause");
            break;

        }


        }


    }
    while(menu != 0 );





}
