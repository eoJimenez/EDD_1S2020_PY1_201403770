#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <string>
using namespace std;

class NodoSimple;

class ListaSimple
{
    public:
        ListaSimple();

        NodoSimple *primero, *ultimo;
        void agregarNodo(string);
        void imprimir();
        void graficarLista();
        void graficaInorden();
        void graficaPostorden();
        string DefinirNodo();
        string apuntador();

        virtual ~ListaSimple();

    protected:

    private:
};

//CLASE NODO SIMPLE
class NodoSimple
{
    public:
        NodoSimple* siguiente;
        string palabra;

        NodoSimple(string);
        //virtual ~NodoSimple();

    protected:

    private:

};

#endif // LISTASIMPLE_H
