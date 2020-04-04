#include "ArbolBB.h"
#include "ListaSimple.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;
ListaSimple ls;
ListaSimple pre;
ListaSimple post;

ArbolBB::ArbolBB()
{
    raiz = NULL;
}
/*ArbolBB::~ArbolBB()
{
    destroy_arbol();
}*/

//MÉTODOS
/*void ArbolBB::destroy_arbol()
{
    destroy_arbol(raiz);
}
void ArbolBB::destroy_arbol(NodoArbol *hoja)
{
    if(hoja != NULL)
    {
        destroy_arbol(hoja->izquierda);
        destroy_arbol(hoja->derecha);
        delete hoja;
    }
}*/
///INSERTAR
void ArbolBB::insertarABB(string key)
{
    if(raiz != NULL)
    {
        insertarABB(key, raiz);
    }
    else
    {
        raiz = new NodoArbol(key);
        //cout << "raiz vacia " << key << endl;
        raiz->izquierda = NULL;
        raiz->derecha = NULL;
    }
}
///INSERTAR RECURSIVO
void ArbolBB::insertarABB(string key, NodoArbol* hoja)
{
    if(key < hoja->dato)
    {
        if(hoja->izquierda != NULL)
        {
            insertarABB(key, hoja->izquierda);
        }
        else
        {
            hoja->izquierda = new NodoArbol(key);
            hoja->izquierda->izquierda = NULL;
            hoja->izquierda->derecha = NULL;
        }
    }
    else if(key > hoja->dato)
    {
        if(hoja->derecha != NULL)
        {

            insertarABB(key, hoja->derecha);
        }
        else
        {
            hoja->derecha = new NodoArbol(key);
            hoja->derecha->izquierda = NULL;
            hoja->derecha->derecha = NULL;
        }
    }
}
///BUSCAR
NodoArbol *ArbolBB::buscar(string key)
{
    return buscar(key, raiz);
}
///BUSCAR RECURSIVO
NodoArbol *ArbolBB::buscar(string key, NodoArbol* hoja)
{
    if(hoja != NULL)
    {
        if(key == hoja->dato)
        {
            //cout << "El Jugador: " << hoja->dato <<" YA EXISTE ingrese otro nombre "<< endl;
            return hoja;
        }
        if(key<hoja->dato)
            return buscar(key, hoja->izquierda);
        else
            return buscar(key, hoja->derecha);
    }
    else return NULL;
}
///ELIMINAR ABB
NodoArbol *ArbolBB::EliminarNodo(string key)
{
    return eliminar(key,raiz);
}
///ELIMINAR NODOS ABB, MÉTODO RECURSIVO
NodoArbol *ArbolBB::eliminar(string key, NodoArbol *hoja)
{
    if(hoja == NULL)
    {
        return hoja;
    }
    if(hoja->dato>key)
    {
        hoja->izquierda = eliminar(key,hoja->izquierda);
        return hoja;
    }
    else if(hoja->dato<key)
    {
        hoja->derecha = eliminar(key,hoja->derecha);
        return hoja;
    }
    if(hoja->izquierda == NULL)
    {
        NodoArbol *temp = hoja->derecha;
        delete hoja;
        return temp;
    }
    else if(hoja->derecha == NULL)
    {
        NodoArbol *temp = hoja->izquierda;
        delete hoja;
        return temp;
    }
    else
    {
        NodoArbol *aux = hoja->derecha;
        NodoArbol *temp = hoja->derecha;
        while(temp->izquierda != NULL)
        {
            aux = temp;
            temp = temp->izquierda;
        }
        aux->izquierda = temp->derecha;
        hoja->dato = temp->dato;
        delete temp;
        return hoja;
    }
}
/////////////////////////////////////////////////////////////////////
///RECORRIDOS
///PREORDEN
void ArbolBB::recorridoPre()
{
    if(raiz != NULL)
    {
        recorridoPreorden(raiz);
    }
    //pre.imprimir();
    pre.graficarLista();
}
///PREORDEN RECURSIVO
void ArbolBB::recorridoPreorden(NodoArbol* t)
{
    //cout << t->dato << "-";
    pre.agregarNodo(t->dato);
    if(t->izquierda != NULL) recorridoPreorden(t->izquierda);
    if(t->derecha != NULL) recorridoPreorden(t->derecha);
}
///INORDEN
void ArbolBB::recorridoIn()
{
    if(raiz != NULL)
    {
        recorridoInorden(raiz);
    }
    //ls.imprimir();
    ls.graficaInorden();
}
///INORDEN RECURSIVO
void ArbolBB::recorridoInorden(NodoArbol* nodo)
{
    if(nodo->izquierda != NULL) recorridoInorden(nodo->izquierda);
    ls.agregarNodo(nodo->dato);
    //cout << nodo->dato << "-";
    if(nodo->derecha != NULL) recorridoInorden(nodo->derecha);
}
///POSTORDEN
void ArbolBB::recorridoPost()
{
    if(raiz != NULL)
    {
        recorridoPostorden(raiz);
    }
    //post.imprimir();
    post.graficaPostorden();
}
///POSTORDEN RECURSIVO
void ArbolBB::recorridoPostorden(NodoArbol* nodo)
{
    if(nodo->izquierda != NULL) recorridoPostorden(nodo->izquierda);
    if(nodo->derecha != NULL) recorridoPostorden(nodo->derecha);
    post.agregarNodo(nodo->dato);
    //cout << nodo->dato << "-";
}
/////////////////////////////////////////////////////////////////////////////
///GRAFICAS DEL ARBOL
void ArbolBB::graficar()
{
    if(raiz != NULL)
    {
        graficaArbol(raiz);
    }
    else
    {
        cout<<"El arbol esta vacio"<<endl;
    }
}
void ArbolBB::graficaArbol(NodoArbol* nodo)
{
    string cadNodos;
    string cadApuntadores;
    ofstream archivoABB;
    archivoABB.open("C:/imagenes/Arbol.dot",ios::out);
    if(archivoABB.fail())
    {
        cout<<"Error al crear archivo";
        exit(1);
    }
    archivoABB<<"digraph Arbol\n{"<<endl;
    archivoABB<<"\tRankidir=TB;"<<endl;
    archivoABB<<"\tordering=out;";
    archivoABB<<"\tgraph [splines=compound,nodesep=0.5];"<<endl;
    archivoABB<<"\tsubgraph cluster_0{"<<endl;
    archivoABB<<"\tstyle=filled;"<<endl;
    archivoABB<<"\tcolor=lightgrey;"<<endl;
    archivoABB<<"\tlabelloc=t;"<<endl;
    archivoABB<<"\tnode [shape = record, style=\"rounded,filled\", fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cadNodos = getCodigoInterno(nodo);
    //cadApuntadores = apuntadoresArbol(nodo);
    archivoABB<<"\n";
    archivoABB<<cadNodos<<endl;
    archivoABB<<"\n";
    //archivoABB<<cadApuntadores<<endl;
    //archivoABB<<"\n";
    archivoABB<<"\tlabel=\"Arbol Binario de Busqueda\";"<<endl;
    archivoABB<<"\t}"<<endl;
    archivoABB<<"}"<<endl;
    archivoABB.close();
    system("dot C:/imagenes/Arbol.dot -o C:/imagenes/Arbol.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/Arbol.png");
}
///CODIGO QUE GENERA LOS NODOS Y APUNTADORES DEL ÁRBOL
string ArbolBB::getCodigoInterno(NodoArbol* hoja)
{
    string etiqueta;
    if(hoja->izquierda == NULL && hoja->derecha == NULL)
    {
        etiqueta += "nodo"+hoja->dato+"[label=\""+hoja->dato+"\"];\n";
    }
    else
    {
        etiqueta+="nodo"+hoja->dato+"[label=\"<C0>|"+hoja->dato+"|<C1>\"];\n";
    }
    if(hoja->izquierda != NULL)
    {
        etiqueta+= getCodigoInterno(hoja->izquierda) + "nodo"+hoja->dato+":C0->nodo"+hoja->izquierda->dato+"\n";
    }
    if(hoja->derecha != NULL)
    {
        etiqueta+= getCodigoInterno(hoja->derecha) + "nodo"+hoja->dato+":C1->nodo"+hoja->derecha->dato+"\n";
    }
    return etiqueta;
}
///GRAFICA RECORRIDO INORDEN ABB\\\///NO FUNCIONA\\\///
void ArbolBB::graficarInorder()
{
    if(raiz != NULL)
    {
        graficaInOrden(raiz);
    }
    else
    {
        cout<<"El arbol esta vacio"<<endl;
    }
}
void ArbolBB::graficaInOrden(NodoArbol* nodo)
{
    string inorden;
    ofstream archivoINO;
    archivoINO.open("C:/imagenes/arbolInorden.dot",ios::out);
    if(archivoINO.fail())
    {
        cout<<"Error al crear el archivo";
        exit(1);
    }
    archivoINO<<"digraph arbol\n{"<<endl;
    archivoINO<<"\trankdir=LR;"<<endl;
    archivoINO<<"\tordering=out;";
    archivoINO<<"\tgraph [splines=compound,nodesep=0.5];"<<endl;
    archivoINO<<"\tsubgraph cluster_0{"<<endl;
    archivoINO<<"\tstyle=filled;"<<endl;
    archivoINO<<"\tcolor=lightgrey;"<<endl;
    archivoINO<<"\tlabelloc=t;"<<endl;
    archivoINO<<"\tnode [shape = rectangle, style=\"rounded,filled\", fillcolor=\"orange:white\",width=0.7,height=0.5];"<<endl;
    archivoINO<<"\n";
    inorden = getInorder(nodo);
    archivoINO<<"\n";
    archivoINO<<inorden<<endl;
    archivoINO<<"\n";
    archivoINO<<"\tlabel=\"Recorrido InOrden\";"<<endl;
    archivoINO<<"\t}"<<endl;
    archivoINO<<"}"<<endl;
    archivoINO.close();
    system("dot C:/imagenes/arbolInorden.dot -o C:/imagenes/arbolInorden.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/arbolInorden.png");
}
string ArbolBB::getInorder(NodoArbol* leaf)
{
    string cadenaInO;
    if(leaf->izquierda != NULL)
    {
        getInorder(leaf->izquierda);
    }
    cadenaInO += "\t"+leaf->dato+"[label=\""+leaf->dato+"\"];\n";
    cadenaInO += leaf->dato + "->";
    //cout<<cadenaInO<<endl;
    if(leaf->derecha != NULL)
    {
        getInorder(leaf->derecha);
    }
    return cadenaInO;
}
///+= "\t"+hoja->dato+"[label=\""+hoja->dato+"\"];\n";

///CLASE NODO ARBOL
NodoArbol::NodoArbol(string key)
{
    izquierda = NULL;
    derecha = NULL;
    dato = key;
}

void ArbolBB::seleccionarJugador()
{

}
