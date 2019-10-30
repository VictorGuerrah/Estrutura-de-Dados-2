#ifndef BNODE_H
#define BNODE_H
#include <iostream>

class bNode{
    private:
    	int* chave; //vetor de chaves
    	int t; //grau minimo
    	bNode** filhos; //vetor de ponteiros para filhos
    	int n; //numero atual de chaves
    	bool folha; //eh 1 se o no for uma folha e 0 se nao

    public:
	bNode(int t, bool folha); //construtor
	~bNode(); //destrutor
	void percorre(); //funcao percorre todos os nos da subarvore com raiz no no que chamou o percorre
	bNode* busca(int k); //funcao que procura a chave k na subarvore com a raiz no noh que chamou a funcao busca
	void insereNonFull(int k); // funcao utilizada para inserir uma nova chave na subarvore com raiz nesse no. O no deve ter espaco quando essa funcao eh chamada
	void divideFilho(int i, bNode *y); // funcao utilizada para dividir os filhos de um no, i eh o indice do vetor filhos. Os filhos do no devem estar cheios.


};
#endif //BNODE_H
