#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include <string>
using namespace std;

class NodoLista;

class ListaOrdenada
{
    public:
        NodoLista *primero, *ultimo;

        //CONSTRUCTOR
        ListaOrdenada();
        void graficarLista(string);
        string DefinirNodo();
        string apuntador();
        string intToString(int valor);
        void agregarPuntaje(int);
        void ImprimirPuntaje();

    protected:

    private:
};

//CLASE NODO LISTA ORDENADA
class NodoLista
{
public:
    NodoLista *siguiente;
    int puntaje;
    //CONSTRUCTOr
    NodoLista(int);
};

#endif // LISTAORDENADA_H
