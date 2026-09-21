#include <iostream>
#include <chrono>
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
    int tamanhos[] = {5000, 50000, 500000};

    for (int k = 0; k < 3; k++)
    {
        int n = tamanhos[k];

        int A[500000];

        // Preenche o vetor.
        for (int i = 0; i < n; i++)
        {
            A[i] = i;
        }

        int x = 0;
        int esq = 0;
        int dir = n;

        long long soma = 0;

        // Faz 5 execuções da busca.
        for (int repeticao = 0; repeticao < 5; repeticao++)
        {
            auto inicio = chrono::high_resolution_clock::now();

            bool resultado = buscaLinear(A, esq, dir, x);

            auto fim = chrono::high_resolution_clock::now();

            auto tempo = chrono::duration_cast<chrono::nanoseconds>(
                fim - inicio
            );

            soma += tempo.count();
        }

        long long media = soma / 5;

        cout << "n = " << n
             << " | Media = " << media
             << " ns" << endl;
    }

    return 0;
}