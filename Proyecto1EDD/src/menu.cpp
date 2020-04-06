#include "menu.h"
#include <iostream>
#include <fstream>
#include "ListaDoble.h"
#include "ListaCircularDoble.h"
#include "Cola.h"
#include "ListaOrdenada.h"
#include "ArbolBB.h"
#include "MatrizD.h"
#include "Json.h"
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <time.h>
#include <fstream>
#include "json.hpp"
#include <typeinfo>
#include "SimpleDobles.h"
#include "SimpleTriples.h"
#include "ListaValidacion.h"

using json = nlohmann::json;

using namespace std;

int contador = 1, contJ1, contJ2, puntajej1, puntajej2;
string  jugador1, jugador2, primero, segundo, palabraJ1, palabraJ2;
char ficha;
char f,g;
int i = 1;
int j = 1;
int x, y;
char c;

ListaDoble LD;
ListaDoble j1;
ListaDoble j2;
ListaCircularDoble LCD;
Cola CL;
ListaOrdenada ListaJ1;
ListaOrdenada ListaJ2;
ArbolBB ABB;
MatrizD Matriz;
Json archivo;
SimpleDobles Ldoble;
SimpleTriples Ltriple;
ListaValidacion jugar1;
ListaValidacion jugar2;

menu::menu()
{
    MenuPrincipal();
}

