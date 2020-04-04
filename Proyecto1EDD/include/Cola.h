#ifndef COLA_H
#define COLA_H
#include <string>

using namespace std;

class nodoCola;

class Cola
{
    public:
        nodoCola *primero, *ultimo;
        //CONSTRUCTOR
        Cola();
        void graficarCola();
        void agregarCola(char dato,int puntos);
        char eliminarCola();
        void imprimirCola();
        string getString(char c);
        string getIntToString(int c);
        string DefNodos();
        string apuntadores();
        void colaAleatoria();
        void ObtenerFichas();

    protected:

    private:
};

//CLASE NODO
class nodoCola
{
public:
    //CONSTRUCTOR
    nodoCola(char,int);
    char caracter;
    int puntaje;

    nodoCola *siguiente;
};

#endif // COLA_H
