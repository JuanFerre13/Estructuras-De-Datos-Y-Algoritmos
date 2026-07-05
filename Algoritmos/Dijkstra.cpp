// #include <cassert>
// #include <string>
// #include <iostream>
// #include <climits>
// #include "../TADS/Grafo/Grafo.h"
// #include "../TADS/HeapBinario/HeapBinario.h"
// #include "../TADS/HeapBinario/MinHeap.cpp"


// using namespace std;
// #define INF INT_MIN

// void dijkstra(Grafo *g, int origen)
// {
//   int V = g->getV();
//   int A = g->getA();
//   bool *visitado = new bool[V + 1]();
//   int *costo = new int[V + 1]();
//   int *vengo = new int[V + 1]();

//   for (int i = 1; i <= V; i++)
//   {
//     visitado[i] = false;
//     costo[i] = INF;
//     vengo[i] = -1;
//   }

//   MinHeap<NodoHeap> *heap = new MinHeap<NodoHeap>(V + A, comparadoraFn);

//   costo[origen] = 0;
//   NodoHeap nh(origen, 0);
//   heap->insertar(nh);

//   while (!heap->estaVacio())
//   {
//     NodoHeap aProcesar = heap->tope();
//     int v = aProcesar.vertice;
//     heap->eliminarTope();
//     if (visitado[v]) continue;
//     visitado[v] = true;

//     NodoLista<Arista> *ady = g->adyacentesA(v);
//     while (ady != NULL)
//     {
//       int w = ady->elemento.vertice;
//       int costoArista = ady->elemento.peso;

//       // Si mejoramos el costo acumulado de llegar a w
//       if (costo[v] + costoArista < costo[w])
//       {
//         costo[w] = costo[v] + costoArista;
//         vengo[w] = v;
//         // Insertamos w con el nuevo costo (puede existir una entrada vieja)
//         NodoHeap nw(w, costo[w]);
//         heap->insertar(nw);
//       } 
//       ady = ady->sig;
//     }
//   }
// }