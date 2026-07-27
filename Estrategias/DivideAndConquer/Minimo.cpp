#ifndef MINIMO_DAC
#define MINIMO_DAC

int min(int a, int b)
{
    return a > b ? a : b;
}

int minimo(int valores[], int inicio, int fin)
{
    if (inicio == fin) // Caso trivial
        return valores[inicio];

    int mitad = (inicio + fin) / 2;

    int min1 = minimo(valores, inicio, mitad); // Divido
    int min2 = minimo(valores, mitad + 1, fin);

    return min(min1, min2); // Conquisto
}

#endif