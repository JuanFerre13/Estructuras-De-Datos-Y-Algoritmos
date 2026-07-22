#ifndef PILA_IMP
#define PILA_IMP

#include <cassert>
#include "Pila.h"

Pila::Pila()
{
    vector = new int[50];
    largoVector = 50;
    cantElementos = 0;
}

Pila::Pila(const Pila &otra)
{
    largoVector = otra.largoVector;
    cantElementos = otra.cantElementos;
    vector = new int[largoVector];
    for (int i = 0; i < cantElementos; i++)
    {
        vector[i] = otra.vector[i];
    }
}

Pila &Pila::operator=(const Pila &otra)
{
    if (this != &otra)
    {
        delete[] vector;
        largoVector = otra.largoVector;
        cantElementos = otra.cantElementos;
        vector = new int[largoVector];
        for (int i = 0; i < cantElementos; i++)
        {
            vector[i] = otra.vector[i];
        }
    }
    return *this;
}

Pila::~Pila()
{
    delete[] vector;
}

void Pila::reagrandar()
{
    int *arrayNuevo = new int[2 * largoVector];
    for (int i = 0; i < cantElementos; i++)
    {
        arrayNuevo[i] = vector[i];
    }
    largoVector = 2 * largoVector;
    delete[] vector;
    vector = arrayNuevo;
}

void Pila::push(int e)
{
    if (cantElementos == largoVector) // La pila esta llena
    {
        reagrandar();
    }
    vector[cantElementos] = e;
    cantElementos++;
}

int Pila::top()
{
    assert(!esVacia());
    return vector[cantElementos - 1];
}

void Pila::pop()
{
    assert(!esVacia());
    cantElementos--;
}

bool Pila::esVacia()
{
    return cantElementos == 0;
}

unsigned int Pila::cantidadElementos()
{
    return cantElementos;
}

#endif
