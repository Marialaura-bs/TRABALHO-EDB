#include <iostream>
using namespace std;

// 1 - Busca Linear Iterativa
bool buscaLinear(int A[], int esq, int dir, int x) //chama todas as variaveis que serão utilizadas no código e que foram definidas na main
{
    // Percorre o intervalo [esq, dir).
    for (int i = esq; i < dir; i++)
    {
        // Verifica se o elemento atual é igual ao valor procurado.
        if (A[i] == x)
        {
            return true;
        }
    }

    // O valor não foi encontrado.
    return false;
}


int main()
{
    int A[] = {7, 3, 9, 1, 5};

    int x = 9;

    int esq = 0;
    int dir = 5;

    // Teste da busca iterativa.
    bool resultadoIterativo = buscaLinear(A, esq, dir, x);

    // Teste da busca recursiva.
    bool resultadoRecursivo =
        buscaLinearRecursiva(A, esq, dir, x);

    if (resultadoIterativo)
    {
        cout << "Iterativa: elemento encontrado!" << endl;
    }
    else
    {
        cout << "Iterativa: elemento nao encontrado!" << endl;
    }

    if (resultadoRecursivo)
    {
        cout << "Recursiva: elemento encontrado!" << endl;
    }
    else
    {
        cout << "Recursiva: elemento nao encontrado!" << endl;
    }

    return 0;
}