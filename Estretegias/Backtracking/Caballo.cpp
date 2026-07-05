#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

#define N 8

bool esSolucion(int fAc, int cAc, int fDes, int cDes)
{
    return fAc == fDes && cAc == cDes;
}

void imprimirTablero(int **pase)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "[";
            if (pase[i][j] > 0)
            {
                if (pase[i][j] < 10)
                {
                    cout << " " << pase[i][j];
                }
                else
                {
                    cout << pase[i][j];
                }
            }
            else
            {
                cout << "  ";
            }
            cout << "]";
        }
        cout << endl;
    }
    cout << endl;
}

bool coordenadaValida(int fila, int col)
{
    return fila < N && col < N && fila >= 0 && col >= 0;
}

bool puedoAplicarMovimiento(int fila, int columna, int **pase)
{
    return coordenadaValida(fila, columna) && pase[fila][columna] == 0;
}

void aplicarMovimiento(int fila, int columna, int **pase, int nroPaso)
{
    pase[fila][columna] = nroPaso;
}

void deshacerMovimiento(int fila, int columna, int **pase)
{
    pase[fila][columna] = 0;
}

void caballo_enum(int fAc, int cAc, int fDes, int cDes, int **pase, int nroPaso)
{
    if (esSolucion(fAc, cAc, fDes, cDes))
    {
        imprimirTablero(pase);
    }
    else
    {
        int dFila[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dCol[8] = {-2, -1, 1, 2, 2, 1, -1, 2};
        for (int i = 0; i < 8; i++)
        {
            int nuevaFila = fAc + dFila[i];
            int nuevaCol = cAc + dCol[i];
            if (puedoAplicarMovimiento(nuevaFila, nuevaCol, pase))
            {
                aplicarMovimiento(nuevaFila, nuevaCol, pase, nroPaso);
                caballo_enum(nuevaFila, nuevaCol, fDes, cDes, pase, nroPaso + 1);
                deshacerMovimiento(nuevaFila, nuevaCol, pase);
            }
        }
    }
}

bool esMejorSolucion(int nroPaso, int &mejorNroPaso)
{
    return nroPaso < mejorNroPaso;
}

bool puedoPodar(int nroPaso, int mejorNroPaso)
{
    return nroPaso > mejorNroPaso;
}

void clonarSolucion(int **pase, int **mejorPase)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mejorPase[i][j] = pase[i][j];
        }
    }
}

void caballo_opt(int fAc, int cAc, int fDes, int cDes, int **pase, int nroPaso, int &mejorNroPaso, int **&mejorPase)
{
    if (!puedoPodar(nroPaso, mejorNroPaso))
    {
        if (esSolucion(fAc, cAc, fDes, cDes) && esMejorSolucion(nroPaso, mejorNroPaso))
        {
            mejorNroPaso = nroPaso;
            clonarSolucion(pase, mejorPase);
        }
        else
        {
            int dFila[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
            int dCol[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
            for (int i = 0; i < 8; i++)
            {
                int nuevaFila = fAc + dFila[i];
                int nuevaCol = cAc + dCol[i];
                if (puedoAplicarMovimiento(nuevaFila, nuevaCol, pase))
                {
                    aplicarMovimiento(nuevaFila, nuevaCol, pase, nroPaso);
                    caballo_opt(nuevaFila, nuevaCol, fDes, cDes, pase, nroPaso + 1, mejorNroPaso, mejorPase);
                    deshacerMovimiento(nuevaFila, nuevaCol, pase);
                }
            }
        }
    }
}

int main()
{
    int **pase = new int *[N]();
    int **mejorPase = new int *[N]();
    for (int i = 0; i < N; i++)
    {
        pase[i] = new int[N]();
        mejorPase[i] = new int[N]();
    }
    pase[0][0] = 1;

    // caballo_enum(0, 0, 7, 7, pase, 2);

    int mejorPasos = 65;
    caballo_opt(0, 0, 7, 7, pase, 2, mejorPasos, mejorPase);
    imprimirTablero(mejorPase);

    return 0;
}