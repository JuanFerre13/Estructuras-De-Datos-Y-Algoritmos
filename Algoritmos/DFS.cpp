#ifndef DFS_H
#define DFS_H

#include <iostream>
#include "../TADS/Grafo/Grafo.h"

using namespace std;

void DFS(Grafo *g, bool *visitados, int nodoActual)
{
    int V = g->getV();
    visitados[nodoActual] = true;
    NodoLista<Arista> *ady = g->adyacentesA(nodoActual);
    while (ady != NULL)
    {
        int destino = ady->elemento.destino;
        if (!visitados[destino])
        {
            DFS(g, visitados, destino);
        }
        ady = ady->sig;
    }
}

#endif
