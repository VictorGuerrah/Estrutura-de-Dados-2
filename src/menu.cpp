#include "menu.h"
#define TAMANHO 8
#include <iostream>
#include "algoritmosOrdenacao.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

void menu::exibirMenu(){
    int escolha = -1;
    int vet[TAMANHO]; // criando vetor
    algoritmosOrdenacao a(vet, TAMANHO); //instanciando objeto para ordenação
    a.randomiza(); // aleatorizando elementos do vetor

    ofstream arquivo;

    cout << "Insira o que deseja fazer: " << endl;
    while(escolha != 0){
        cout << endl << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Heap Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Quick Sort iterativo" << endl;
        cout << "7. Merge Sort" << endl;
        cout << "8. Count Sort(MeuSort)" << endl;
        cout << "0. Encerrar o programa" << endl << endl;
        cin >> escolha;
        switch(escolha){
        case 1:
            cout << "Vetor: ";
            a.imprime();
            cout << "Bubble Sort: ";
            arquivo.open ("bubbleSort.txt");
            a.bubbleSort();
            arquivo << "teste";
            escolha = 0;
            break;
        case 2:
            cout << endl << "Vetor: ";
            a.imprime();
            cout << "Selection Sort: ";
            a.selectionSort();
            a.imprime();
            escolha = 0;
            break;
        case 3:
            cout << endl << "Vetor: ";
            a.imprime();
            cout << "Insertion Sort: ";
            a.insertionSort();
            a.imprime();
            escolha = 0;
            break;
        case 4:
            cout << endl << "Vetor: ";
            a.imprime();
            cout << "Heap Sort: ";
            a.heapSort();
            a.imprime();
            escolha = 0;
            break;
        case 5:
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Quick Sort Recursivo: ";
            a.quickSort();
            a.imprime();
            escolha = 0;
            break;
        case 6:
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Quick Sort Hibrido: ";
            a.auxQuickSortHibrido();
            a.imprime();
            escolha = 0;
            break;
        case 7:
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Merge Sort: ";
            a.mergeSortAux();
            a.imprime();
            escolha = 0;
            break;
        case 8:
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Count Sort: ";
            a.countSort();
            a.imprime();
            escolha = 0;
            break;
        case 0:
            break;
        default:
            cout << endl <<  "Por favor insira um valor correto" << endl;
        }
    }
    arquivo.close();
}
