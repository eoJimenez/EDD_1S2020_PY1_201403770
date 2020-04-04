#include <iostream>
#include <fstream>
#include <string>
#include "ListaDoble.h"
#include "ListaCircularDoble.h"
#include "Cola.h"
#include "ListaOrdenada.h"
#include "ArbolBB.h"
#include "MatrizD.h"
#include "menu.h"
#include "Json.h"

using namespace std;
//ArbolBB *root = NULL;
int main()
{
    //menu MenuP;
    //MenuP.menu();
    /*
    Json js;
    js.leerJSon();*/
    ListaDoble LD, doble;
    LD.agregarNodo('a');
    LD.agregarNodo('b');
    LD.agregarNodo('c');
    LD.agregarNodo('d');
    LD.agregarNodo('e');
    LD.agregarNodo('f');
    LD.agregarNodo('a');
    LD.agregarNodo('b');
    LD.agregarNodo('c');
    LD.agregarNodo('d');
    LD.agregarNodo('e');
    LD.agregarNodo('f');
    LD.imprimirLista();
    LD.graficarLista("nombre");
    //LD.eliminarNodo('a');
    //LD.graficarLista("eliminada");
    //LD.eliminarNodo('b');
    //LD.graficarLista("eliminada1");

    cout << LD.eliminarTodo() << endl;
    LD.graficarLista("n");
/*
    cout <<"\n";
    ListaCircularDoble lc;
    lc.agregar("hola");
    lc.agregar("mundo");
    lc.agregar("prueba");
    lc.agregar("diccionario");
    lc.agregar("nuevo");
    lc.imprimirC();
    lc.Graficar();
    string palabra = "";
    char cadena[] = "CARRO";
    for(int i = 0; i<strlen(cadena); i++)
    {
        cadena[i] = tolower(cadena[i]);
    }
    ListaDoble ld;
    cout<<cadena;
    //palabra = ld.getString(cadena);

    if(lc.buscarPalabra(cadena) != NULL)
    {
        cout << " la palabra existe" <<endl;
    }
    else
    {
        cout << " la palabra no existe" <<endl;
    }
    //if(lc.buscarPalabra(cadena).c_str() == NULL)



/*
    cout <<"\n";
    Cola cola;
    cola.agregarCola('h',2);
    cola.agregarCola('a',1);
    cola.agregarCola('b',1);
    cola.agregarCola('c',1);
    cola.agregarCola('d',1);
    cola.agregarCola('e',2);
    cola.agregarCola('f',1);
    cola.agregarCola('g',1);
    cola.agregarCola('h',1);
    cola.agregarCola('i',1);
    cola.agregarCola('j',2);
    cola.agregarCola('k',1);
    cola.agregarCola('l',1);
    cola.agregarCola('m',1);
    cola.agregarCola('n',1);
    cola.agregarCola('o',2);
    cola.agregarCola('s',1);
    cola.agregarCola('t',1);
    cola.agregarCola('t',1);
    cola.agregarCola('a',1);

    cout <<"\n";
    //cola.colaAleatoria();
    //cola.imprimirCola();
    //cola.graficarCola();
    char f,g;
    string datos;
    int i = 1;
    int j = 1;
    while(i <= 7)
    {
        f = cola.eliminarCola();
        LD.agregarNodo(f);

        datos = cola.getString(f);
        cout <<datos;
        i++;

    }
    LD.graficarLista("LD");

    while(j <= 7)
    {
        g = cola.eliminarCola();
        doble.agregarNodo(g);

        datos = cola.getString(g);
        cout <<datos;
        j++;

    }
    //LD.graficarLista();
    doble.graficarLista("doble");
    cola.graficarCola();
    cout <<"\n";
    cola.imprimirCola();
    /*
    cout <<"\n";
    ListaOrdenada Lo;
    Lo.agregarPuntaje(0);
    Lo.agregarPuntaje(35);
    Lo.agregarPuntaje(10);
    Lo.agregarPuntaje(1);
    Lo.agregarPuntaje(5);
    Lo.agregarPuntaje(20);
    Lo.agregarPuntaje(18);
    Lo.ImprimirPuntaje();
    Lo.graficarLista();
    cout <<"\n";
    ArbolBB abb;
    abb.insertarABB("Heidy");
    abb.insertarABB("Carlos");
    abb.insertarABB("Rodrigo");
    abb.insertarABB("Antonio");
    abb.insertarABB("Eduardo");
    abb.insertarABB("Andres");
    abb.insertarABB("Bruno");
    abb.insertarABB("Fernando");
    abb.insertarABB("Diana");
    abb.insertarABB("Jackeline");
    abb.insertarABB("Tatiana");
    abb.insertarABB("Edgar");
    abb.insertarABB("Ricardo");
    abb.insertarABB("Veronica");
    abb.insertarABB("Estela");
    abb.graficar();
    //abb.EliminarNodo("Carlos");
    //abb.graficar();
    cout << "\n";
    abb.recorridoPre();
    //cout << "\n";
    abb.recorridoIn();
    //cout << "\n";
    abb.recorridoPost();


    int i,j;
    for(i=1;i<=11;i++)
    {
        for(j=1;j<=11;j++)
        {
            if(i!=j)
            {
                matriz.InsertarElemento(i,j,'a');
            }

        }
    }
    matriz.Graficar();
    MatrizD matriz;
    matriz.InsertarElemento(10,4,'h');
    //matriz.Graficar();
    matriz.InsertarElemento(8,5,'O');
    matriz.InsertarElemento(10,6,'L');
    matriz.InsertarElemento(11,6,'3');
    matriz.InsertarElemento(10,5,'2');
    matriz.Graficar();
    matriz.InsertarElemento(11,6,'S');
    matriz.InsertarElemento(8,4,'C');
    matriz.InsertarElemento(8,6,'P');
    matriz.InsertarElemento(10,5,'A');
    matriz.Graficar();
/*
    matriz.modificar(10,5,'H');
    matriz.modificar(8,6,'H');
    matriz.modificar(11,5,'H');
    matriz.modificar(10,6,'H');
    matriz.modificar(8,4,'H');
    matriz.modificar(11,4,'a');
    matriz.modificar(11,6,'a');
    matriz.modificar(8,5,'a');
    matriz.modificar(10,4,'a');
    matriz.InsertarElemento(1,1,'A');
    matriz.modificar(1,1,'a');
    matriz.imprimir();
    matriz.Graficar();*/

    return 0;
}
