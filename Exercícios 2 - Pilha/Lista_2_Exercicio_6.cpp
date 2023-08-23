/*6. Crie uma função para buscar um valor v em uma pilha P fazendo uso de uma pilha auxiliar AUX. Observações:
- Protótipo da função:
bool buscaValor(Pilha *p, int valor);
- Não é permitido o uso de vetores auxiliares.
- Após a chamada da função, a pilha P deve conter os mesmos elementos, os valores devem ser
preservados.
- Implementação da função:
- Desempilhar os elementos de P e empilhar em AUX. Dentro de um laço de repetição:
- Desempilhar um elemento da pilha P e empilhar na pilha AUX.
- Verificar se o elemento desempilhado é igual v. Caso afirmativo, o valor v está presente
na pilha P e, no final da função, o valor true deve ser retornado.
- Devolver os elementos armazenados em AUX para P. Dentro de um laço de repetição:
- Desempilhar um elemento da pilha AUX e empilhar na pilha P.
- Retorna true ou false
- Exemplo:
bool buscaValor(Pilha *p, int valor)
{
//criar e inicializar a pilha AUX
bool encontrou=false;
while(! vaziaP(p))
{
V = desempilha(p);
Empilha(&aux, v);
If(v== valor)
{
encontrou=true;
break;
}
}
//implementar o laço de repetição para devolver os elementos
//armazenados em AUX para P
return encontrou;
}
*/


#include <iostream>
using namespace std;

#include "include/pilha.hpp"

bool buscaValor(Pilha *p, int valor)
{
//criar e inicializar a pilha AUX
    bool encontrou=false;
    int v;


    while(! vaziaP(p))
    {
        v = desempilhaP(p);
        empilhaP(&aux, v);
        if(v == valor)
        {
            encontrou=true;
            break;
        }
    }

     while(! vaziaP(&aux))
    {
        V = desempilhaP(&aux);
        empilhaP(p, v);

        }

        destroiP(&pAux)
        //implementar o laço de repetição para devolver os elementos
//armazenados em AUX para P
    return encontrou;
}

int main(void)
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    Pilha pAux;
    int tamPilha = 10, valor, menu;
    bool resultado;

    inicializaP(&p1, tamPilha);

    for(int i = 0; i < tamPilha; i++)
    {
        empilhaP(&p1, rand() % 100);

    }
    mostraP(&p1,tamPilha);

    cout << "\nInforme um valor: ";
    cin >> valor;


}
