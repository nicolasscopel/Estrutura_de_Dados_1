/* 4) Crie um programa que declare uma estrutura (registro) para o cadastro de clientes.
a. Dever�o ser armazenados, para cada cliente: CPF, nome completo e ano
de nascimento.
b. Ao in�cio do programa, o usu�rio dever� informar o n�mero de clientes que ser�o
armazenados
c. O programa devera alocar dinamicamente a quantidade necess�ria de mem�ria
para armazenar os registros dos clientes.
d. O programa dever� pedir ao usu�rio que entre com as informa��es clientes.
e. Ao final, mostrar os dados armazenados e liberar a mem�ria alocada.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

struct cadastro
{

    string cpf;
    string nome;
    int ano;

};

void ler(cadastro v[], int i);
void exibe(cadastro v[], int i);

main()
{
    srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

	int qtd;

	cout << "\nInforme a quantidade de clientes que ser�o armazenados: ";
	cin >> qtd;

	cadastro *vet = new cadastro[qtd];

	ler(vet, qtd);
	exibe(vet, qtd);

	delete[] vet;





}

void ler(cadastro v[], int i)
{


    for(int j = 0; j < i; j++)
    {
        cout << "\n------- CLIENTE " << j + 1<< " -------" << endl;
        cout << "Informe o CPF (SEM PONTUACAO): ";
        cin >> v[j].cpf;
        fflush(stdin);
        cout << "Informe o NOME: ";
        cin >> v[j].nome;
        fflush(stdin);
        cout << "Informe o ANO DE NASCIMENTO: ";
        cin >> v[j].ano;
        fflush(stdin);

    }
}

void exibe(cadastro v[], int i)
{
    system("cls");

    for(int j = 0; j < i; j++)
    {
        cout << "\n------- CLIENTE " << j + 1<< " -------" << endl;
        cout << "CPF: " << v[j].cpf << endl;
        fflush(stdin);
        cout << "NOME: " << v[j].nome << endl;
        fflush(stdin);
        cout << "ANO DE NASCIMENTO: " << v[j].ano << endl;
        fflush(stdin);


}

}
