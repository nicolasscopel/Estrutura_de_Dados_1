#include <iostream>
#include <string>
using namespace std;

#include "pilha-char.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    Pilha p1;

    string str;
    cout << "Informe uma palavra: ";
    //cin>> str;
    getline(cin, str);

    inicializaP(&p1, str.size());

    for (int i=0; i<str.size(); i++)
    {
        if(str[i] != ' ')
            empilhaP(&p1, str[i]);

    }

    mostraP(&p1);

    char c;
    bool palindromo = true;
    for (int i=0; i<str.size(); i++)
    {
        if(str[i] == ' ')
            continue;

        c = desempilhaP(&p1);
        if(c!=str[i])
        {
            palindromo = false;
            break;
        }
    }

    if(palindromo)
        cout << "A palavra " << str << " é um palindromo!\n";
    else
        cout << "A palavra " << str << " NÃO é um palindromo!\n";


   /* int tamPilha = 10;
    inicializaP(&p1, tamPilha);
    for (int i=0; i<tamPilha; i++)
        empilhaP(&p1, rand()%100);


    mostraP(&p1);

    int valor;
    cout << "Informe o valor: ";
    cin >> valor;

    cout << buscaValor(&p1, valor, tamPilha) << endl;

    mostraP(&p1);*/

    //desalocar memória
    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main

