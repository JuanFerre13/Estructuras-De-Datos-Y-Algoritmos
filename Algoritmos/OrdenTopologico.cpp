#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include "../TADS/Grafo/Grafo.h"
#include "../TADS/Cola/Cola.h"
#include "../TADS/Cola/ColaImp.cpp"
using namespace std;

bool esCiclico(Grafo *g)
{
    int V = g->getV();
    int *gradoEntrada = new int[V + 1]();
    Cola<int> *bolsa = new ColaImp<int>();
    // recorro todos los vertices
    for (int i = 1; i <= V; i++)
    {
        // recorro todas las aristas
        NodoLista<Arista> *ady = g->adyacentesA(i);
        while (ady != NULL)
        {
            int destino = ady->elemento.destino;
            gradoEntrada[destino]++;
            ady = ady->sig;
        }
    }

    // recorro todos los vertices nuevamente
    for (int i = 1; i <= V; i++)
    {
        // en caso que tengan grado de entrada 0
        // entonces puedo usarlo
        if (gradoEntrada[i] == 0)
        {
            bolsa->encolar(i);
        }
    }

    while (!bolsa->estaVacia())
    {
        int v = bolsa->desencolar();
        // recorro todas las aristas
        NodoLista<Arista> *ady = g->adyacentesA(v);
        while (ady != NULL)
        {
            int destino = ady->elemento.destino;
            // (esta listo para se procesado)
            if (--gradoEntrada[destino] == 0)
                bolsa->encolar(destino);
            ady = ady->sig;
        }
    }

    // verifiquemos: si quedo algun vertice con grado de entrada > 0
    // entonces nunca se pudo procesar, por lo tanto hay un ciclo
    bool hayCiclo = false;
    for (int i = 1; i <= V; i++)
    {
        if (gradoEntrada[i] > 0)
        {
            hayCiclo = true;
        }
    }

    delete[] gradoEntrada;
    delete bolsa;
    return hayCiclo;
}

void ordenTopologico(Grafo *g)
{
    int V = g->getV();
    int *gradoEntrada = new int[V + 1]();
    Cola<int> *bolsa = new ColaImp<int>();
    // recorro todos los vertices
    for (int i = 1; i <= V; i++)
    {
        // recorro todas las aristas
        NodoLista<Arista> *ady = g->adyacentesA(i);
        while (ady != NULL)
        {
            int destino = ady->elemento.destino;
            gradoEntrada[destino]++;
            ady = ady->sig;
        }
    }

    // recorro todos los vertices nuevamente
    for (int i = 1; i <= V; i++)
    {
        // en caso que tengan grado de entrada 0
        // entonces puedo usarlo
        if (gradoEntrada[i] == 0)
        {
            bolsa->encolar(i);
        }
    }

    while (!bolsa->estaVacia())
    {
        int v = bolsa->desencolar();
        cout << v << endl; // lo procesamos
        // recorro todas las aristas
        NodoLista<Arista> *ady = g->adyacentesA(v);
        while (ady != NULL)
        {
            int destino = ady->elemento.destino;
            // (esta listo para se procesado)
            if (--gradoEntrada[destino] == 0)
                bolsa->encolar(destino);
            ady = ady->sig;
        }
    }

    delete[] gradoEntrada;
    delete bolsa;
}