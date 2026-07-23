#ifndef PRIM
#define PRIM

#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include "../TADS/Grafo/Grafo.h"
#include "../TADS/HeapBinario/HeapBinario.h"
#include "../TADS/HeapBinario/MinHeap.cpp"
#include "../TADS/HeapBinario/NodoHeap.h"

using namespace std;

void prim(Grafo *g, int origen)
{
    int V = g->getV();
    int A = g->getA();
    bool *visitado = new bool[V + 1]();
    int *costo = new int[V + 1]();
    int *vengo = new int[V + 1]();

    for (int i = 1; i <= V; i++)
    {
        visitado[i] = false;
        costo[i] = INF;
        vengo[i] = -1;
    }

    // La capacidad debe ser mayor a V debido a que insertaremos repetidos.
    // getA() cuenta cada arista una vez, pero en un grafo no dirigido la lista
    // de adyacencia guarda las dos direcciones: hasta 2*A inserciones, +1 por el origen.
    MinHeap<NodoHeap> *heap = new MinHeap<NodoHeap>(V + 2 * A + 1, esMenorFn);

    costo[origen] = 0;
    NodoHeap nh(origen, 0);
    heap->insertar(nh);

    while (!heap->estaVacio())
    {
        NodoHeap aProcesar = heap->tope();
        int v = aProcesar.vertice;
        heap->eliminarTope();
        if (visitado[v])
            continue;
        visitado[v] = true;

        NodoLista<Arista> *ady = g->adyacentesA(v);
        while (ady != NULL)
        {
            // W el destino de la arista
            int w = ady->elemento.destino;
            // costoArista es el costo de dicha arista que recorremos
            int costoArista = ady->elemento.peso;

            // Prim compara SOLO el peso de la arista contra el mejor conocido
            // para w (no el costo acumulado: eso seria Dijkstra).
            // Si w ya esta en el arbol su costo es definitivo, no se toca.
            if (!visitado[w] && costoArista < costo[w])
            {
                // Actualizamos el costo
                costo[w] = costoArista;
                // Actualizamos el vengo
                vengo[w] = v;
                // Insertamos w con el nuevo costo (puede existir una entrada vieja)
                NodoHeap nw(w, costo[w]);
                heap->insertar(nw);
            }
            ady = ady->sig;
        }
    }

    // Mostramos el arbol generador minimo resultante
    int costoTotal = 0;
    for (int i = 1; i <= V; i++)
    {
        if (vengo[i] != -1)
        {
            cout << vengo[i] << " - " << i << " (peso " << costo[i] << ")" << endl;
            costoTotal += costo[i];
        }
    }
    cout << "Costo total: " << costoTotal << endl;

    delete[] visitado;
    delete[] costo;
    delete[] vengo;
    delete heap;
}

#endif