#include <iostream>
#include "ListaOrdenada.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

ListaOrdenada::ListaOrdenada()
{
    primero = NULL;
    ultimo = primero;
}

void ListaOrdenada::agregarPuntaje(int p)
{
    NodoLista *aux = new NodoLista(p);
    if(primero == NULL)
    {
        primero = aux;
    }
    else
    {
        if(p > primero->puntaje)
        {
            aux->siguiente = primero;
            primero = aux;
        }
        else
        {
            NodoLista *temp = primero;
            NodoLista *atras = primero;
            while(p <= temp->puntaje && temp->siguiente != NULL)
            {
                atras = temp;
                temp = temp->siguiente;
            }
            if(p <= temp->puntaje)
            {
                temp->siguiente = aux;
            }
            else
            {
                aux->siguiente = temp;
                atras->siguiente = aux;
            }
        }
    }
}

void ListaOrdenada::ImprimirPuntaje()
{
    NodoLista *temp = primero;
    while(temp != NULL)
    {
        cout << temp->puntaje << ",";
        temp = temp->siguiente;
    }
    cout << "\n";
}

void ListaOrdenada::graficarLista(string nombre)
{
    string cadNodo;
    string cadApuntador;
    string compilarDot;
    string abrirDot;
    ofstream archivoD;
    archivoD.open("C:/imagenes/ListaOrdenada "+nombre+".dot",ios::out);
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
    archivoD<<"\tlabel=\"Lista Ordenada: Puntaje de: "+nombre+"\n\n\";"<<endl;
    archivoD<<"\t}"<<endl;
    archivoD<<"}"<<endl;
    archivoD.close();
    compilarDot = "dot C:/imagenes/ListaOrdenada "+nombre+".dot -o C:/imagenes/ListaOrdenada "+nombre+".png -Tpng -Gcharset=utf8";
    system(compilarDot.c_str());
    abrirDot = "C:/imagenes/ListaOrdenada "+nombre+".png";
    system(abrirDot.c_str());
}
string ListaOrdenada::DefinirNodo()
{
    string cad = "";
    if(primero == NULL)
    {
        cout <<  "lista vacia" <<endl;
    }
    else
    {
        NodoLista *aux = primero;
        while(aux != NULL)
        {
            cad += "\t"+intToString(aux->puntaje)+"[label=\"{"+intToString(aux->puntaje)+"}\"];\n";
            aux = aux->siguiente;
        }
    }
    return cad;
}
string ListaOrdenada::apuntador()
{
    string cad = "";
    if(primero == NULL)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        NodoLista *aux = primero;
        while(aux->siguiente != NULL)
        {
            cad += "\t"+intToString(aux->puntaje)+"->"+intToString(aux->siguiente->puntaje)+";\n";
            aux = aux->siguiente;
        }
    }
    return cad;
}
string ListaOrdenada::intToString(int val)
{
    string cad="";
    cad = static_cast<std::ostringstream*>(&(std::ostringstream() << val))->str();
    return cad;
}
//CLASE NODO LISTA ORDENADA
NodoLista::NodoLista(int p)
{
    siguiente = NULL;
    puntaje = p;
}
