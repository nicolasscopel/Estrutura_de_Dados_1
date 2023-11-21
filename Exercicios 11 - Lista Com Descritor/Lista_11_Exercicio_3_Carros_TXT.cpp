/*
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include <unistd.h>
#include <sstream>
#include <fstream>

using namespace std;

#include "include/lista_descritor_carro.hpp"



main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha, placa,modelo,fabricante;
    int ano,escolhaOrdem;
    char menu;

    Lista lista = Lista();


    ifstream arq ("cadastro.txt");

    if (!arq.is_open())
    {
        cout << "Erro: n�o foi poss�vel abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        if(linha.size()==0)
            break;

        strBuffer = stringstream(linha);
        int contPlavra=1;
        string palavra;
        while(getline(strBuffer, palavra, '#'))  //le cada palavra da linha separada pelo delimitador #
        {
            if(contPlavra==1) //primeira palavra da linha
                placa = palavra;
            else if(contPlavra==2) //segunda palavra da linha
                ano = stoi(palavra);
            else if(contPlavra==3) //segunda palavra da linha
                fabricante = palavra;
            else if(contPlavra==4) //segunda palavra da linha
                modelo = palavra;


            contPlavra++;
        }
        insereFimL(&lista,Carro(placa,ano,fabricante,modelo));

        usleep(10000);

    }

    do
    {
        system("cls");
        cout << "\n -------------------------- MENU -------------------------- ";
        cout << "\na - Mostrar lista de ve�culos";
        cout << "\nb - Ordenar lista de ve�culos";
        cout << "\nc - Remover um ve�culo da lista pela placa";
        cout << "\nd - Remover ve�culos com base no fabricante e no ano";
        cout << "\ne - Filtrar ve�culo";
        cout << "\nf - Encerrar programa" << endl;
        cout << "Sua Escolha: ";
        cin >> menu;


        switch(menu)
        {
        case 'a':
        {
            system("cls");
            cout << "\nLista de Ve�culos: ";
            mostraL(&lista);

            system("pause");
            break;

        }

        case 'b':
        {
            system("cls");
            do
            {
                cout << "\nComo voce deseja ordenar?\n 1 - Pelo Ano \n 2 - Pelo Modelo" << endl << "Sua escolha:";
                cin >> escolhaOrdem;

                if(escolhaOrdem != 1 && escolhaOrdem != 2)
                {
                    cout << "\nOpcao Inv�lida" << endl;
                    system("pause");
                    system("cls");

                }
                else if(escolhaOrdem == 1)
                {
                    cout << "\nLista Ordenada pelo Ano: ";
                    ordenaAnoL(&lista);
                    mostraL(&lista);
                }
                else if(escolhaOrdem == 2)
                {
                    cout << "\nLista Ordenada pelo Modelo: ";
                    ordenaModeloL(&lista);
                    mostraL(&lista);
                }

            }
            while((escolhaOrdem != 1 && escolhaOrdem != 2));


            system("pause");
            break;

        }

        case 'c':
        {
            system("cls");

            cout << "\nInforme a placa do ve�culo que deseja remover: ";
            cin >> placa;

            if(removeL(&lista,placa))
            {
                cout << "\nVeiculo placa " << placa << " foi removido da lista!";
            }
            else
            {
                cout << "\nNao foi possivel encontrar esse ve�culo!";
            }



            system("pause");
            break;

        }

        case 'd':
        {
            system("cls");

            cout << "\nInforme o fabricante do ve�culo: ";
            cin >> fabricante;

            removeFabricanteL(&lista,fabricante);
            mostraL(&lista);

            system("pause");
            break;

        }

        case 'e':
        {
            system("cls");
            cout << "\nInforme o fabricante que deseja ver as placas: ";
            cin >> fabricante;

            consultaPlacaL(&lista,fabricante);
            cout << "\n" << lista << endl;

            system("pause");
            break;

        }

        case 'f':
        {
            system("cls");

            cout << "\nPrograma Finalizado!" << endl;

            system("pause");
            break;

        }


        }


    }
    while (menu != 'f');



    return 0;
}


