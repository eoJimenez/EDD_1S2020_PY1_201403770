#include "Json.h"
#include "ListaCircularDoble.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <typeinfo>
using json = nlohmann::json;

using namespace std;
Json::Json()
{
    //ctor
}

void Json::leerJSon()
{
    ListaCircularDoble nueva;
    string Lcircular ="";
    std::ifstream archivo("JsNuevo.json");
    json j3;
    archivo >> j3;
    ///DEVUELVE LA DIMENSION DE LA MATRIZ
    cout<<"La dimension de la matriz es de: "<<j3.at("dimension")<<endl<<endl;

    ///CICLO QUE RECORRE EL ARCHIVO JSON
    cout<<"CASILLAS DOBLES"<<endl;
    for(int x = 0;x<j3.at("casillas").at("dobles").size();x++)
    {
        cout<<"posicion x: "<<j3.at("casillas").at("dobles")[x].at("x")<<endl;
        cout<<"posicion y: "<<j3.at("casillas").at("dobles")[x].at("y")<<endl<<endl;
    }
    cout<<"CASILLAS TRIPLES"<<endl;
    for(int x = 0;x<j3.at("casillas").at("triples").size();x++)
    {
        cout<<"posicion x: "<<j3.at("casillas").at("triples")[x].at("x")<<endl;
        cout<<"posicion y: "<<j3.at("casillas").at("triples")[x].at("y")<<endl<<endl;
    }
    cout<<"DICCIONARIO"<<endl;
    for (int x = 0;x<j3.at("diccionario").size();x++)
    {
        //cout<<"palabra: "<<j3.at("diccionario")[x].at("palabra")<<endl;
        Lcircular = j3.at("diccionario")[x].at("palabra");
        nueva.agregar(Lcircular);
        //cout << Lcircular << endl;
    }
    //nueva.Graficar();
}
