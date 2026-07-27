#ifndef ARISTA_H
#define ARISTA_H

struct Arista
{
    int origen;
    int destino;
    int peso;
    Arista(int origen, int destino, int peso) : origen(origen), destino(destino), peso(peso) {}
    Arista(int origen, int destino) : origen(origen), destino(destino), peso(1) {}
    Arista() {}
    ~Arista() {}

    bool operator==(const Arista &other) const
    {
        return origen == other.origen && destino == other.destino && peso == other.peso;
    }
};

#endif
