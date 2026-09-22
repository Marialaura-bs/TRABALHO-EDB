#include <iostream>
#include <chrono>
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
        // n / 2 corresponde ao elemento que está no meio do vetor.
        // Isso representa o melhor caso da busca binária.
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

            // Executa a busca binária iterativa.
            bool resultado =
                buscaBinaria(A, esq, dir, x);

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