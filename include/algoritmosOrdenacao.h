#ifndef ALGORITMOSORDENACAO_H
#define ALGORITMOSORDENACAO_H


class algoritmosOrdenacao
{
    public:
        algoritmosOrdenacao(int *vetor, int tam);
        virtual ~algoritmosOrdenacao();
        void bubbleSort();
        void selectionSort();
        void insertionSort();
        void heapSort();
        void maxHeapfy(int* arvore,int indice);
        void buildMaxHeap(int* arvore);
        void swap(int *a, int *b);
        void imprime();
        void randomiza();
        void quickSort();
        int particao();

    protected:

    private:
        int *vetor1, tam1;

};

#endif // ALGORITMOSORDENACAO_H
