#include<iostream>
#include<string>
#include<ctime>

using namespace std;

struct Cliente{
    string CPF;
    string nome;
    int ano;
    Cliente()
    {
        CPF="";
        nome = "";
        ano = 0;
    }
    Cliente(string c, string n, int a)
    {
        CPF=c;
        nome = n;
        ano = a;
    }
};

void alocaMatriz(int ***m, int L, int C)
{
    *m = new int*[L];
    for (int l=0; l<L ;l++)
        (*m)[l] = new int[C];
}

void geraMatriz(int **m, int L, int C)
{
    for (int l=0; l<L ;l++)
        for (int c=0; c<C ;c++)
            m[l][c] = rand()%100;

}
void mostraMatriz(int **m, int L, int C, string nome)
{


    cout << nome << "\n";
    for (int l=0; l<L ;l++)
    {
        for (int c=0; c<C ;c++)
            cout << m[l][c] << "\t";
        cout << endl;
    }
    cout << endl;


}

void excluirMatriz(int ***m, int L, int C)
{
    for (int l=0; l<L ;l++)
        delete[] (*m)[l];

    delete[] (*m);

    *m = NULL;
}
int main()
{
    srand(time(NULL));

    const int L=5, C=7;
    int **m1, **m2;

    alocaMatriz(&m1, L, C);
    alocaMatriz(&m2, L, C);

    geraMatriz(m1, L, C);
    geraMatriz(m2, L, C);

    mostraMatriz(m1, L, C, "M1:");
    mostraMatriz(m2, L, C, "M2:");

    excluirMatriz(&m1, L, C);
    excluirMatriz(&m2, L, C);

    cout << m1 << endl;
    cout << m2 << endl;


    Cliente p("123456789", "Ciclano", 2000);
    //Cliente p;

    cout << "CPF: " << p.CPF << endl;
    cout << "Nome: " << p.nome << endl;
    cout << "Ano: " << p.ano << endl;
    int n;
    cout << "Informe a quantidade de clientes: ";
    cin >> n;
    Cliente *c = new Cliente[n];

    c[0].nome = "Fulano";
    c[0].CPF = "123456789";
    c[0].ano = 1980;

    cout << c[0].nome  << endl;

    return 0;
}
