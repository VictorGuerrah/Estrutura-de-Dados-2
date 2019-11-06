#include <iostream>
#include "arvoreB.h"
#include "bNode.h"

using namespace std;

arvoreB::arvoreB(int t)
{
    raiz = NULL;
    this->t = t;
    //ctor
}

arvoreB::~arvoreB()
{
    //dtor
}

void arvoreB::percorre()
{
    if(raiz != NULL)
    {
        raiz->percorre();
    }
    else
    {
        cout<<"arvore vazia"<<endl;
    }
}


bNode* arvoreB::procura(int k)
{
    if(raiz == NULL)
    {
        return NULL;
    }
    else
        return raiz->busca(k);
}

void arvoreB::insere(int k)
{
    // Se a arvore estiver vazia
    if(raiz == NULL)
    {
        // Aloca memoria para raiz
        raiz = new bNode(t,true);
        raiz->chave[0] = k; // Insere chave
        raiz->n = 1; // Atualiza o numero de chaves na raiz

    }
    else // Se a arvore nao estiver vazia
    {
        //Se a raiz esta cheia, entao a arvore cresce em altura
        if(raiz->n == 2*t-1)
        {
            //Aloca memoria para nova raiz
            bNode *s = new bNode(t, false);

            //Fazer a raiz antiga virar filha da nova
            s->filhos[0] = raiz;

            //Dividi a antiga raiz e move uma chave para a nova raiz
            s->divideFilho(0, raiz);

            //Nova raiz tem dois filhos agora. Decide qual dos dois filhos vai ter a nova chave
            int i = 0;
            if(s->chave[0] < k)
                i++;
            s->filhos[i]->insereNonFull(k);

            //Muda a raiz
            raiz = s;
        }
        else // Se a raiz nao esta cheia, chama a funcao insereNonFull para a raiz
            raiz->insereNonFull(k);
    }
}

void bNode::insereNonFull(int k)
{
    //Inicializa o indice como indice do elemento mais a direita
    int i = n-1;

    //Se esse no eh folha
    if(folha == true)
    {
        // O while faz duas coisas:
        // 1) Encontra a localizacao da chava e a ser inserida
        // 2) Move todas as maiores chaves para um espaco a frente
        while(i >=0 && chave[i] > k)
        {
            chave[i+1] = chave[i];
            i--;
        }
        // Insere a nova chave no local encontrado
        chave[i+1] = k;
        n = n + 1;
    }
    else // Se esse no nao for folha
    {
        //Encontra o filho que tera a nova a chave
        while (i >= 0 && chave[i] > k)
            i--;
        //Verifica se o no filho esta cheio
        if (filhos[i+1]->n == 2*t -1)
        {
            //Se o filho esta cheio, divide ele
            divideFilho(i+1, filhos[i+1]);

            //Apos dividir, a chave do meio de filhos[i] vai para cima
            // e C[i] eh dividido em 2. Verifica qual dos dois tera
            // a nova chave
            if(chave[i+1] < k)
                i++;

        }
        filhos[i+1]->insereNonFull(k);

    }
}