void menu::MenuPrincipal()
{
    int opcion = 0;
    do
    {
        cout << "\n|--------------------|";
        cout << "\n| ° Menú Principal ° |";
        cout << "\n|--------------------|";
        cout << "\n| 1. Cargar Archivo  |";
        cout << "\n| 2. Juego           |";
        cout << "\n| 3. Reportes        |";
        cout << "\n| 4. Salir           |";
        cout << "\n|--------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            {
                CL.colaAleatoria();
                string Lcircular ="";
                int posX, posY;
                std::ifstream archivo("Ejemplo.json");///JsNuevo
                json j3;
                archivo >> j3;
                ///DEVUELVE LA DIMENSION DE LA MATRIZ
                cout<<"La dimension de la matriz es de: "<<j3.at("dimension")<<endl<<endl;

                ///CICLO QUE RECORRE EL ARCHIVO JSON
                cout<<"CASILLAS DOBLES"<<endl;
                for(int x = 0; x<j3.at("casillas").at("dobles").size(); x++)
                {
                    //cout<<"posicion x: "<<j3.at("casillas").at("dobles")[x].at("x")<<endl;
                    posX = j3.at("casillas").at("dobles")[x].at("x");
                    //cout<<"posicion y: "<<j3.at("casillas").at("dobles")[x].at("y")<<endl<<endl;
                    posY = j3.at("casillas").at("dobles")[x].at("y");
                    Matriz.InsertarElemento(posX,posY,'2');
                    Ldoble.agregar(posX,posY);
                }
                Ldoble.imprimir();
                cout<<"CASILLAS TRIPLES"<<endl;
                for(int x = 0; x<j3.at("casillas").at("triples").size(); x++)
                {
                    //cout<<"posicion x: "<<j3.at("casillas").at("triples")[x].at("x")<<endl;
                    posX = j3.at("casillas").at("triples")[x].at("x");
                    //cout<<"posicion y: "<<j3.at("casillas").at("triples")[x].at("y")<<endl<<endl;
                    posY = j3.at("casillas").at("triples")[x].at("y");
                    Matriz.InsertarElemento(posX,posY,'3');
                    Ltriple.agregarTriple(posX,posY);
                }
                Ltriple.imprimir();
                //cout<<"DICCIONARIO"<<endl;
                for (int x = 0; x<j3.at("diccionario").size(); x++)
                {
                    //cout<<"palabra: "<<j3.at("diccionario")[x].at("palabra")<<endl;
                    Lcircular = j3.at("diccionario")[x].at("palabra");
                    LCD.agregar(Lcircular);
                    //cout << Lcircular << endl;
                }
            }
            ///CARGAR ARCHIVO
            //archivo.leerJSon();
            break;
        case 2:
            ///JUEGO
            IniciarJuego();
            break;
        case 3:
            ///REPORTES
            Reportes();
            break;
        case 4:
            ///SALIR
            cout<< "\n\n Programa Finalizado...\n";
            exit(0);
            break;
        default:
            cout<< "\n\n Opcion NO VALIDA \n\n";
        }
    }
    while(opcion != 4);
}
///MENU DEL JUEGO
void menu::IniciarJuego()
{
    int opcIJ = 0;
    do
    {
        cout << "\n|----------------------|";
        cout << "\n| °   Menu Juego   °   |";
        cout << "\n|----------------------|";
        cout << "\n| 1. Ingresar Jugador  |";
        cout << "\n| 2. Jugar             |";
        cout << "\n| 3. Regresar          |";
        cout << "\n|----------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin>>opcIJ;
        system("cls");
        switch(opcIJ)
        {
        case 1:
            {
                string nombre = "";
                cout<<"Ingrese el nombre del Jugador: ";
                cin>>nombre;
                if(ABB.buscar(nombre) == NULL)
                {
                    ABB.insertarABB(nombre);
                    cout<<" Jugador Ingresado";
                }
                else
                {
                    cout << "El nombre: " <<nombre << " YA EXISTE, ingrese otro nombre." << endl;
                }
            }
            break;
        case 2:
            MenuJugar();
            break;
        case 3:
            MenuPrincipal();
            break;
        }
    }
    while(opcIJ != 3);
}
///MENU JUGAR
void menu::MenuJugar()
{
    int opcMenuJ = 0;
    do
    {
        cout << "\n|------------------------|";
        cout << "\n|   ° MENU DEL JUEGO °   |";
        cout << "\n|------------------------|";
        cout << "\n| 1. Seleccionar Jugador |";
        cout << "\n| 2. Obtener Fichas      |";
        cout << "\n| 3. Scrabble            |";
        cout << "\n| 4. Regresar            |";
        cout << "\n|------------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin>>opcMenuJ;
        system("cls");
        switch(opcMenuJ)
        {
        case 1:
            {
                while(contador <= 2)
                {

                    if(contador == 1)
                    {
                        cout<<"Ingrese el nombre del 1er. Jugador: ";
                        cin>>jugador1;
                        if(ABB.buscar(jugador1) != NULL)
                        {

                            cout<<" Jugador: " << jugador1 << endl;
                            ListaDoble j1;
                            contador++;
                        }
                        else
                        {
                            //jugador1 = nombre;
                            cout<<"El Jugador 1: " << jugador1 << "NO existe"<<endl;
                        }
                    }
                    if(contador == 2)
                    {
                        cout<<"Ingrese el nombre del  2do. Jugador: ";
                        cin>>jugador2;
                        if(ABB.buscar(jugador2) != NULL)
                        {

                            cout<<" Jugador 2: " << jugador2 << endl;
                            ListaDoble j2;
                            contador++;
                        }
                        else
                        {
                            //jugador2 = nombre;
                            cout<<"El Jugador: " << jugador2 << "NO existe"<<endl;
                        }
                    }
                }
                cout << "YA NO SE ADMITEN MAS JUGADORES" << endl;
            }
            break;
        case 2:
            {
                while(i <= 7)
                {
                    f = CL.eliminarCola();
                    //cout <<"prueba de eliminar"<< CL.getString(f);
                    j1.agregarNodo(f);
                    i++;
                }
                j1.graficarLista(jugador1);
                while(j <= 7)
                {
                    g = CL.eliminarCola();
                    j2.agregarNodo(g);
                    j++;
                }
                j2.graficarLista(jugador2);
            }
            break;
        case 3:
            {
                int contador = 1;
                string jugadores[2] ={jugador1,jugador2};
                srand(time(NULL));
                while(contador <= 1)
                {
                    primero = jugadores [rand() % 2];
                    cout << primero << endl;
                    contador++;
                }
                if(primero != jugador1)
                {
                    segundo = jugador1;
                }
                else if(primero == jugador1)
                {
                    segundo = jugador2;
                }
                movimientoJ1();
            }
            break;
        case 4:
            IniciarJuego();
        }
    }
    while(opcMenuJ != 4);
}
///MENU DEL JUEGO SCRABBLE
void menu::MenuScrabble()
{
    int opScrabble = 0;
    int opS;
    do
    {
        cout << "\n|----------------------------------|";
        cout << "\n|        °   SCRABBLE++   °        |";
        cout << "\n|----------------------------------|";
        cout << "\n| 1. movimiento de "+primero+"     |";
        cout << "\n| 2. movimiento de "+segundo+"     |";
        cout << "\n| 3. terminar juego                |";
        cout << "\n|----------------------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin>>opScrabble;
        system("cls");
        switch(opScrabble)
        {
        case 1:
            ///COLOCAR FICHAS JUGADOR 1
            movimientoJ1();
            break;
        case 2:
            ///COLOCAR FICHAS JUGADOR 2
            movimientoJ2();
            break;
        case 3:
            cout << "Juego TERMINADO \n";/*
            opS = getch();
            switch(opS)
            {
            case 'S':case 's':
                MenuJugar();
                break;
            case 'n':
                MenuScrabble();
                break;
            }*/
            MenuJugar();
            break;
        }
    }
    while(opScrabble != 3);///ACÁ DEBO DE ANUNCIAR AL GANADOR
}
///MENU DE LOS REPORTES
void menu::Reportes()
{
    int opcR = 0;
    do
    {
        cout << "\n|----------------------|";
        cout << "\n| °  Menú Reportes  °  |";
        cout << "\n|----------------------|";
        cout << "\n| 1. Diccionario       |";
        cout << "\n| 2. Fichas            |";
        cout << "\n| 3. Jugadores         |";
        cout << "\n| 4. Recorrido Pre     |";
        cout << "\n| 5. Recorrido In      |";
        cout << "\n| 6. recorrido Post    |";
        cout << "\n| 7. Historial Puntaje |";
        cout << "\n| 8. ScoreBoard        |";
        cout << "\n| 9. Tablero           |";
        cout << "\n| 10.Regresar          |";
        cout << "\n|----------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin>>opcR;
        system("cls");
        switch(opcR)
        {
        case 1:

            LCD.Graficar();
            break;
        case 2:
            CL.graficarCola();
            break;
        case 3:
            ABB.graficar();
            break;
        case 4:
            ABB.recorridoPre();
            break;
        case 5:
            ABB.recorridoIn();
            break;
        case 6:
            ABB.recorridoPost();
            break;
        case 7:
            {
                if(primero == jugador1)
                {
                    ListaJ1.graficarLista(primero);
                }
                else
                {
                    ListaJ1.graficarLista(segundo);
                }

                if(segundo == jugador1)
                {
                    ListaJ2.graficarLista(primero);
                }
                else
                {
                    ListaJ2.graficarLista(segundo);
                }
            }
            //LO.graficarLista();
            break;
        case 8:
            //LO.graficarLista();
            break;
        case 9:
            Matriz.Graficar();
            break;
        }
    }
    while(opcR!= 10);
}
///MÉTODOS DEL JUEGO
void menu::movimientoJ1()
{
    int J1 = 0;
    int OpS;
    do
    {
        cout << "\n|----------------------|";
        cout << "\n|  °  "+primero+"  °   |";
        cout << "\n|----------------------|";
        cout << "\n| 1. Agregar letra     |";
        cout << "\n| 2. Validar palabra   |";
        cout << "\n| 3. Cambiar fichas    |";
        cout << "\n| 4. Paso              |";
        cout << "\n| 5. Terminar Juego    |";
        cout << "\n|----------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin>>J1;
        system("cls");
        switch(J1)
        {
        case 1:
            {
                //int x, y;
                //char c;
                cout << "coordenada X: " << endl;
                cin >> x;
                cout << "coordenada Y: " << endl;
                cin >> y;
                cout << "letra: " << endl;
                cin >> c;
                if(primero == jugador1)
                {
                    if(j1.buscarNodo(c) != NULL)
                    {
                        j1.eliminarNodo(c);
                        palabraJ1 += CL.getString(c);
                        Matriz.InsertarElemento(x,y,c);
                        jugar1.agregarNodo(x,y,c);
                        //jugar1.imprimirLista();
                        Matriz.Graficar();
                        j1.graficarLista(primero);
                        //cout << palabraJ1 << endl;
                    }
                    else
                    {
                        cout << "La letra no se encuentra en la lista\n\n";
                    }
                }
                else if(primero == jugador2)
                {
                    if(j2.buscarNodo(c) != NULL)
                    {
                        j2.eliminarNodo(c);
                        palabraJ2 += CL.getString(c);
                        Matriz.InsertarElemento(x,y,c);
                        jugar2.agregarNodo(x,y,c);
                        //jugar2.imprimirLista();
                        Matriz.Graficar();
                        j2.graficarLista(primero);
                        //cout << palabraJ2 << endl;
                    }
                    else
                    {
                        cout << "La letra no se encuentra en la lista\n\n";
                    }
                }
            }
            break;
        case 2:
            {

                if(primero == jugador1)
                {/*
                    if(jugar1.buscarColumna() != NULL)
                    {
                        ///la palabra se busca en las columnas
                        palabraJ1 = Matriz.recorrerColumna(jugar1.retornarColumna());*/
                        if(LCD.buscarPalabra(palabraJ1) != NULL)
                        {
                            cout << "la palabra si existe \n\n";
                            for(int i = 0; i<palabraJ1.size(); i++)
                            {
                                puntajej1 = puntajej1 + sumaPuntos(palabraJ1[i]);
                            }
                            cout << "Tus puntos son: " << LD.getIntToString(puntajej1) << endl;
                            palabraJ1 = "";
                            movimientoJ2();
                        }
                        else
                        {
                            cout << "La palabra no esta en el Diccionario \n\n";
                            palabraJ1 = "";
                            movimientoJ2();
                        }/*
                    }
                    else if(jugar1.buscarFila() != NULL)
                    {
                        /// la palabra se busca en las filas
                        palabraJ1 = Matriz.recorrerFila(jugar1.retornarFila());
                        if(LCD.buscarPalabra(palabraJ1) != NULL)
                        {
                            cout << "la palabra si existe \n\n";
                            for(int i = 0; i<palabraJ1.size(); i++)
                            {
                                puntajej1 = puntajej1 + sumaPuntos(palabraJ1[i]);
                            }
                            cout << "Tus puntos son: " << LD.getIntToString(puntajej1) << endl;
                            movimientoJ2();
                        }
                        else
                        {
                            cout << "La palabra no esta en el Diccionario \n\n";
                            movimientoJ2();
                        }
                    }
                    else
                    {
                        /// LA PALABRA NO EXISTE
                        cout << "Palabra no valida \n\n";
                        movimientoJ2();
                    }*/
                    ///////////////////////////////////

                }
                else
                {/*
                    if(jugar2.buscarColumna() != NULL)
                    {
                        ///la palabra se busca en las columnas
                        palabraJ2 = Matriz.recorrerColumna(jugar2.retornarColumna());*/
                        if(LCD.buscarPalabra(palabraJ2) != NULL)
                        {
                            cout << "la palabra si existe \n\n";
                            for(int i = 0; i<palabraJ2.size(); i++)
                            {
                                puntajej2 = puntajej2 + sumaPuntos(palabraJ2[i]);
                            }
                            cout << "Tus puntos son: " << LD.getIntToString(puntajej2) << endl;
                            palabraJ2 = "";
                            movimientoJ2();
                        }
                        else
                        {
                            cout << "La palabra no esta en el Diccionario \n\n";
                            palabraJ2 = "";
                            movimientoJ2();
                        }/*
                    }
                    else if(jugar2.buscarFila() != NULL)
                    {
                        /// la palabra se busca en las filas
                        palabraJ2 = Matriz.recorrerFila(jugar2.retornarFila());
                        if(LCD.buscarPalabra(palabraJ2) != NULL)
                        {
                            cout << "la palabra si existe \n\n";
                            for(int i = 0; i<palabraJ2.size(); i++)
                            {
                                puntajej2 = puntajej2 + sumaPuntos(palabraJ2[i]);
                            }
                            cout << "Tus puntos son: " << LD.getIntToString(puntajej2) << endl;
                            movimientoJ2();
                        }
                        else
                        {
                            cout << "La palabra no esta en el Diccionario \n\n";
                            movimientoJ2();
                        }
                    }
                    else
                    {
                        /// LA PALABRA NO EXISTE
                        cout << "Palabra no valida \n\n";
                        movimientoJ2();
                    }*/

                }
            }
            break;
        case 3:
            ///*PENSAR COMO HACER EL CAMBIO DE FICHAS*/
                {
                    i = 1;
                    j = 1;
                    while(i <= 7)
                    {
                        f = CL.eliminarCola();
                        //cout <<"prueba de eliminar"<< CL.getString(f);
                        j1.agregarNodo(f);
                        i++;
                    }
                    j1.graficarLista(jugador1);
                    while(j <= 7)
                    {
                        g = CL.eliminarCola();
                        j2.agregarNodo(g);
                        j++;
                    }
                    j2.graficarLista(jugador2);
                }
            break;
        case 4:
            movimientoJ2();
            break;
        case 5:
            {
                cout << "Desea terminar el Juego -*S* para salir -*n* para continuar \n";
                OpS = getch();
                switch(OpS)
                {
                case 'S':
                case 's':
                    if(primero == jugador1)
                    {
                        ListaJ1.agregarPuntaje(puntajej1);
                    }
                    else if(primero == jugador2)
                    {
                        ListaJ2.agregarPuntaje(puntajej2);
                    }
                    contador = 1;

                    MenuJugar();

                    break;
                case 'n':
                    movimientoJ1();
                    break;
                }
            }
            break;
        }
    }
    while(J1 != 5);
}

