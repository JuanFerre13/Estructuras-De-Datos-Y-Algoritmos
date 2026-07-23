#ifndef BELLMANFORD
#define BELLMANFORD

#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include "../TADS/Grafo/Grafo.h"
#include "../TADS/Cola/Cola.h"
#include "../TADS/Cola/ColaImp.cpp"

using namespace std;

#define INF INT_MAX

void bellmanford(Grafo *g, int origen)
{
    int V = g->getV();
    int *costo = new int[V + 1]();
    int *vengo = new int[V + 1]();
    int *vecesEncolado = new int[V + 1](); // Array para evitar ciclos negativos
    bool *encolado = new bool[V + 1]();
    bool *visitado = new bool[V + 1]();
    for (int i = 1; i <= V; i++)
    {
        costo[i] = INF;
        vengo[i] = -1;
        vecesEncolado[i] = 0; // EVITA ciclos negativos
        encolado[i] = false;
        visitado[i] = false;
    }

    Cola<int> *aProcesar = new ColaImp<int>();
    costo[origen] = 0;
    encolado[origen] = true;
    vecesEncolado[origen]++; // EVITA ciclos negativos
    aProcesar->encolar(origen);

    while (!aProcesar->estaVacia())
    {
        int nodoAProcesar = aProcesar->desencolar();
        assert(vecesEncolado[nodoAProcesar] < V); // EVITA ciclos negativos
        if (vecesEncolado[nodoAProcesar] > V)
        {
            cout << "Existe un ciclo negativo" << endl;
            return;
        }
        encolado[nodoAProcesar] = false;
        visitado[nodoAProcesar] = true;
        NodoLista<Arista> *ady = g->adyacentesA(nodoAProcesar);
        while (ady != NULL)
        {
            int destino = ady->elemento.destino;
            int peso = ady->elemento.peso;
            if (costo[nodoAProcesar] + peso < costo[destino])
            {
                // Actualizamos costo y vengo
                costo[destino] = costo[nodoAProcesar] + peso;
                vengo[destino] = nodoAProcesar;

                // Solo encolamos si no está ya encolado
                if (!encolado[destino])
                {
                    encolado[destino] = true;
                    vecesEncolado[destino]++; // EVITA ciclos negativos
                    aProcesar->encolar(destino);
                }
            }
            ady = ady->sig;
        }
    }
}

#endif