#include <iostream>
using namespace std;

struct nodo{
    int n;
    nodo* sig;
};

struct cola
{
    nodo* delante;
    nodo* atras;
};

struct cola q;

q.delante = NULL;
q.detras = NULL;