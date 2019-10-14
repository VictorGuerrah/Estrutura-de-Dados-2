#ifndef HASHMAP_H
#define HASHMAP_H
#include "hashNode.h"
#include <iostream>
#include "registro.h"
#include <list>
#include <string>
#include "registro.h"
#include <cmath>
#include <vector>

using namespace std;

class hashMap{

    private:
        hashNode **table;
	vector<int> primos;
	int tamMax;
        int tam;
	list<int> *tabela;
	unsigned long int numComparacoes;
	long colisoes;

    public:
        hashMap(int n);
	~hashMap();
        
	//sondagem linear
	int buscaLinear(int chave);
	void insercaoLinear(registro* reg);
	void remocaoLinear(int chave);
	int hashLinear(int chave, int i);

	//sondagem quadratica
	int buscaQuadratica(int chave);
	void InsercaoQuadratica(registro* chave, int valor);
	void remocaoQuadratica(int chave);
	int hashQuadratica(int chave, int i);
	
	//duploHash
	int buscaDuploHash(int chave);
	void insercaoDuploHash(registro* chave, int valor);
	void remocaoDuploHash(int chave, int i);
	int hashDuploHash(int chave, int i);
	int hashDuploHash2(int chave);
	
	//Encadeamento separado
	int buscaEncadSeparado(int chave);
	void insereEncadSeparado(registro* chave, int valor);
	void remocaoEncadSeparado(int chave, int i);
	int hashEncadSeparado(int chave, int i);

	//Encadeamento coalescido
	unsigned long int qtdColisoes();
	void insercaoEncadCoalescido(registro *chave);
	void buscaEncadCoalescido(registro* chave, int valor);
	int hashEncadCoalescido(int chave);
	int encontraProxPosicao();
	
	//funcoes auxiliares
	void primo(int t);
	int buscaPrimo(int esq, int dir, int n);
	int tamanhoMap();
	bool vazio();
	void setTam(int novo){tam = novo;};
	void imprimeHash();
	void imprimeHashEncad();
	int getTamanho(){return tam;};

	unsigned long int getComparacoes(){return numComparacoes;};
};

#endif //HASH_MAP
