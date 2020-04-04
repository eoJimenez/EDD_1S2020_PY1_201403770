#ifndef LISTADCIRCULAR_H
#define LISTADCIRCULAR_H
#include <iostream>
#include <string>

using namespace std;
string s;
class nodoD;

class ListaDCircular
{
public:
    ListaDCircular();


    void EliminarNodo();
    void ImprimirLista();
    void agregarLista(string);

    virtual ~ListaDCircular();

protected:

private:
    nodoD *primero;
    nodoD *ultimo;
};

class nodoD
{
public:
    //CONSTRUCTOR
    nodoD(string);

    nodoD *siguiente, *anterior;
    string palabra;

};

#endif // LISTADCIRCULAR_H
