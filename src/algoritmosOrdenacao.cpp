#include "algoritmosOrdenacao.h"
#include "iostream"
#include <stdlib.h>

using namespace std;

///Construtor
algoritmosOrdenacao::algoritmosOrdenacao(int *vetor, int tam){
    vetor1=vetor;
    tam1=tam;
}

///Destrutor
algoritmosOrdenacao::~algoritmosOrdenacao()
{
    //dtor
}

/// Fun��es Auxiliares
//*******************************************************************************************************************************

///Fun��o de Troca
void algoritmosOrdenacao::swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

///imprime o vetor
void algoritmosOrdenacao::imprime(){
    for(int i=0;i<tam1;i++){
        cout<<vetor1[i]<<" ";
    }
    cout<<endl;
}
///Radomiza a ordem dos elementos no vetor
void algoritmosOrdenacao::randomiza(){
    int indice;
    for(int i = 0; i < tam1; i++){
        vetor1[i] = rand() % 999;

    }
}

//*******************************************************************************************************************************

///Fun��es de Ordena��o
//*******************************************************************************************************************************

///BubbleSort
//A ideia � percorrer o vetor diversas vezes, e a cada passagem fazer "flutuar" para o topo o maior elemento da sequ�ncia.
//No melhor caso o algoritmo  de ordem n, no pior caso n^2.
//A complexidade � quadratica, por isso ele n�o pe recomendado para programas que precisem de velocidade e operem com quantidade
//elevada de dados
void algoritmosOrdenacao::bubbleSort(){
    for(int i=0;i<tam1-1;i++){
        for(int j=0;j<tam1-i-1;j++){
            if(vetor1[j]>vetor1[j+1]){
                swap(&vetor1[j],&vetor1[j+1]);
            }
        }
    }
}

///Selection Sort
//A ideia � passar sempre o menor valor do vetor para a primeira posicao e assim sucessivamente
//Complexidade no melhor caso O(n^2) - Complexidade no pior caso O(n^2)
//� um dos mais lentos para vetores grandes. N�o e est�vel
void algoritmosOrdenacao::selectionSort(){
    for(int i=0;i<tam1;i++){
        int imen=i;
        for(int iseg=i+1;iseg<tam1;iseg++){
            if(vetor1[iseg]<vetor1[imen]){
                imen=iseg;
            }
        }
        int aux=vetor1[i];
        vetor1[i]=vetor1[imen];
        vetor1[imen]=aux;
    }
}

///Insertion sort
//A ideia � percorrer as posicoes do vetor
//Estavel, bom para pequenas entradas
//Melhor caso O(n) - Pior caso O(n^2)
void algoritmosOrdenacao::insertionSort(){
for(int i=1; i<tam1;i++){
    int escolhido = vetor1[i];
    int j=i-1;
    while((j>=0)&&(vetor1[j]>escolhido)){
        vetor1[j+1]=vetor1[j];
        j--;
    }
    vetor1[j+1]=escolhido;
}
}


//QuickSort recursivo
//O algoritmo adota a estrat�gia de divis�o e conquista. A estrat�gia consiste em rearranjar as chaves
//de modo que as chaves menores precedam as maiores.
//� um algoritmmo n�o est�vel
//No pior caso possui complexidade O(n^2) - No melhor caso possui complexidade O(log2n)
void algoritmosOrdenacao::quickSort(){

}
