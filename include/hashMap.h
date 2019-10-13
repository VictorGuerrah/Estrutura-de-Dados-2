#ifndef HASHMAP_H
#define HASHMAP_H
#include "hashNode.h"
#include <iostream>
#include "registro.h"
#include <vector>
#include <string>
#include "registro.h"
#include <cmath>

using namespace std;

class hashMap{

    private:
        int tamMax;
        int tam;
        vector<int> primos;
        hashNode** tabela; //tabela usada pela sondagem linear, sondagem quadratica e duplo hash

    public:
        //funcoes de hash
        int hash(int chave);
        int hash2(int chave, int i);
        void primo(int t);
        int buscaPrimo(int esq, int dir, int n);

        //tratamento de colisão
        void sondagemLinear(registro* reg);
        void sondagemQuadratica(registro* reg);
        void duploHash(registro* reg);
        void encadSeparado(registro* reg);
        void encadCoalescido(registro* reg);

        hashMap(int tamanho);
        ~hashMap();
};

#endif //HASH_MAP
