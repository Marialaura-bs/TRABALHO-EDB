#include <iostream>
using namespace std;

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

    bool resultado =
        buscaSequencialAlternativa(A, esq, dir, x);

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