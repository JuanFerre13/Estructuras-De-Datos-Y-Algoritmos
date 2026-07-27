#ifndef LABERINTO_GREEDY
#define LABERINTO_GREEDY

// Estrategia greedy: nos movemos de a una celda desde el inicio hasta el
// destino (fFinal, cFinal). En cada paso hay a lo sumo dos movimientos, y los
// dos nos acercan al objetivo (nunca nos alejamos):
//   - horizontal: avanzar una columna hacia cFinal (a la derecha)
//   - vertical:   avanzar una fila hacia fFinal (bajar o subir, según dónde
//                 esté fFinal respecto de la fila actual)
// Como jamás pasamos de fFinal ni de cFinal, nunca nos salimos de la matriz y
// no hace falta conocer sus dimensiones.
//
// Decisión en cada paso:
//   1) Si una opción es libre (0) y la otra pared (1), tomamos la libre para no
//      romper pared.
//   2) Si ambas son iguales (las dos libres o las dos pared), avanzamos por el
//      eje cuya coordenada está MÁS LEJOS del destino (así emparejamos las
//      distancias). Ej.: en (0,2) hacia (9,4), falta 9 en fila y 2 en columna,
//      entonces priorizamos la fila y vamos a (1,2).
//   3) Si ya llegamos a la fila (o a la columna) del destino, solo queda el
//      otro movimiento.
// Devuelve la cantidad de paredes rotas.
int laberinto(int **mat, int fInicio, int cInicio, int fFinal, int cFinal) {
    int fila = fInicio;
    int columna = cInicio;
    int paredesRotas = 0;

    // Si la celda de inicio es una pared, hay que romperla.
    if (mat[fila][columna] == 1) {
        paredesRotas++;
    }

    // Nos movemos de a una celda hasta alcanzar el destino.
    while (fila != fFinal || columna != cFinal) {
        bool puedeVertical = (fila != fFinal);
        bool puedeHorizontal = (columna != cFinal);

        int filaV = fila + (fFinal > fila ? 1 : -1); // acercarse en fila
        int colH = columna + 1;                       // acercarse en columna (a la derecha)

        bool elegirVertical;

        if (!puedeVertical) {
            // Ya estamos en la fila destino: solo queda avanzar en columna.
            elegirVertical = false;
        } else if (!puedeHorizontal) {
            // Ya estamos en la columna destino: solo queda avanzar en fila.
            elegirVertical = true;
        } else {
            bool libreV = (mat[filaV][columna] == 0);
            bool libreH = (mat[fila][colH] == 0);

            if (libreV != libreH) {
                // Una libre y una pared: elegimos la libre para no romper.
                elegirVertical = libreV;
            } else {
                // Empate (ambas libres o ambas pared): avanzamos por el eje
                // cuya coordenada está más lejos del destino.
                int distFila = (fFinal > fila ? fFinal - fila : fila - fFinal);
                int distCol = cFinal - columna;
                elegirVertical = (distFila >= distCol);
            }
        }

        if (elegirVertical) {
            fila = filaV;
        } else {
            columna = colH;
        }

        // Si entramos a una celda con pared, la rompemos.
        if (mat[fila][columna] == 1) {
            paredesRotas++;
        }
    }

    return paredesRotas;
}

#endif
