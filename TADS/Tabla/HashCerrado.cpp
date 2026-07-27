#ifndef HASH_TABLE_OPENING_ADDRESSING
#define HASH_TABLE_OPENING_ADDRESSING
#include <cmath>
#include <climits>
#include <cassert>
#include "Tabla.h"

template <class K, class V>
struct ClaveValor
{
    K clave;
    V valor;
    ClaveValor(K _clave, V _valor)
    {
        clave = _clave;
        valor = _valor;
    }
};

template <class K, class V>
class HashCerrado : public Tabla<K, V>
{
private:
    // The table itself
    ClaveValor<K, V> **tabla;
    bool *eliminado;
    int N;
    int B;
    int (*hashFunction1)(K);
    int (*hashFunction2)(K);

    int pos(K key, unsigned int i)
    {
        assert(hashFunction2(key) != 0);
        return abs((int)(hashFunction1(key) + i * hashFunction2(key))) % B;
    }

    void rehash()
    {
        int nuevoLargo = B * 2;
        ClaveValor<K, V> **nuevaTabla = new ClaveValor<K, V> *[nuevoLargo]();
        bool *nuevoEliminado = new bool[nuevoLargo]();
        for (int i = 0; i < nuevoLargo; i++)
        {
            nuevaTabla[i] = NULL;
            nuevoEliminado[i] = false;
        }

        ClaveValor<K, V> **tablaAntigua = tabla;
        bool *eliminadoAntiguo = eliminado;
        int BAntiguo = B;

        tabla = nuevaTabla;
        eliminado = nuevoEliminado;
        B = nuevoLargo;
        N = 0;

        for (int i = 0; i < BAntiguo; i++)
        {
            if (tablaAntigua[i] != NULL && !eliminadoAntiguo[i])
            {
                bool actualice = false;
                int intento = 0;
                while (!actualice)
                {
                    int p = pos(tablaAntigua[i]->clave, intento);
                    if (tabla[p] == NULL && !eliminado[p])
                    {
                        tabla[p] = new ClaveValor<K, V>(tablaAntigua[i]->clave, tablaAntigua[i]->valor);
                        N++;
                        actualice = true;
                    }
                    else
                    {
                        intento++;
                        assert(intento < B);
                    }
                }
            }
        }

        for (int i = 0; i < BAntiguo; i++)
        {
            if (tablaAntigua[i] != NULL)
            {
                delete tablaAntigua[i];
            }
        }
        delete[] tablaAntigua;
        delete[] eliminadoAntiguo;
    }

public:
    HashCerrado(int _B, int (*_hashFunction1)(K), int (*_hashFunction2)(K))
    {
        B = _B;
        N = 0;
        hashFunction1 = _hashFunction1;
        hashFunction2 = _hashFunction2;
        tabla = new ClaveValor<K, V> *[B]();
        for (int i = 0; i < B; i++)
        {
            tabla[i] = NULL;
        }
        eliminado = new bool[B]();
    }

    ~HashCerrado()
    {
        for (int i = 0; i < B; i++)
        {
            if (tabla[i] != NULL)
            {
                delete tabla[i];
            }
        }
        delete[] tabla;
        delete[] eliminado;
    }

    /**
     * If the key is already in the table, update the value. Otherwise, insert the key-value pair
     *
     * @param key The key to insert
     * @param value The value to insert into the table.
     */
    void insertarOActualizar(K key, V value)
    {
        if (this->getLoadFactor() >= 0.7)
        {
            this->rehash();
        }
        assert(N < B);
        bool actualice = false;
        int intento = 0;
        while (!actualice)
        {
            int p = pos(key, intento);
            if (tabla[p] == NULL)
            { // el bucket está vacio
                if (!eliminado[p])
                { // no está eliminado
                    tabla[p] = new ClaveValor<K, V>(key, value);
                    N++;
                    actualice = true;
                }
                else
                {
                    intento++;
                    assert(intento < B);
                }
            }
            else
            {
                if (!eliminado[p] && tabla[p]->clave == key)
                { // el bucket está ocupado y la clave coincide
                    tabla[p]->valor = value;
                    actualice = true;
                }
                else
                {
                    intento++;
                    assert(intento < B);
                }
            }
        }
    }

    // pre: toma una clave existente dentro de la Tabla.
    // pos: elimina el elemento
    void eliminar(K key)
    {
        assert(this->exists(key));
        int intento = 0;
        for (intento = 0; intento < B; intento++)
        {
            int p = pos(key, intento);
            if (tabla[p] != NULL && !eliminado[p])
            {
                if (tabla[p]->clave == key)
                {
                    delete tabla[p];
                    tabla[p] = NULL;
                    eliminado[p] = true;
                    N--;
                    return;
                }
            }
        }
        throw "Quedo en loop!";
    }

    // /**
    //  * The key exists, return the value associated with it
    //  *
    //  * @param key The key of the element you want to get.
    //  *
    //  * @return The value of the key.
    //  */
    V get(K key)
    {
        assert(this->exists(key));
        for (int intento = 0; intento < B; intento++)
        {
            int p = pos(key, intento);
            if (tabla[p] != NULL && !eliminado[p])
            {
                if (tabla[p]->clave == key)
                {
                    return tabla[p]->valor;
                }
            }
        }
        throw "Quedo en loop!";
    }

    // /**
    //  * If the key is not found, return false. If the key is found, return true
    //  *
    //  * @param key The key of the element you want to check if it exists.
    //  */
    bool exists(K key)
    {
        bool existe = false;
        for (int intento = 0; intento < B; intento++)
        {
            int p = pos(key, intento);
            if (tabla[p] == NULL && !eliminado[p])
            {
                return false;
            }
            if (tabla[p] != NULL && !eliminado[p])
            {
                if (tabla[p]->clave == key)
                {
                    return true;
                }
            }
        }
        throw "Quedo en loop!";
    }

    float getLoadFactor()
    {
        return (float)N / B;
    }

    int getSize()
    {
        return N;
    }

    K obtenerClaveconValorMax()
    {
        K claveMax;
        int valorMax = INT_MIN;
        bool encontrado = false;
        for (int i = 0; i < B; i++)
        {
            if (tabla[i] != NULL && !eliminado[i])
            {
                if (!encontrado || tabla[i]->valor > valorMax)
                {
                    valorMax = tabla[i]->valor;
                    claveMax = tabla[i]->clave;
                    encontrado = true;
                }
            }
        }
        return claveMax;
    }
};
#endif
