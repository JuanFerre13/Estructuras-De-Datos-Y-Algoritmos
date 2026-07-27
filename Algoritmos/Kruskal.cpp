#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include "./Grafo.h"
#include "./ListaAdyacencia.cpp"
#include "../TADS/HeapBinario/MinHeap.cpp"
#include "../TADS/MFSet/MFSet.cpp"
using namespace std;

#define INF INT_MAX

bool comparadoraFn(Arista a, Arista b)
{
    return a.peso < b.peso;
}

void *imprimirGrafo(Grafo *g)
{
    int V = g->getV();
    int A = g->getA();
    cout << "El grafo tiene " << V << " vertices y " << A << " aristas." << endl;
    int pesoTotal = 0;
    for (int v = 1; v <= V; v++)
    {
        NodoLista<Arista> *ady = g->adyacentesA(v);
        while (ady != NULL)
        {
            Arista a = ady->elemento;
            if (a.origen < a.destino)
            {
                cout << a.origen << "--(" << a.peso << ")--" << a.destino << endl;
                pesoTotal += a.peso;
            }
            ady = ady->sig;
        }
    }

    cout << endl
         << "El costo total es de " << pesoTotal << endl;
}

Grafo *kruskal(Grafo *g)
{
    int V = g->getV();
    int A = g->getA();
    Grafo *ACM = new ListaAdyacencia(V, true, false);

    MinHeap<Arista> *aristarPorPeso = new MinHeap<Arista>(A, comparadoraFn);
    for (int v = 1; v <= V; v++)
    {
        NodoLista<Arista> *ady = g->adyacentesA(v);
        while (ady != NULL)
        {
            Arista a = ady->elemento;
            if (a.origen < a.destino) // EVITO insertar aristas repetidas (1,2) y (2,1)
            {
                aristarPorPeso->insertar(a);
                ady = ady->sig;
            }
        }
    }

    MFSet *mfset = new MFSet(V);
    while (!aristarPorPeso->estaVacio())
    {
        Arista a = aristarPorPeso->tope();
        aristarPorPeso->eliminarTope();
        if (!mfset->pertenecenAlMismo(a.origen, a.destino))
        {
            ACM->agregarArista(a.origen, a.destino, a.peso);
            mfset->merge(a.origen, a.destino);
        }
    }

    return ACM;
}
