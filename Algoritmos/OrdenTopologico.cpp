// #include <cassert>
// #include <string>
// #include <iostream>
// #include <climits>
// #include "../TADS/Grafo/Grafo.h"
// #include "../TADS/Cola/Cola.h"
// using namespace std;

// bool esCiclico(Grafo * g) {
//   int V = g->getV();
//   int* gradoEntrada = new int[V + 1]();
//   Queue<int>* bolsa = new QueueImp<int>();
//   // recorro todos los vertices
//   for (int i = 1; i <= V; i++)
//   {
//     // recorro todas las aristas
//     NodoLista<Arista> *ady = g->adyacentesA(i);
//     while (ady != NULL)
//     {
//       int destino  = ady->elemento.destino;
//       gradoEntrada[destino]++;
//       ady = ady->sig;
//     }
//   }

//   // recorro todos los vertices nuevamente
//   for (int i = 1; i <= V; i++)
//   {
//     // en caso que tengan grado de entrada 0
//     // entonces puedo usarlo
//     if(gradoEntrada[i] == 0) {
//       bolsa->enqueue(i);
//     }
//   }


//   while(!bolsa->isEmpty()) {
//     int v = bolsa->dequeue();
//     // recorro todas las aristas
//     NodoLista<Arista> *ady = g->adyacentesA(v);
//     while (ady != NULL)
//     {
//       int destino  = ady->elemento.destino;
//       // (esta listo para se procesado)
//       if(--gradoEntrada[destino] == 0) bolsa->enqueue(destino);
//       ady = ady->sig;
//     }
//   }

//   // verifiquemos 
//   bool esCiclico = false;
//   for (int i = 1; i <= V; i++)
//   {
//     if(gradoEntrada[i] > 0) {
//       return true;
//     }
//   }

//   return false;
// }

// void ordenTopologico(Grafo * g) {
//   int V = g->getV();
//   int* gradoEntrada = new int[V + 1]();
//   Queue<int>* bolsa = new QueueImp<int>();
//   // recorro todos los vertices
//   for (int i = 1; i <= V; i++)
//   {
//     // recorro todas las aristas
//     NodoLista<Arista> *ady = g->adyacentesA(i);
//     while (ady != NULL)
//     {
//       int destino  = ady->elemento.destino;
//       gradoEntrada[destino]++;
//       ady = ady->sig;
//     }
//   }

//   // recorro todos los vertices nuevamente
//   for (int i = 1; i <= V; i++)
//   {
//     // en caso que tengan grado de entrada 0
//     // entonces puedo usarlo
//     if(gradoEntrada[i] == 0) {
//       bolsa->enqueue(i);
//     }
//   }


//   while(!bolsa->isEmpty()) {
//     int v = bolsa->dequeue();
//     cout << v << endl; // lo procesamos
//     // recorro todas las aristas
//     NodoLista<Arista> *ady = g->adyacentesA(v);
//     while (ady != NULL)
//     {
//       int destino  = ady->elemento.destino;
//       // (esta listo para se procesado)
//       if(--gradoEntrada[destino] == 0) bolsa->enqueue(destino);
//       ady = ady->sig;
//     }
//   }
// }