#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <ostream>
#include <fstream>
#include "ListaOrdenada.h"

using namespace std;

class NodoArbol;

class ArbolBB
{

    public:
        NodoArbol *raiz;
    //CONSTRUCTOR
        ArbolBB();
    //DESTRUCTOR
    //~ArbolBB();
    //MÉTODOS
        void insertarABB(string key);
        NodoArbol *buscar(string key);
        NodoArbol *EliminarNodo(string key);

        void recorridoPre();
        void recorridoIn();
        void recorridoPost();
    //void destroy_arbol();
        void graficar();
        void graficarInorder();
        ///METODOS DEL MENU
        void seleccionarJugador();


    private:
        //void destroy_arbol(NodoArbol *hoja);

        void insertarABB(string key, NodoArbol *hoja);
        NodoArbol *buscar(string key, NodoArbol *hoja);
        NodoArbol *eliminar(string key, NodoArbol *hoja);
        //RECORRIDOS
        void recorridoPreorden(NodoArbol*);
        void recorridoInorden(NodoArbol*);
        void recorridoPostorden(NodoArbol*);
        //GRAFICA ARBOL
        void graficaArbol(NodoArbol*);
        string getCodigoInterno(NodoArbol*);
        //GRAFICA DE RECORRIDOS
        void graficaPreOrden(NodoArbol*);
        void graficaInOrden(NodoArbol*);
        string getInorder(NodoArbol*);
        void graficaPostOrden(NodoArbol*);
};
//CLASE NODO
class NodoArbol
{
public:
    NodoArbol *izquierda, *derecha;
    string dato;
    //CONSTRUCTOR
    NodoArbol(string);
};
#endif // ARBOLBB_H
