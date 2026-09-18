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

// 2 - Busca Linear Recursiva
bool buscaLinearRecursiva(int A[], int esq, int dir, int x) //chama todas as variaveis que serão utilizadas no código e que foram definidas na main
{
    // Caso base: o intervalo está vazio.
    if (esq >= dir)
    {
        return false;
    }

    // Verifica o elemento atual.
    if (A[esq] == x)
    {
        return true;
    }

    // Chama a própria função para procurar no próximo índice.
    return buscaLinearRecursiva(A, esq + 1, dir, x);
}

// 3 - Busca Sequencial Alternativa Iterativa
bool buscaSequencialAlternativa(int A[], int esq, int dir, int x)
{
    // i começa no início do intervalo.
    int i = esq;

    // j começa no último elemento válido do intervalo.
    int j = dir - 1;

    // Continua enquanto os índices não se cruzarem.
    while (i <= j)
    {
        // Verifica o elemento da esquerda.
        if (A[i] == x)
        {
            return true;
        }

        // Verifica o elemento da direita.
        if (A[j] == x)
        {
            return true;
        }

        // Avança uma posição pela esquerda.
        i++;

        // Volta uma posição pela direita.
        j--;
    }

    // O elemento não foi encontrado.
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