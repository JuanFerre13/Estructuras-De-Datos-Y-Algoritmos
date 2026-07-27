#ifndef MOCHILA0INF_DAC
#define MOCHILA0INF_DAC

int max(int a, int b)
{
    a > b ? a : b;
}

int mochila0INF(int *pesos, int *valores, int capacidad, int n)
{
    if (n < 0 || capacidad == 0) // Capacidad == 0 SOLO si ningun objeto tiene peso 0
        return 0;

    if (pesos[n] > capacidad) // base 0
        return mochila0INF(pesos, valores, capacidad, n - 1);

    // Para convertirla en una mochila 0-1 debemos agregar un "-1" a "n" al usar el objeto
    int valorUsarObj = mochila0INF(pesos, valores, capacidad - pesos[n], n);
    int valorNoUsarObj = mochila0INF(pesos, valores, capacidad, n - 1);
    return max(valorUsarObj, valorNoUsarObj);
}

#endif