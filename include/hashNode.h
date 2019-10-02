#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
#include <list>
#include "registro.h"

using namespace std;

class hashNode
{
    private:
	int chave;
	registro* reg;
	int indice;
	//Tabela Encadeada
	hashNode* prox;
	hashNode* ant;
	int proxChave;

   public:
	hashNode(int chave, int indice, registro* reg);
	~hashNode();
	
	int getKey();
	
	int getIndice();
	void setIndice(int indice);

	hashNode* getProx();
	void setProx(hashNode* prox);

	hashNode* getAnt();
	void setAnt(hashNode* prox);

	void setProxChave(int chave);
	int getProxChave();
};

#endif //HASHNODE_H
