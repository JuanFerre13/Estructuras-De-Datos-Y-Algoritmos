#ifndef NODO_LISTA
#define NODO_LISTA

#include <cstddef>

template <class T>
struct NodoLista
{
    T elemento;
    NodoLista *sig;
    NodoLista(T _el, NodoLista *_sig = NULL)
    {
        elemento = _el;
        sig = _sig;
    }
};

#endif