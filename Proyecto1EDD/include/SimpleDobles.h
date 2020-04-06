#ifndef SIMPLEDOBLES_H
#define SIMPLEDOBLES_H
#include <string>
using namespace std;

class nodoSimpleDoble
{
public:
    nodoSimpleDoble *siguiente;
    int posx;
    int posy;
    nodoSimpleDoble(int,int);
};
class SimpleDobles
{
    public:
        SimpleDobles();

        nodoSimpleDoble *primero, *ultimo;
        void agregar(int,int);
        void imprimir();
        string IntToString(int i);
        virtual ~SimpleDobles();

    protected:

    private:
};

#endif // SIMPLEDOBLES_H
