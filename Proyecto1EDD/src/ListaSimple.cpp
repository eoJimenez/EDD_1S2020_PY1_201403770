#include "ListaSimple.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;

ListaSimple::ListaSimple()
{
    primero = NULL;
    ultimo = primero;
}
///AGREGAR NODOS A LA LISTA SIMPLE
void ListaSimple::agregarNodo(string s)
{
    if(primero != NULL)
    {
        ultimo->siguiente = new NodoSimple(s);
        ultimo = ultimo->siguiente;
    }
    else
    {
        primero = new NodoSimple(s);
        ultimo = primero;
    }
}
///MÉTODO QUE RECORRE LA LISTA E IMPRIME LOS DATOS ALMACENADOS EN ELLA
void ListaSimple::imprimir()
{
    NodoSimple *temporal = primero;
    while(temporal != NULL)
    {
        cout << temporal->palabra <<",";
        temporal = temporal->siguiente;

    }
}
///MÉTODOS PARA GRAFICAR
void ListaSimple::graficarLista()///RECORRIDO PREORDEN
{
    string cadNodo;
    string cadApuntador;
    ofstream archivoD;
    archivoD.open("C:/imagenes/RecorridoPre.dot",ios::out);
    archivoD <<"digraph ListaCircularDoble\n{"<<endl;
    archivoD <<"\trankdir=LR;"<<endl;
    archivoD<<"\tgraph [nodesep=0.3];"<<endl;
    archivoD<<"\tsubgraph cluster_0{"<<endl;
    archivoD<<"\tstyle=filled;"<<endl;
    archivoD<<"\tcolor=lightgrey;"<<endl;
    archivoD<<"\tlabelloc=t;"<<endl;
    archivoD<<"\tnode [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cadNodo = DefinirNodo();
    cadApuntador = apuntador();
    archivoD<<"\n";
    archivoD<<cadNodo<<endl;
    archivoD<<"\n";
    archivoD<<cadApuntador<<endl;
    archivoD<<"\n";
    archivoD<<"\tlabel=\"Recorrido Pre Orden\n\n\";"<<endl;
    archivoD<<"\t}"<<endl;
    archivoD<<"}"<<endl;
    archivoD.close();
    system("dot C:/imagenes/RecorridoPre.dot -o C:/imagenes/RecorridoPre.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/RecorridoPre.png");
}
void ListaSimple::graficaInorden()///RECORRIDO INORDEN
{
    string cadNodo;
    string cadApuntador;
    ofstream archivoD;
    archivoD.open("C:/imagenes/RecorridoIn.dot",ios::out);
    archivoD <<"digraph ListaCircularDoble\n{"<<endl;
    archivoD <<"\trankdir=LR;"<<endl;
    archivoD<<"\tgraph [nodesep=0.3];"<<endl;
    archivoD<<"\tsubgraph cluster_0{"<<endl;
    archivoD<<"\tstyle=filled;"<<endl;
    archivoD<<"\tcolor=lightgrey;"<<endl;
    archivoD<<"\tlabelloc=t;"<<endl;
    archivoD<<"\tnode [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cadNodo = DefinirNodo();
    cadApuntador = apuntador();
    archivoD<<"\n";
    archivoD<<cadNodo<<endl;
    archivoD<<"\n";
    archivoD<<cadApuntador<<endl;
    archivoD<<"\n";
    archivoD<<"\tlabel=\"Recorrido In Orden\n\n\";"<<endl;
    archivoD<<"\t}"<<endl;
    archivoD<<"}"<<endl;
    archivoD.close();
    system("dot C:/imagenes/RecorridoIn.dot -o C:/imagenes/RecorridoIn.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/RecorridoIn.png");
}
void ListaSimple::graficaPostorden()///RECORRIDO POSTORDEN
{
    string cadNodo;
    string cadApuntador;
    ofstream archivoD;
    archivoD.open("C:/imagenes/RecorridoPost.dot",ios::out);
    archivoD <<"digraph ListaCircularDoble\n{"<<endl;
    archivoD <<"\trankdir=LR;"<<endl;
    archivoD<<"\tgraph [nodesep=0.3];"<<endl;
    archivoD<<"\tsubgraph cluster_0{"<<endl;
    archivoD<<"\tstyle=filled;"<<endl;
    archivoD<<"\tcolor=lightgrey;"<<endl;
    archivoD<<"\tlabelloc=t;"<<endl;
    archivoD<<"\tnode [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cadNodo = DefinirNodo();
    cadApuntador = apuntador();
    archivoD<<"\n";
    archivoD<<cadNodo<<endl;
    archivoD<<"\n";
    archivoD<<cadApuntador<<endl;
    archivoD<<"\n";
    archivoD<<"\tlabel=\"Recorrido Post Orden\n\n\";"<<endl;
    archivoD<<"\t}"<<endl;
    archivoD<<"}"<<endl;
    archivoD.close();
    system("dot C:/imagenes/RecorridoPost.dot -o C:/imagenes/RecorridoPost.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/RecorridoPost.png");
}
///MÉTODO QUE DEFINE LOS NODOS DE LA LISTA
string ListaSimple::DefinirNodo()
{
    string cad = "";
    if(primero == NULL)
    {
        cout <<  "lista vacia" <<endl;
    }
    else
    {
        NodoSimple *aux = primero;
        while(aux != NULL)
        {
            cad += "\t"+aux->palabra+"[label=\"{"+aux->palabra+"}\"];\n";
            aux = aux->siguiente;
        }
    }
    return cad;
}
///MÉTODO QUE DEFINE LOS APUNTADORES DE LA LISTA
string ListaSimple::apuntador()
{
    string cad = "";
    if(primero == NULL)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        NodoSimple *aux = primero;
        while(aux->siguiente != NULL)
        {
            cad += "\t"+aux->palabra+"->"+aux->siguiente->palabra+";\n";
            aux = aux->siguiente;
        }
    }
    return cad;
}
///DESTRUCTOR CLASE LISTA; NO UTILIZADO
ListaSimple::~ListaSimple()
{
    //dtor
}
///CONSTRUCTOR DE LA CLASE NODOSIMPLE
NodoSimple::NodoSimple(string s)
{
    siguiente = NULL;
    palabra = s;
}
