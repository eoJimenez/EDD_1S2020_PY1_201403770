#include "ListaValidacion.h"
#include "ListaDoble.h"
#include <iostream>
#include <string>

using namespace std;
ListaDoble doble;
ListaValidacion::ListaValidacion()
{
    primero = NULL;
    ultimo = primero;
}

void ListaValidacion::agregarNodo(int x, int y, char c)
{
    if(primero != NULL)
    {
        ultimo->siguiente = new nodoValidacion(x,y,c);
        ultimo = ultimo->siguiente;
    }
    else
    {
        primero = new nodoValidacion(x,y,c);
        ultimo = primero;
    }
}
void ListaValidacion::imprimirLista()
{
    nodoValidacion *aux = primero;
    while(aux != NULL)
    {
        cout << doble.getIntToString(aux->xpos) << ",";
        cout << doble.getIntToString(aux->ypos) << ",";
        cout << doble.getString(aux->letra) << endl;
        aux = aux->siguiente;
    }
}
bool ListaValidacion::buscarColumna()
{
    bool encontrado = false;
    if(primero->xpos == primero->siguiente->xpos)
    {
        encontrado = true;
        return true;
    }
    return encontrado;
}
bool ListaValidacion::buscarFila()
{
    bool encontrado = false;
    if(primero->ypos == primero->siguiente->ypos)
    {
        encontrado = true;
        return encontrado;
    }
    return encontrado;
}
int ListaValidacion::retornarColumna()
{
    if(primero != NULL)
    {
        return primero->xpos;
    }
}
int ListaValidacion::retornarFila()
{
    if(primero != NULL)
    {
        return primero->ypos;
    }
}
ListaValidacion::~ListaValidacion()
{
    //dtor
}

nodoValidacion::nodoValidacion(int x, int y, char l)
{
    siguiente = NULL;
    xpos = x;
    ypos = y;
    letra = l;
}
