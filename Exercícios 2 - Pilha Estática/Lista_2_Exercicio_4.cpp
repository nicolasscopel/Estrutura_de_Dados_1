/*4. Implemente um programa que manipule uma pilha. O programa deve ser desenvolvido com as seguintes regras:
• Criar um menu com as opções:
o Criar pilhar – O usuário deve informar o tamanho da pilha; caso a pilha já tenha sido criada
anteriormente, antes de criar uma pilha nova, a pilha antiga deve ser removida e a memória deve
ser desalocada.
o Inserir – O usuário deve informar um valor a ser inserido; caso a pilha esteja cheia, uma mensagem
deve ser exibida.
o Remover – Remover um elemento da pilha e mostrar o elemento removido; caso a pilha esteja
vazia, uma mensagem deve ser exibida.
o Consultar – Verificar se a pilha contém um determinado valor informado pelo usuário.
o Mostrar – Mostar a pilha.
o Sair – Sair do programa.


• Não permitir a inclusão de valores duplicados;
• Imprimir uma mensagem de erro caso a pilha não tenha sido criada e o usuário tente executar uma das
seguintes operações: inserir, remover, consultar ou mostrar.*/


#include <iostream>
using namespace std;

#include "include/pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int tamPilha, valor, menu;
    bool resultado;


    do
    {
        system("cls");
        cout << "------- MENU -------" << endl;
        cout << "0 - Sair           -" << endl;
        cout << "1 - Criar Pilha    -" << endl;
        cout << "2 - Inserir        -" << endl;
        cout << "3 - Remover        -" << endl;
        cout << "4 - Consultar      -" << endl;
        cout << "5 - Mostrar        -" << endl;
        cout << "--------------------" << endl;
        cout << "Sua Escolha: ";
        cin >> menu;
        fflush(stdin);

        if(menu >= 2 && menu <= 5 && !verificaInicializacaoP(&p1))
        {
            cout << "\nPilha nao iniciada!!!!!!!";
            system("pause");
            continue;
        }




        switch(menu)
        {
        case 0:
        {

            system("cls");
            cout << "Programa finalizado." << endl;
            system("pause");
            break;
        }

        case 1: ///CRIAR PILHA
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
        case 2:///INSERIR VALOR
        {
            system("cls");


            resultado = verificaInicializacaoP(&p1);

            if(resultado == false)
            {
                cout << "\nA pilha ainda nao foi criada." << endl;
                system("pause");
                break;
            }

            cout << "\nInforme um valor para inserir na pilha: ";
            cin >> valor;

            resultado = buscaP(&p1, valor);
            if(resultado == true)
            {
                cout << "\nValor já existe na pilha, nao foi possivel inserir novamente!" << endl;
                system("pause");
                break;

            }


            resultado = empilhaP(&p1, valor);
            if(resultado == true)
            {
                cout << "O valor " << valor << " foi empilhado com sucesso!\n";
            }
            else
            {
                cout << "Não foi possível empilhar o valor " << valor <<"!\n";
                system("pause");
                break;
            }



            system("pause");
            break;
        }
        case 3:///REMOVER VALOR
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
                cout << "O valor desempilhado é " << valor << endl;
            }


            system("pause");
            break;
        }
        case 4:///CONSULTAR
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

            cout << "\nInforme um valor para buscar na pilha: ";
            cin >> valor;

            if(buscaP(&p1, valor) == true)
                cout << "O valor " << valor << " foi encontrado na pilha!\n";
            else
                cout << "O valor " << valor << " NÃO foi encontrado na pilha!\n";



            system("pause");
            break;
        }
        case 5:///MOSTRAR PILHA
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
    while(menu != 0);

}
