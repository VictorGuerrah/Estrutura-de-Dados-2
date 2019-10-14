#ifndef ALGORITMOSORDENACAO_H
#define ALGORITMOSORDENACAO_H
#include <iostream>
#include <vector>

using namespace std;

class algoritmosOrdenacao
{
    public:
        algoritmosOrdenacao(vector<int>& vetor, int tam);
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
	void quickSortMediana(); //Camila
        void quickSortMedianaAux(vector<int>& vetor, int inicio, int fim); //Camila
        void countSort(); //Victor
        void auxQuickSortHibrido();//Pedro
        void QuickSortHibrido(vector<int>& vetor,int inicio,int fim);//Pedro
        int particaoQuickSort(vector<int>& vetor,int inicio,int fim);//Pedro
        void mergeSort(vector<int>& vetor, int inicio, int fim); //Daniel
        void intercala(vector<int>& vetor, int inicio, int meio, int fim); //Daniel
        void mergeSortAux(); //Daniel
	int getComparacoes();
	int getTrocas();
    protected:

    private:
	vector<int> vetor1;
        int tam1, inicio1, fim1;
	int comparacoes,trocas;
};

#endif // ALGORITMOSORDENACAO_H
