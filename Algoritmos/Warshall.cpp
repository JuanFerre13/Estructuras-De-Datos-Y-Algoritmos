#ifndef WARSHALL
#define WARSHALL

#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include "../TADS/Grafo/Grafo.h"
#include "../TADS/Lista/NodoLista.cpp"

bool** warshall(Grafo *g)
{
  int V = g->getV();
  bool **mct = new bool *[V + 1]();

  for (int i = 1; i <= V; i++)
  {
    mct[i] = new bool[V + 1]();
  }

  for (int origen = 1; origen <= V; origen++)
  {
    NodoLista<Arista> *ady = g->adyacentesA(origen);
    while (ady != NULL)
    {
      int destino = ady->elemento.destino;
      if (origen != destino)
      {
        mct[origen][destino] = true;
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
          mct[i][j] = mct[i][j] || (mct[i][k] && mct[k][j]);
      }
    }
  }
  return mct;
}

#endif