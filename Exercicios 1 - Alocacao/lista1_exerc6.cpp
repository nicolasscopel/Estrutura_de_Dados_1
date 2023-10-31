#include<iostream>
#include<string>
#include<ctime>

using namespace std;

void gerar(int **v, int tam)
{
    //if((*v))
        //delete[] (*v);

    if(*v != NULL)
        delete[] (*v);

    *v = new int[tam];

    for (int i=0;i<tam ; i++)
        (*v)[i] = rand()%100;
}
int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *v = nullptr;
    int menu, tam;

    do{
        cout << "MENU\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar\n";
        cout << "2 - Mostrar\n";
        cin >> menu;
        switch (menu)
        {
        case 0:
            break;
        case 1:
            cout << "Informe o tamanho do vetor:";
            cin >> tam;
            gerar(&v, tam);
            break;
        case 2:
            if(v) // if(v!= NULL)
            {
               for (int i=0;i<tam ; i++)
                    cout << v[i] << ", ";

                cout << endl;
            }
            else
                cout << "Gere o vetor primeiro!\n";

            break;
        default:
            cout << "Opção inválida!\n";
            break;
        }

    }while(menu!=0);



    return 0;
}
