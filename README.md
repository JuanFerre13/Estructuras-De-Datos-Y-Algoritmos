# Estructuras de Datos y Algoritmos

Repositorio con implementaciones en **C++** de los TADs, algoritmos y estrategias vistos en
**Estructura de Datos y Algoritmos 1 y 2**, incluyendo material del curso de EDA2 dictado por el
docente **Joaquín Vigna**.

## Sobre este repositorio

El código acá reunido proviene de dos materias:

- **Estructura de Datos y Algoritmos 1** — TADs básicos (lista, pila, cola, tabla de hash, árboles).
- **Estructura de Datos y Algoritmos 2** — grafos, algoritmos sobre grafos y estrategias
  algorítmicas. Buena parte de este material sale del curso dictado por el docente
  **Joaquín Vigna**, de donde se tomaron ideas, implementaciones y criterios de diseño.

Nació como un **resumen personal** para tener todo lo aprendido en un solo lugar, pero se publica
también con la intención de que le **sirva a otros estudiantes** que estén cursando estas materias.
Cada archivo está comentado con precondiciones, poscondiciones y notas sobre el costo de las
operaciones, de manera que se pueda leer como material de estudio y no solamente como código.

> ⚠️ La idea es que sirva de referencia y guía de estudio. Copiar y pegar sin entender no ayuda a
> aprobar el parcial.

## Estructura del proyecto

```
.
├── TADS/                     Tipos Abstractos de Datos
│   ├── Lista/                Lista sobre vector dinámico + NodoLista (lista enlazada)
│   ├── Pila/                 Pila (LIFO)
│   ├── Cola/                 Cola (FIFO)
│   ├── Tabla/               Tabla de hash (implementación con hash cerrado)
│   ├── ABB/                  Árbol Binario de Búsqueda
│   ├── AVL/                  Árbol Binario de Búsqueda balanceado
│   ├── HeapBinario/          Heap binario (MinHeap y MaxHeap)
│   ├── MFSet/                Merge-Find Set (union-find con unión por altura)
│   └── Grafo/                Grafo: interfaz + Matriz y Lista de Adyacencia
│
├── Algoritmos/               Algoritmos sobre grafos
│   ├── BFS.cpp               Recorrida en amplitud
│   ├── DFS.cpp               Recorrida en profundidad
│   ├── OrdenTopologico.cpp   Orden topológico
│   ├── Dijkstra.cpp          Camino mínimo desde un origen (pesos no negativos)
│   ├── BellmanFord.cpp       Camino mínimo desde un origen (admite pesos negativos)
│   ├── Floyd.cpp             Caminos mínimos entre todo par de vértices
│   ├── Warshall.cpp          Clausura transitiva
│   ├── Prim.cpp              Árbol generador mínimo
│   └── Kruskal.cpp           Árbol generador mínimo (usa MFSet)
│
└── Estrategias/              Estrategias algorítmicas
    ├── Backtracking/         N-Reinas, recorrida del Caballo
    ├── Greedy/               Aeropuerto
    ├── ProgramacionDinamica/ Problema del Cambio
    └── DivideAndConquer/     (pendiente)
```

## Cómo compilar y ejecutar

Los TADs genéricos están implementados en headers (`.h`) y en `.cpp` incluidos directamente, así que
alcanza con compilar el archivo que tenga el `main` que quieras probar:

```bash
g++ -std=c++17 -Wall Algoritmos/Dijkstra.cpp -o dijkstra
./dijkstra
```

```bash
g++ -std=c++17 -Wall Estrategias/Backtracking/N-Reinas.cpp -o reinas
./reinas
```

En Windows con MinGW el comando es el mismo, cambiando el ejecutable de salida a `.exe`.

## Convenciones del código

- Comentarios `// PRE:` y `// POS:` sobre cada operación, siguiendo la notación usada en la materia.
- Los TADs con memoria dinámica implementan **constructor de copia**, **operador de asignación** y
  **destructor** (regla de los tres).
- Las estructuras genéricas usan `template <class T>`.

