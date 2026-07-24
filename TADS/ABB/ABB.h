#ifndef ABB_H
#define ABB_H

#include <algorithm>
#include <iostream>

using namespace std;

/*
 * TAD ABB
 * -------
 * Árbol Binario de Búsqueda.
 *
 * Cada nodo mantiene a su izquierda los elementos menores y a su
 * derecha los mayores, lo que permite buscar, insertar y borrar
 * recorriendo un único camino desde la raíz hasta una hoja.
 *
 * El costo de las operaciones es O(altura). En un árbol equilibrado
 * la altura es O(log n), pero si los elementos se insertan ordenados
 * el árbol degenera en una lista y el costo pasa a ser O(n).
 * Para garantizar O(log n) en el peor caso, ver el TAD AVL.
 *
 * Requisitos sobre el tipo T:
 *   - Debe tener definidos los operadores de comparación
 *     '<', '>' e '==' (orden total).
 *
 * Invariante de representación:
 *   - Para cada nodo, todos los elementos del subárbol izquierdo son
 *     menores que su elemento, y todos los del subárbol derecho, mayores.
 *   - No se admiten elementos repetidos.
 */

template <class T>
class ABB
{
private:
    class nodoABB
    {
    public:
        T elemento;
        nodoABB *izq;
        nodoABB *der;
        nodoABB(T _elemento)
        {
            elemento = _elemento;
            izq = NULL;
            der = NULL;
        };
    };

    nodoABB *raiz;
    int cantidad;

    nodoABB *insertar(nodoABB *nodo, T elemento)
    {
        if (nodo == NULL)
        {
            cantidad++;
            return new nodoABB(elemento);
        }
        if (elemento < nodo->elemento)
        {
            nodo->izq = insertar(nodo->izq, elemento);
        }
        else if (elemento > nodo->elemento)
        {
            nodo->der = insertar(nodo->der, elemento);
        }

        // Si el elemento ya existe el árbol queda igual (no hay repetidos)
        return nodo;
    }

    bool contiene(nodoABB *nodo, T elemento)
    {
        if (nodo == NULL)
        {
            return false;
        }
        if (nodo->elemento == elemento)
        {
            return true;
        }
        else if (nodo->elemento > elemento)
        {
            return contiene(nodo->izq, elemento);
        }
        else
        {
            return contiene(nodo->der, elemento);
        }
    }

    nodoABB *minimo(nodoABB *nodo)
    {
        // El menor elemento es el que está más a la izquierda
        while (nodo->izq != NULL)
        {
            nodo = nodo->izq;
        }
        return nodo;
    }

    nodoABB *maximo(nodoABB *nodo)
    {
        // El mayor elemento es el que está más a la derecha
        while (nodo->der != NULL)
        {
            nodo = nodo->der;
        }
        return nodo;
    }

    nodoABB *borrar(nodoABB *nodo, T elemento)
    {
        if (nodo == NULL)
        {
            return NULL;
        }

        // Busco el nodo a borrar
        if (elemento < nodo->elemento)
        {
            nodo->izq = borrar(nodo->izq, elemento);
            return nodo;
        }
        if (elemento > nodo->elemento)
        {
            nodo->der = borrar(nodo->der, elemento);
            return nodo;
        }

        // Encontré el nodo, existen 3 casos

        // Caso 1: sin hijo izquierdo (cubre también el caso hoja)
        if (nodo->izq == NULL)
        {
            nodoABB *hijo = nodo->der;
            delete nodo;
            cantidad--;
            return hijo;
        }

        // Caso 2: sin hijo derecho
        if (nodo->der == NULL)
        {
            nodoABB *hijo = nodo->izq;
            delete nodo;
            cantidad--;
            return hijo;
        }

        /* Caso 3: tiene ambos hijos.
           Lo sustituyo por su sucesor inorden (el mínimo del subárbol
           derecho), que es el menor de los elementos mayores, y luego
           borro ese sucesor de su posición original. */
        nodoABB *sucesor = minimo(nodo->der);
        nodo->elemento = sucesor->elemento;
        nodo->der = borrar(nodo->der, sucesor->elemento);
        return nodo;
    }

    int altura(nodoABB *nodo)
    {
        if (nodo == NULL)
        {
            return 0;
        }
        return 1 + max(altura(nodo->izq), altura(nodo->der));
    }

