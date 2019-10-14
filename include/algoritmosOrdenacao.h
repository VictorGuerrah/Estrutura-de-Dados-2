#ifndef ALGORITMOSORDENACAO_H
#define ALGORITMOSORDENACAO_H
#include <iostream>
#include <vector>
#include "registro.h"
using namespace std;

class algoritmosOrdenacao
{
    public:
        algoritmosOrdenacao(vector<int>& vetor, int tam);
        algoritmosOrdenacao(vector<registro>& vetorregs, int tam);
        virtual ~algoritmosOrdenacao();
        void bubbleSort();//Todos
        void selectionSort();//Todos
        void insertionSort();//Todos
        void heapSort();//Victor
        void heapfy(vector<int>& arvore,int indice);//Victor
        void buildMaxHeap(vector<int>& arvore);//Victor
        void swap(int* a, int* b);
        void imprime();
        void randomiza();
        void quickSort(); //Camila
        void quickSortAux(vector<int>& vetor, int inicio, int fim); //Camila

        void quickSortRegistro();
        void quickSortAuxRegistro(vector<registro>& vetor, int inicio, int fim);




        void quickSortMediana(); //Camila
        void quickSortMedianaAux(vector<int>& vetor, int inicio, int fim); //Camila
        void countSort(); //Victor
        void auxQuickSortHibrido();//Pedro
        void QuickSortHibrido(vector<int>& vetor,int inicio,int fim);//Pedro
        int particaoQuickSort(vector<int>& vetor,int inicio,int fim);//Pedro
        void mergeSort(vector<int>& vetor, int inicio, int fim); //Daniel
        void intercala(vector<int>& vetor, int inicio, int meio, int fim); //Daniel
        void mergeSortAux(); //Daniel

        void zeraTrocas(){trocas = 0;};
        void zeraComparacoes(){comparacoes = 0;};

	int getComparacoes();
	int getTrocas();
    protected:

    private:
	vector<int> vetor1;
	vector<registro> vetorregs1;
        int tam1, inicio1, fim1;
	int comparacoes,trocas;
};

#endif // ALGORITMOSORDENACAO_H
