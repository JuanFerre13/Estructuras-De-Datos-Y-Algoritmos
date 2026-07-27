#ifndef MOCHILA01_DAC
#define MOCHILA01_DAC

int max(int a, int b)
{
    a > b ? a : b;
}

int mochila01(int *pesos, int *valores, int capacidad, int n)
{
    if (n < 0 || capacidad == 0) // Capacidad == 0 SOLO si ningun objeto tiene peso 0
        return 0;

    if (pesos[n] > capacidad) // base 0
        return mochila01(pesos, valores, capacidad, n - 1);

    // El "-1" al usar el objeto es lo que diferencia una mochila 0-1 de una 0-INF
    int valorUsarObj = mochila01(pesos, valores, capacidad - pesos[n], n - 1);
    int valorNoUsarObj = mochila01(pesos, valores, capacidad, n - 1);
    return max(valorUsarObj, valorNoUsarObj);
}

#endif