    void imprimirInOrden(nodoABB *nodo)
    {
        if (nodo == NULL)
        {
            return;
        }
        // IZQ - RAIZ - DER: recorre los elementos en orden creciente
        imprimirInOrden(nodo->izq);
        cout << nodo->elemento << " ";
        imprimirInOrden(nodo->der);
    }

    void imprimirPreOrden(nodoABB *nodo)
    {
        if (nodo == NULL)
        {
            return;
        }
        // RAIZ - IZQ - DER
        cout << nodo->elemento << " ";
        imprimirPreOrden(nodo->izq);
        imprimirPreOrden(nodo->der);
    }

    void imprimirPostOrden(nodoABB *nodo)
    {
        if (nodo == NULL)
        {
            return;
        }
        // IZQ - DER - RAIZ
        imprimirPostOrden(nodo->izq);
        imprimirPostOrden(nodo->der);
        cout << nodo->elemento << " ";
    }

    void liberar(nodoABB *nodo)
    {
        if (nodo == NULL)
        {
            return;
        }
        // Recorrido en postorden: primero los hijos, luego el nodo
        liberar(nodo->izq);
        liberar(nodo->der);
        delete nodo;
    }

public:
    /*
     * Constructor.
     * Pre:  -
     * Post: crea un árbol binario de búsqueda vacío.
     */
    ABB() : raiz(NULL), cantidad(0) {}

    /*
     * Destructor.
     * Pre:  -
     * Post: libera toda la memoria ocupada por los nodos del árbol.
     */
    ~ABB()
    {
        liberar(raiz);
    }

    /*
     * Pre:  -
     * Post: inserta 'elemento' manteniendo el orden del árbol.
     *       Si 'elemento' ya existe, el árbol queda igual (no hay repetidos).
     * Costo: O(altura)
     */
    void insertar(T elemento)
    {
        raiz = insertar(raiz, elemento);
    }

    /*
     * Pre:  -
     * Post: elimina 'elemento' del árbol manteniendo el orden.
     *       Si 'elemento' no pertenece, el árbol queda igual.
     * Costo: O(altura)
     */
    void borrar(T elemento)
    {
        raiz = borrar(raiz, elemento);
    }

    /*
     * Pre:  -
     * Post: retorna true si 'elemento' pertenece al árbol; false en caso contrario.
     * Costo: O(altura)
     */
    bool contiene(T elemento)
    {
        return contiene(raiz, elemento);
    }

    /*
     * Pre:  el árbol no está vacío.
     * Post: retorna el menor elemento del árbol.
     * Costo: O(altura)
     */
    T minimo()
    {
        return minimo(raiz)->elemento;
    }

    /*
     * Pre:  el árbol no está vacío.
     * Post: retorna el mayor elemento del árbol.
     * Costo: O(altura)
     */
    T maximo()
    {
        return maximo(raiz)->elemento;
    }

    /*
     * Pre:  -
     * Post: retorna true si el árbol no tiene elementos.
     * Costo: O(1)
     */
    bool esVacio()
    {
        return raiz == NULL;
    }

    /*
     * Pre:  -
     * Post: retorna la cantidad de elementos del árbol.
     * Costo: O(1)
     */
    int largo()
    {
        return cantidad;
    }

    /*
     * Pre:  -
     * Post: retorna la cantidad de nodos del camino más largo
     *       desde la raíz hasta una hoja (0 si el árbol es vacío).
     * Costo: O(n)
     */
    int altura()
    {
        return altura(raiz);
    }

    /*
     * Pre:  T debe tener definido el operador '<<'.
     * Post: imprime los elementos en orden creciente.
     * Costo: O(n)
     */
    void imprimirInOrden()
    {
        imprimirInOrden(raiz);
        cout << endl;
    }

    /*
     * Pre:  T debe tener definido el operador '<<'.
     * Post: imprime los elementos en preorden (RAIZ - IZQ - DER).
     * Costo: O(n)
     */
    void imprimirPreOrden()
    {
        imprimirPreOrden(raiz);
        cout << endl;
    }

    /*
     * Pre:  T debe tener definido el operador '<<'.
     * Post: imprime los elementos en postorden (IZQ - DER - RAIZ).
     * Costo: O(n)
     */
    void imprimirPostOrden()
    {
        imprimirPostOrden(raiz);
        cout << endl;
    }
};

#endif
