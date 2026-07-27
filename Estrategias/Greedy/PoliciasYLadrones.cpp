#ifndef POLICIASLADRONES
#define POLICIASLADRONES

#include <cassert>
#include <string>
#include <iostream>

using namespace std;

// Cada policia captura a lo sumo un ladron que este a distancia <= K.
// Greedy: se recorren policias y ladrones de izquierda a derecha y se empareja
// el primer policia disponible con el primer ladron a su alcance. Si no llegan
// a alcanzarse, se avanza el de menor indice porque ya no tiene con quien emparejarse
// mas a la izquierda.
int policiasYLadrones(string cadena, int K)
{
    int largo = (int)cadena.size();
    int capturados = 0;
    int policia = 0;
    int ladron = 0;

    while (true)
    {
        while (policia < largo && cadena[policia] != 'P')
        {
            policia++;
        }
        while (ladron < largo && cadena[ladron] != 'L')
        {
            ladron++;
        }

        if (policia == largo || ladron == largo)
        {
            break;
        }

        int distancia = policia > ladron ? policia - ladron : ladron - policia;

        if (distancia <= K)
        {
            capturados++;
            policia++;
            ladron++;
        }
        else if (policia < ladron)
        {
            policia++;
        }
        else
        {
            ladron++;
        }
    }

    return capturados;
}

#endif