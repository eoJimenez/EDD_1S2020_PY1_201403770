#include "ListaDCircular.h"
#include <iostream>
#include <string>

using namespace std;
std::string cadena;

//CLASE LISTA DOBLE CIRCULAR
    //CONSTRUCTOR
ListaDCircular::ListaDCircular()
{
   primero = NULL;
   ultimo = NULL;
}

//MÉTODOS
ListaDCircular::agregarLista(string cadena)
{
    nodoD *temp = new nodoD(cadena);
    if(primero != NULL)
    {
        primero->siguiente = temp;
        temp->anterior = primero;
        ultimo = temp;
        ultimo->siguiente = primero;
        primero->anterior = ultimo;
    }
    else
    {
        primero = temp;
        ultimo = temp;
    }
}

ListaDCircular::ImprimirLista()
{
    nodoD *temp = primero;
    while(temp != NULL)
        {
            cout << "Dato:" << temp->palabra << endl;
            temp = temp->siguiente;
        }
}

nodoD::nodoD(string cadena)
{
    siguiente = NULL;
    anterior = NULL;
    palabra = cadena;
}

ListaDCircular::~ListaDCircular()
{
    //dtor
}
