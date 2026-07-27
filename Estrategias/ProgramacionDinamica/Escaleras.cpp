#ifndef PROBLEMAESCALERAS
#define PROBLEMAESCALERAS

// Puedo subir de a 1 o de a 2 escalones.
// El truco es pensar de cuantas formas puedo LLEGAR al escalon n:
// o venia del escalon n-1 (subi 1) o venia del n-2 (subi 2), entonces sumo ambas.
// F(0) = 1 (ya estoy parado ahi, 1 forma: no hacer nada)
// F(1) = 1
// F(n) = F(n-1) + F(n-2)

// RECURSIVO
// Orden temporal: O(2^n)
int escalerasRec(int escalon)
{
    if (escalon <= 1)
        return 1;
    return escalerasRec(escalon - 1) + escalerasRec(escalon - 2);
}

// MEMOIZACIÓN
// memo debe tener un valor de "no calculado", en este caso -1 porque estoy seguro que todos los valores son > 0
int escalerasMemo(int escalon, int *memo)
{
    if (escalon <= 1)
        return 1;
    if (memo[escalon] == -1)
    {
        memo[escalon] = escalerasMemo(escalon - 1, memo) + escalerasMemo(escalon - 2, memo);
    }
    return memo[escalon];
}

// TABULACIÓN
// Orden temporal: O(n)
// Orden espacial: O(n)
int escalerasTab(int escalon)
{
    if (escalon <= 1)
        return 1;
    int *tab = new int[escalon + 1]();
    tab[0] = 1;
    tab[1] = 1;
    for (int i = 2; i <= escalon; i++) // Comienzo el for en el 1er valor que no sea caso base
    {
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab[escalon];
}

// TABULACION OPTIMIZADO
// Orden temporal: O(n)
// Orden espacial: O(1)
int escalerasTabOpt(int escalon)
{
    if (escalon <= 1)
        return 1;
    int ante = 1;     // formas de llegar al escalon i-1
    int anteante = 1; // formas de llegar al escalon i-2
    int aux;
    for (int i = 2; i <= escalon; i++)
    {
        aux = ante + anteante;
        anteante = ante;
        ante = aux;
    }
    return ante;
}

#endif
