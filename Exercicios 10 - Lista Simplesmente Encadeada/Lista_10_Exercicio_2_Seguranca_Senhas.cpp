/*2. Um grupo de pesquisa em seguran�a da informa��o est� estudando a frequ�ncia de uso de senhas
semelhantes pelos usu�rios de um determinado sistema. Assim, foi criada uma lista contendo as
senhas dos usu�rios. Uma das an�lises a ser realizada � a verifica��o de senhas n�o seguras. Uma
senha pode ser considerada �n�o segura� se ela possuir uma quantidade muito pequena de
caracteres ou for utilizada por uma quantidade muito grande de usu�rios. Para classificar as senhas
n�o seguras, voc� deve criar uma lista simplesmente encadeada contendo todas as senhas com
menos de 4 caracteres ou cuja frequ�ncia de utiliza��o � maior que 5 (ou seja, senhas que aparecem
mais que cinco vezes na lista). Crie a fun��o naoSeguras que recebe uma lista de senhas e retorna
outra lista contendo todas as senhas n�o seguras existentes.
*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

#include "include/lista.hpp"



main()
{
	srand(time(NULL));
	setlocale (LC_ALL, "Portuguese");

}
