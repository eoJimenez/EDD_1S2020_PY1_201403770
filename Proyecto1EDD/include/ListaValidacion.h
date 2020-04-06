#ifndef LISTAVALIDACION_H
#define LISTAVALIDACION_H
#include <iostream>
#include <string>
using namespace std;

class nodoValidacion
{
public:
    nodoValidacion *siguiente;
    int xpos;
    int ypos;
    char letra;
    nodoValidacion(int,int,char);
};

class ListaValidacion
{
    public:
        ListaValidacion();

        nodoValidacion *primero, *ultimo;
        void agregarNodo(int,int,char);
        void imprimirLista();
        bool buscarColumna();
        bool buscarFila();
        int retornarColumna();
        int retornarFila();

        virtual ~ListaValidacion();

    protected:

    private:
};

#endif // LISTAVALIDACION_H
