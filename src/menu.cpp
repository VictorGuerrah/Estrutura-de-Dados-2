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
void menu::leituraArquivo(int N, list<registro>& lista, vector<int>& listaId)
{
    fstream bbg;
    int linha=0;
    bbg.open("bgg-13m-reviews.csv", ios::in);
    if(bbg.is_open())
    {
        int num = 0;//numero de linhas no arquivo
        string str,palavra;
        while(bbg)
        {
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
        while(getline(bbg, str))
        {
            stringstream s(str);
            if(contN >= random && contN <=random+N)
            {
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
    else
    {
        cout<<"erro ao abrir o arquivo"<<endl;
    }
}

void menu::exibirMenu()
{


    int escolha = -1;
    ofstream arquivo;

    cout << "Insira o que deseja fazer: " << endl;
    while(escolha != 0)
    {

        cout << "1. Cenario 1" << endl;
        cout << "2. Cenario 2" << endl;
        cout << "3. Cenario 3" << endl;
        cout << "4. Cenario 4" << endl;
        cout << "0 Encerrar o programa" << endl << endl;
        cin >> escolha;
        switch(escolha)
        {
        case 1: ///Cenario 1
        {
            break;
        }
        case 2: ///Cenario 2
        {

        }
        case 3: ///Cenario 3
        {
            arquivo.open ("cenario3.txt");
            int tamanho;
            cin >> tamanho;
            for(int i=0; i < 5; i++)
            {
                list<registro> regs;
                vector<int> ids;
                leituraArquivo(tamanho, regs, ids);
                random_shuffle(ids.begin(), ids.end());
                algoritmosOrdenacao a(ids, tamanho); //instanciando objeto para ordenação
                cout << "Quicksort: " << endl;
                auto start = std::chrono::high_resolution_clock::now();
                a.auxQuickSortHibrido();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<long  double> elapsed = finish - start;
                arquivo<<"Tempo QuickSort: "<<elapsed.count()<<endl;

                cout << "Insertionsort: " << endl;
                auto start1 = std::chrono::high_resolution_clock::now();
                a.insertionSort();
                auto finish1 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<long double> elapsed1 = finish1 - start1;
                arquivo<<"Tempo Insertion: "<<elapsed1.count()<<endl;

                cout <<"MergeSort: " << endl;
                auto start2 = std::chrono::high_resolution_clock::now();
                a.mergeSortAux();
                auto finish2 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<long  double> elapsed2 = finish2 - start2;
                arquivo<<"Tempo MergeSort: "<<elapsed2.count()<<endl;

                cout <<"HeapSort " << endl;
                auto start3 = std::chrono::high_resolution_clock::now();
                a.heapSort();
                auto finish3 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<long  double> elapsed3 = finish3 - start3;
                arquivo<<"Tempo HeapSort: "<<elapsed3.count()<<endl;


                cout <<"CountSort " << endl;
                auto start4 = std::chrono::high_resolution_clock::now();
                a.countSort();
                auto finish4 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<long double> elapsed4 = finish4 - start4;
                arquivo<<"Tempo CountSort: "<<elapsed4.count()<<endl;

            }
            break;
        }


        case 4: ///Cenario 4
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
