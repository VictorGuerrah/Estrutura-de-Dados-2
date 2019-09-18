#include "menu.h"
#define TAMANHO 8
#include <iostream>
#include "algoritmosOrdenacao.h"
#include <stdlib.h>
#include <fstream>
//Tamanho do bloco a ser pego no arquivo:
#define TAM 100 

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
void menu::leituraArquivo(int N, list<registro>& lista){
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
                getline(s, palavra, ',');
                reg.setUser(palavra);
                getline(s, palavra, ',');
                reg.setRating(stoi(palavra));
                getline(s, palavra, ',');
                if(palavra != ""){
                     contN--;
                }
                else{
                    getline(s, palavra, ',');
                    reg.setId(stoi(palavra));
                    lista.push_back(reg);
                }
            }
            contN++;
            s.clear();
	}
    }
    else{
    	cout<<"erro ao abrir o arquivo"<<endl;
    }
}

void menu::exibirMenu(){

    list<registro> regs;
    leituraArquivo(TAM,regs);
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
        {
            cout << "Vetor: ";
            a.imprime();
            cout << "Bubble Sort: ";
            arquivo.open ("bubbleSort.txt");
            auto start = std::chrono::high_resolution_clock::now();
            a.bubbleSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
            break;
        }
        case 2:
        {
            cout << endl << "Vetor: ";
            a.imprime();
            cout << "Selection Sort: ";
            auto start = std::chrono::high_resolution_clock::now();
            a.selectionSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
            break;
        }
        case 3:
        {
            cout << endl << "Vetor: ";
            a.imprime();
            cout << "Insertion Sort: ";
            auto start = std::chrono::high_resolution_clock::now();
            a.insertionSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
            break;
        }
        case 4:
        {
            cout << endl << "Vetor: ";
            a.imprime();
            cout << "Heap Sort: ";
            auto start = std::chrono::high_resolution_clock::now();
            a.heapSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
        }
            break;
        case 5:
        {
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Quick Sort Recursivo: ";
            auto start = std::chrono::high_resolution_clock::now();
            a.quickSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
            break;
        }
        case 6:
        {
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Quick Sort Hibrido: ";
            auto start = std::chrono::high_resolution_clock::now();
            a.auxQuickSortHibrido();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
            break;
        }
        case 7:
        {
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Merge Sort: ";
            auto start = std::chrono::high_resolution_clock::now();
            a.mergeSortAux();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
            break;
        }
        case 8:
        {
            cout << endl << "Vetor: ";
            a.imprime();
            cout<<"Count Sort: ";
            auto start = std::chrono::high_resolution_clock::now();
            a.countSort();
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "Elapsed time: " << elapsed.count() << " s\n";
            a.imprime();
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
