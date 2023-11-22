/*
a. Inserir no final da lista
b. Remover o primeiro elemento
c. Remover o último elemento. É proibido percorrer alista. Para encontrar o penúltimo nó,
acesse o ponteiro “anterior”.
Observação: faça uso do descritor da lista para remover ou inserir um novo nó, ou seja, não é
necessário percorrer a lista.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/lista_dupla.hpp"



main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");


    Lista lista = Lista();


    cout << "\n --- FUNCAO PARA INSERIR NO FINAL --- " << endl;
    insereFinalL(&lista,10);
    mostraL(&lista);
    insereFinalL(&lista,5);
    mostraL(&lista);
    mostrarInversoL(&lista);

    cout << "\n --- FUNCAO PARA REMOVER O PRIMEIRO ELEMENTO --- " << endl;
    mostraL(&lista);

    cout << "Elemento removido: "<< removeInicioL(&lista) << endl;
    mostraL(&lista);
    cout << "Elemento removido: " << removeInicioL(&lista) << endl;
    cout << "Elemento removido: "<< removeInicioL(&lista) << endl;

    cout << "\n LISTA VAZIA" << endl;
    mostraL(&lista);
    mostrarInversoL(&lista);

    insereInicioL(&lista,15);
    insereFinalL(&lista,10);

    cout << "\n LISTA COM 2 ELEMENTOS" << endl;
    mostraL(&lista);
    mostrarInversoL(&lista);


    cout << "\n --- FUNCAO PARA REMOVER O ULTIMO ELEMENTO --- " << endl;
    mostraL(&lista);

    cout << "Elemento removido: " << removeFinalL(&lista) << endl;
    mostraL(&lista);

    cout << "Elemento removido: " << removeFinalL(&lista) << endl;
    mostraL(&lista);

    cout << "Elemento removido: " << removeFinalL(&lista) << endl;

    cout << "\n --- TESTE FINAL --- " << endl;
    insereFinalL(&lista,30);
    insereFinalL(&lista,20);
    insereFinalL(&lista,10);
    insereFinalL(&lista,0);
    mostraL(&lista);
    mostrarInversoL(&lista);


}
