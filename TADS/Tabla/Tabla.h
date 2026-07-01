#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class K, class V>
class Tabla
{
public:
    /*
     * Inserts the given key and value in the hash table.
     *
     * @param key The key to insert.
     * @param value The value to insert.
     */
    virtual void insertarOActualizar(K key, V value) = 0;

    /**
     * Delete the given key from the hash table.
     */
    virtual void eliminar(K key) = 0;

    // /**
    //  * Returns the value associated with the given key.
    //  *
    //  * @param key The key to search.
    //  *
    //  * @return The value associated with the given key.
    //  *
    //  * @pre The key must be in the hash table.
    //  */
    virtual V get(K key) = 0;

    // /**
    //  * Returns if the key is in the table.
    //  *
    //  * @param key The key to search.
    //  *
    //  * @return If the key is in the table.
    //  */
    virtual bool exists(K key) = 0;

    // /**
    //  * Returns the load factor of the table. λ=n/b (siendo n la cantidad de elementos y b la cantidad de buckets).
    //  *
    //  * @return The load factor of the table.
    //  */
    virtual float getLoadFactor() = 0;

    // /**
    //  * Returns the number of elements in the table.
    //  */
    virtual int getSize() = 0;

    // /**
    //  * Returns the key with the highest value. If multiple keys have the same highest value, returns the first one found.
    //  *
    //  * @return The key with the highest value.
    //  */
    virtual K obtenerClaveconValorMax() = 0;
};

#endif // HASH_TABLE_H