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
    a.insertionSort();
    a.imprime();

    return 0;
}
