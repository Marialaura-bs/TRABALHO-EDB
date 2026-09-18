// 2 - Busca Linear Recursiva
bool buscaLinearRecursiva(int A[], int esq, int dir, int x) //chama todas as variaveis que serão utilizadas no código e que foram definidas na main
{
    // Caso base: o intervalo está vazio.
    if (esq >= dir)
    {
        return false;
    }

    // Verifica o elemento atual.
    if (A[esq] == x)
    {
        return true;
    }

    // Chama a própria função para procurar no próximo índice.
    return buscaLinearRecursiva(A, esq + 1, dir, x);
}