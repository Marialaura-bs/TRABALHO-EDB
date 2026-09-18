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