## Resumen de órdenes temporales

### TADs

| Estructura | Operación | Caso promedio | Peor caso | Espacio |
|---|---|---|---|---|
| **Lista (vector dinámico)** | Acceso por índice | O(1) | O(1) | O(n) |
| | Insertar al final | O(1) amortizado | O(n) (al reagrandar) | |
| | Insertar / borrar en posición | O(n) | O(n) | |
| | Búsqueda | O(n) | O(n) | |
| **Lista enlazada** | Acceso por índice | O(n) | O(n) | O(n) |
| | Insertar / borrar al inicio | O(1) | O(1) | |
| | Búsqueda | O(n) | O(n) | |
| **Pila** | Apilar / Desapilar / Tope | O(1) | O(1) | O(n) |
| **Cola** | Encolar / Desencolar / Frente | O(1) | O(1) | O(n) |
| **Tabla de hash** | Insertar / Buscar / Borrar | O(1) | O(n) (todo colisiona) | O(n) |
| **ABB** | Insertar / Buscar / Borrar | O(log n) | O(n) (degenera en lista) | O(n) |
| | Mínimo / Máximo | O(log n) | O(n) | |
| | Recorrida (in/pre/pos orden) | O(n) | O(n) | |
| **AVL** | Insertar / Buscar / Borrar | O(log n) | **O(log n)** | O(n) |
| **Heap binario** | Insertar | O(log n) | O(log n) | O(n) |
| | Obtener mínimo / máximo | O(1) | O(1) | |
| | Borrar mínimo / máximo | O(log n) | O(log n) | |
| | Construcción desde vector | O(n) | O(n) | |
| **MFSet (union-find)** | Find | O(α(n)) amortizado | O(log n) | O(n) |
| | Merge | O(α(n)) amortizado | O(log n) | |

> La implementación combina **unión por altura** y **compresión de caminos**, por lo que el costo
> amortizado de `find` y `merge` es O(α(n)) — con α la inversa de Ackermann, que para cualquier n
> práctico vale menos que 5, es decir, prácticamente constante. Sin compresión de caminos el costo
> sería O(log n).

### Grafos: representación

Con **V** vértices y **A** aristas:

| Operación | Matriz de adyacencia | Lista de adyacencia |
|---|---|---|
| Espacio | O(V²) | O(V + A) |
| Agregar arista | O(1) | O(1) |
| ¿Existe arista (u,v)? | O(1) | O(grado(u)) |
| Recorrer adyacentes a u | O(V) | O(grado(u)) |

### Algoritmos sobre grafos

| Algoritmo | Orden temporal | Notas |
|---|---|---|
| **BFS** | O(V + A) | Con lista de adyacencia; O(V²) con matriz |
| **DFS** | O(V + A) | Con lista de adyacencia; O(V²) con matriz |
| **Orden topológico** | O(V + A) | Solo sobre grafos dirigidos acíclicos (DAG) |
| **Dijkstra** | O(A log V) | Con heap binario. No admite pesos negativos |
| **Bellman-Ford** | O(V · A) | Admite pesos negativos y detecta ciclos negativos |
| **Floyd** | O(V³) | Caminos mínimos entre todo par de vértices |
| **Warshall** | O(V³) | Clausura transitiva (alcanzabilidad) |
| **Prim** | O(A log V) | Árbol generador mínimo; conviene en grafos densos |
| **Kruskal** | O(A log A) | Árbol generador mínimo; usa MFSet. Conviene en grafos ralos |

### Estrategias algorítmicas

| Problema | Estrategia | Orden temporal |
|---|---|---|
| **N-Reinas** | Backtracking | O(n!) en el peor caso |
| **Recorrida del Caballo** | Backtracking | Exponencial |
| **Aeropuerto** | Greedy | O(n log n) (dominado por el ordenamiento) |
| **Problema del Cambio** | Programación dinámica | O(n · M), con M el monto y n la cantidad de monedas |

---

Si encontrás un error o algo que se pueda explicar mejor, los issues y pull requests son bienvenidos.
