#include <iostream>
using namespace std;

// 5 - Busca Binária Iterativa

// Procura o valor x no intervalo [esq, dir).
// O vetor deve estar ordenado em ordem crescente.
// A cada passo, verifica o elemento do meio
// e descarta metade do intervalo.
// Retorna true se encontrar x e false caso contrário.
bool buscaBinaria(int A[], int esq, int dir, int x)
{
    while (esq < dir)
    {
        // Calcula o índice do elemento do meio.
        int meio = esq + (dir - esq) / 2;

        // Se encontrou o elemento, retorna true.
        if (A[meio] == x)
        {
            return true;
        }

        // Se x é maior que o elemento do meio,
        // procura na metade direita.
        if (x > A[meio])
        {
            esq = meio + 1;
        }
        // Caso contrário, procura na metade esquerda.
        else
        {
            dir = meio;
        }
    }

    // O elemento não foi encontrado.
    return false;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    int x = 7;

    int esq = 0;
    int dir = 5;

    bool resultado = buscaBinaria(A, esq, dir, x);

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