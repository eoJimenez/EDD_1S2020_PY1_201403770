#include "SimpleDobles.h"
#include <iostream>
using namespace std;

SimpleDobles::SimpleDobles()
{
    primero = NULL;
    ultimo = primero;
}
void SimpleDobles::agregar(int x, int y)
{
    if(primero != NULL)
    {
        ultimo->siguiente = new nodoSimpleDoble(x,y);
        ultimo = ultimo->siguiente;
    }
    else
    {
        primero = new nodoSimpleDoble(x,y);
        ultimo = primero;
    }
}
void SimpleDobles::imprimir()
{
    nodoSimpleDoble *tempo = primero;
    while(tempo != NULL)
    {
        cout << IntToString(tempo->posx)<< ",";
        cout << IntToString(tempo->posy) << endl;
        tempo = tempo->siguiente;
    }
}

SimpleDobles::~SimpleDobles()
{
    //dtor
}

nodoSimpleDoble::nodoSimpleDoble(int x, int y)
{
    siguiente = NULL;
    posx = x;
    posy = y;
}

string SimpleDobles::IntToString(int i)
{
    string str = to_string(i);
    return str;
}
