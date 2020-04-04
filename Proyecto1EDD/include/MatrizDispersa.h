#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include <string>

using namespace std;

class NodoMatriz;

class MatrizDispersa
{
    public:
        NodoMatriz *root;
        ///CONSTRUCTOR
        MatrizDispersa();
        virtual ~MatrizDispersa();

        NodoMatriz *buscarFila(int y);
        NodoMatriz *buscarColumna(int x);
        void insertarElemento(char dato, int col, int fil);
    protected:

    private:
};

class NodoMatriz
{
public:
    ///DATO
    char caracter;
    int fila;
    int columna;
    ///APUNTADORES
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *anterior;
    NodoMatriz *siguiente;
    ///CONSTRUCTOR
    NodoMatriz(char caracter,int columna,int fila)
    {

    }
};

#endif // MATRIZDISPERSA_H
