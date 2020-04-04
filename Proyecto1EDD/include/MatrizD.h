#ifndef MATRIZD_H
#define MATRIZD_H
#include <string>
#include <iostream>
using namespace std;
class NodoM
{
public:
    NodoM(int,int,char);
    char caracter;
    int fila;
    int columna;

    NodoM *arriba;
    NodoM *abajo;
    NodoM *siguiente;
    NodoM *anterior;
};
class MatrizD
{
    public:
        MatrizD();
        NodoM *root;
        NodoM *columna;
        NodoM *Fila;
        NodoM *nuevo;
        NodoM *NodoC;
        NodoM *NodoF;
        NodoM *nodoNuevo;
        NodoM *buscarFila(int fila);
        NodoM *buscarColumna(int columna);
        NodoM *insertarOrdenadoColumna(NodoM *nuevo,NodoM *cabCol);
        NodoM *insertarOrdenadoFila(NodoM *nuevo, NodoM *cabFil);
        NodoM *crearColumna(int x);
        NodoM *crearFila(int y);
        void InsertarElemento(int column, int row, char dato);
        void imprimir();
        void Graficar();
        string NodosColumnas();
        string NodosFilas();
        string EnlaceNodos();
        string RankSame();
        string enlaceColumna();
        string enlaceNodosEnMedio();

        string IntToString(int);
        string getString(char);

        void modificar(int x, int y, char dato);

    protected:

    private:
        void GraficarMatriz(NodoM*);
};

#endif // MATRIZD_H
