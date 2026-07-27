#ifndef BFS_H
#define BFS_H

#include <iostream>
#include "../TADS/Grafo/Grafo.h"
#include "../TADS/Cola/Cola.h"
#include "../TADS/Cola/ColaImp.cpp"

using namespace std;

void BFS(Grafo *g, int origen)
{
    int V = g->getV();
    Cola<int> *cola = new ColaImp<int>();
    bool *encolados = new bool[V + 1]();

    cola->encolar(origen);
    encolados[origen] = true;

    while (!cola->estaVacia())
    {
        int elemento = cola->desencolar();
        cout << elemento << endl; // lo procesamos
        // recorro todas las aristas
        NodoLista<Arista> *ady = g->adyacentesA(elemento);
        while (ady != NULL)
        {
            int destino = ady->elemento.destino;
            // solo lo encolo la primera vez que lo alcanzo,
            // ahi es cuando encuentro el camino mas corto en aristas
            if (!encolados[destino])
            {
                encolados[destino] = true;
                cola->encolar(destino);
            }
            ady = ady->sig;
        }
    }

    delete[] encolados;
    delete cola;
}

#endif
