#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

#include "ListaCircularDoble.h"

using namespace std;

///CLASE LISTA
ListaCircularDoble::ListaCircularDoble()///CONSTRUCTOR
{
    primero = NULL;
    ultimo = NULL;
}
///MÉTODO AGREGAR NODO
void ListaCircularDoble::agregar(string s)
{
    Node *temp = new Node(s);
    if(primero == NULL)
    {
        primero = temp;
        primero->siguiente = primero;
        primero->anterior = primero;
    }
    else
    {
        Node *aux = primero;
        while(aux->siguiente != primero)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = temp;
        temp->anterior = aux;
        temp->siguiente = primero;
        primero->anterior = temp;
    }
}

///BUSCAR
bool ListaCircularDoble::buscarPalabra(string palabra)
{
    Node *actual = primero;
    bool encontrado = false;
    if(primero != NULL)
    {
        do
        {
            if(actual->cadena == palabra)
            {
                encontrado = true;
                //cout << "se encontro la palabra" << palabra << endl;
                return encontrado;///RETORNAR TRUE O FALSE
            }
            actual = actual->siguiente;
        }
        while(actual != primero && encontrado != true);

        if(!encontrado)
        {
            //cout << "\n La Palabra No se encontro \n\n";
            return encontrado;
        }
    }
    else
    {
        cout << "\n La Lista esta Vacia\n\n";
        return encontrado;
    }
}
///IMPRIME LOS DATOS ALMACENADOS EN LA LISTA
void ListaCircularDoble::imprimirC()
{
    Node *aux = primero;
    if(aux != NULL)
    {
        do
        {
             cout << aux->cadena << endl;
            aux = aux->siguiente;
        }
        while(aux != primero);
    }
}
///GENERA ARCHIVO .DOT Y ABRE IMAGEN
void ListaCircularDoble::Graficar()
{
    ofstream archivoD;
    archivoD.open("C:/imagenes/ListaDobleCircular.dot",ios::out);
    archivoD <<"digraph ListaCircularDoble\n{"<<endl;
    archivoD <<"\trankdir=LR;"<<endl;
    archivoD<<"\tgraph [nodesep=0.3];"<<endl;
    archivoD<<"\tsubgraph cluster_0{"<<endl;
    archivoD<<"\tstyle=filled;"<<endl;
    archivoD<<"\tcolor=lightgrey;"<<endl;
    archivoD<<"\tlabelloc=t;"<<endl;
    archivoD<<"\tnode [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;

    Node *aux = primero;

   if(primero == NULL){
     cout << "Lista vacia" << endl;
   }else{
     do{
       archivoD << "\n" << aux->cadena << "[label =\"{" << aux->cadena << "}\"];\n";
       archivoD << "\n" << aux->cadena << "->" << aux->siguiente->cadena << ";";
       archivoD << "\n" << aux->siguiente->cadena << "->" << aux->cadena << ";";
       aux = aux->siguiente;
     }while(primero != aux);
   }

    archivoD<<"\n";
    archivoD<<"\tlabel=\"Lista Circular Doble: Diccionario\n\n\";"<<endl;
    archivoD<<"\t}"<<endl;
    archivoD<<"}"<<endl;
    archivoD.close();
    system("dot C:/imagenes/ListaDobleCircular.dot -o C:/imagenes/ListaDobleCircular.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/ListaDobleCircular.png");
}

///CLASE NODO LISTA
Node::Node(string s)///CONSTRUCTOR
{
    siguiente = NULL;
    anterior = NULL;
    cadena = s;
}

