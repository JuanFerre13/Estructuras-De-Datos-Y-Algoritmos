#ifndef NODO_HEAP_H
#define NODO_HEAP_H

#include <climits>

// Tanto Dijkstra como Prim minimizan, por lo que el valor inicial
// de un costo desconocido debe ser el maximo posible, no el minimo.
#define INF INT_MAX

// Elemento que guardamos en el MinHeap: un vertice junto al costo
// con el que lo alcanzamos. Se usa en Dijkstra y en Prim.
struct NodoHeap
{
    int vertice;
    int costo;
    // El MinHeap hace new T[capacidad](), asi que T necesita constructor por defecto.
    NodoHeap()
    {
        vertice = -1;
        costo = INF;
    }
    NodoHeap(int _vertice, int _costo)
    {
        vertice = _vertice;
        costo = _costo;
    }
};

// inline para que puedan incluirla varias unidades de compilacion
// sin que el linker se queje de definiciones duplicadas.
inline bool esMenorFn(NodoHeap a, NodoHeap b)
{
    return a.costo < b.costo;
}

#endif
