#ifndef COLA_IMP
#define COLA_IMP

#include "Cola.h"
#include <cassert>

template <class T>
class ColaImp : public Cola<T>
{
private:
    class Nodo
    {
    public:
        T elemento;
        Nodo *siguiente;
        Nodo(T _elemento, Nodo *_siguiente)
        {
            elemento = _elemento;
            siguiente = _siguiente;
        }
    };

    Nodo *inicio;
    Nodo *fin;
    int tamanio;

public:
    ColaImp()
    {
        inicio = NULL;
        fin = NULL;
        tamanio = 0;
    }

    ~ColaImp()
    {
        while (!estaVacia())
        {
            desencolar();
        }
    }

    void encolar(T elemento)
    {
        Nodo *nuevoNodo = new Nodo(elemento, NULL);
        if (estaVacia())
        {
            inicio = nuevoNodo;
            fin = nuevoNodo;
        }
        else
        {
            fin->siguiente = nuevoNodo;
            fin = nuevoNodo;
        }
        tamanio++;
    }

    T desencolar()
    {
        assert(!estaVacia());
        Nodo *nodoAEliminar = inicio;
        T elemento = nodoAEliminar->elemento;
        inicio = inicio->siguiente;
        if (inicio == NULL)
        {
            fin = NULL;
        }
        delete nodoAEliminar;
        tamanio--;
        return elemento;
    }

    T frente()
    {
        assert(!estaVacia());
        return inicio->elemento;
    }

    bool estaVacia()
    {
        return inicio == NULL;
    }

    int getTamanio()
    {
        return tamanio;
    }
};

#endif
