#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <string>

using namespace std;

class nodoDoble;
///CLASE LISTA DOBLE
class ListaDoble
{
public:

    ///CONSTRUCTOR
    ListaDoble();
    ///MÉTODOS
    void graficarLista(string);
    void agregarNodo(char);
    void eliminarNodo(char);
    char buscarNodo(char);
    void imprimirLista();
    char eliminarTodo();
    string getString(char c);
    string DefNodos();
    string apuntadores();
    string getIntToString(int c);
    void cambiarApuntadores();


    ///DESTRUCTOR
    virtual ~ListaDoble();

protected:

private:
    nodoDoble *primero;
    nodoDoble *ultimo;
};

///CLASE NODO DOBLE
class nodoDoble
{
public:
    ///CONSTRUCTOR
    nodoDoble(char);

    nodoDoble *siguiente, *anterior;
    char caracter;

};

#endif // LISTADOBLE_H
