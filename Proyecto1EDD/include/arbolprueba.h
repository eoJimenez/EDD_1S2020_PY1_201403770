#ifndef ARBOLPRUEBA_H
#define ARBOLPRUEBA_H
#include <iostream>

using namespace std;

class nodoRoot;

class arbolprueba
{
    public:
        nodoRoot *root;

        arbolprueba();
        //virtual ~arbolprueba();
        void insertar(char[] key);
        nodoRoot *buscar(char[] key)

    protected:

    private:
        void insertar(char[] key, nodoRoot *hoja);
        nodoRoot *buscar(char[] key, nodoRoot *hoja);
};

class nodoRoot
{
public:
    nodoRoot *izquierdo, *derecho;
    char[] data;

    nodoRoot(char[]);
};
#endif // ARBOLPRUEBA_H
