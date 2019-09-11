#include "algoritmosOrdenacao.h"
#include "iostream"
#include <stdlib.h>
#include<stack>
using namespace std;

///Construtor
algoritmosOrdenacao::algoritmosOrdenacao(int *vetor, int tam)
{
    vetor1=vetor;
    tam1=tam;
    inicio1=0;
    fim1=tam;

}

///Destrutor
algoritmosOrdenacao::~algoritmosOrdenacao()
{
    //dtor
}

/// Funções Auxiliares
//*******************************************************************************************************************************

///Função de Troca
void algoritmosOrdenacao::swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

///imprime o vetor
void algoritmosOrdenacao::imprime()
{
    for(int i=0; i<tam1; i++)
    {
        cout<<vetor1[i]<<" ";
    }
    cout<<endl;
}
///Radomiza a ordem dos elementos no vetor
void algoritmosOrdenacao::randomiza()
{
    int indice;
    for(int i = 0; i < tam1; i++)
    {
        vetor1[i] = rand() % 999;

    }
}

//*******************************************************************************************************************************

///Funções de Ordenação
//*******************************************************************************************************************************

///BubbleSort
//A ideia é percorrer o vetor diversas vezes, e a cada passagem fazer "flutuar" para o topo o maior elemento da sequência.
//No melhor caso o algoritmo  de ordem n, no pior caso n^2.
//A complexidade é quadratica, por isso ele não pe recomendado para programas que precisem de velocidade e operem com quantidade
//elevada de dados
void algoritmosOrdenacao::bubbleSort()
{
    for(int i=0; i<tam1-1; i++)
    {
        for(int j=0; j<tam1-i-1; j++)
        {
            if(vetor1[j]>vetor1[j+1])
            {
                swap(&vetor1[j],&vetor1[j+1]);
            }
        }
    }
}

///Selection Sort
//A ideia é passar sempre o menor valor do vetor para a primeira posicao e assim sucessivamente
//Complexidade no melhor caso O(n^2) - Complexidade no pior caso O(n^2)
//É um dos mais lentos para vetores grandes. Não e estável
void algoritmosOrdenacao::selectionSort()
{
    for(int i=0; i<tam1; i++)
    {
        int imen=i;
        for(int iseg=i+1; iseg<tam1; iseg++)
        {
            if(vetor1[iseg]<vetor1[imen])
            {
                imen=iseg;
            }
        }
        int aux=vetor1[i];
        vetor1[i]=vetor1[imen];
        vetor1[imen]=aux;
    }
}

///Insertion sort
//A ideia é percorrer as posicoes do vetor
//Estavel, bom para pequenas entradas
//Melhor caso O(n) - Pior caso O(n^2)
void algoritmosOrdenacao::insertionSort()
{
    for(int i=1; i<tam1; i++)
    {
        int escolhido = vetor1[i];
        int j=i-1;
        while((j>=0)&&(vetor1[j]>escolhido))
        {
            vetor1[j+1]=vetor1[j];
            j--;
        }
        vetor1[j+1]=escolhido;
    }
}


//QuickSort recursivo
//O algoritmo adota a estratégia de divisão e conquista. A estratégia consiste em rearranjar as chaves
//de modo que as chaves menores precedam as maiores.
//é um algoritmmo não estável
//No pior caso possui complexidade O(n^2) - No melhor caso possui complexidade O(log2n)
void algoritmosOrdenacao::quickSort()
{

    quickSortAux(vetor1,inicio1,fim1);
}

void algoritmosOrdenacao::quickSortAux(int *vetor, int inicio, int fim)
{
    int i, j, pivo, aux;
    i=inicio;
    j=fim-1;
    pivo=vetor[(inicio+fim)/2];
    while(i<=j)
    {
        while(vetor[i]<pivo&&i<fim)
        {
            i++;
        }
        while(vetor[j]>pivo&&j>inicio)
        {
            j--;
        }
        if(i<=j)
        {
            aux=vetor[i];
            vetor[i]=vetor[j];
            vetor[j]=aux;
            i++;
            j--;
        }
    }
    if(j>inicio)
    {
        quickSortAux(vetor,inicio,j+1);
    }
    if(i<fim)
    {
        quickSortAux(vetor,i,fim);
    }
}

