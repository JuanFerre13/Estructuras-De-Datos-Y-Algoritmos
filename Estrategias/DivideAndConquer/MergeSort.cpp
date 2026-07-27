#ifndef MERGESORT_DAC
#define MERGESORT_DAC

int *intercalar(int arr1[], int arr2[])
{
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int *ret = new int[n1 + n2];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            ret[k++] = arr1[i++];
        }
        else
        {
            ret[k++] = arr2[j++];
        }
    }

    while (i < n1)
    {
        ret[k++] = arr1[i++];
    }

    while (j < n2)
    {
        ret[k++] = arr2[j++];
    }

    return ret;
}

int *mergeSort(int valores[], int inicio, int fin)
{
    if (inicio == fin)
    {
        int *ret = new int[1];
        ret[0] = valores[inicio];
        return ret;
    }

    int mitad = (inicio + fin) / 2;

    int *ord1 = mergeSort(valores, inicio, mitad);
    int *ord2 = mergeSort(valores, mitad + 1, fin);

    return intercalar(ord1, ord2);
}

#endif