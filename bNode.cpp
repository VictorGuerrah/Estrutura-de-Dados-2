#include <iostream>
#include "bNode.h"

using namespace std;

bNode::bNode(int t, bool folha){
    this->t = t;
    this->folha = folha;
    chave = new int[2*t - 1];
    filhos = new bNode*[2*t];
    n = 0;
    //ctor
}

bNode::~bNode(){
    //dtor
}

void bNode::percorre(){
    int i;
    for(i = 0; i<n; i++){
    	if(!folha)
	    filhos[i]->percorre();
	cout<<" "<<chave[i];
    }
    if(!folha)
	filhos[i]->percorre();
}

bNode *bNode::busca(int k){
    int i = 0;
    while(i < n && k>chave[i])
        i++;

    if(chave[i] == k)
	return this;
	
    if(folha)
	return NULL;

    return filhos[i]->busca(k);
}

