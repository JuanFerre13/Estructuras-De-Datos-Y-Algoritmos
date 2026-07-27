#ifndef SECUENCIAMAXIMA
#define SECUENCIAMAXIMA

#include <limits>

#define INF INT_MIN;

int max(int a, int b)
{
    a > b ? a : b;
}

int sumaMaximaCruzada(int arreglo[], int izquierda, int medio, int derecha)
{
    int suma = 0;
    int sumaIzq = INF;
    for (int i = medio; i >= izquierda; --i)
    {
        suma += arreglo[i];
        if (suma > sumaIzq)
        {
            sumaIzq = suma;
        }
    }
    suma = 0;
    int sumaDer = INF;
    for (int i = medio + 1; i <= derecha; ++i)
    {
        suma += arreglo[i];
        if (suma > sumaDer)
        {
            sumaDer = suma;
        }
    }
    return sumaIzq + sumaDer;
}

int sumaMaximaSubArreglo(int arreglo[], int izquierda, int derecha)
{
    if (izquierda == derecha)
    {
        return arreglo[izquierda];
    }
    int medio = (izquierda + derecha) / 2;
    int maxIzq = sumaMaximaSubArreglo(arreglo, izquierda, medio);
    int maxDer = sumaMaximaSubArreglo(arreglo, medio + 1, derecha);
    return max(maxIzq, max(maxDer, sumaMaximaCruzada(arreglo, izquierda, medio, derecha)));
}

#endif