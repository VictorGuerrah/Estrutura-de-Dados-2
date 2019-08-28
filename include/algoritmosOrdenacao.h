#ifndef ALGORITMOSORDENACAO_H
#define ALGORITMOSORDENACAO_H


class algoritmosOrdenacao
{
    public:
        algoritmosOrdenacao(int *vetor, int tam);
        virtual ~algoritmosOrdenacao();
        void bubbleSort();//Todos
        void selectionSort();//Todos
        void insertionSort();//Todos
        void heapSort();//Victor
        void heapfy(int* arvore,int indice);//Victor
        void buildMaxHeap(int* arvore);//Victor
        void swap(int *a, int *b);
        void imprime();
        void randomiza();
        void quickSort(); //Camila
        void quickSortAux(int *vetor, int inicio, int fim); //Camila

    protected:

    private:
        int *vetor1, tam1, inicio1, fim1;

};

#endif // ALGORITMOSORDENACAO_H
