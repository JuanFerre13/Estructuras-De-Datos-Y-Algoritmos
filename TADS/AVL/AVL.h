#ifndef AVL_H
#define AVL_H

#include <algorithm>

/*
 * TAD AVL
 * -------
 * Árbol Binario de Búsqueda auto-balanceado (Adelson-Velsky y Landis).
 *
 * En todo momento, para cada nodo del árbol, la diferencia de altura
 * entre sus subárboles izquierdo y derecho (factor de balance) es
 * a lo sumo 1. Esto garantiza que las operaciones de inserción y
 * búsqueda tengan costo O(log n).
 *
 * Requisitos sobre el tipo T:
 *   - Debe tener definidos los operadores de comparación
 *     '<', '>' e '==' (orden total).
 *
 * Invariante de representación:
 *   - Para cada nodo, todos los elementos del subárbol izquierdo son
 *     menores que su elemento, y todos los del subárbol derecho, mayores.
 *   - No se admiten elementos repetidos.
 *   - |altura(izq) - altura(der)| <= 1 para todo nodo.
 */

template <class T>
class AVL
{
private:
    class nodoAVL
    {
    public:
        T elemento;
        nodoAVL *izq;
        nodoAVL *der;
        int altura;
        nodoAVL(T _elemento)
        {
            elemento = _elemento;
            izq = NULL;
            der = NULL;
            altura = 1;
        };
    };

    nodoAVL *raiz;

    int obtenerAltura(nodoAVL *nodo)
    {
        if (nodo == NULL)
        {
            return 0;
        }
        return nodo->altura;
    }

    nodoAVL *rotacionDer(nodoAVL *y)
    {
        nodoAVL *x = y->izq;
        nodoAVL *T2 = x->der;

        // Realizo la rotación
        x->der = y;
        y->izq = T2;

        // Actualizo alturas
        y->altura = std::max(obtenerAltura(y->izq),
                             obtenerAltura(y->der)) +
                    1;

        x->altura = std::max(obtenerAltura(x->izq),
                             obtenerAltura(x->der)) +
                    1;

        // Retorno la nueva raiz
        return x;
    }

    nodoAVL *rotacionIzq(nodoAVL *x)
    {
        nodoAVL *y = x->der;
        nodoAVL *T2 = y->izq;

        // Realizo la rotación
        y->izq = x;
        x->der = T2;

        // Actualizo alturas
        x->altura = std::max(obtenerAltura(x->izq),
                             obtenerAltura(x->der)) +
                    1;

        y->altura = std::max(obtenerAltura(y->izq),
                             obtenerAltura(y->der)) +
                    1;

        // Retorno la nueva raiz
        return y;
    }

    int getBalance(nodoAVL *nodo)
    {
        if (nodo == NULL)
        {
            return 0;
        }
        return obtenerAltura(nodo->der) - obtenerAltura(nodo->izq);
    }

    nodoAVL *insertar(nodoAVL *nodo, T elemento)
    {
        if (nodo == NULL)
        {
            return new nodoAVL(elemento);
        }
        if (elemento < nodo->elemento)
        {
            nodo->izq = insertar(nodo->izq, elemento);
        }
        else if (elemento > nodo->elemento)
        {
            nodo->der = insertar(nodo->der, elemento);
        }
        else
        {
            return nodo;
        }

        // Actualizo la altura de su antecesor
        nodo->altura = 1 + std::max(obtenerAltura(nodo->izq),
                                    obtenerAltura(nodo->der));

        /* Obtengo el factor de balance de su antecesor
            para verificar que no se haya desbalanceado*/

        int balance = getBalance(nodo);

        // Si se desbalanceó existen 4 casos

        // Caso IZQ IZQ
        if (balance < -1 && elemento < nodo->izq->elemento)
        {
            return rotacionDer(nodo);
        }

        // Caso DER DER
        if (balance > 1 && elemento > nodo->der->elemento)
        {
            return rotacionIzq(nodo);
        }

        // Caso IZQ DER
        if (balance < -1 && elemento > nodo->izq->elemento)
        {
            nodo->izq = rotacionIzq(nodo->izq);
            return rotacionDer(nodo);
        }

        // Caso DER IZQ
        if (balance > 1 && elemento < nodo->der->elemento)
        {
            nodo->der = rotacionDer(nodo->der);
            return rotacionIzq(nodo);
        }

        // Retorno el puntero al nodo
        return nodo;
    }

    bool contiene(nodoAVL *nodo, T elemento)
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

    void liberar(nodoAVL *nodo)
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
     * Post: crea un árbol AVL vacío.
     */
    AVL() : raiz(NULL) {}

    /*
     * Destructor.
     * Pre:  -
     * Post: libera toda la memoria ocupada por los nodos del árbol.
     */
    ~AVL()
    {
        liberar(raiz);
    }

    /*
     * Pre:  -
     * Post: inserta 'elemento' manteniendo el orden y el balanceo AVL.
     *       Si 'elemento' ya existe, el árbol queda igual (no hay repetidos).
     * Costo: O(log n)
     */
    void insertar(T elemento)
    {
        raiz = insertar(raiz, elemento);
    }

    /*
     * Pre:  -
     * Post: retorna true si 'elemento' pertenece al árbol; false en caso contrario.
     * Costo: O(log n)
     */
    bool contiene(T elemento)
    {
        return contiene(raiz, elemento);
    }
};

#endif
