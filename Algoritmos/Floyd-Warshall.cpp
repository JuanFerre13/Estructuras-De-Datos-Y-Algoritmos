#ifndef FLOYDWARSHALL
#define FLOYDWARSHALL

#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include "../TADS/Grafo/Grafo.h"
#include "../TADS/Lista/NodoLista.cpp"

using namespace std;

#define INF INT_MAX

void floyd(Grafo *g)
{
    int V = g->getV();
    int **costo = new int *[V + 1]();
    int **vengo = new int *[V + 1]();

    /* costo[i][j] arranca en INF (no conocemos camino de i a j todavia) salvo la
      diagonal, que vale 0 porque ir de un vertice a si mismo no cuesta nada.
      vengo[i][j] = -1 significa "sin predecesor", igual que en Dijkstra. */
    for (int i = 1; i <= V; i++)
    {
        costo[i] = new int[V + 1];
        vengo[i] = new int[V + 1];

        for (int j = 1; j <= V; j++)
        {
            costo[i][j] = (i == j) ? 0 : INF;
            vengo[i][j] = -1;
        }
    }

    for (int origen = 1; origen <= V; origen++)
    {
        NodoLista<Arista> *ady = g->adyacentesA(origen);
        while (ady != NULL)
        {
            int destino = ady->elemento.destino;
            int peso = ady->elemento.peso;
            if (origen != destino)
            {
                costo[origen][destino] = peso;
                vengo[origen][destino] = origen;
            }
            ady = ady->sig;
        }
    }

    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (costo[i][k] != INF && costo[k][j] != INF)
                { // preguto si actualmente existe un camino en ambos tramos
                    if (costo[i][k] + costo[k][j] < costo[i][j])
                    { // si mejoro el costo
                        costo[i][j] = costo[i][k] + costo[k][j];
                        vengo[i][j] = vengo[k][j];
                    }
                }
            }
        }
    }

    // Mostramos el costo minimo entre cada par de vertices
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << i << " -> " << j << ": ";
            if (costo[i][j] == INF)
            {
                cout << "inalcanzable" << endl;
            }
            else
            {
                cout << "costo " << costo[i][j] << endl;
            }
        }
    }

    // Cada new[] necesita su delete[]: primero las filas, despues el array de punteros
    for (int i = 1; i <= V; i++)
    {
        delete[] costo[i];
        delete[] vengo[i];
    }
    delete[] costo;
    delete[] vengo;
}

#endif