#ifndef PILA_H
#define PILA_H

class Pila
{
private:
    int *vector;
    int largoVector;
    int cantElementos;

    // PRE: -
    // POS: duplica la capacidad interna de la pila
    void reagrandar();

public:
    // PRE: -
    // POS: crea una pila vacia
    Pila();

    // PRE: -
    // POS: crea una copia de otra pila sin compartir memoria
    Pila(const Pila &otra);

    // PRE: -
    // POS: asigna una copia de otra pila sin compartir memoria
    Pila &operator=(const Pila &otra);

    // PRE: -
    // POS: libera la memoria de la pila
    ~Pila();

    // PRE: -
    // POS: inserta un elemento en la cima de la pila
    void push(int e);

    // PRE: !esVacia()
    // POS: retorna el elemento de la cima de la pila sin eliminarlo
    int top();

    // PRE: !esVacia()
    // POS: elimina el elemento de la cima de la pila
    void pop();

    // PRE: -
    // POS: retorna true si y solo si la pila esta vacia
    bool esVacia();

    // PRE: -
    // POS: retorna la cantidad de elementos presentes en la pila
    unsigned int cantidadElementos();
};

#endif
