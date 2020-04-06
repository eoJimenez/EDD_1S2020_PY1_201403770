#include "SimpleTriples.h"

SimpleTriples::SimpleTriples()
{
    primero = NULL;
    ultimo = primero;
}
void SimpleTriples::agregarTriple(int x, int y)
{
    if(primero != NULL)
    {
        ultimo->siguiente = new nodoSimpleTriple(x,y);
        ultimo = ultimo->siguiente;
    }
    else
    {
        primero = new nodoSimpleTriple(x,y);
        ultimo = primero;
    }
}
void SimpleTriples::imprimir()
{
    nodoSimpleTriple *aux = primero;
    while(aux != NULL)
    {
        cout << getIntToString(aux->posx)<< ",";
        cout << getIntToString(aux->posy)<< endl;
        aux = aux->siguiente;
    }
}
string SimpleTriples::getIntToString(int i)
{
    string str = to_string(i);
    return str;
}
SimpleTriples::~SimpleTriples()
{
    //dtor
}
nodoSimpleTriple::nodoSimpleTriple(int x, int y)
{
    siguiente = NULL;
    posx = x;
    posy = y;
}
