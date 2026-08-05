#ifndef CAMINOS_MATRIZ
#define CAMINOS_MATRIZ

// Matriz con dimensiones M x N, ¿Cuántas formas de llegar al destino tengo?

// PROBLEMA CAMINOS EN MATRIZ

// RECURSIVO
int caminos_rec(int fila, int columna)
{
    if (fila == 0 && columna == 0)
        return 1;
    if (fila == 0)
        return caminos_rec(fila, columna - 1);
    if (columna == 0)
        return caminos_rec(fila - 1, columna);
    return caminos_rec(fila - 1, columna) + caminos_rec(fila, columna - 1);
}

// MEMOIZACIÓN
int caminos_memo(int fila, int columna, int **memo)
{
    if (fila == 0 && columna == 0)
        return 1;
    int res;
    if (memo[fila][columna] == -1) // Utilizo -1 como valor de NO calculado
    {
        if (fila == 0)
            res = caminos_memo(fila, columna - 1, memo);
        if (columna == 0)
            res = caminos_memo(fila - 1, columna, memo);
        res = caminos_memo(fila, columna - 1, memo) + caminos_memo(fila - 1, columna, memo);
        memo[fila][columna] = res;
    }
    return memo[fila][columna];
}

// TABULACIÓN
int caminos_tab(int fila, int columna)
{
    if (fila == 0 && columna == 0)
        return 1;
    int **tab = new int *[fila]();
    for (int i = 0; i < fila; i++)
    {
        tab[i] = new int[columna]();
    }
    tab[0][0] = 1;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                tab[i][j] = tab[i][j - 1];
            else if (j == 0)
                tab[i][j] = tab[i - 1][j];
            else
                tab[i][j] = tab[i][j - 1] + tab[i - 1][j];
        }
    }
    return tab[fila - 1][columna - 1];
}

// TABULACIÓN OPTIMIZADO
int caminos_tab_opt(int fila, int columna)
{
    if (fila == 0 && columna == 0)
        return 1;
    int *tab = new int[columna]();
    tab[0] = 1;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                tab[j] = tab[j - 1];
            else if (j == 0)
                tab[j] = tab[j];
            else
                tab[j] = tab[j] = tab[j - 1];
        }
    }
    return tab[columna - 1];
}

// PROBLEMA CAMINOS EN MATRIZ CON OBSTACULOS

int camino_obstaculos_tab(int fila, int columna, bool **obs)
{
    if (fila == 0 && columna == 0)
        return 1;
    int **tab = new int *[fila]();
    for (int i = 0; i < fila; i++)
    {
        tab[i] = new int[columna]();
    }
    tab[0][0] = 1;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (obs[i][j])
                tab[i][j] = 0;
            else if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                tab[i][j] = tab[i][j - 1];
            else if (j == 0)
                tab[i][j] = tab[i - 1][j];
            else
                tab[i][j] = tab[i][j - 1] + tab[i - 1][j];
        }
    }
    return tab[fila - 1][columna - 1];
}

#endif