#include "menu.h"
#include <bits/stdc++.h>
#define TAMANHO 8
#include <iostream>
#include "algoritmosOrdenacao.h"
#include <stdlib.h>
#include <fstream>
#include <vector>

//Tamanho do bloco a ser pego no arquivo:
#define TAM 1000

using namespace std;

menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

/*
 **********************************************************************************************
 *                                                                                            *
 * Funcao responsavel pela leitura de um bloco de dados de tamanho N do arquivo e armazena-lo *
 * em uma lista de registros                                                                  *
 *                                                                                            *
 **********************************************************************************************
 */
void menu::leituraArquivo(int N, list<registro>& lista, vector<int>& listaId){
    fstream bbg;
    int linha=0;
    bbg.open("bgg-13m-reviews.csv", ios::in);
    if(bbg.is_open()){
        int num = 0;//numero de linhas no arquivo
        string str,palavra;
        while(bbg){
            getline(bbg,str);
            num++;
        }
        //reinicializando o arquivo
        bbg.clear();
        bbg.seekg(0, ios::beg);

        getline(bbg,str);
        srand(time(NULL));//inicializando semente de randomizacao
        int random = num-N;
        random = rand() % random;
        int cont = 0;
        int contN = 0;
	while(getline(bbg, str)){
            stringstream s(str);
            if(contN >= random && contN <=random+N){
                registro reg;
                getline(s, palavra, ',');
                reg.setId(stoi(palavra));
                listaId.push_back(stoi(palavra));
                getline(s, palavra, ',');
                reg.setUser(palavra);
                getline(s, palavra, ',');
                if(palavra>="0.0" && palavra<="10.0")
                    reg.setRating(stoi(palavra));
                else
                    contN--;
            }
            contN++;
            s.clear();
	}
	cout<<endl;
    }
    else{
    	cout<<"erro ao abrir o arquivo"<<endl;
    }
}

void menu::exibirMenu(){

    list<registro> regs;
    vector<int> ids;
    random_shuffle(ids.begin(), ids.end());
    leituraArquivo(TAM, regs, ids);
    int escolha = -1;
    int vet[TAMANHO]; // criando vetor
    algoritmosOrdenacao a(ids, TAM); //instanciando objeto para ordenação
    a.randomiza(); // aleatorizando elementos do vetor
/*    for(vector<int>::iterator it = ids.begin(); it != ids.end(); ++it)
	cout<<*it<< "  ";
    cout<<endl;
*/
    ofstream arquivo;

    cout << "Insira o que deseja fazer: " << endl;
    while(escolha != 0){
        cout << endl << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Heap Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Quick Sort hibrido" << endl;
        cout << "7. Merge Sort" << endl;
        cout << "8. Count Sort(MeuSort)" << endl;
        cout << "9. Cenario 1" << endl;
        cout << "10. Cenario 2" << endl;
        cout << "11. Cenario 3" << endl;
        cout << "12. Cenario 4" << endl;
        cout << "0. Encerrar o programa" << endl << endl;
        cin >> escolha;
        switch(escolha){
        case 1:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.bubbleSort();
            auto finish = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo BubbleSort: "<<elapsed.count()<<endl;
            cout<< "Fim Bubble Sort"<< endl;
            break;
        }
        case 2:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.selectionSort();
            auto finish = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo SelectionSort: "<<elapsed.count()<<endl;
            cout<< "Fim Selection Sort"<< endl;

            break;
        }
        case 3:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.insertionSort();
            auto finish = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo InsertionSort: "<<elapsed.count()<<endl;
            cout<< "Insertion Sort"<< endl;
            break;
        }
        case 4:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.heapSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo HeapSort: "<<elapsed.count()<<endl;
            cout<< "Fim Heap Sort"<< endl;

        }
            break;
        case 5:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.quickSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo QuickSortRecursivo: "<<elapsed.count()<<endl;
            cout<< "Fim Quick Sort Recursivo"<< endl;
            break;
        }
        case 6:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.auxQuickSortHibrido();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo QuickSortHibrido: "<<elapsed.count()<<endl;
            cout<< "Fim Quick Sort Hibrido"<< endl;
            break;
        }
        case 7:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.mergeSortAux();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo MergeSort: "<<elapsed.count()<<endl;
            cout<< "Fim Merge Sort"<< endl;
            break;
        }
        case 8:
        {
            arquivo.open ("Sort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.countSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            arquivo<<"Tempo CountSort: "<<elapsed.count()<<endl;
            cout<< "Fim Count Sort"<< endl;
            break;
        }
        case 9: ///Cenario 1
            {
               break;
            }
        case 10: ///Cenario 2
            {
                arquivo.open ("cenario2.txt");
                arquivo<<"Vetor de tamanho: "<<TAM<<endl;
                auto start = std::chrono::high_resolution_clock::now();
                a.quickSort();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;
                arquivo<<"Tempo QuickSortRecursivo: "<<elapsed.count()<<endl;
                auto start1 = std::chrono::high_resolution_clock::now();
                a.auxQuickSortHibrido();
                auto finish1 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed1 = finish1 - start1;
                arquivo<<"Tempo QuickSortHibrido: "<<elapsed1.count()<<endl;
                cout<< "Fim Cenario 2"<< endl;
                break;
            }
        case 11: ///Cenario 3
            {
               break;
            }
        case 12: ///Cenario 4
            {
               break;
            }

        case 0:
            break;
        default:
            cout << endl <<  "Por favor insira um valor correto" << endl;
        }
    }
    arquivo.close();
}
