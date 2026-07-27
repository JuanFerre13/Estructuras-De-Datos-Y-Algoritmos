#ifndef COLA_H
#define COLA_H

template <class T>
class Cola
{
public:
    virtual ~Cola() {}

    // pre: -
    // post: el elemento es insertado al final de la cola
    virtual void encolar(T elemento) = 0;

    // pre: la cola no esta vacia
    // post: elimina y retorna el elemento del frente de la cola
    virtual T desencolar() = 0;

    // pre: la cola no esta vacia
    // post: retorna el elemento del frente sin eliminarlo
    virtual T frente() = 0;

    // pre: -
    // post: retorna verdadero si la cola no tiene elementos
    virtual bool estaVacia() = 0;

    // pre: -
    // post: retorna la cantidad de elementos en la cola
    virtual int getTamanio() = 0;
};

#endif
