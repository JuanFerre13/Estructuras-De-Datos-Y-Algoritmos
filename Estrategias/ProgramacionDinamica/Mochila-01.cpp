#ifndef MOCHILA01_PD
#define MOCHILA01_PD

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define C 13
#define V 8
#define N 4

string nombres[N] = {"lingote", "diamante", "ruby", "moneda"};
int valores[N] = {10, 20, 25, 8};
int pesos[N] = {5, 3, 8, 4};
int volumenes[N] = {12, 1, 5, 3};

// MOCHILA 0-1 DE 1 DIMENSIÓN
void mochila01()
{
    int **tab = new int *[N + 1]();
    for (int i = 0; i <= N; i++)
    {
        tab[i] = new int[C + 1]();
    }

    for (int obj = 1; obj <= N; obj++)
    {
        int pesoObj = pesos[obj - 1];
        int valorObj = valores[obj - 1];
        for (int cap = 0; cap <= C; cap++)
        {
            int valorMochila;
            if (pesoObj > cap)
            {
                valorMochila = tab[obj - 1][cap];
            }
            else
            {
                int usarObj = valorObj + tab[obj - 1][cap - pesoObj];
                int noUsarObj = tab[obj - 1][cap];
                valorMochila = max(usarObj, noUsarObj);
            }
            tab[obj][cap] = valorMochila;
        }
    }

    cout << "El valor de la mochila es: " << tab[N][C] << endl;

    // PARA RECONSTRUIR MI CAMINO:
    int estoyC = C;
    int estoyN = N;

    while (estoyN > 0)
    {
        int pesoObj = pesos[estoyN - 1];
        string nombreObj = nombres[estoyN - 1];
        if (tab[estoyN][estoyC] != tab[estoyN - 1][estoyC])
        {
            cout << "Usé el objeto: " << nombreObj << endl;
            estoyC -= pesoObj;
        }
        estoyN--;
    }
}


// MOCHILA 0-1 DE 2 DIMENSIONES
void mochila01_2D()
{
    int ***tab = new int **[N + 1]();
    for (int i = 0; i <= N; i++)
    {
        tab[i] = new int *[C + 1]();
        for (int j = 0; j <= C; j++)
        {
            tab[i][j] = new int[V + 1]();
        }
    }

    for (int obj = 1; obj <= N; obj++)
    {
        int pesoObj = pesos[obj - 1];
        int valorObj = valores[obj - 1];
        int volumenObj = volumenes[obj - 1];
        for (int capPeso = 0; capPeso <= C; capPeso++)
        {
            for (int capVol = 0; capVol <= V; capVol++)
            {

                int valorMochila;
                if (pesoObj > capPeso || volumenObj > capVol)
                {
                    valorMochila = tab[obj - 1][capPeso][capVol];
                }
                else
                {
                    int usarObj = valorObj + tab[obj - 1][capPeso - pesoObj][capVol - volumenObj];
                    int noUsarObj = tab[obj - 1][capPeso][capVol];
                    valorMochila = max(usarObj, noUsarObj);
                }
                tab[obj][capPeso][capVol] = valorMochila;
            }
        }
    }

    cout << "El valor de la mochila es: " << tab[N][C][V]    << endl;

    // PARA RECONSTRUIR MI CAMINO:
    int estoyC = C;
    int estoyN = N;
    int estoyV = V;

    while (estoyN > 0)
    {
        int pesoObj = pesos[estoyN - 1];
        int volObj = volumenes[estoyN -1];
        string nombreObj = nombres[estoyN - 1];
        if (tab[estoyN][estoyC][estoyV] != tab[estoyN - 1][estoyC][estoyV])
        {
            cout << "Usé el objeto: " << nombreObj << endl;
            estoyC -= pesoObj;
            estoyV -= volObj;
        }
        estoyN--;
    }
}

#endif