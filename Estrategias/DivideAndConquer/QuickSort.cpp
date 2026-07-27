#ifndef QUICKSORT_DAC
#define QUICKSORT_DAC


void swap(int &a, int &b) {
  int aux = a;
  a = b;
  b = aux;
}

int particion(int valores[], int inicio, int fin) {
  int pivote = valores[fin];
  int i = inicio - 1;

  for(int j = inicio; j < fin; j++) {
    if(valores[j] < pivote) {
      i++;
      swap(valores[i], valores[j]);
    }
  }

  swap(valores[i + 1], valores[fin]);
  return i + 1;
}

void quickSort(int valores[], int inicio, int fin) {
  if(inicio < fin) {
    int pivote = particion(valores, inicio, fin);
    quickSort(valores, inicio, pivote - 1);
    quickSort(valores, pivote + 1, fin);
  }
}

#endif