#ifndef MENU_H
#define MENU_H
#include "registro.h"
#include <bits/stdc++.h>
#include <list>
#include <iterator>

class menu
{
    public:
        menu();
        ~menu();
        void exibirMenu();
        void leituraArquivo(int N, list<registro>& lista);

    private:
};

#endif // MENU_H
