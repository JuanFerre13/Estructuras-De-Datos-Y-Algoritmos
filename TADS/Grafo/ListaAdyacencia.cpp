#ifndef LA
#define LA
#include <cassert>
#include "Grafo.h"

// using namespace std;
class ListaAdyacencia : public Grafo
{
private:
    NodoLista<Arista> **listaNodos;
    int V;
    int A;
    bool esPonderado;
    bool esDirigido;

public:
    ListaAdyacencia(int _V, bool _esPonderado, bool _esDirigido)
    {
        V = _V;
        A = 0;
        esDirigido = _esDirigido;
        esPonderado = _esPonderado;
        listaNodos = new NodoLista<Arista> *[V + 1]();
        for (int i = 1; i <= V; i++)
        {
            listaNodos[i] = NULL;
        }
    }

    ~ListaAdyacencia()
    {
        for (int i = 1; i <= V; i++)
        {
            NodoLista<Arista> *actual = listaNodos[i];
            while (actual != NULL)
            {
                NodoLista<Arista> *aBorrar = actual;
                actual = actual->sig;
                delete aBorrar;
            }
        }
        delete[] listaNodos;
    }

    void agregarArista(int origen, int destino, int peso = 1)
    {
        assert(esPonderado || peso == 1);
        Arista a(origen, destino, peso);

        listaNodos[origen] = new NodoLista<Arista>(a, listaNodos[origen]);
        if (!esDirigido)
        {
            Arista a(destino, origen, peso);
            listaNodos[destino] = new NodoLista<Arista>(a, listaNodos[destino]);
        }
        A++;
    }

    NodoLista<Arista> *adyacentesA(int origen)
    {
        return listaNodos[origen];
    }

    int getV()
    {
        return V;
    }

    int getA()
    {
        return A;
    }
};

#endif
