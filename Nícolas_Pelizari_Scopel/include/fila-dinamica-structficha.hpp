#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA


struct NoFila
{
    Ficha dado; //informacao do nó
    NoFila *prox; //proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila()  //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(Fila *f, Ficha dado)
{
    NoFila *novo = new NoFila();
    if (novo == NULL) /// não conseguiu alocar memória (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

//Dequeue
Ficha desenfileiraF(Fila *f)
{
    Ficha dado;

    // se não estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro nó
        NoFila *apagar = f->inicio; //guarda o primeiro nó em uma variável auxiliar;
        f->inicio = f->inicio->prox; // atualiza o início da fila
        delete apagar;  // libera a memória

        if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
Ficha espiaF(Fila* f)
{
    Ficha dado;

    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show
void mostraF(Fila *f)
{

    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        cout << "{";

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << "[" << no->dado.nome << ", S=" << no->dado.sexo << ", T=" << no->dado.tipo << ", Q=" << no->dado.quantidade << "]"; // REFAZER
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "}";
    }
    else
        cout << "vazia!\n";
}

// retorna true se o valor existe na fila
// retorna false se o valor não existe na fila
bool buscaFnome(Fila *f, string nome)
{

    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.nome == nome)
            return true;

        no = no->prox;
    }

    return false;
}



void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o nó em uma variável auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

int contaF(Fila *f)
{
    int cont = 0;


    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cont++;

            no = no->prox;

        }
    }
    return cont;


}



int contaFLivros(Fila *f)
{
    int soma = 0;


    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            if(no->dado.tipo == 'L')
                soma += no->dado.quantidade;

            no = no->prox;

        }
    }
    return soma;


}

int contaFRoupas(Fila *f)
{
    int soma = 0;


    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            if(no->dado.tipo == 'R')
                soma += no->dado.quantidade;

            no = no->prox;

        }
    }
    return soma;


}

int contaFHomens(Fila *f)
{
    int soma = 0;


    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            if(no->dado.sexo == 'M')
                soma ++;

            no = no->prox;

        }
    }
    return soma;
}

void procuraMenorFem(Fila *f, Fila *f2, string *nome, int *qtd)
{

    NoFila *no = f->inicio;
    *qtd = no->dado.quantidade;
    *nome = no->dado.nome;

    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            if(no->dado.sexo == 'F')
            {
                if(no->dado.quantidade < (*qtd))
                {
                    *qtd = no->dado.quantidade;
                    *nome = no->dado.nome;
                }

            }
            no = no->prox;

        }
    }
    if(vaziaF(f2) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f2->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            if(no->dado.sexo == 'F')
            {
                if(no->dado.quantidade < (*qtd))
                {
                    *qtd = no->dado.quantidade;
                    *nome = no->dado.nome;
                }

            }
            no = no->prox;

        }
    }

    cout << "\n" << *nome << " sexo (F) possui a menor quantidade de itens (" << *qtd << ")";

}
void procuraMenorMasc(Fila *f, Fila *f2, string *nome, int *qtd)
{
     NoFila *no = f->inicio;
    *qtd = no->dado.quantidade;
    *nome = no->dado.nome;

    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            if(no->dado.sexo == 'M')
            {
                if(no->dado.quantidade < (*qtd))
                {
                    *qtd = no->dado.quantidade;
                    *nome = no->dado.nome;
                }

            }
            no = no->prox;

        }
    }
    if(vaziaF(f2) == false) //verifica se a fila não está vazia
    {

        NoFila *no = f2->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            if(no->dado.sexo == 'M')
            {
                if(no->dado.quantidade < (*qtd))
                {
                    *qtd = no->dado.quantidade;
                    *nome = no->dado.nome;
                }

            }
            no = no->prox;

        }
    }

    cout << "\n" << *nome << " sexo (M) possui a menor quantidade de itens (" << *qtd << ")";
}


#endif // _HPP_FILA_DINAMICA






