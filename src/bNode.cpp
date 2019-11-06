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

int bNode::encontraChave(int k){
    int indice = 0;
    while(indice<n && chave[indice] <k){
    	indice++;
    }
    return indice;
}

void bNode::remove(int k){
    int i = encontraChave(k);
    //se a chave esta presente no noh
    if(i<n && chave[i] == k){
	//removemos ela, sendo folha ou nao
    	if(folha)
	    removeFolha(i);
	else
	    removeNoInterno(i);
    }
    //caso a chave nao esteja no noh
    else{
    	//se o no for folha, a chave nao esta presente na arvore
	if(folha){
	    cout<<"A chave "<<k<<" nao se encontra na arvore"<<endl;
	    return ;
	}
	//Ou se a chave pode estar presente em uma subarvore com raiz nesse no
	bool flag; //a flag indica se a chave esta presente na subarvore com a raiz no ultimo filho desse no
	if(i == n)
	    flag = true;
	else
	    flag = false;
        if(filhos[i]->n < t)
	    preenche(i);
        if (flag && i > n) 
            filhos[i-1]->remove(k); 
        else
            filhos[i]->remove(k); 
    } 
}

void bNode::removeFolha(int i){
    //move todas as chaves depois do indice i para um a esquerda
    for(int j = i+1; j<n; ++j)
    	chave[i-1] = chave[i];
    //diminui 1 no contador de chaves
    n--;
}

void bNode::removeNoInterno(int i){
    int k = chave[i];
    //se o filho anterior a k tem pelo menos t chaves, encontra o anterior, substitui k pela chave anterior e remove anterior do no que se encontrava
    if(filhos[i]->n >= t){
    	int ant = getAnt(i);
	chave[i] = ant;
	filhos[i]->remove(ant);
    }
    //Se o filho filho[i] tem menos de t chaves, inspecionar filho[i+1]
    //caso o filho filho[i+1] tenha pelo menos t chaves, encontrar a proxima chave de k na subarvore com a raiz em filho[i+1], entao substituir o k pelo prox e recursivamente deletar o prox no filho[i+1]
    else if(filhos[i+1]->n >= t){
    	int prox = getProx(i);
	chave[i] = prox;
	filhos[i+1]->remove(prox);
    }
    //se filhos[i] e filhos[i+1] tem menos de t chaves, fundiremos k e todos as chaves de filhos[i+1] em filhos[i], assim filhos[i+1] tera 2*t-1 chaves
    else{
        merge(i);
        filhos[i]->remove(k);
    }
}

int bNode::getAnt(int k){
    //ir ate a folha mais a direita da arvore
    bNode *atual=filhos[k]; 
    while (!atual->folha) 
        atual = atual->filhos[atual->n]; 
  
    //retorna a ultima chave da folha 
    return atual->chave[atual->n-1]; 
}

int bNode::getProx(int k){
    //ir ate a folha mais a esquerda, comecao de filhos[i+1]
    bNode *atual = filhos[k+1];
    while (!atual->folha)
        atual = atual->filhos[0];

    //retorna a primeira chave da folha
    return atual->chave[0];
} 

void bNode::preenche(int p){
    //Se o filho anterior tem menos de t-1 chave, pegamos uma chave desse filho
    if (p!=0 && filhos[p-1]->n>=t) 
        pegaAnt(p); 
    //Se o proximo filho de filhos[p+1] tem mais de t-1 chaves, pegarenos uuma chave desse filho
    else if (p!=n && filhos[p+1]->n>=t) 
        pegaProx(p); 
    //Funde filho[p] com os seus irmaos, caso filhos[p] for o ultimo filho, fundiremos ele com o seus irmaos anteriores e, caso contrario, fundiremos ele com os proximos irmaos 
    else
    { 
        if (p != n) 
            merge(p); 
        else
            merge(p-1); 
    } 
}