//Quicksort e Insertinsort
int algoritmosOrdenacao::particaoQuickSort(int vet[], int inicio, int fim)
{
    int x = vet[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (vet[j] <= x)
        {
            i++;
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[fim]);
    return (i + 1);
}

void algoritmosOrdenacao::auxQuickSortHibrido()
{

    int inicio2=inicio1;
    int fim2=fim1;
    QuickSortHibrido(vetor1,inicio2,fim2);


}
void algoritmosOrdenacao::QuickSortHibrido(int* vetor,int inicio,int fim)
{

    while (inicio < fim)
    {
// do insertion sort if 10 or smaller
        if(inicio - fim < 10)
        {
            insertionSort();
            break;
        }
        else
        {
            int pivo = particaoQuickSort(vetor1, inicio, fim);


            if (pivo - inicio < fim - pivo)
            {
                QuickSortHibrido(vetor1, inicio, fim - 1);
                inicio1 = pivo + 1;
            }
            else
            {
                QuickSortHibrido(vetor1, pivo + 1, fim);
                fim = pivo - 1;
            }
        }
    }


}


void algoritmosOrdenacao::heapfy(int* arvore, int indice)
{
    int maior = indice; //inicializaa maior como raiz
    int l = 2 * indice + 1;
    int r = 2 * indice + 2;
    int aux;

    // Se o filho da esquerda for maior que a raiz
    if(l  < tam1 && arvore[l] > arvore[maior])
    {
        maior = l;
    }
    // Se o filho da direita for o maior até agora
    if(r < tam1 && arvore[r] > arvore[maior])
    {
        maior = r;
    }
    //Se o maior não for a raiz
    if(maior != indice)
    {
        aux = arvore[maior];
        arvore[maior] = arvore[indice];
        arvore[indice] = aux;
        heapfy(arvore, maior);
    }
}
//Constrói a heap
void algoritmosOrdenacao::buildMaxHeap(int* arvore)
{
    for(int i = tam1 / 2 - 1; i >= 0; i--)
    {
        heapfy(arvore, i);
    }
}
///Heap Sortsrc
void algoritmosOrdenacao::heapSort()
{
    int tamanho = tam1;
    buildMaxHeap(vetor1);
    //Extrai elemento da heap um por um
    for(int i = tam1 - 1; i >= 0; i--)
    {
        //troca a raiz atual com o final da heap
        int aux = vetor1[i];
        vetor1[i] = vetor1[0];
        vetor1[0] = aux;
        //Diminui o tamanho da heap
        tam1 -= 1;
        //Chama heapfy na heap reduzida
        heapfy(vetor1, 0);
    }
    tam1 = tamanho;
}

void algoritmosOrdenacao::mergeSortAux()
{

    mergeSort(vetor1,inicio1,fim1);

}


void algoritmosOrdenacao::mergeSort(int vetor[], int inicio, int fim)
{


    if(inicio < fim)
    {

        int meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        intercala(vetor, inicio, meio, fim);

    }
}


void algoritmosOrdenacao::intercala(int vetor[], int inicio, int meio, int fim)
{

    int i, j, k;
    int n1 = meio-inicio +1;
    int n2 = fim-meio;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = vetor[inicio+i];
    for(int j = 0; j < n2; j++)
        R[j] = vetor[meio+1+j];

    i = 0;
    j = 0;
    k = inicio;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {

            vetor[k] = R[j];
            j++;
        }
        k++;


    }

    while(i < n1)
    {

        vetor[k] = L[i];
        i++;
        k++;


    }

    while(j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;


    }

}

void algoritmosOrdenacao::countSort()
{
    int m = 0;

    //Encontra o maior valor do vetor
    for(int i = 0; i < tam1; i++)
    {
        if(vetor1[i] > m)
        {
            m = vetor1[i];
        }
    }

    m += 1;

    int vetorAuxiliar[m];

    //Inicializa vetor auxiliar com 0
    for(int i = 0; i < m; i++)
    {
        vetorAuxiliar[i] = 0;
    }
    //Conta as ocorrencias de cada elemento do vetor
    for(int i = 0; i < tam1; i++)
    {
        vetorAuxiliar[vetor1[i]]++;
    }

    // Ordena os indices do vetor auxiliar
    int sum = 0;
    for(int i = 1; i < m; i++)
    {
        int dum = vetorAuxiliar[i];
        vetorAuxiliar[i] = sum;
        sum += dum;
    }
    int vetorOrdenado[tam1];
    for(int i = 0; i < tam1; i++)
    {
        vetorOrdenado[vetorAuxiliar[vetor1[i]]] = vetor1[i];
        vetorAuxiliar[vetor1[i]]++;
    }
    //Retorna os valores ordenados para o vetor de entrada
    for (int i = 0; i < tam1; i++)
    {
        vetor1[i] = vetorOrdenado[i];
    }
}
