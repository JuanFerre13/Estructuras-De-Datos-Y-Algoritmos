#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

#define N 8

bool esSolucion(int colAct)
{
    return colAct == N;
}

void imprimirTablero(bool **tablero)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "[";
            if (tablero[i][j])
            {
                cout << "R";
            }
            else
            {
                cout << " ";
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

bool puedoAplicarMovimiento(int fila, int col, bool **tablero)
{
    // revisar la fila
    for (int i = fila, j = col; coordenadaValida(i, j); j--)
    {
        if (tablero[i][j])
        {
            return false;
        }
    }

    // revisar la diagonal superior
    // OPCION A
    for (int i = fila, j = col; coordenadaValida(i, j); i--, j--)
    {
        if (tablero[i][j])
        {
            return false;
        }
    }

    // OPCION B
    // int filaAux = fila;
    // int colAux = col;
    // while(esCoordenadaValida(filaAux, colAux)){
    //     if(tablero[filaAux][colAux]){
    //         return false;
    //     }
    //     filaAux--;
    //     colAux--;
    // }

    // revisar diagonal inferior
    for (int i = fila, j = col; coordenadaValida(i, j); i++, j--)
    {
        if (tablero[i][j])
        {
            return false;
        }
    }

    return true;
}

void aplicarMovimiento(int fila, int col, bool **tablero)
{
    tablero[fila][col] = true;
}

void deshacerMovimiento(int fila, int col, bool **tablero)
{
    tablero[fila][col] = false;
}

void nreinas_enum(bool **tablero, int col)
{
    if (esSolucion(col))
    {
        imprimirTablero(tablero);
    }
    else
    {
        for (int fila = 0; fila < N; fila++)
        {
            if (puedoAplicarMovimiento(fila, col, tablero)){
                aplicarMovimiento(fila, col, tablero);
                nreinas_enum(tablero, col + 1);
                deshacerMovimiento(fila, col, tablero);
            }
        }
    }
}

int main()
{
    bool **tablero = new bool *[N]();
    for (int i = 0; i < N; i++)
    {
        tablero[i] = new bool[N]();
    }

    nreinas_enum(tablero, 0);
    return 0;
}