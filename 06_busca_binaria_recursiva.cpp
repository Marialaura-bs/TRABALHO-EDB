#include <iostream>
using namespace std;

// 6 - Busca Binária Recursiva

// Procura o valor x no intervalo [esq, dir).
// O vetor deve estar ordenado em ordem crescente.
// Verifica o elemento do meio e continua a busca
// recursivamente em uma das duas metades.
// Retorna true se encontrar x e false caso contrário.
bool buscaBinariaRecursiva(int A[], int esq, int dir, int x)
{
    // Caso base: o intervalo está vazio.
    if (esq >= dir)
    {
        return false;
    }

    // Calcula o índice do elemento do meio.
    int meio = esq + (dir - esq) / 2;

    // Se encontrou o elemento, retorna true.
    if (A[meio] == x)
    {
        return true;
    }

    // Se x é maior, procura na metade direita.
    if (x > A[meio])
    {
        return buscaBinariaRecursiva(A, meio + 1, dir, x);
    }

    // Caso contrário, procura na metade esquerda.
    return buscaBinariaRecursiva(A, esq, meio, x);
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    int x = 7;

    int esq = 0;
    int dir = 5;

    bool resultado =
        buscaBinariaRecursiva(A, esq, dir, x);

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