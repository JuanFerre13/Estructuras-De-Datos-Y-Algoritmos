#include <string>
#include <iostream>
#include "TADS/HeapBinario/MinHeap.cpp"

using namespace std;

struct Actividad
{
    string banda;
    int inicio;
    int fin;
};

bool actividadMenor(Actividad a1, Actividad a2)
{
    return a1.fin < a2.fin;
}

void seleccionarActividad(Actividad *actividades, int n)
{
    if (n == 0)
        return;

    MinHeap<Actividad> minHeap(n, actividadMenor);
    for (int i = 0; i < n; i++)
    {
        minHeap.insertar(actividades[i]);
    }

    Actividad primera = minHeap.tope();
    minHeap.eliminarTope();
    int tiempoFinalizacion = primera.fin;
    cout << "Banda: " << primera.banda << ", Inicio: " << primera.inicio << " Fin: " << primera.fin << endl;

    while (!minHeap.estaVacio())
    {
        Actividad siguiente = minHeap.tope();
        minHeap.eliminarTope();
        if (siguiente.inicio >= tiempoFinalizacion)
        {
            cout << "Banda: " << siguiente.banda << ", Inicio: " << siguiente.inicio << " Fin: " << siguiente.fin << endl;
            tiempoFinalizacion = siguiente.fin;
        }
    }
}