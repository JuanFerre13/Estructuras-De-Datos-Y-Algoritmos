#ifndef CAMBIO_GREEDY
#define CAMBIO_GREEDY

int cambioGreedy(int n, int *monedas, int cambio){
    int cantidad = 0;
    for (int i = n-1; i >= 0; i--)
    {
        while(cambio > monedas[i]){
            cambio -= monedas[i];
            cantidad++;
        }
    }
    return cantidad == 0 ? cantidad : -1;
}

#endif