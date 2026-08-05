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
│   ├── Tabla/                Tabla de hash (implementación con hash cerrado)
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
    │
    ├── Backtracking/
    │   ├── N-Reinas.cpp              N reinas en un tablero de N x N
    │   ├── Caballo.cpp               Recorrida del caballo
    │   └── Mochila01.cpp             Mochila 0-1 (esquema con poda)
    │
    ├── Greedy/
    │   ├── Aeropuerto.cpp            Máximo de aviones simultáneos en tierra (usa MinHeap)
    │   ├── Mochila.cpp               Mochila greedy (asume objetos ya ordenados por heurística)
    │   ├── Laberinto.cpp             Camino en matriz rompiendo la menor cantidad de paredes
    │   ├── Parentesis.cpp            Mínimos intercambios para balancear una cadena de []
    │   ├── PoliciasYLadrones.cpp     Máximo de capturas con distancia <= K
    │   ├── OperadoresYCuadrillas.cpp Máximo de emparejamientos con distancia <= K
    │   └── Cambio.cpp                Problema del Cambio con criterio greedy (no siempre óptimo)
    │
    ├── ProgramacionDinamica/
    │   ├── Fibonacci.cpp             Recursivo, memoización y tabulación
    │   ├── Escaleras.cpp             Formas de subir una escalera de a 1 o 2 escalones
    │   ├── EscalerasPonderadas.cpp   Misma escalera minimizando el esfuerzo
    │   ├── Cambio.cpp                Problema del Cambio + reconstrucción de las monedas usadas
    │   ├── Combinatoria.cpp          Triángulo de Pascal por filas + consultas en cola
    │   ├── CaminosMatriz.cpp         Caminos en una matriz (rec, memo, tab y tab optimizada)
    │   └── Mochila-01.cpp            Mochila 0-1 tabulada, de 1 y 2 dimensiones, con reconstrucción
    │
    └── DivideAndConquer/
        ├── MergeSort.cpp             Ordenación por intercalación
        ├── QuickSort.cpp             Ordenación por partición
        ├── Minimo.cpp                Mínimo de un arreglo
        ├── Prefijo.cpp               Prefijo común más largo de un conjunto de strings
        ├── SecuenciaMaxima.cpp       Subarreglo de suma máxima
        ├── Mochila-01.cpp            Mochila 0-1 recursiva (cada objeto se usa a lo sumo 1 vez)
        └── Mochila-0INF.cpp          Mochila 0-INF recursiva (objetos con repetición)
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

Varios archivos de `Estrategias/` no traen `main`: son solo la función del problema, protegida con
`#ifndef`, pensada para incluirla desde otro archivo o para leerla como referencia. Los que sí se
pueden compilar y correr directamente son `Backtracking/N-Reinas.cpp`, `Backtracking/Caballo.cpp`,
`ProgramacionDinamica/Cambio.cpp`, `ProgramacionDinamica/Combinatoria.cpp` y
`Greedy/OperadoresYCuadrillas.cpp` (estos tres últimos leen los casos por entrada estándar).

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
| **Mochila 0-1** | Backtracking | 2^N |
| **Aeropuerto** | Greedy | N Log N |
| **Mochila greedy** | Greedy | N (ya ordenado) / N Log N (ordenando) |
| **Laberinto** | Greedy | F + C (filas + columnas a recorrer) |
| **Paréntesis** | Greedy | N² (peor caso) |
| **Policías y Ladrones** | Greedy | N |
| **Operadores y Cuadrillas** | Greedy | N + M (índices ya ordenados) |
| **Problema del Cambio** | Greedy | N (monedas ya ordenadas) |
| **Fibonacci** | Prog. Dinámica | 2^N (rec) / N (memo y tab) |
| **Escaleras** | Prog. Dinámica | 2^N (rec) / N (memo y tab) |
| **Escaleras Ponderadas** | Prog. Dinámica | 2^N (rec) / N (memo y tab) |
| **Problema del Cambio** | Prog. Dinámica | N · M (M = monto) |
| **Combinatoria** | Prog. Dinámica | N² |
| **Caminos en Matriz** | Prog. Dinámica | 2^(F+C) (rec) / F · C (memo y tab) |
| **Mochila 0-1 (1 dim)** | Prog. Dinámica | N · C (C = capacidad) |
| **Mochila 0-1 (2 dim)** | Prog. Dinámica | N · C · V (V = volumen) |
| **MergeSort** | Divide & Conquer | N Log N |
| **QuickSort** | Divide & Conquer | N Log N (promedio) / N² (peor) |
| **Mínimo** | Divide & Conquer | N |
| **Prefijo común** | Divide & Conquer | N · L (L = largo del prefijo) |
| **Secuencia Máxima** | Divide & Conquer | N Log N |
| **Mochila 0-1 / 0-INF** | Divide & Conquer | Exponencial |

Notas:

- **Divide & Conquer vs. Programación Dinámica**: las mochilas recursivas de
  `DivideAndConquer/` resuelven el mismo problema una y otra vez; son el punto de partida al que
  después se le agrega memoización para bajar el costo. `ProgramacionDinamica/Mochila-01.cpp` es
  el cierre de ese recorrido: la misma mochila 0-1 ya tabulada, primero con una sola restricción
  (peso) y después con dos (peso y volumen), incluyendo el recorrido hacia atrás sobre la tabla
  para saber **qué objetos** se usaron y no solo el valor final.
- **Problema del Cambio**: está resuelto de las dos formas. El greedy de `Greedy/Cambio.cpp` va
  tomando siempre la moneda más grande que entra —es O(N), pero **solo da el óptimo con ciertos
  sistemas de monedas**—; la versión de `ProgramacionDinamica/Cambio.cpp` arma la tabla monto a
  monto, siempre encuentra el mínimo y además reconstruye qué monedas se entregaron.
- **Caminos en Matriz**: mismo esquema que Fibonacci pero en dos dimensiones. Se incluye la versión
  recursiva, la memoizada, la tabulada y una tabulación optimizada que reusa un único arreglo de
  una fila, más la variante con **obstáculos** (las celdas bloqueadas quedan en 0 y cortan el
  camino).
- **Combinatoria**: se calcula el triángulo de Pascal fila por fila reusando un único arreglo, y las
  consultas se resuelven al vuelo desde una cola, por lo que deben venir ordenadas por `n`.
- **Operadores y Cuadrillas** y **Policías y Ladrones** usan la misma idea: dos punteros que avanzan
  de izquierda a derecha emparejando el primer candidato que esté a distancia `K`.

---

Si encontrás un error o algo que se pueda explicar mejor, los issues y pull requests son bienvenidos.
