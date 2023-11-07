#include <iostream>
using namespace std;

#include "include/lista.hpp"

/*
Um grupo de pesquisa em seguran�a da informa��o est� estudando a frequ�ncia de uso de senhas
semelhantes pelos usu�rios de um determinado sistema. Assim, foi criada uma lista contendo as
senhas dos usu�rios. Uma das an�lises a ser realizada � a verifica��o de senhas n�o seguras. Uma
senha pode ser considerada �n�o segura� se ela possuir uma quantidade muito pequena de
caracteres ou for utilizada por uma quantidade muito grande de usu�rios. Para classificar as senhas
n�o seguras, voc� deve criar uma lista simplesmente encadeada contendo todas as senhas com
menos de 4 caracteres ou cuja frequ�ncia de utiliza��o � maior que 5 (ou seja, senhas que aparecem
mais que cinco vezes na lista). Crie a fun��o naoSeguras que recebe uma lista de senhas e retorna
outra lista contendo todas as senhas n�o seguras existentes.
*/

void senhasFracas(No<string> **ListaSenhas);
int buscaQuantidade(No<string> ***ListaSenhas, string senha);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<string> *ListaSenhas; // cria o primeiro n�
    inicializaL(&ListaSenhas);

    string senha = "aaaaaaaaa";
    insereInicioL(&ListaSenhas, senha);
    senha = "abc1234";
    insereInicioL(&ListaSenhas, senha);
    senha = "hgflkj99";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "123";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "123";
    insereInicioL(&ListaSenhas, senha);


    mostraL(&ListaSenhas);
    senhasFracas(&ListaSenhas);

    int num = 5;

    return EXIT_SUCCESS;
}

void senhasFracas(No<string> **ListaSenhas)
{
    No<string> *senhasFracas; // cria o primeiro n�
    inicializaL(&senhasFracas);
    string senha;

    for (int i = 0; i < totalL(ListaSenhas); i++)
    {
        senha = removeInicioL(ListaSenhas);
        if (senha.length() < 4 || (buscaQuantidade(&ListaSenhas, senha) > 5))
        {
            if (buscaL(&senhasFracas, senha) == NULL)
            {
              insereInicioL(&senhasFracas, senha);
            }
        }
        insereFinalL(ListaSenhas, senha);
    }
    mostraL(&senhasFracas);
}

int buscaQuantidade(No<string> ***ListaSenhas, string senha)
{
    int cont = 0;
    string senhaAux;

    No<string> *listaAux; // cria o primeiro n�
    inicializaL(&listaAux);

    while (!(vaziaL(*ListaSenhas)))
    {
        senhaAux = removeInicioL(*ListaSenhas);
        if (senha == senhaAux)
        {
            cont++;
        }
        insereFinalL(&listaAux, senhaAux);
    }

    while(!vaziaL(&listaAux))
    {
        insereFinalL(*ListaSenhas, removeInicioL(&listaAux));
    }
    return cont;
}
