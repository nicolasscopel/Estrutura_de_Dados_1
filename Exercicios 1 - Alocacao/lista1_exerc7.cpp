#include<iostream>
#include<string>
#include<ctime>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    ifstream arq ("entrada.txt");

    if (!arq.is_open())
    {
        cout << "Informe o nome do arquivo corretamente!\n";
        return 0;
    }

    string operacao;
    float v1, v2, resultado;

    while(!arq.eof())
    {
        if(!(arq >> operacao) || operacao.size()<=0)
            break;
        //arq >> operacao;
        cout << operacao << endl;

        arq >> v1;
        arq >> v2;

        if(operacao == "SOMA")
            resultado = v1 + v2;
        else if(operacao == "DIVISAO")
            resultado = v1 / v2;
        else if(operacao == "SUBTRACAO")
            resultado = v1 - v2;
        else if(operacao == "MULTIPLICACAO")
            resultado = v1 * v2;

        cout << resultado << endl;

    }


    return 0;
}
