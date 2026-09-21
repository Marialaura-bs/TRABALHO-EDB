#include <iostream>
using namespace std;

// 8 - Busca Ternária Recursiva

// Procura o valor x no intervalo [esq, dir).
// O vetor deve estar ordenado em ordem crescente.
// Divide o intervalo em três partes e continua
// recursivamente na parte onde x pode estar.
// Retorna true se encontrar x e false caso contrário.
bool buscaTernariaRecursiva(int A[], int esq, int dir, int x)
{
    // Caso base: o intervalo está vazio.
    if (esq >= dir)
    {
        return false;
    }

    // Calcula os dois pontos de divisão.
    int meio1 = esq + (dir - esq) / 3;
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

    // Se x está antes de meio1,
    // continua procurando na primeira parte.
    if (x < A[meio1])
    {
        return buscaTernariaRecursiva(
            A, esq, meio1, x);
    }

    // Se x está depois de meio2,
    // continua procurando na terceira parte.
    if (x > A[meio2])
    {
        return buscaTernariaRecursiva(
            A, meio2 + 1, dir, x);
    }

    // Caso contrário, x está na parte do meio.
    return buscaTernariaRecursiva(
        A, meio1 + 1, meio2, x);
}

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};

    int x = 13;

    int esq = 0;
    int dir = 9;

    bool resultado =
        buscaTernariaRecursiva(A, esq, dir, x);

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