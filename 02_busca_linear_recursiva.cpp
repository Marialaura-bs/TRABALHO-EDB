#include <iostream>
using namespace std;

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

int main()
{
    int A[] = {7, 3, 9, 1, 5};

    int x = 9;

    int esq = 0;
    int dir = 5;

    // Teste da busca recursiva.
    bool resultadoRecursivo =
        buscaLinearRecursiva(A, esq, dir, x);

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