#include <iostream>
#include <chrono>
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
    // Define os tamanhos dos vetores que serão utilizados nos testes.
    int tamanhos[] = {5000, 50000, 500000};

    // Percorre cada um dos tamanhos definidos para realizar os testes.
    for (int k = 0; k < 3; k++)
    {
        // Armazena o tamanho atual do vetor.
        int n = tamanhos[k];

        // Cria um vetor com capacidade para o maior tamanho utilizado.
        int A[500000];

        // Preenche o vetor com valores crescentes de 0 até n - 1.
        for (int i = 0; i < n; i++)
        {
            A[i] = i;
        }

        // Define o valor que será procurado.
        // 0 está na primeira posição, representando o melhor caso.
        int x = -1;

        // Define o início do intervalo de busca.
        int esq = 0;

        // Define o fim do intervalo de busca.
        // Como o intervalo é [esq, dir), dir não pertence ao intervalo.
        int dir = n;

        // Armazena a soma dos tempos das cinco execuções.
        long long soma = 0;

        // Repete a busca cinco vezes para obter uma média do tempo.
        for (int repeticao = 0; repeticao < 5; repeticao++)
        {
            // Registra o instante inicial da execução da busca.
            auto inicio = chrono::high_resolution_clock::now();

            // Executa a busca sequencial alternativa recursiva.
            bool resultado =
                buscaSequencialAlternativaRecursiva(
                    A, esq, dir, x);

            // Registra o instante final da execução da busca.
            auto fim = chrono::high_resolution_clock::now();

            // Calcula o tempo de execução em nanosegundos.
            auto tempo = chrono::duration_cast<chrono::nanoseconds>(
                fim - inicio
            );

            // Adiciona o tempo desta execução à soma.
            soma += tempo.count();
        }

        // Calcula a média dos tempos das cinco execuções.
        long long media = soma / 5;

        // Exibe o tamanho do vetor e o tempo médio obtido.
        cout << "n = " << n
             << " | Media = " << media
             << " ns" << endl;
    }

    return 0;
}