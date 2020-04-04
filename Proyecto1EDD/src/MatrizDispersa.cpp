#include "MatrizDispersa.h"
#include <iostream>
#include <string>
using namespace std;

MatrizDispersa::MatrizDispersa()
{
    NodoMatriz *tmp = new NodoMatriz('R',1,1);
    root = tmp;
}

NodoMatriz *MatrizDispersa::buscarFila(int y)
{
    NodoMatriz *temp = root;
    while(temp != NULL)
    {
        if(temp->fila == y)
        {
            return temp;
        }
        temp = temp->abajo;
    }
    return NULL;
}
NodoMatriz *MatrizDispersa::buscarColumna(int x)
{
    NodoMatriz *temp = root;
    while(temp != NULL)
    {
        if(temp->columna == x)
        {
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}
///INSERCIÓN GENERAL
void MatrizDispersa::insertarElemento(char dato, int columna, int fila)
{
    NodoMatriz *nuevo = new NodoMatriz(dato, columna, fila);
    NodoMatriz *nodoColumna = buscarColumna(columna);
    NodoMatriz *nodoFila = buscarFila(fila);
    ///CASO 1: COLUMNA Y FILA NO EXISTEN
    if(nodoColumna == NULL && nodoFila == NULL)
    {
        cout << "caso1"<<endl;
        ///CREAR COLUMNA
        ///CREAR FILA
        ///INSERTAR ORDENADO EN COLUMNA
        ///INSERTAR ORDENADO EN FILA
    }
    ///CASO 2: COLUMNA NO EXISTE, FILA EXISTE
    else if(nodoColumna == NULL && nodoFila != NULL)
    {
        cout << "caso2" <<endl;
        ///CREAR COLUMNA
        ///INSERTAR ORDENADO EN COLUMNA
        ///INSERTAR ORDENADO EN FILA
    }
    ///CASO 3: COLUMAN EXISTE, FILA NO EXISTE
    else if(nodoColumna != NULL && nodoFila == NULL)
    {
        cout << "caso3" <<endl;
        ///CREAR FILA
        ///INSERTAR ORDENADO EN COLUMNA
        ///INSERTAR ORDENADO EN FILA
    }
    ///CASO 4: COLUMNA Y FILA EXISTEN
    else if(nodoColumna != NULL && nodoFila != NULL)
    {
        cout << "caso4" <<endl;
        ///INSERTAR ORDENADO EN COLUMNA
        ///INSERTAR ORDENADO EN FILA
    }
}

NodoMatriz::NodoMatriz(char c, int x, int y)
{
    caracter = c;
    columna = x;
    fila = y;
}
