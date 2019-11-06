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
	int encontraChave(int k);//funcao que retorna o indice da primeira chave que for maior ou igual a k
	void insereNonFull(int k); // funcao utilizada para inserir uma nova chave na subarvore com raiz nesse no. O no deve ter espaco quando essa funcao eh chamada
	void divideFilho(int i, bNode *y); // funcao utilizada para dividir os filhos de um no, i eh o indice do vetor filhos. Os filhos do no devem estar cheios.
	void remove(int k); //Funcao responsavel pela remocao da chave e da adaptacao dos filhos que compoem da mesma
	void removeFolha(int i); //Funcao remove a chave k desde que o mesmo seja uma folha
	void removeNoInterno(int i); // funcao remoca a chave k desde que o mesmo nao seja uma folha
	int getAnt(int k); //retorna a chave anterior a chave k, presente em um mesmo no
	int getProx(int k); //retorna a chave seguinte a k, presente em um mesmo no
	void preenche(int p); //funcao preenche o no filho na posicao p dentro do vetor filhosse o mesmo tiver espaco
	void pegaAnt(int p); //funcao pega a chave anterior filhos[p-1] e coloca em filhos[p]
	void pegaProx(int p); //funcao pega a prox chave filhos[p+1] e coloca em filhos[p]
	void merge(int p);//funcao que junta o filho p de um no com o filho p+1
    friend class arvoreB;
};
#endif //BNODE_H
