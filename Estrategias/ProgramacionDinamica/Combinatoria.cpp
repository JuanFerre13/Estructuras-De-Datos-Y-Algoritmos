#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "../../TADS/Cola/Cola.h"
#include "../../TADS/Cola/ColaImp.cpp"

using namespace std;

struct Coordenada
{
    int n;
    int k;
    Coordenada(int _n, int _k)
    {
        n = _n;
        k = _k;
    }
};

int main()
{
    int N;
    cin >> N;
    int P;
    cin >> P;

    long long *tab = new long long[N + 1];
    Cola<Coordenada> *aProcesar = new ColaImp<Coordenada>();

    for (int i = 0; i < P; i++)
    {
        int n;
        int k;
        cin >> n >> k;
        Coordenada C(n, k);
        aProcesar->encolar(C);
    }

    Coordenada actual = aProcesar->desencolar();

    for (int n = 0; n < N + 1; n++)
    {
        for (int k = n; k >= 0; k--)
        {
            if (k == 0 || k == n)
                tab[k] = 1;
            else
                tab[k] = tab[k - 1] + tab[k];
        }

        // Opción 1
        // for (int k = 0; k <= n; k++)
        // {
        //     if (actual.n == n && actual.k == k)
        //     {
        //         cout << tab[k] << endl;
        //         if (!aProcesar->estaVacia())
        //         {
        //             actual = aProcesar->desencolar();
        //         }
        //     }
        // }

        // Opción 2
        while (actual.n == n)
        {
            cout << tab[actual.k] << endl;
            if (!aProcesar->estaVacia())
            {
                actual = aProcesar->desencolar();
            }
            else
            {
                return 0;
            }
        }
    }
}