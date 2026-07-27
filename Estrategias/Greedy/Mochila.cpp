#ifndef MOCHILA_GREEDY
#define MOCHILA_GREEDY

// Asume los elem ORDENADOS por Heurística
int mochilaGreedy(int *pesos, int *valores, int n, int P) 
{
    int pesoTotal;
    int valorTotal;
    for (int obj = 0; obj < n; obj++) // Base 0
    {
        if (pesoTotal + pesos[obj] <= P)
        {
            pesoTotal += pesos[obj];
            valorTotal += valores[obj];
        }
    }
    return valorTotal;
}

#endif