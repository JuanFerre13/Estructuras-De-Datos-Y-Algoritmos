#ifndef GRAPH_H
#define GRAPH_H
#include "../Lista/NodoLista.cpp"
#include "Arista.h"

class Grafo
{
public:
    virtual ~Grafo() {}

    virtual void agregarArista(int origen, int destino, int peso = 1) = 0;

    virtual NodoLista<Arista> *adyacentesA(int origen) = 0;

    virtual int getV() = 0;

    virtual int getA() = 0;
};
#endif
