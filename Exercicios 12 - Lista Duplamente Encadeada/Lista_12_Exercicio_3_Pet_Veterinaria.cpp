/*

*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/lista_dupla_pet.hpp"



main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    Lista lista = Lista();
    Lista menos = Lista();
    Lista mais = Lista();
    int menu, cont = 3, cod, idade;
    float peso;

    insereFinalL(&lista,Animal(1,7,12.7f));
    insereFinalL(&lista,Animal(2,12,73.7f));
    insereFinalL(&lista,Animal(3,3,51.7f));
    insereFinalL(&lista,Animal(4,3,50.0f));


    do
    {
        system("cls");
        cout << "\n -------- MENU --------";
        cout << "\n 0 - Sair";
        cout << "\n 1 - Inserir animal ";
        cout << "\n 2 - Remover via codigo ";
        cout << "\n 3 - Imprime em ordem de chegada ";
        cout << "\n 4 - Imprime 3 ultimos ";
        cout << "\n 5 - Separa peso ";
        cout << "\n Sua escolha: ";
        cin >> menu;


        switch(menu)
        {
        case 0:
        {
            system("cls");
            cout << "\nPrograma Finalizado!\n";
            system("pause");
            break;
        }
        case 1:
        {
            system("cls");


            cout << "\nInforme a idade: ";
            cin >> idade;

            cout << "\nInforme o peso: ";
            cin >> peso;
            cont++;

            insereFinalL(&lista,Animal(cont,idade,peso));

            mostraL(&lista);

            system("pause");
            break;
        }

        case 2:
        {
            system("cls");

            mostraL(&lista);

            cout << "Informe o codigo do animal que deseja remover: " ;
            cin >> cod;

            if(removeL(&lista,cod))
                cout << "\nAnimal codigo " << cod << " removido!";
            else
                cout << "\nCodigo inexistente!\n";

            mostraL(&lista);

            system("pause");
            break;
        }

        case 3:
        {
            system("cls");

            mostraL(&lista);

            system("pause");
            break;
        }

        case 4:
        {
            system("cls");

            mostrar3UltL(&lista);
            cout << endl;

            system("pause");
            break;
        }

        case 5:
        {
            system("cls");

            mostraL(&lista);

            separaListaP(&lista,&menos,&mais);

            mostraL(&lista);
            cout << "\nLista com menos ou igual a 50kg ";
            mostraL(&menos);

            cout << "\nLista com mais de 50kg ";
            mostraL(&mais);


            destroiL(&menos);
            destroiL(&mais);
            system("pause");
            break;
        }

        }

    }
    while(menu != 0);


}
