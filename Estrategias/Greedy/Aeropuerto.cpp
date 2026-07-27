#ifndef AEROPUERTO
#define AEROPUERTO

#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "../../TADS/HeapBinario/MinHeap.cpp"

using namespace std;

bool funcionComparadora(int a, int b)
{
    return a < b;
}

int Aeropuerto(int N, int *llegadas, int *partidas)
{
    MinHeap<int> *heapLlegadas = new MinHeap<int>(N, funcionComparadora);
    MinHeap<int> *heapPartidas = new MinHeap<int>(N, funcionComparadora);
    for (int i = 0; i < N; i++)
    {
        heapLlegadas->insertar(llegadas[i]);
        heapPartidas->insertar(partidas[i]);
    }
    int countLocal = 0;
    int max = 0;

    while (!heapLlegadas->estaVacio())
    {
        int siguienteLlegada = heapLlegadas->tope();
        int siguientePartida = heapPartidas->tope();
        if (siguienteLlegada < siguientePartida)
        {
            countLocal++;
            heapLlegadas->eliminarTope();
        }
        else
        {
            countLocal--;
            heapPartidas->eliminarTope();
        }
        max = countLocal > max ? countLocal : max;
    }

    delete heapLlegadas;
    delete heapPartidas;

    return max;
}

#endif