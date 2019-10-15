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


            //variavel para aumenar indice do vetor;
            arquivo.open ("cenario1.txt");

            arquivo<<"Interação,Tamanho do Vetor(N),No de Comparações,No de Trocas,Tempo"<<endl;
            
            for(int i=0; i<numN; i++)
            {
                for(int j=0; j<5; j++)
                {
                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(vetN[i], regs, ids);
                    random_shuffle(ids.begin(), ids.end());
                    algoritmosOrdenacao a(ids, vetN[i]); //instanciando objeto para ordenação
                    a.zeraTrocas();
                    a.zeraComparacoes();
                    auto start = std::chrono::high_resolution_clock::now();
                    a.quickSort();
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed = finish - start;
                    arquivo<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed.count()<<endl;
                    /*arquivo<<"Tempo cenario 1(VETOR DE INTEIROS): "<<endl<<elapsed.count()<<endl;
                    arquivo<<"Iteracao: "<<endl<<j+1<<endl;
                    arquivo<<"Tamanho: "<<endl<<vetN[i]<<endl;
                    arquivo<<"Comparacoes: "<<endl<<a.getComparacoes()<<endl;
                    arquivo<<"Trocas: "<<endl<<a.getTrocas()<<endl;
                    arquivo<<endl;*/

                }
            }
            arquivo<<endl<<endl;
            arquivo<<"Interação,Tamanho do Vetor(N),No de Comparações,No de Trocas,Tempo"<<endl;
            for(int i=0; i<numN; i++)
            {
                for(int j=0; j<5; j++)
                {
                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(vetN[i], regs, ids);
                    random_shuffle(regs.begin(), regs.end());
                    algoritmosOrdenacao b(regs,vetN[i]);
                    b.zeraTrocas();
                    b.zeraComparacoes();
                    auto start = std::chrono::high_resolution_clock::now();

                    b.quickSortRegistro();
                    auto finish = std::chrono::high_resolution_clock::now();

                    std::chrono::duration<long  double> elapsed = finish - start;

                    arquivo<<j+1<<","<<vetN[i]<<","<<b.getComparacoes()<<","<<b.getTrocas()<<","<<elapsed.count()<<endl;

                    /*cout <<"Tempo Cenario 1(VETOR DE OBJETOS)): "<<endl<<elapsed.count()<< endl;
                    cout<<"Iteracao: "<<endl<<j+1<<endl;
                    cout<<"Tamanho: "<<endl<<vetN[i]<<endl;
                    cout<<"Comparacoes: "<<endl<<b.getComparacoes()<<endl;
                    cout<<"Trocas: "<<endl<<b.getTrocas()<<endl;

                    arquivo<<"Tempo cenario 1(VETOR DE OBJETOS):"<<endl<<elapsed.count()<<endl;
                    arquivo<<"Iteracao:"<<endl<<j+1<<endl;
                    arquivo<<"Tamanho:"<<endl<<vetN[i]<<endl;
                    arquivo<<"Comparacoes:"<<endl<<b.getComparacoes()<<endl;
                    arquivo<<"Trocas:"<<endl<<b.getTrocas()<<endl;
                    arquivo<<endl;*/

                }
            }


            arquivo.close();
            break;
        }
        case 2: ///Cenario 2
        {

            arquivo.open ("cenario2.txt");
            int numN = 0; //armazena o número de N's do arquivo
            ifstream infile ("entradaY.txt");
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




            arquivo<<endl<<endl;
            arquivo<<"Algoritmo,Iteracao,Tamanho do Vetor(N),No de Comparacoes,No de Trocas,Tempo"<<endl;

            for(int i=0; i<numN; i++)
            {
                /*
                cout << "----------------------------" << endl;
                arquivo << "----------------------------" << endl;
                cout << "Comeco da iteracao: " << i + 1 << endl;
                arquivo << "Comeco da iteracao: " << i + 1 << endl;
                cout << "Tamanho do Vetor: " << vetN[i] << endl;
                arquivo<< "Tamanho do Vetor: " << vetN[i] << endl;
                cout << "----------------------------" << endl;
                arquivo << "----------------------------" << endl;
                */
                for(int j=0; j<5; j++)
                {

                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(vetN[i], regs, ids);
                    random_shuffle(ids.begin(), ids.end());
                    algoritmosOrdenacao a(ids, vetN[i]); //instanciando objeto para ordenação
                    a.zeraComparacoes();
                    a.zeraTrocas();


                    auto start = std::chrono::high_resolution_clock::now();
                    a.quickSort();
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed = finish - start;
                     arquivo<<"QuickSort,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed.count()<<endl;
                    /*
                    cout << "Quicksort Recursivo CONCLUIDO" << endl;
                    arquivo<<"Tempo QuickSort Recursivo: "<<elapsed.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                        */
                    a.randomiza();
                   // arquivo << endl;

                    a.zeraComparacoes();
                    a.zeraTrocas();

                    auto start1 = std::chrono::high_resolution_clock::now();
                     a.auxQuickSortHibrido();
                    auto finish1 = std::chrono::high_resolution_clock::now();
                   // cout <<"QuickSort com Insercao CONCLUIDO " << endl;
                    std::chrono::duration<long double> elapsed1 = finish1 - start1;
                     arquivo<<"QuickSort com Insercao,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed1.count()<<endl;
                    /*
                    arquivo<<"Tempo QuickSort com Insercao: "<<elapsed1.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                    */
                    a.randomiza();
                   // arquivo << endl;
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();

                    auto start2 = std::chrono::high_resolution_clock::now();
                    a.quickSortMediana();
                    //cout <<"QuickSort Mediana CONCLUIDO " << endl;
                    auto finish2 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed2 = finish2 - start2;
                     arquivo<<"QuickSort Mediana com 3,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed2.count()<<endl;
                    /*
                    arquivo<<"Tempo QuickSort Mediana: "<<elapsed2.count()<<endl;
                    arquivo<<"Numero de comparacoes: ";
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: ";
                    arquivo << a.getTrocas() << endl;
                    */
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();
                    /*
                    arquivo << endl;
                    cout << "//////////////////////////////" << endl;
                    arquivo << "//////////////////////////////" << endl;
                    */
                }
               // cout << "Fim da iteracao: " << i + 1 << endl;
              //  arquivo << "Fim da iteracao: " << i + 1 << endl;
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
            arquivo<<"Algoritmo,Interação,Tamanho do Vetor(N),No de Comparações,No de Trocas,Tempo"<<endl;
            for(int i=0; i<numN; i++)
            {
                /*cout << "----------------------------" << endl;
                arquivo << "----------------------------" << endl;
                cout << "Comeco da iteracao: " << i + 1 << endl;
                arquivo << "Comeco da iteracao: " << i + 1 << endl;
                cout << "Tamanho do Vetor: " << vetN[i] << endl;
                arquivo<< "Tamanho do Vetor: " << vetN[i] << endl;
                cout << "----------------------------" << endl;
                arquivo << "----------------------------" << endl;*/

                for(int j=0; j<5; j++)
                {

                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(vetN[i], regs, ids);
                    random_shuffle(ids.begin(), ids.end());
                    algoritmosOrdenacao a(ids, vetN[i]); //instanciando objeto para ordenação
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();
                    auto start = std::chrono::high_resolution_clock::now();
                    a.quickSort();
                    auto finish = std::chrono::high_resolution_clock::now();
                    //cout << "Quicksort CONCLUIDO" << endl;
                    std::chrono::duration<long  double> elapsed = finish - start;
                    arquivo<<"QuickSort,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed.count()<<endl;
                    /*arquivo<<"Tempo QuickSort:"<<endl<<elapsed.count()<<endl;
                    arquivo<<"Numero de comparacoes:"<<endl;
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas:"<<endl;
                    arquivo << a.getTrocas() << endl;
*/
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();

                    auto start1 = std::chrono::high_resolution_clock::now();
                    a.insertionSort();
                    auto finish1 = std::chrono::high_resolution_clock::now();
                    //cout <<"Insertion CONCLUIDO " << endl;
                    std::chrono::duration<long double> elapsed1 = finish1 - start1;
                    arquivo<<"InsertionSort,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed.count()<<endl;
                    /*arquivo<<"Tempo Insertion:"<<endl<<elapsed1.count()<<endl;
                    arquivo<<"Numero de comparacoes:"<<endl;
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas:"<<endl;
                    arquivo << a.getTrocas() << endl;
                    */
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();


                    auto start2 = std::chrono::high_resolution_clock::now();
                    a.mergeSortAux();
                    auto finish2 = std::chrono::high_resolution_clock::now();
                    //cout <<"MergeSort CONCLUIDO " << endl;
                    std::chrono::duration<long  double> elapsed2 = finish2 - start2;
                    arquivo<<"MergeSort,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed.count()<<endl;
                    /*arquivo<<"Tempo MergeSort: "<<endl<<elapsed2.count()<<endl;
                    arquivo<<"Numero de comparacoes:"<<endl;
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas:"<<endl;
                    arquivo << a.getTrocas() << endl;
                    */
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();


                    auto start3 = std::chrono::high_resolution_clock::now();
                    a.heapSort();
                    //cout <<"HeapSort CONCLUIDO" << endl;
                    auto finish3 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long  double> elapsed3 = finish3 - start3;
                    /*arquivo<<"Tempo HeapSort: "<<endl<<elapsed3.count()<<endl;
                    arquivo<<"Numero de comparacoes: "<<endl;
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: "<<endl;
                    arquivo << a.getTrocas() << endl;
                    */
                    arquivo<<"HeapSort,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed.count()<<endl;
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    a.randomiza();


                    auto start4 = std::chrono::high_resolution_clock::now();
                    a.countSort();
                    //cout <<"CountSort CONCLUIDO" << endl;
                    auto finish4 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<long double> elapsed4 = finish4 - start4;
                    /*arquivo<<"Tempo CountSort: "<<endl<<elapsed4.count()<<endl;
                    arquivo<<"Numero de comparacoes: "<<endl;
                    arquivo << a.getComparacoes() << endl;
                    arquivo<<"Numero de trocas: "<<endl;
                    arquivo << a.getTrocas() << endl;
*/
                    arquivo<<"CountSort,"<<j+1<<","<<vetN[i]<<","<<a.getComparacoes()<<","<<a.getTrocas()<<","<<elapsed.count()<<endl;
                    a.randomiza();
                    a.zeraComparacoes();
                    a.zeraTrocas();
                    //arquivo << endl;
                    /*cout << "//////////////////////////////" << endl;
                    arquivo << "//////////////////////////////" << endl;
*/
                }
            }
            arquivo.close();
            break;
        }


        
        case 4: ///Cenario 4
        {
                       arquivo.open ("cenario4-1.txt");
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
            arquivo<<"Algoritmo,Interação,Tamanho do Vetor(N),No de Comparações"<<endl;
            for(int i=0; i<numN; i++)
            {
                for(int j=0; j<5; j++)
                {
                    vector<registro> regs;
                    vector<int> ids;
                    leituraArquivo(vetN[i], regs, ids);
                    random_shuffle(ids.begin(), ids.end());
                    hashMap *h = new hashMap(vetN[i]);

                    h->insercaoLinear(&regs[j]);
                    arquivo<< "Hash Linear,"<<j<<","<<i<<","<< h->getComparacoes()<< endl;
                    h->insercaoDuploHash(&regs[j],0);
                    arquivo<< "Duplo Hash," <<j<<","<<vetN[i]<<","<< h->getComparacoes() << endl;
                    //h->InsercaoQuadratica(&regs[j],0);
                    //arquivo<< "Numero de comparaçoes Hash Quadratico: " << h->getComparacoes() << endl;
                    h->insereEncadSeparado(&regs[j],0);
                    arquivo<< "Hash Encadeado Separado," <<j<<","<<i<<","<< h->getComparacoes() << endl;
                    h->insercaoEncadCoalescido(&regs[j]);
                    arquivo<< "Hash Encadeado Coalescido," <<j<<","<<i<<","<< h->getComparacoes() << endl;
                }
            }
            arquivo.close()
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
