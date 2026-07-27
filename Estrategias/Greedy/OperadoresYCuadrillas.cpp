#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

int resolverCaso(int K, int* opIndexes, int opCount, int* cuIndexes, int cuCount) {
    int atendidos = 0;
    int opIndex = 0;
    int cuIndex = 0;
    while(opIndex < opCount && cuIndex < cuCount) {
        if(abs(opIndexes[opIndex] - cuIndexes[cuIndex]) <= K) {
            atendidos++;
            opIndex++;
            cuIndex++;
        }
        else if(opIndexes[opIndex] < cuIndexes[cuIndex]) opIndex++;
        else cuIndex++;
    }
    return atendidos;
}

int main()
{
    int P;
    int K;
    int N;
    cin >> P;
    for (int i = 0; i < P; i++)
    {
        cin >> K >> N;
        int cantOperadores = 0;
        int cantCuadrillas = 0;
        char * caso = new char[N]();
        for (int i = 0; i < N; i++)
        {
            cin >> caso[i];
            if (caso[i] == 'O') cantOperadores++;
            if (caso[i] == 'C') cantCuadrillas++;
        }
        int* operadoresIndex = new int[cantOperadores];
        int* cuadrillasIndex = new int[cantCuadrillas];
        int indexOp = 0;
        int indexCu = 0;
        for (int i = 0; i < N; i++)
        {
            if (caso[i] == 'O') operadoresIndex[indexOp++] = i;
            if (caso[i] == 'C') cuadrillasIndex[indexCu++] = i;
        }
        cout << resolverCaso(K, operadoresIndex, cantOperadores, cuadrillasIndex, cantCuadrillas) << endl;
    }
    
    return 0;
}