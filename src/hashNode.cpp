#include "hashNode.h"
#include <iostream>

using namespace std;

hashNode::hashNode(){
    //ctor
}

hashNode::hashNode(int chave, int indice, registro* reg){
    //ctor
    this->chave = chave;
    this->indice = indice;
    this->reg = reg;
    prox = NULL;
    ant = NULL;
    primeiro = NULL;
    proxChave = -1;
}

hashNode::hashNode(int indice, registro* reg){
    //ctor
    chave = reg->getId();
    this->indice = indice;
    this->reg = reg;
    prox = NULL;
    ant = NULL;
    primeiro = NULL;
    proxChave = -1;
}

hashNode::~hashNode(){
    //dtor
}

void hashNode::setKey(int chave){
    this->chave = chave;
}

int hashNode::getKey(){
    return chave;
}

void hashNode::setIndice(int indice){
    this->indice = indice;
}

int hashNode::getIndice(){
    return indice;
}

hashNode* hashNode::getProx(){
    return prox;
}

void hashNode::setProx(hashNode* prox){
    this->prox = prox;
}

hashNode* hashNode::getAnt(){
    return ant;
}

void hashNode::setAnt(hashNode* ant){
    this->ant = ant;
}

void hashNode::setProxChave(int chave){
    this->proxChave = chave;
}

int hashNode::getProxChave(){
    return proxChave;
}
