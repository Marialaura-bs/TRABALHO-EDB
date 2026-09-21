#include <iostream>
using namespace std;

// 4 - Busca Sequencial Alternativa Recursiva

// Verifica simultaneamente o primeiro e o último elemento.
// Chama a própria função para continuar a busca.
// Retorna true se encontrar x e false caso contrário.

bool buscaSequencialAlternativaRecursiva(
    int A[], int esq, int dir, int x)
{
    // Caso base: o intervalo está vazio.
    if (esq >= dir)
    {
        return false;
    }

    // Verifica o elemento da esquerda.
    if (A[esq] == x)
    {
        return true;
    }

    // Verifica o último elemento válido do intervalo.
    if (A[dir - 1] == x)
    {
        return true;
    }

    // Chama a própria função, diminuindo o intervalo.
    return buscaSequencialAlternativaRecursiva(
        A, esq + 1, dir - 1, x);
}

int main()
{
    int A[] = {7, 3, 9, 1, 5};

    int x = 9;

    int esq = 0;
    int dir = 5;

    bool resultado =
        buscaSequencialAlternativaRecursiva(
            A, esq, dir, x);

    if (resultado)
    {
        cout << "Elemento encontrado!" << endl;
    }
    else
    {
        cout << "Elemento nao encontrado!" << endl;
    }

    return 0;
}