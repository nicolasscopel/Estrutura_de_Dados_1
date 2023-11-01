/*2. Um grupo de pesquisa em segurança da informação está estudando a frequência de uso de senhas
semelhantes pelos usuários de um determinado sistema. Assim, foi criada uma lista contendo as
senhas dos usuários. Uma das análises a ser realizada é a verificação de senhas não seguras. Uma
senha pode ser considerada “não segura” se ela possuir uma quantidade muito pequena de
caracteres ou for utilizada por uma quantidade muito grande de usuários. Para classificar as senhas
não seguras, você deve criar uma lista simplesmente encadeada contendo todas as senhas com
menos de 4 caracteres ou cuja frequência de utilização é maior que 5 (ou seja, senhas que aparecem
mais que cinco vezes na lista). Crie a função naoSeguras que recebe uma lista de senhas e retorna
outra lista contendo todas as senhas não seguras existentes.
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
