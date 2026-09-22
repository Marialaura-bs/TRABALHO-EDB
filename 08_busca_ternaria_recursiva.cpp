#include <iostream>
#include <chrono>
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
        // n / 3 corresponde ao elemento que está no meio do vetor.
        // -1 é o pior caso pois não existe na amostra
        // Isso representa o melhor caso da busca binária.
        int x =  -1;

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

            // Executa a busca Ternaria Rercursiva.
            bool resultado =
                buscaTernariaRecursiva(A, esq, dir, x);

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