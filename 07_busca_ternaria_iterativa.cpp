#include <iostream>
using namespace std;

// 7 - Busca Ternária Iterativa

// Procura o valor x no intervalo [esq, dir).
// O vetor deve estar ordenado em ordem crescente.
// Divide o intervalo em três partes e verifica
// os dois pontos de divisão.
// Retorna true se encontrar x e false caso contrário.
bool buscaTernaria(int A[], int esq, int dir, int x)
{
    while (esq < dir)
    {
        // Calcula o primeiro ponto de divisão.
        int meio1 = esq + (dir - esq) / 3;

        // Calcula o segundo ponto de divisão.
        int meio2 = dir - (dir - esq) / 3;

        // Verifica o primeiro ponto.
        if (A[meio1] == x)
        {
            return true;
        }

        // Verifica o segundo ponto.
        if (A[meio2] == x)
        {
            return true;
        }

        // x está na primeira parte.
        if (x < A[meio1])
        {
            dir = meio1;
        }
        // x está na terceira parte.
        else if (x > A[meio2])
        {
            esq = meio2 + 1;
        }
        // x está na parte do meio.
        else
        {
            esq = meio1 + 1;
            dir = meio2;
        }
    }

    // O elemento não foi encontrado.
    return false;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};

    int x = 13;

    int esq = 0;
    int dir = 9;

    bool resultado = buscaTernaria(A, esq, dir, x);

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