///MOVIMIENTOS DEL JUGADOR 2
void menu::movimientoJ2()
{
    int J2 = 0;
    int ops;
    do
    {
        cout << "\n|----------------------|";
        cout << "\n|  °  "+segundo+"  °   |";
        cout << "\n|----------------------|";
        cout << "\n| 1. Agregar letra     |";
        cout << "\n| 2. Validar palabra   |";
        cout << "\n| 3. Cambiar fichas    |";
        cout << "\n| 4. Paso1             |";
        cout << "\n| 5. Terminar Juego    |";
        cout << "\n|----------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin>>J2;
        system("cls");
        switch(J2)
        {
        case 1:
            {
                int x, y;
                char c;
                cout << "coordenada X: " << endl;
                cin >> x;
                cout << "coordenada Y: " << endl;
                cin >> y;
                cout << "letra: " << endl;
                cin >> c;
                if(segundo == jugador1)
                {
                    if(j1.buscarNodo(c) != NULL)
                    {
                        j1.eliminarNodo(c);
                        palabraJ1 += CL.getString(c);
                        Matriz.InsertarElemento(x,y,c);
                        jugar1.agregarNodo(x,y,c);
                        //jugar1.imprimirLista();
                        Matriz.Graficar();
                        j1.graficarLista(segundo);
                        //cout << " " << palabraJ1 << endl;
                    }
                    else
                    {
                        cout << "La letra no se encuentra en la lista\n\n";
                    }
                }
                else if(segundo == jugador2)
                {
                    if(j2.buscarNodo(c) != NULL)
                    {
                        j2.eliminarNodo(c);
                        palabraJ2 += CL.getString(c);
                        Matriz.InsertarElemento(x,y,c);
                        jugar2.agregarNodo(x,y,c);
                        //jugar2.imprimirLista();
                        Matriz.Graficar();
                        j2.graficarLista(segundo);
                        //cout << palabraJ2 << endl;
                    }
                    else
                    {
                        cout << "La letra no se encuentra en la lista\n\n";
                    }
                }
            }
            break;
        case 2:
            {

                    if(segundo == jugador1)
                    {/*
                        if(jugar1.buscarColumna() != NULL)
                        {
                            ///la palabra se busca en las columnas
                            palabraJ1 = Matriz.recorrerColumna(jugar1.retornarColumna());*/
                            if(LCD.buscarPalabra(palabraJ1) != NULL)
                            {
                                cout << "la palabra si existe \n\n";
                                for(int i = 0; i<palabraJ1.size(); i++)
                                {
                                    puntajej1 = puntajej1 + sumaPuntos(palabraJ1[i]);
                                    //cout<<palabraJ1[i] << endl;
                                    //CREAR VARIABLES GLOBALES PARA LA SUMA DE PUNTAJES, LA SUMA DEL MAIN SI FUNCIONA!!!!
                                    //HACER EL METODO QUE LLENE LA LISTA DE PUNTAJE DE CADA JUGADOR
                                    //FALTA HACER LA SUMA DE LAS CASILLAS DOBLES Y TRIPLES
                                }
                                cout << "Tus puntos son: " << LD.getIntToString(puntajej1) <<endl;
                                palabraJ1 = "";
                                movimientoJ1();
                            }
                            else
                            {
                                cout << "La palabra no esta en el Diccionario \n\n";
                                palabraJ1 = "";
                                //CORREGIR LA ELIMINACION DE LA MATRIZ, PARA DEVOLVER LAS FICHAS INGRESADAS
                                movimientoJ1();
                            }/*
                        }
                        else if(jugar1.buscarFila() != NULL)
                        {
                            /// la palabra se busca en las filas
                            palabraJ1 = Matriz.recorrerFila(jugar1.retornarColumna());
                            if(LCD.buscarPalabra(palabraJ1) != NULL)
                            {
                                cout << "la palabra si existe \n\n";
                                for(int i = 0; i<palabraJ1.size(); i++)
                                {
                                    puntajej1 = puntajej1 + sumaPuntos(palabraJ1[i]);
                                    //cout<<palabraJ1[i] << endl;
                                    //CREAR VARIABLES GLOBALES PARA LA SUMA DE PUNTAJES, LA SUMA DEL MAIN SI FUNCIONA!!!!
                                    //HACER EL METODO QUE LLENE LA LISTA DE PUNTAJE DE CADA JUGADOR
                                    //FALTA HACER LA SUMA DE LAS CASILLAS DOBLES Y TRIPLES
                                }
                                cout << "Tus puntos son: " << LD.getIntToString(puntajej1) <<endl;
                                movimientoJ1();
                            }
                            else
                            {
                                cout << "La palabra no esta en el Diccionario \n\n";
                                //CORREGIR LA ELIMINACION DE LA MATRIZ, PARA DEVOLVER LAS FICHAS INGRESADAS
                                movimientoJ1();
                            }
                        }
                        else
                        {
                            /// LA PALABRA NO EXISTE
                            cout << "Palabra no valida \n\n";
                            movimientoJ1();
                        }*/
                        ///////////////////////////////////

                    }
                    else
                    {/*
                        if(jugar2.buscarColumna() != NULL)
                        {
                            ///la palabra se busca en las columnas
                            palabraJ2 = Matriz.recorrerColumna(jugar2.retornarColumna());
                        }
                        else if(jugar2.buscarFila() != NULL)
                        {
                            /// la palabra se busca en las filas
                            palabraJ2 = Matriz.recorrerFila(jugar2.retornarFila());
                        }
                        else
                        {
                            /// LA PALABRA NO EXISTE
                            cout << "Palabra no valida \n\n";
                        }*/
                        ///////////////////////////////////
                        if(LCD.buscarPalabra(palabraJ2) != NULL)
                        {
                            cout << "la palabra si existe \n\n";
                            for(int i = 0; i<palabraJ2.size(); i++)
                            {
                                puntajej2 = puntajej2 + sumaPuntos(palabraJ2[i]);
                            }
                            cout << "Tus puntos son: " << LD.getIntToString(puntajej2) << endl;
                            palabraJ2 = "";
                            movimientoJ1();
                        }
                        else
                        {
                            cout << "La palabra no esta en el Diccionario \n\n";
                            palabraJ2 = "";
                            movimientoJ1();
                        }
                    }
            }
            break;
        case 3:
            {
                i = 1;
                j = 1;
                while(i <= 7)
                {
                    f = CL.eliminarCola();
                    //cout <<"prueba de eliminar"<< CL.getString(f);
                    j1.agregarNodo(f);
                    i++;
                }
                j1.graficarLista(jugador1);
                while(j <= 7)
                {
                    g = CL.eliminarCola();
                    j2.agregarNodo(g);
                    j++;
                }
                j2.graficarLista(jugador2);
            }
            break;
        case 4:
            movimientoJ1();
            break;
        case 5:
            {
                cout << "Desea terminar el Juego -*S* para salir -*n* para continuar \n";
                ops = getch();
                switch(ops)
                {
                case 'S':
                case 's':
                    if(segundo == jugador1)
                    {
                        ListaJ2.agregarPuntaje(puntajej1);
                    }
                    else
                    {
                        ListaJ2.agregarPuntaje(puntajej2);
                    }
                    contador = 1;

                    MenuJugar();
                    break;
                case 'n':
                    movimientoJ2();
                    break;
                }
            }
            break;
        }
    }
    while(J2 != 5);
}

///METODO PARA SUMAR PUNTOS
int menu::sumaPuntos(char c)
{
    int puntos = 0;
    {
        switch(c)
        {
        case 'a':
        case 'e':
        case 'o':
        case 'i':
        case 's':
        case 'n':
        case 'l':
        case 'r':
        case 'u':
        case 't':
            puntos = 1;
            return puntos;
            break;

        case 'd':
        case 'g':
            puntos = 2;
            return puntos;
            break;

        case 'c':
        case 'b':
        case 'm':
        case 'p':
            puntos = 3;
            return puntos;
            break;

        case 'h':
        case 'f':
        case 'v':
        case 'y':
            puntos = 4;
            return puntos;
            break;

        case 'q':
            puntos = 5;
            return puntos;
            break;

        case 'j':
        case 'x':
            puntos = 8;
            return puntos;
            break;

        case 'z':
            puntos = 10;
            return puntos;
            break;
        }
    }
}