void bNode::pegaAnt(int p){
    bNode* filho = filhos[p];
    bNode* irmao = filhos[p-1];
    //Movendo todas as chaves de filhos[p] para frente 
    for (int i=filho->n-1; i>=0; --i) 
        filho->chave[i+1] = filho->chave[i];

    if (!filho->folha) 
    {
	//move todos os seus filhos para frente 
        for(int i=filho->n; i>=0; --i) 
            filho->filhos[i+1] = filho->filhos[i]; 
    } 
    filho->chave[0] = chave[p-1]; 
  
    if(!filho->folha) 
        filho->filhos[0] = irmao->filhos[irmao->n]; 
  
    filhos[p-1] = irmao; 
  
    filho->n += 1; 
    irmao->n -= 1; 
} 

void bNode::pegaProx(int p){
    bNode *filho=filhos[p]; 
    bNode *irmao=filhos[p+1]; 
  
    //chave[p] eh inserida como a ultima chave de filhos[p] 
    filho->chave[(filho->n)] = chave[p]; 
  
    //O primeiro chave do irmao eh inserido como o ulimo filho 
    if (!(filho->folha)) 
        filho->filhos[(filho->n)+1] = irmao->filhos[0]; 
  
    //A primeira chave do irmao eh inserida em chaves[p] 
    chave[p] = irmao->chave[0]; 
  
    //move todas as chaves do irmao para tras 
    for (int i=1; i<irmao->n; ++i) 
        irmao->chave[i-1] = irmao->chave[i]; 
  
    //Move os ponteiros dos filhos para tras 
    if (!irmao->folha){ 
        for(int i=1; i<=irmao->n; ++i) 
            irmao->filhos[i-1] = irmao->filhos[i]; 
    } 
    filho->n += 1; 
    irmao->n -= 1; 
} 

void bNode::merge(int p){
   bNode* filho = filhos[p];
   bNode *irmao = filhos[p+1]; 
  
    //Pegar uma chave do noh atual e inserir na posicao (t-1) filhos[p] 
    filho->chave[t-1] = chave[p]; 
  
    //Copia a chave de filhos[p+1] para filho[p] 
    for (int i=0; i<irmao->n; ++i) 
        filho->chave[i+t] = irmao->chave[i]; 
  
    //Copia os ponteiros do filho filhos[p+1] para filhos[p] 
    if (!filho->folha) 
    { 
        for(int i=0; i<=irmao->n; ++i) 
            filho->filhos[i+t] = irmao->filhos[i]; 
    } 
  
    //Move todas as chaves depois de p no noh atual  
    for (int i=p+1; i<n; ++i) 
        chave[i-1] = chave[i]; 
  
    //Move os ponteiros dos ponteiros dos filhos depois de p+1 do no atual 
    for (int i=p+2; i<=n; ++i) 
        filhos[i-1] = filhos[i]; 
  
    filho->n += irmao->n+1; 
    n--; 
  
    delete(irmao);  
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


void bNode::divideFilho(int i, bNode *y){
    //cria um novo noh para armazenar (t-1) chave do noh y
    bNode *z = new bNode(y->t, y->folha);
    z->n = t-1;

    //copia as ultimas (t-1) chaves de y para z
    for(int j = 0; j < t-1; j++)
    	z->chave[j] = y->chave[j+t];

    //copia os t ultimos filhos de y para z
    if(y->folha == false)
	for(int j = 0; j<t; j++)
	    z->filhos[j] = y->filhos[j+t];

    //decrementa o numero de chaves armazenadas em y
    y->n = t-1;

    //cria espaco para o novo filho
    for(int j = n; j>=1+i; j--)
	    filhos[j+1] = filhos[j];
    filhos[i+1] = z;

    //a chave do meio de y vai mudar para o novo no e vai shiftar todas as chaves maiores que ela para a direita
    for(int j = n-1; j >= i; j--)
    	chave[j+1] = chave[j];
    chave[i] = y->chave[t-1];
    n++;
}
