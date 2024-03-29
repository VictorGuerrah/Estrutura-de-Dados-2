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
        hashNode* primeiro;

        int proxChave;

   public:
        hashNode();
        hashNode(int chave, registro* reg);
        hashNode(int chave, int indice, registro* reg);
        ~hashNode();

        void setKey(int chave);
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
