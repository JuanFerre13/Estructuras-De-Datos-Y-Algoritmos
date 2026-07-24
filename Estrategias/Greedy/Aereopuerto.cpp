#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "../TADS/HeapBinario/MinHeap.cpp"

using namespace std;

bool funcionComparadora(int a, int b)
{
    return a < b;
}

int main()
{
    int N;
    int llegadaAux;
    int partidaAux;
    cin >> N;
    MinHeap<int> *llegadas = new MinHeap<int>(N, funcionComparadora);
    MinHeap<int> *partidas = new MinHeap<int>(N, funcionComparadora);
    for (int i = 0; i < N; i++)
    {
        cin >> llegadaAux >> partidaAux;
        llegadas->insertar(llegadaAux);
        partidas->insertar(partidaAux);
    }
    int countLocal = 0;
    int max = 0;

    while (!llegadas->estaVacio())
    {
        int siguienteLlegada = llegadas->tope();
        int siguientePartida = partidas->tope();
        if (siguienteLlegada < siguientePartida)
        {
            countLocal++;
            llegadas->eliminarTope();
        }
        else
        {
            countLocal--;
            partidas->eliminarTope();
        }
        max = countLocal > max ? countLocal : max;
    }
    cout << max << endl;
    return 0;
}