#include "hashMap.h"
#include "hashNode.h"

hashMap::hashMap(int n){
    tamMax = n+1337;
    tam = 0;
    table = new hashNode*[tamMax];
    for(int i = 0; i<tamMax; i++){ //iniciando todos os valores da tabelo com NULL
    	table[i] = NULL;
    }
    tabela=new list<int>[tamMax];//lista utilizada no encadeamento separado
    numComparacoes = 0;
    colisoes = 0; //utilizada no encadeamento coalescido
}

hashMap::~hashMap(){
    delete [] table;
}

int hashMap::tamanhoMap(){
    return tam;
}

bool hashMap::vazio(){
    if(tam ==0)
        return true;
    else
	return false;
}

int hashMap::hashLinear(int chave, int i){
    return(chave+i)%tamMax;
}

int hashMap::buscaLinear(int chave){
    int i = 0;
    int indice = hashLinear(chave, i);
    while(table[indice] != NULL && table[indice]->getKey() != chave){
    	i++;
	indice = hashLinear(chave, i);
    }
    if(table[indice] == NULL)
	return -1;
    else{
    	return indice;
    }
}

void hashMap::insercaoLinear(registro* reg){
    int i=0;
    int indice = hashLinear(reg->getId(), i);
    numComparacoes++;
    while(table[indice]!=NULL){
	numComparacoes++;
        i++;
	indice = hashLinear(reg->getId(), i);
    }
    table[indice] = new hashNode(reg->getId(), indice, reg);
    tam++;
}

void hashMap::remocaoLinear(int chave){
    int i = 0;
    int indice = hashLinear(chave, i);
    while(table[indice]->getKey() == chave){
    	if(table[indice]->getKey() == chave){
	    hashNode *aux = table[indice];
	    table[indice] =NULL;
	    tam--;
	}
	i++;
	indice = hashLinear(chave, i);
    }
}

//Sondagem Quadratica
int hashMap::hashQuadratica(int chave, int i){
    return(chave+(i*i));
}

int hashMap::buscaQuadratica(int chave){
    int i= 0;
    int indice = hashQuadratica(chave, i);
    while(table[indice] != NULL && table[indice]->getKey() != chave){
    	i++;
	indice = hashQuadratica(chave, i);
    }
    if(table[indice] == NULL)
    	return -1;
    else
	return indice;
}

void hashMap::InsercaoQuadratica(registro* chave, int valor){
    int i = 0;
    int indice = hashQuadratica(chave->getId(),i);
    numComparacoes++;
    while(table[indice] != NULL){
    	numComparacoes++;
	i++;
	indice = hashQuadratica(chave->getId(), i);
    }
    table[indice] = new hashNode(chave->getId(), valor, chave);
    tam++;
}

void hashMap::remocaoQuadratica(int chave){
    int i = 0;
    int indice = hashQuadratica(chave, i);
    while(table[indice] != NULL){
    	if(table[indice]->getKey() == chave){
	    hashNode *aux = table[indice];
	    table[indice] == NULL;
	    tam--;
	}
	i++;
	indice = hashQuadratica(chave, i);
    }
}

//duplo hash

void hashMap::primo(int t){
    primos.clear();
    int n = t;
    int nNew = sqrt(n);
    int marked[n/2 + 500] = {0};
    for(int i = 1; i<=(nNew-1)/2; i++){
        for(int j = (i*(i+1))<<1; j<=n/2; j = j+2*i+1)
                marked[j] = 1;
    }
    primos.push_back(2);

    for(int i = 1; i<=n/2; i++)
        if(marked[i] == 0)
                primos.push_back(2*i + 1);
}

int hashMap::buscaPrimo(int esq, int dir, int n){
    if(esq<=dir){
        int meio = (esq+dir)/2;
        if(meio == 0 || meio == primos.size()-1)
            return primos[meio];

        if(primos[meio] == n)
            return primos[meio-1];
        if(primos[meio] < n && primos[meio+1] > n){
            return primos[meio];
        }
        if(n<primos[meio])
            return buscaPrimo(esq, meio-1, n);
       else
            return buscaPrimo(meio+1, dir, n);
    }
    return 0;
}

int hashMap::hashDuploHash2(int chave){
    primo(tamMax);
    int p = buscaPrimo(0,primos.size()-1,tamMax);
    return(p-(chave%p));
}


