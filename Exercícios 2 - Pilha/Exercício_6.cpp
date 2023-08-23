/*6. Crie uma fun��o para buscar um valor v em uma pilha P fazendo uso de uma pilha auxiliar AUX. Observa��es:
- Prot�tipo da fun��o:
bool buscaValor(Pilha *p, int valor);
- N�o � permitido o uso de vetores auxiliares.
- Ap�s a chamada da fun��o, a pilha P deve conter os mesmos elementos, os valores devem ser
preservados.
- Implementa��o da fun��o:
- Desempilhar os elementos de P e empilhar em AUX. Dentro de um la�o de repeti��o:
- Desempilhar um elemento da pilha P e empilhar na pilha AUX.
- Verificar se o elemento desempilhado � igual v. Caso afirmativo, o valor v est� presente
na pilha P e, no final da fun��o, o valor true deve ser retornado.
- Devolver os elementos armazenados em AUX para P. Dentro de um la�o de repeti��o:
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
//implementar o la�o de repeti��o para devolver os elementos
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
        //implementar o la�o de repeti��o para devolver os elementos
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
