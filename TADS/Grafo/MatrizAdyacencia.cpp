#ifndef MA
#define MA

#include <cassert>
#include <climits>
#include "./Grafo.h"

#define INF INT_MAX

class MatrizAdyacencia : public Grafo
{
private:
    int **mat;
    int V;
    int A;
    bool esPonderado;
    bool esDirigido;

public:
    MatrizAdyacencia(int _V, bool _esPonderado, bool _esDirigido)
    {
        V = _V;
        A = 0;
        esDirigido = _esDirigido;
        esPonderado = _esPonderado;
        mat = new int *[V + 1]();
        for (int i = 1; i <= V; i++)
        {
            mat[i] = new int[V + 1]();
            for (int j = 1; j <= V; j++)
            {
                mat[i][j] = INF;
            }
        }
    }

    ~MatrizAdyacencia()
    {
        for (int i = 1; i <= V; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void agregarArista(int origen, int destino, int peso = 1)
    {
        assert(esPonderado || peso == 1);
        assert(origen >= 1 && origen <= V);
        assert(destino >= 1 && destino <= V);

        // Si la arista ya existia solo se actualiza el peso: no es una arista nueva.
        bool esNueva = mat[origen][destino] == INF;
        mat[origen][destino] = peso;
        if (!esDirigido)
        {
            mat[destino][origen] = peso;
        }
        if (esNueva)
        {
            A++;
        }
    }

    NodoLista<Arista> *adyacentesA(int origen)
    {
        NodoLista<Arista> *ret = NULL;
        for (int i = 1; i <= V; i++) // i es el destino
        {
            int peso = mat[origen][i];
            if (peso != INF)
            {
                Arista a(origen, i, peso);
                ret = new NodoLista<Arista>(a, ret);
            }
        }
        return ret;
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
