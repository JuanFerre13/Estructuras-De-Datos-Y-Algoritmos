#ifndef DIJKSTRA
#define DIJKSTRA

#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include "../TADS/Grafo/Grafo.h"
#include "../TADS/HeapBinario/HeapBinario.h"
#include "../TADS/HeapBinario/MinHeap.cpp"
#include "../TADS/HeapBinario/NodoHeap.h"
#include "../TADS/Pila/Pila.h"
#include "../TADS/Pila/Pila.cpp"

using namespace std;

// PRE: destino es alcanzable desde origen (costo[destino] != INF)
// POS: imprime el camino minimo origen -> destino
// vengo[i] guarda el vertice anterior a i en el camino minimo, asi que
// recorriendolo hacia atras obtenemos el camino al reves. Lo apilamos para
// que al desapilar salga en el orden correcto (el ultimo en entrar, origen,
// es el primero en salir).
// inline para poder incluir este archivo desde varias unidades de compilacion.
inline void imprimirCamino(int *vengo, int destino)
{
    Pila camino;
    int actual = destino;
    while (actual != -1)
    {
        camino.push(actual);
        actual = vengo[actual];
    }

    while (!camino.esVacia())
    {
        cout << camino.top();
        camino.pop();
        if (!camino.esVacia())
            cout << " -> ";
    }
}

void dijkstra(Grafo *g, int origen)
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

            // Si mejoramos el costo acumulado de llegar a w
            if (costo[w] > costo[v] + costoArista)
            {
                // Actualizamos el costo
                costo[w] = costo[v] + costoArista;
                // Actualizamos el vengo
                vengo[w] = v;
                // Insertamos w con el nuevo costo (puede existir una entrada vieja)
                NodoHeap nw(w, costo[w]);
                heap->insertar(nw);
            }
            ady = ady->sig;
        }
    }

    // Mostramos el costo minimo y el camino desde origen hacia cada vertice
    for (int i = 1; i <= V; i++)
    {
        cout << origen << " -> " << i << ": ";
        if (costo[i] == INF)
        {
            cout << "inalcanzable" << endl;
        }
        else
        {
            cout << "costo " << costo[i] << " | camino: ";
            imprimirCamino(vengo, i);
            cout << endl;
        }
    }

    delete[] visitado;
    delete[] costo;
    delete[] vengo;
    delete heap;
}

#endif