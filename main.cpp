#include <iostream>
#include "algoritmosOrdenacao.h"
using namespace std;

int main()
{
    int vet[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(vet)/sizeof(vet[0]);
    algoritmosOrdenacao a(vet, n);
    a.imprime();
    a.bubbleSort();
    //a.selectionSort();
    //a.insertionSort();
    a.imprime();
    return 0;
}
