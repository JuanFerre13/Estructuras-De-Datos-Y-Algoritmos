#ifndef ESCALERAS_PONDERADAS
#define ESCALERAS_PONDERADAS

#include <iostream>

using namespace std;

int min(int a, int b)
{
    a < b ? a : b;
}

// RECURSIVO
int escPondRec(int escalon, int *esfuerzo)
{
    if (escalon == 0)
        return esfuerzo[0];
    if (escalon == 1)
        return esfuerzo[0] + esfuerzo[1];
    return min(escPondRec(escalon - 1, esfuerzo), escPondRec(escalon - 2, esfuerzo)) + esfuerzo[escalon];
}

// MEMOIZACIÓN
int escPondMemo(int escalon, int *esfuerzo, int *memo)
{
    if (escalon == 0)
        return esfuerzo[0];
    if (escalon == 1)
        return esfuerzo[0] + esfuerzo[1];
    if (memo[escalon] == -1)
        return min(escPondMemo(escalon - 1, esfuerzo, memo), escPondMemo(escalon - 2, esfuerzo, memo)) + esfuerzo[escalon];
    return memo[escalon];
}

// TABULACIÓN
int escPondTab(int escalon, int *esfuerzo)
{
    if (escalon == 0)
        return esfuerzo[0];
    if (escalon == 1)
        return esfuerzo[0] + esfuerzo[1];
    int *tab = new int[escalon + 1]();
    tab[0] = esfuerzo[0];
    tab[1] = esfuerzo[0] + esfuerzo[1];
    for (int i = 2; i <= escalon; i++)
    {
        tab[i] = min(tab[i - 1], tab[i - 2]) + esfuerzo[escalon];
        // Si quiero imprimir el camino
        
        // int estoy = escalon;
        // while (estoy != 0)
        // {
        //     cout << "vengo de: " << estoy << endl;
        //     if (tab[estoy - 1] < tab[estoy - 2])
        //     {
        //         estoy--;
        //     }
        //     else
        //     {
        //         estoy -= 2;
        //     }
        // }
    }
    return tab[escalon];
}

#endif