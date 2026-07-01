#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H

template <class T>
class HeapBinario
{
public:
    virtual bool estaLleno() = 0;

    virtual bool estaVacio() = 0;

    virtual void insertar(T el) = 0;

    virtual T tope() = 0;

    virtual void eliminarTope() = 0;
};

#endif