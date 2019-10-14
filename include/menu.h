#ifndef MENU_H
#define MENU_H
#include "registro.h"
#include <bits/stdc++.h>
#include <list>
#include <iterator>
#include <vector>

using namespace std;

class menu
{
    public:
        menu();
        ~menu();
        void exibirMenu();
	void leituraArquivo(int N, vector<registro>& lista, vector<int>& listaId);
    private:
};

#endif // MENU_H
