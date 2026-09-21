#include <iostream>
#include <chrono>

using namespace std;

// 1 - Busca Linear Iterativa

// Procura o valor x no intervalo [esq, dir).
// Percorre o vetor da esquerda para a direita.
// Retorna true se encontrar x e false caso contrário.
bool buscaLinear(int A[], int esq, int dir, int x)
{
    for (int i = esq; i < dir; i++)
    {
        if (A[i] == x)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    int x = 9;

    int esq = 0;
    int dir = 5;

    // Começa a medição.
    auto inicio = chrono::high_resolution_clock::now();

    // Executa a busca.
    bool resultado = buscaLinear(A, esq, dir, x);

    // Termina a medição.
    auto fim = chrono::high_resolution_clock::now();

    // Calcula o tempo em nanosegundos.
    auto tempo = chrono::duration_cast<chrono::nanoseconds>(
        fim - inicio
    );

    if (resultado)
    {
        cout << "Elemento encontrado!" << endl;
    }
    else
    {
        cout << "Elemento nao encontrado!" << endl;
    }

    cout << "Tempo: " << tempo.count() << " ns" << endl;

    return 0;
}