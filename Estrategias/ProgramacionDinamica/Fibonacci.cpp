#ifndef FIBONACCI
#define FIBONACCI

// RECURSIVO
int fiboRec(int n)
{
    if (n <= 1)
        return n;
    return fiboRec(n - 1) + fiboRec(n - 2);
}

// MEMOIZACIÓN
// memo debe tener un valor de "no calculado", en este caso -1 porque estoy seguro que todos los valores son > 0
// Si no sé con que valor inicializar puedo crear un array booleano "calculado"
int fiboMemo(int n, int *memo)
{
    if (n <= 1)
        return n;
    if (memo[n] == -1)
    {
        memo[n] = fiboMemo(n - 1, memo) + fiboMemo(n - 2, memo);
    }
    return memo[n];
}

// TABULACIÓN
// Orden temporal: O(n)
// Orden espacial: O(n)
int fiboTab(int n)
{
    if (n <= 1)
        return n;
    int *tab = new int[n + 1]();
    tab[0] = 0;
    tab[1] = 1;
    for (int i = 2; i <= n; i++) // Comienzo el for en el 1er valor que no sea caso base
    {
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab[n];
}

// TABULACION OPTIMIZADO
// Orden temporal: O(n)
// Orden espacial: O(1)
int fiboTabOpt(int n)
{
    if (n <= 1)
        return n;
    int ante = 1;
    int anteante = 0;
    int aux;
    for (int i = 2; i <= n; i++)
    {
        aux = ante + anteante;
        anteante = ante;
        ante = aux;
    }
    return ante;
}

#endif