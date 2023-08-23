/* 4) Crie um programa que declare uma estrutura (registro) para o cadastro de clientes.
a. Deverão ser armazenados, para cada cliente: CPF, nome completo e ano
de nascimento.
b. Ao início do programa, o usuário deverá informar o número de clientes que serão
armazenados
c. O programa devera alocar dinamicamente a quantidade necessária de memória
para armazenar os registros dos clientes.
d. O programa deverá pedir ao usuário que entre com as informações clientes.
e. Ao final, mostrar os dados armazenados e liberar a memória alocada.*/

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

	cout << "\nInforme a quantidade de clientes que serão armazenados: ";
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
