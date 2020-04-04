#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include <ostream>
#include <fstream>
#include <iostream>
using namespace std;

class Node;
//CLASE LISTA
class ListaCircularDoble
{
    public:
        Node *primero;
        Node *ultimo;
        //CONSTRUCTOR
        ListaCircularDoble();

        void Graficar();

        void agregar(string);
        void imprimirC();
        bool buscarPalabra(string);

    protected:

    private:

};

//CLASE NODO
class Node
{
public:
    Node *siguiente, *anterior;
    string cadena;
    //CONSTRUCTOR
    Node(string);
};

#endif // LISTACIRCULARDOBLE_H
