#ifndef LISTA_IMP
#define LISTA_IMP

#include <cstddef>
#include "Lista.h"

struct _representacionListaPosInt
{
    int *vector;
    int largoVector;
    int cantElementos;
};

ListaPosInt crearListaPosInt()
{
    ListaPosInt l = new _representacionListaPosInt;
    l->vector = new int[50];
    l->largoVector = 50;
    l->cantElementos = 0;
    return l;
}

// PRE: Toma una ListaPosInt
// POS: Duplica el tamanio de la lista
void reagrandar(ListaPosInt &l)
{
    int *arrayNuevo = new int[2 * l->largoVector];
    for (int i = 0; i < l->cantElementos; i++)
    {
        arrayNuevo[i] = l->vector[i];
    }
    l->largoVector = 2 * l->largoVector;
    delete[] l->vector;
    l->vector = arrayNuevo;
}

void agregar(ListaPosInt &l, int e, unsigned int pos)
{
    if (l->cantElementos == l->largoVector) // La lista esta llena
    {
        reagrandar(l);
    }
    if (pos >= l->cantElementos)
    {
        l->vector[l->cantElementos] = e;
    }
    else
    {
        for (int i = l->cantElementos; i > pos; i--)
        {
            l->vector[i] = l->vector[i - 1];
        }
        l->vector[pos] = e;
    }
    l->cantElementos++;
}

void borrar(ListaPosInt &l, unsigned int pos)
{
    if (pos >= l->cantElementos)
    {
        return;
    }
    for (int i = pos; i < l->cantElementos - 1; i++)
    {
        l->vector[i] = l->vector[i + 1];
    }
    l->cantElementos--;
}

int elemento(ListaPosInt l, unsigned int pos)
{
    return l->vector[pos];
}

bool esVacia(ListaPosInt l)
{
    if (l == NULL)
    {
        return true;
    }
    return l->cantElementos == 0;
}

unsigned int cantidadElementos(ListaPosInt l)
{
    return l->cantElementos;
}

ListaPosInt clon(ListaPosInt l)
{
    ListaPosInt copia = new _representacionListaPosInt;
    copia->largoVector = l->largoVector;
    copia->cantElementos = l->cantElementos;
    copia->vector = new int[copia->largoVector];
    for (int i = 0; i < l->cantElementos; i++)
    {
        copia->vector[i] = l->vector[i];
    }
    return copia;
}

void destruir(ListaPosInt &l)
{
    if (l == NULL)
    {
        return;
    }
    delete[] l->vector;
    delete l;
    l = NULL;
}

#endif
