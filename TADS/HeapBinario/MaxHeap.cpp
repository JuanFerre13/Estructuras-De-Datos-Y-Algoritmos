#ifndef MAX_HEAP
#define MAX_HEAP
#include <cassert>
#include <iostream>
#include "HeapBinario.h"
using namespace std;

template <class T>
class MaxHeap : public HeapBinario<T>
{
private:
    // atributos
    T *arr;
    int sigLibre;
    int capacidad;
    bool (*esMayor)(T, T);

    int padre(int pos)
    {
        return (pos - 1) / 2;
    }

    int hijoIzq(int pos)
    {
        return (2 * pos) + 1;
    }

    int hijoDer(int pos)
    {
        return (2 * pos) + 2;
    }

    void intercambiar(int pos1, int pos2)
    {
        T aux = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = aux;
    }

    void flotar(int pos)
    {
        if (pos > 0)
        {
            int posPadre = padre(pos);
            if (this->esMayor(arr[pos], arr[posPadre]))
            {
                intercambiar(pos, posPadre);
                flotar(posPadre);
            }
        }
    }

    void hundir(int pos)
    {
        int posHijoIzq = this->hijoIzq(pos);
        int posHijoDer = this->hijoDer(pos);
        if (posHijoIzq < sigLibre)
        {
            int posMenorHijo = posHijoIzq;
            if (posHijoDer < sigLibre && this->esMayor(arr[posHijoDer], arr[posMenorHijo]))
            {
                posMenorHijo = posHijoDer;
            }
            if (this->esMayor(arr[posMenorHijo], arr[pos]))
            {
                intercambiar(pos, posMenorHijo);
                hundir(posMenorHijo);
            }
        }
    }

public:
    MaxHeap(int _capacidad, bool (*_esMayor)(T, T))
    {
        assert(_capacidad > 0);
        sigLibre = 0;
        capacidad = _capacidad;
        arr = new T[capacidad]();
        esMayor = _esMayor;
    }

    ~MaxHeap()
    {
        delete[] arr;
    }

    bool estaLleno()
    {
        return sigLibre == capacidad;
    }

    bool estaVacio()
    {
        return sigLibre == 0;
    }

    void insertar(T el)
    {
        assert(!estaLleno());
        arr[sigLibre] = el;
        sigLibre++;
        flotar(sigLibre - 1);
    }

    T tope()
    {
        assert(!estaVacio());
        return arr[0];
    }

    void eliminarTope()
    {
        assert(!estaVacio());
        sigLibre--;
        intercambiar(0, sigLibre);
        hundir(0);
    }
};

#endif