#include <iostream>
#include "algoritmosOrdenacao.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define TAMANHO 8

int main()
{
    int vet[TAMANHO]; // criando vetor
    algoritmosOrdenacao a(vet, TAMANHO); //instanciando objeto para ordenação
    a.randomiza(); // aleatorizando elementos do vetor


    ///Teste Bubble Sort
    cout << "Vetor: ";
    a.imprime();
    cout << "Bubble Sort: ";
    a.bubbleSort();
    a.imprime();

    ///Teste Selection Sort
    a.randomiza();
    cout << endl << "Vetor: ";
    a.imprime();
    cout << "Selection Sort: ";
    a.selectionSort();
    a.imprime();

    ///Teste Insertion Sort
    a.randomiza();
    cout << endl << "Vetor: ";
    a.imprime();
    cout << "Insertion Sort: ";
    a.insertionSort();
    a.imprime();

    ///Teste Heap Sort
    a.randomiza();
    cout << endl << "Vetor: ";
    a.imprime();
    cout << "Heap Sort: ";
    a.heapSort();
    a.imprime();

    ///Teste Quick Sort Recursivo
    a.randomiza();
    cout << endl << "Vetor: ";
    a.imprime();
    cout<<"Quick Sort Recursivo: ";
    a.quickSort();
    a.imprime();

    ///Teste Quick Sort Hibrido
    a.randomiza();
    cout << endl << "Vetor: ";
    a.imprime();
    cout<<"Quick Sort Hibrido: ";
    a.auxQuickSortHibrido();
    a.imprime();


    ///Teste Merge Sort
    a.randomiza();
    cout << endl << "Vetor: ";
    a.imprime();
    cout<<"Merge Sort: ";
    a.mergeSortAux();
    a.imprime();

    return 0;
}
