#include "ListaDoble.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

//CLASE LISTA DOBLE
    //CONSTRUCTOR
ListaDoble::ListaDoble()
{
    primero = NULL;
    ultimo = NULL;
}

//MÉTODOS
void ListaDoble::agregarNodo(char c)
{
    nodoDoble *nuevoNodo = new nodoDoble(c);
    if(primero != NULL)
    {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        ultimo = nuevoNodo;
    }else
    {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }
}

void ListaDoble::imprimirLista()
{
    nodoDoble *temp = primero;
    while(temp != NULL)
    {
        cout << "Dato:" << temp->caracter << endl;
        //cout << "\t"<<getString(temp->caracter)<<"[label =\"{"<<getString(temp->caracter)<<"}\"];\n";
        //cout << "\t"<<getString(temp->caracter)<<"->"<<getString(temp->siguiente->caracter)<<";\n";
        temp = temp->siguiente;
    }
}

char ListaDoble::buscarNodo(char letra)
{
    nodoDoble *actual = primero;
    bool encontrado = false;
    if(primero != NULL)
    {
        while(actual != NULL && encontrado != true)
        {
            if(actual->caracter == letra)
            {
                encontrado = true;
                return letra;
            }
            actual = actual->siguiente;
        }
        if(!encontrado)
        {
            return NULL;
        }
    }
    else
    {
        cout << "\n Lista Vacia \n\n";
        return NULL;
    }
}
void ListaDoble::eliminarNodo(char dato)
{
    nodoDoble *aux = primero;
    nodoDoble *anterior = NULL;
    bool encontrado = false;
    //char caracter;
    //cout << "Ingrese el nodo que desea agregar a la matriz:";
    //cin >> caracter;
    if(primero != NULL)
    {
        while(aux != NULL && encontrado != true)
        {
            if(aux->caracter == dato)
            {
                cout << "\n caracter encontrado ( "<<dato<<") Encontrado";
                if(aux == primero)
                {
                    primero = primero->siguiente;
                    primero->anterior = NULL;
                }else if(aux == ultimo)
                {
                    anterior->siguiente = NULL;
                    ultimo = anterior;
                }
                else
                {
                    anterior->siguiente = aux->siguiente;
                    aux->siguiente->anterior = anterior;
                }
                cout << "\n Nodo eliminado de la lista y agregado a la matriz";
                encontrado = true;
            }
            anterior = aux;
            aux = aux->siguiente;
        }
        if(!encontrado)
        {
            cout << "\n Caracter no encontrado\n\n";
        }
    }
    else
    {
        cout << "\n La lista se encuentra vacia\n\n";
    }
}
//MÉTODO PARA GRAFICAR LA LISTA
void ListaDoble::graficarLista(string nombre)
{
    string cadena = "";
    string cadena1 = "";
    string compilarDot;
    string abrirDot;
    ofstream archivoLD;
    archivoLD.open("C:/imagenes/ListaDoble"+nombre+".dot",ios::out);
    archivoLD <<"digraph ListaDoble\n{"<<endl;
    archivoLD <<"\trankdir=LR;"<<endl;
    archivoLD<<"\tgraph [nodesep=0.3];"<<endl;
    archivoLD<<"\tsubgraph cluster_0{"<<endl;
    archivoLD<<"\tstyle=filled;"<<endl;
    archivoLD<<"\tcolor=lightgrey;"<<endl;
    archivoLD<<"\tlabelloc=t;"<<endl;
    archivoLD<<"\tnode [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    nodoDoble *temp = primero;
    cadena = DefNodos();
    cadena1 = apuntadores();
    archivoLD<<"\n";
    archivoLD<<cadena<<endl;
    archivoLD<<"\n";
    archivoLD<<cadena1<<endl;
    archivoLD<<"\n";
    archivoLD<<"\tlabel=\"Lista Doble: Fichas de "+nombre+"\n\n\";"<<endl;
    archivoLD<<"\t}"<<endl;
    archivoLD<<"}"<<endl;
    archivoLD.close();
    compilarDot = "dot C:/imagenes/ListaDoble"+nombre+".dot -o C:/imagenes/ListaDoble"+nombre+".png -Tpng -Gcharset=utf8";
    system(compilarDot.c_str());
    abrirDot ="C:/imagenes/ListaDoble"+nombre+".png";
    system(abrirDot.c_str());
}

string ListaDoble::DefNodos()
{
    string cad = "";

    if(primero == NULL)
    {
        cout << "La Lista Está Vacía" << endl;
    }
    else
    {
        nodoDoble *aux = primero;
        int i = 1;
        while(aux != NULL)
        {
            cad += getString(aux->caracter)+getIntToString(i)+"[label =\"{"+getString(aux->caracter)+"}\"];\n";
            aux = aux->siguiente;
            i++;
        }
    }
    return cad;
}

string ListaDoble::apuntadores()
{
    string cad = "";
    if(primero == NULL)
    {
        cout << "La Lista Está Vacía" << endl;
    }
    else
    {
        int i = 1;
        nodoDoble *temp = primero;
        while(temp->siguiente != NULL)
        {
            cad += getString(temp->caracter)+getIntToString(i);
            cad += "->";
            cad += getString(temp->siguiente->caracter)+getIntToString(i+1)+";\n";
            cad += getString(temp->siguiente->caracter)+getIntToString(i+1);
            cad += "->";
            cad += getString(temp->caracter)+getIntToString(i)+";\n";
            temp = temp->siguiente;
            i++;
        }
    }
    return cad;
}
string ListaDoble::getString(char c)
{
    string s(1,c);
    return s;
}
string ListaDoble::getIntToString(int i)
{
    string str = to_string(i);
    return str;
}
///ELIMINAR TODO DE LA LISTA
char ListaDoble::eliminarTodo()
{
    char c;
    nodoDoble *aux = primero;
    do
    {
        c = aux->caracter;

        primero = aux->siguiente;
        return c;
        aux->anterior->siguiente = NULL;
        aux->anterior = NULL;

        aux = aux->siguiente;

    }while(aux != NULL);
}
//CLASE NODO DOBLE
    //CONSTRUCTOR
nodoDoble::nodoDoble(char c)
{
    siguiente = NULL;
    anterior = NULL;
    caracter = c;
}

ListaDoble::~ListaDoble()
{
    //dtor
}