int hashMap::hashDuploHash(int chave, int i){
    return(chave+i*hashDuploHash2(chave))%tamMax;
}

int hashMap::buscaDuploHash(int chave){
    int i=0;
    int indice=hashDuploHash(chave,i);
    while(table[indice] != NULL && table[indice]->getKey() != chave)
    {
        i++;
        indice=hashDuploHash(chave,i);
    }
    if(table[indice] == NULL)
        return -1;
    else
    {

        return indice;
    }

}

void hashMap::insercaoDuploHash(registro* chave, int valor){
    int aux = 0;
    int indice = hashDuploHash(chave->getId(), aux);
    numComparacoes++;
    while(table[indice] != NULL){
    	numComparacoes++;
	aux++;
	indice = hashDuploHash2(chave->getId());
    }
    table[indice] = new hashNode(chave->getId(), valor, chave);
    tam++;
}

void hashMap::remocaoDuploHash(int chave, int i){
    int aux = 0;
    int indice = hashDuploHash(chave, aux);
    while(table[indice] != NULL){
        if(table[indice]->getKey() == chave){
	    hashNode *aux = table[indice];
	    table[indice] = NULL;
	    tam--;
	}
	aux++;
	indice = hashDuploHash(chave, aux);
    }    
}

//encadeamento separado

int hashMap::hashEncadSeparado(int chave, int i){
    return (chave+i)%tamMax;
}

int hashMap::buscaEncadSeparado(int chave){
    int i = 0;
    int indice = hashEncadSeparado(chave, i);
    if(table[indice] == NULL){
    	return -1;
    }    
    else{
    	hashNode *no = table[indice];
	while(no!=NULL && no->getKey()!=chave)
	    no = no->getProx();
	if(no == NULL)
		return -1;
	else
		return indice;
    }
}

void hashMap::insereEncadSeparado(registro* chave, int valor){
    int indice = hashEncadSeparado(chave->getId(), 0);
    tabela[indice].push_back(chave->getId());
}

//encadeamento coalescido
unsigned long int hashMap::qtdColisoes(){
     return colisoes;
}

int hashMap::hashEncadCoalescido(int chave){
    return chave%tamMax;
}

int hashMap::encontraProxPosicao(){
    return colisoes;
}

void hashMap::insercaoEncadCoalescido(registro *chave){
    hashNode *novo = new hashNode(chave->getId(), 0, chave);
    int indice = hashEncadCoalescido(chave->getId());
    while(table[indice] !=NULL && table[indice]->getKey()!= -1 && ((table[indice]->getKey() != chave->getId()) || (table[indice]->getKey() == chave->getId()) || (table[indice]->getKey() != chave->getId()))){
    	numComparacoes++;
	if(table[indice]->getProxChave() == -1){
	   numComparacoes++;
	   table[indice]->setProxChave(encontraProxPosicao());
	}
    }
    if(table[indice] == NULL || table[indice]->getKey() == -1){
    	numComparacoes++;
	tam++;
    }
    else{
    	novo->setProxChave(table[indice]->getProxChave());
    }
    table[indice] = novo;
}

void hashMap::buscaEncadCoalescido(registro* chave, int valor){
    int indice = hashEncadCoalescido(chave->getId());
    while(table[indice]!=NULL){
    	if(table[indice]->getKey()!=-1 && table[indice]->getKey() == chave->getId()){
	    //cout<<"indice: "<<indice<<" id: "<<table[indice]->getKey()<<" user: "<<table[indice]->getUser()<<" rating: "<< table[indice]->getRating()<<endl;
	    return;
	}
	indice = table[indice]->getProxChave();
    }
    cout<< "nao existe"<<endl;
    return;
}

void hashMap::imprimeHash()
{
    for(int i=0; i<tamMax; i++)
    {
        if(table[i] != NULL && table[i]->getKey() != -1)
        {
            //cout<<"key: "<<table[i]->getKey()<<"  value: "<<table[i]->getValue()<<endl;

            cout<<"i:"<<i<<"  "<<table[i]->getKey()<<" | ";

        }
    }
}


void hashMap::imprimeHashEncad()
{
    for (int i = 0; i < tamMax; i++)
    {
        cout << i;
        for (auto x : tabela[i])
            cout << " --> " << x;
        cout << endl;
    }

}

