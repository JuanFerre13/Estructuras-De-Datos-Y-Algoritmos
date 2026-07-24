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
│   ├── MFSet/                Merge-Find Set (unión por altura + compresión de caminos)
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

### Estructuras de datos

| Estructura | Caso | Insertar | Eliminar | Buscar |
|:---|:---|:---:|:---:|:---:|
| **Lista (vector)** | Caso Promedio | 1 (al final) | N | N |
| | Peor Caso | N (reagrandar) | N | N |
| **Lista enlazada** | Caso Promedio | 1 (al inicio) | N | N |
| | Peor Caso | 1 (al inicio) | N | N |
| **Pila / Cola** | Peor Caso | 1 | 1 | — |
| **ABB** | Caso Promedio | Log N | Log N | Log N |
| | Peor Caso | N | N | N |
| **AVL** | Peor Caso | Log N | Log N | Log N |
| **Hash** | Caso Promedio | 1 | 1 | 1 |
| | Peor Caso | N | N | N |
| **Heap** | Caso Promedio | 1 | Log N (raíz) | 1 (raíz) |
| | Peor Caso | Log N | N (cualquiera) | N (cualquiera) |
| **Heap + Hash** | Caso Promedio | Log N | Log N | Log N (existe: 1) |
| **MFSet** | Con Union By Rank | — | — | Log N (con PC) |
| | Sin mejoras | — | — | N |

Notas:

- **ABB**: el peor caso N ocurre cuando el árbol degenera en lista (inserciones ordenadas).
- **Hash**: el peor caso N ocurre cuando todas las claves colisionan.
- **Heap**: eliminar y buscar son baratos únicamente sobre la raíz; sobre un elemento cualquiera hay
  que recorrer todo el heap. Combinarlo con una tabla de hash (**Heap + Hash**) permite localizar
  cualquier elemento y bajar esas operaciones a Log N.
- **MFSet**: `PC` = compresión de caminos, implementada en `TADS/MFSet/MFSet.cpp`. Combinada con
  unión por altura, el costo amortizado real es O(α(N)) —prácticamente constante—, aunque en la
  materia se acota como Log N.

### Grafos

Con **V** vértices y **A** aristas. **LA** = lista de adyacencia, **MA** = matriz de adyacencia.

| Algoritmo | Orden | |
|:---|:---:|:---:|
| **BFS** | (LA) V + A | (MA) V² |
| **DFS** | (LA) V + A | (MA) V² |
| **Orden Topológico** | V + A | |
| **Dijkstra** | (V + A) Log V | |
| **Bellman-Ford** | V · A | |
| **Floyd - Warshall** | V³ | |
| **Prim** | (V + A) Log V | |
| **Kruskal** | A · Log A | A · Log V |

### Estrategias algorítmicas

| Problema | Estrategia | Orden |
|:---|:---|:---:|
| **N-Reinas** | Backtracking | N! |
| **Recorrida del Caballo** | Backtracking | Exponencial |
| **Aeropuerto** | Greedy | N Log N |
| **Problema del Cambio** | Programación Dinámica | N · M (M = monto) |

---

Si encontrás un error o algo que se pueda explicar mejor, los issues y pull requests son bienvenidos.
