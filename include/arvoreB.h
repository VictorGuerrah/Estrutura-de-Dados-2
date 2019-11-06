#ifndef ARVOREB_H
#define ARVOREB_H
#include <iostream>
#include "bNode.h"

class bNode;

class arvoreB{
    private:
	bNode* raiz; //ponteiro para o noh da arvore
	int t; //grau minimo

    public:
	arvoreB(int t); //construtor
	~arvoreB(); //destrutor
	void percorre(); //percorre a arvore
	bNode* procura(int k); // procura a chave k na arvore
	void insere(int k);
	void remove(int k);
};
#endif //ARVOREB_H
