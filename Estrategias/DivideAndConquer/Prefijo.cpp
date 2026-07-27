#ifndef PREFIJO_DAC
#define PREFIJO_DAC

#include <string>

using namespace std;

string mergePrefijo(string izquierda, string derecha) {
    string resultado = "";
    int longitudMinima = min(izquierda.length(), derecha.length());
    for (int i = 0; i < longitudMinima; ++i) {
        if (izquierda[i] == derecha[i]) {
            resultado += izquierda[i];
        } else {
            break;
        }
    }
    return resultado;
}

string prefijoComun(string arreglo[], int inicio, int fin) {
    if (inicio == fin)
        return arreglo[inicio];
    int medio = (inicio + fin) / 2;
    string prefijoIzq = prefijoComun(arreglo, inicio, medio);
    string prefijoDer = prefijoComun(arreglo, medio + 1, fin);
    return mergePrefijo(prefijoIzq, prefijoDer);
}

#endif