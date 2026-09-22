#include <iostream>
#include <chrono>
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
        // -1 não existe no vetor, representando o pior caso.
        int x = 0;

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

            // Executa a busca sequencial alternativa.
            bool resultado =
                buscaSequencialAlternativa(A, esq, dir, x);

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