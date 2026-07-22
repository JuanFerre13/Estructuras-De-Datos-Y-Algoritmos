#ifndef LISTA_H
#define LISTA_H

class Lista
{
private:
    int *vector;
    int largoVector;
    int cantElementos;

    // PRE: -
    // POS: duplica la capacidad interna de la lista
    void reagrandar();

public:
    // PRE: -
    // POS: crea una lista vacia
    Lista();

    // PRE: -
    // POS: crea una copia de otra lista sin compartir memoria
    Lista(const Lista &otra);

    // PRE: -
    // POS: asigna una copia de otra lista sin compartir memoria
    Lista &operator=(const Lista &otra);

    // PRE: -
    // POS: libera la memoria de la lista
    ~Lista();

    // PRE: -
    // POS: Agrega el elemento e en la posicion pos de la lista haciendo que los elementos
    //    	 en esa y siguientes posiciones avancen una posicion.
    //   	 El primer elemento se encuentra en la posicion 0.
    //   	 Si pos es mayor o igual al largo de la lista insertar al final
    void agregar(int e, unsigned int pos);

    // PRE: -
    // POS: Borra el elemento en la posicion pos de la lista haciendo que los elementos
    //    	 en las siguientes posiciones retrocedan una posicion.
    //   	 El primer elemento se encuentra en la posicion 0.
    //   	 Si pos es mayor o igual al largo de la lista la operacion no tiene efecto
    void borrar(unsigned int pos);

    // PRE: 0 <= pos < cantidadElementos()
    // POS: Retorna el elemento en la posicion pos
    //   	 El primer elemento se encuentra en la posicion 0.
    int elemento(unsigned int pos);

    // PRE: -
    // POS: retorna true si la lista esta vacia
    bool esVacia();

    // PRE: -
    // POS: retorna la cantidad de elementos presentes en la lista
    unsigned int cantidadElementos();
};

#endif
