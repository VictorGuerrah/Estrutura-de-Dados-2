#include "hashMap.h"
#include "hashNode.h"

hashMap::hashMap(int tamanho){
    //ctror
    tam = 0;
    tamMax = tamanho;
    tabela = new hashNode*[tamMax];
    for(int i = 0; i<tamMax; i++){
        tabela[i] = NULL;
    }
}

hashMap::~hashMap(){
    //dtror
    delete[] tabela;
}

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
int hashMap::hash(int chave){
    primo(tamMax);
    int p = buscaPrimo(0, primos.size()-1, tamMax);
    return (chave % p)%tamMax;
}

int hashMap::hash2(int chave, int i){
        primo(tamMax);
        int p = buscaPrimo(0, primos.size()-1, tamMax);
        return (i + (chave%p));
}

void hashMap::sondagemLinear(registro* reg){
    int posicao = hash(reg->getId());
    bool marcador = 0;
    if(tam<tamMax){
        for(int i = posicao; i<tamMax; i++){
            if(tabela[i] == NULL){
                hashNode* h = new hashNode(reg->getId(), i, reg) ;
                tabela[i] = h;
                tam++;
                marcador = 1;
                break;
            }
        }
        if(marcador == 0)
            for(int i = 0; i <posicao; i++){
                if(tabela[i] == NULL){
                   hashNode *aux = new hashNode(reg->getId(), i,reg);
                   tabela[i] = aux;
                   tam++;
                   marcador = 1;
                   break;
                }
            }
    }
    else
        cout<<"erro-tabela cheia"<<endl;
}

void hashMap::sondagemQuadratica(registro* reg){
    int j = 0;
    int chave = reg->getId();
    int p = hash(chave+j*j);
    while(tabela[p] != NULL && j<tamMax){
        j++;
        p = hash(chave+ j*j);
   }
    if(j >= tamMax){
        cout<<"erro-tabela cheia"<<endl;
    }
    else{
        hashNode* h = new hashNode(reg->getId(), p,reg);
        tabela[p] = h;
        tam++;
    }
}

void hashMap::duploHash(registro* reg){
   int chave = reg->getId();
   if (tam == tamMax){
        cout<<"erro - tabela cheia"<<endl;
        return;
   }
   else{
        int indice = hash(chave);
        if(tabela[indice] != NULL){
            int indice2 = hash2(chave, 0);
            int i = 1;
            while(1){
                int indice3 = (indice + i*indice2)%tam;
                if(tabela[indice3] == NULL){
                   hashNode* h =  new hashNode(reg->getId(), indice3,reg);
                   tabela[i] = h;
                   break;
                }
                i++;
            }
        }
        else{
            hashNode* h = new hashNode(reg->getId(), indice, reg);
            tabela[indice] = h;
            tam++;
        }
   }
}

void hashMap::encadSeparado(registro* reg){
    int chave = reg->getId();
    if(tam!=tamMax){
        int posicao = hash(chave);
        if(tabela[posicao] == NULL){
            hashNode* h = new hashNode(reg->getId(), posicao, reg);
            tabela[posicao] = h;
            tam++;
        }
        else{
            if(tam/tamMax <1){
                hashNode* h = new hashNode(reg->getId(), posicao, reg);
                (tabela[posicao])->setProx(h);
                (tabela[posicao])->setProxChave(reg->getId());
                tam++;
            }
            else{
                cout<<"erro-tabela cheia"<<endl;
            }
        }
    }
    else
        cout<<"erro-tabela cheia"<<endl;
}
