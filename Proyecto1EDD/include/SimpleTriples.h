#ifndef SIMPLETRIPLES_H
#define SIMPLETRIPLES_H
#include <iostream>
using namespace std;

class nodoSimpleTriple
{
public:
    nodoSimpleTriple *siguiente;
    int posx;
    int posy;
    nodoSimpleTriple(int,int);
};

class SimpleTriples
{
    public:
        SimpleTriples();
        nodoSimpleTriple *primero, *ultimo;
        void agregarTriple(int,int);
        void imprimir();
        string getIntToString(int i);
        virtual ~SimpleTriples();

    protected:

    private:
};

#endif // SIMPLETRIPLES_H
