#ifndef PARENTESIS_GREEDY
#define PARENTESIS_GREEDY

#include <string>

using namespace std;

int parentesis(string cadena)
{
    int cantCambios = 0;
    int contador = 0;

    for (int i = 0; i < (int)cadena.size(); i++)
    {
        if (cadena[i] == '[')
        {
            contador++; // [ Abre: +1
        }
        else
        {
            contador--; // ] Cierra: -1
        }

        // Cierre sin apertura: intercambio con el último '[' que quede a la derecha
        if (contador == -1)
        {
            int j = cadena.size() - 1;
            while (j > i && cadena[j] != '[')
            {
                j--;
            }

            char aux = cadena[i];
            cadena[i] = cadena[j];
            cadena[j] = aux;

            cantCambios++;
            contador = 1; // Ahora cadena[i] es '[', el -1 pasa a +1
        }
    }
    return cantCambios;
}

#endif