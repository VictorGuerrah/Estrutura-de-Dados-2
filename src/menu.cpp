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
void menu::leituraArquivo(int N, vector<registro>& lista, vector<int>& listaId)
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
                {
                    reg.setRating(stoi(palavra));
                    lista.push_back(reg);
                }
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

            int numN = 0; //armazena o número de N's do arquivo
            ifstream infile ("entrada.txt");
            int i=0;

            while(infile)
            {

                if(i==0)
                {
                    string s;
                    getline(infile,s);
                    numN = atoi(s.c_str()); //pega o número de N's que estão no arquivo.
                    break;
                }
            }

            int vetN[numN]; //cria um vetor para salvar os N's que são quantidades de números que serão testados.

            while(infile)
            {

                string s;
                if(i==0)  //nao pega o primeiro elemento, pois ele indica a quantidade de N's.
                {
                }
                else
                {
                    if(!getline(infile,s))
                        break;
                    vetN[i-1]=atoi(s.c_str()); //pega o valor de N e salva no vetor vetN.
                }
                i++;
            }

            arquivo.open ("cenario1.txt");
            for(int i=0; i<numN; i++)
            {
                for(int j=0; j<5; j++)
                {
                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(vetN[i], regs, ids);
                    random_shuffle(ids.begin(), ids.end());
                    algoritmosOrdenacao a(ids, vetN[i]); //instanciando objeto para ordenação
                    auto start = std::chrono::high_resolution_clock::now();
                    a.quickSort();
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed = finish - start;
                    cout <<"Tempo Cenario 1a): "<<elapsed.count()<< endl;
                    cout<<"Iteracao: "<<j<<endl;
                    cout<<"Tamanho: "<<vetN[i]<<endl;
                    arquivo<<"Tempo cenario 1a: "<<elapsed.count()<<endl;
                    arquivo<<"Iteracao: "<<j<<endl;
                    arquivo<<"Tamanho: "<<vetN[i]<<endl;
                    arquivo<<"Comparacoes: "<<a.getComparacoes()<<endl;
                    arquivo<<"Trocas: "<<a.getTrocas()<<endl;
                    arquivo<<endl;
                }
            }
            break;
        }
        case 2: ///Cenario 2
        {
            arquivo.open ("cenario2.txt");
            int tamanho[6]= {1000,5000,10000,50000,100000,500000};
            for(int j=0; j<6; j++)
            {
                for(int i=0; i < 5; i++)
                {
                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(tamanho[j], regs, ids);
                    random_shuffle(ids.begin(), ids.end());
                    algoritmosOrdenacao a(ids, tamanho[j]); //instanciando objeto para ordenação

                    auto start = std::chrono::high_resolution_clock::now();
                    a.quickSort();
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed = finish - start;
                    arquivo<<"Tempo QuickSort: "<<elapsed.count()<<"Iteracao: "<<i<<"Tamanho"<<tamanho[j]<<endl;

                    auto start1 = std::chrono::high_resolution_clock::now();
                    a.quickSortMediana();
                    auto finish1 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed1 = finish1 - start1;
                    arquivo<<"Tempo QuickSortMediana: "<<elapsed1.count()<<"Iteracao: "<<i<<"Tamanho"<<tamanho[j]<<endl;

                    auto start2 = std::chrono::high_resolution_clock::now();
                    a.auxQuickSortHibrido();
                    auto finish2 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed2 = finish2 - start2;
                    arquivo<<"Tempo QuickSorthibrido: "<<elapsed2.count()<<"Iteracao: "<<i<<"Tamanho"<<tamanho[j]<<endl;

                }
            }
            arquivo.close();
            break;
        }
        case 3: ///Cenario 3
        {
            arquivo.open ("cenario3.txt");
            int numN = 0; //armazena o número de N's do arquivo
            ifstream infile ("entradaT.txt");
            int i=0;

            while(infile)
            {
                if(i==0)
                {
                    string s;
                    getline(infile,s);
                    numN = atoi(s.c_str()); //pega o número de N's que estão no arquivo.
                    break;
                }
            }

            int vetN[numN]; //cria um vetor para salvar os N's que são quantidades de números que serão testados.

            while(infile)
            {
                string s;
                if(i==0)  //nao pega o primeiro elemento, pois ele indica a quantidade de N's.
                {
                }
                else
                {
                    if(!getline(infile,s))
                        break;
                    vetN[i-1]=atoi(s.c_str()); //pega o valor de N e salva no vetor vetN.
                }
                i++;
            }
            for(int i=0; i<numN; i++)
            {
                cout << "Começo da iteração: " << i + 1 << endl;
                for(int j=0; j<5; j++)
                {

                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(vetN[i], regs, ids);
                    random_shuffle(ids.begin(), ids.end());
                    algoritmosOrdenacao a(ids, vetN[i]); //instanciando objeto para ordenação

                    auto start = std::chrono::high_resolution_clock::now();
                    a.quickSort();
                    cout << "Quicksort CONCLUIDO" << endl;
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed = finish - start;
                    arquivo<<"Tempo QuickSort: "<<elapsed.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();

                    auto start1 = std::chrono::high_resolution_clock::now();
                    a.insertionSort();
                    cout <<"Insertion CONCLUIDO " << endl;
                    auto finish1 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long double> elapsed1 = finish1 - start1;
                    arquivo<<"Tempo Insertion: "<<elapsed1.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();


                    auto start2 = std::chrono::high_resolution_clock::now();
                    a.mergeSortAux();
                    cout <<"MergeSort CONCLUIDO " << endl;
                    auto finish2 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed2 = finish2 - start2;
                    arquivo<<"Tempo MergeSort: "<<elapsed2.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();


                    auto start3 = std::chrono::high_resolution_clock::now();
                    a.heapSort();
                    cout <<"HeapSort CONCLUIDO" << endl;
                    auto finish3 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed3 = finish3 - start3;
                    arquivo<<"Tempo HeapSort: "<<elapsed3.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();


                    auto start4 = std::chrono::high_resolution_clock::now();
                    a.countSort();
                    cout <<"CountSort CONCLUIDO" << endl;
                    auto finish4 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long double> elapsed4 = finish4 - start4;
                    arquivo<<"Tempo CountSort: "<<elapsed4.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                    a.randomiza();
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    arquivo << endl;
                    cout << "//////////////////////////////" << endl;
                    arquivo << "//////////////////////////////" << endl;

                }
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
