#ifndef MF_SET
#define MF_SET

#include <cassert>
#include <string>
#include <iostream>
#include <climits>

class MFSet
{
private:
    int *lider;
    int *altura;
    int largo;

public:
    MFSet(int _largo)
    {
        lider = new int[_largo + 1]();
        altura = new int[_largo + 1]();
        largo = _largo;
        for (int i = 0; i <= largo; i++)
        {
            lider[i] = -1;
            altura[i] = 1;
        }
    }

    int find(int x)
    {
        if (lider[x] == -1)
        {
            return x;
        }
        lider[x] = find(lider[x]); // Compression path
        return find(lider[x]);
    }

    void merge(int x, int y)
    {
        /* SIN UNION BY RANK:
        ------------------------------
        int liderX = find(x);
        int liderY = find(y);
        if (liderX == liderY) return;
        lider[liderX] = liderY;
        ------------------------------
        */
        int liderX = find(x);
        int liderY = find(y);
        if (liderX == liderY)
            return;

        if (altura[liderX] > altura[liderY])
        {
            lider[liderY] = liderX;
        }
        else if (altura[liderX] < altura[liderY])
        {
            lider[liderX] = liderY;
        }
        else
        {
            // Son iguales
            lider[liderX] = liderY;
            altura[liderY]++;
        }
    }

    bool pertenecenAlMismo(int x, int y)
    {
        return find(x) == find(y);
    }
};

#endif