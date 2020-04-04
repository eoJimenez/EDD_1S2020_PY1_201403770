#include "MatrizD.h"
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

NodoM::NodoM(int col, int fil,char ca)
{
    columna = col;
    fila = fil;
    caracter = ca;
    arriba = NULL;
    abajo = NULL;
    siguiente = NULL;
    anterior = NULL;
}

MatrizD::MatrizD()
{
    NodoM *tmp = new NodoM(-1,-1,'R');
    root = tmp;
    columna = root->siguiente;
    Fila = root->abajo;
    nuevo = NULL;
    NodoC = NULL;
    NodoF = NULL;
    nodoNuevo = NULL;
}
///METODO QUE BUSCA EL NODO EN LA FILA Y SI EXISTE RETORNA EL NODO, SINO RETORNA NULO
NodoM *MatrizD::buscarFila(int fila)
{
    NodoM *aux = root;
    while(aux != NULL)
    {
        if(aux->fila == fila)
        {
            return aux;
        }
        aux = aux->abajo;
    }
    return NULL;
}
///METODO QUE BUSCA EL NODO EN LA COLUMNA Y SI EXISTE RETORNA EL NODO, SINO RETORNA NULO
NodoM *MatrizD::buscarColumna(int columna)
{
    NodoM *aux = root;
    while(aux != NULL)
    {
        if(aux->columna == columna)
        {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}
///MÉTODO QUE INSERTA LOS NODOS ORDENADOS EN LA COLUMNA
NodoM *MatrizD::insertarOrdenadoColumna(NodoM* nuevo,NodoM* cabCol)
{
    NodoM *temp = cabCol;
    bool bandera = false;
    while(true)
    {
        if(temp->columna == nuevo->columna)///SI LA POSICION ES LA MISMA SOBRE ESCRIBIR
        {
            temp->fila = nuevo->fila;
            temp->caracter = nuevo->caracter;
            return temp; ///RETORNAR LA POSICION DEL NODO
        }
        else if(temp->columna > nuevo->columna)///LA INSERCIÓN SERA ANTES DEL NODO TEMP
        {
            bandera = true;
            break;
        }
        if(temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        else
        {
            break;///LA INSERCIÓN DEL NUEVO NODO SERÁ DESPUES DEL NODO TEMP; BANDERA = FALSE
        }
    }
    if(bandera == true)///INSERCIÓN ANTES DEL NODO TEMP
    {
        nuevo->siguiente = temp;
        temp->anterior->siguiente = nuevo;
        nuevo->anterior = temp->anterior;
        temp->anterior = nuevo;
    }
    else ///INSERCIÓN AL FINAL
    {
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
    }
    return nuevo;
}
///MÉTODO QUE INSERTA LOS NODOS ORDENADOS EN LA FILA
NodoM *MatrizD::insertarOrdenadoFila(NodoM* nuevo, NodoM* cabFil)
{
    NodoM *temp = cabFil;
    bool bandera = false;
    while(true)
    {
        if(temp->fila == nuevo->fila)///SI LA POSICION ES LA MISMA SOBRE ESCRIBIR
        {
            temp->columna = nuevo->columna;
            temp->caracter = nuevo->caracter;
            return temp; ///RETORNAR LA POSICION DEL NODO
        }
        else if(temp->fila > nuevo->fila)///LA INSERCIÓN SERA ANTES DEL NODO TEMP
        {
            bandera = true;
            break;
        }
        if(temp->abajo != NULL)
        {
            temp = temp->abajo;
        }
        else
        {
            break;///LA INSERCIÓN DEL NUEVO NODO SERÁ DESPUES DEL NODO TEMP; BANDERA = FALSE
        }
    }
    if(bandera == true)///INSERCIÓN ANTES DEL NODO TEMP
    {
        nuevo->abajo = temp;
        temp->arriba->abajo = nuevo;
        nuevo->arriba = temp->arriba;
        temp->arriba = nuevo;
    }
    else ///INSERCIÓN AL FINAL
    {
        temp->abajo = nuevo;
        nuevo->arriba = temp;
    }
    return nuevo;
}
///MÉTODO QUE CREA LAS COLUMNAS
NodoM *MatrizD::crearColumna(int x)
{
    NodoM *cabCol = root;
    NodoM *nuevo = new NodoM(x,-1,'C');
    columna = insertarOrdenadoColumna(nuevo,cabCol);
    return columna;
}
///MÉTODO QUE CREA LAS FILAS
NodoM *MatrizD::crearFila(int y)
{
    NodoM *cabFil = root;
    NodoM *nuevo = new NodoM(-1,y,'F');
    Fila = insertarOrdenadoFila(nuevo,cabFil);
    return Fila;
}
///MÉTODO QUE HACE LA INSERCIÓN DE LOS NODOS EN LA MATRIZ
void MatrizD::InsertarElemento(int column, int row,char dato)
{
    nuevo = new NodoM(column,row,dato);
    NodoC = buscarColumna(column);
    NodoF = buscarFila(row);
    ///CASO 1: COLUMNA Y FILA NO EXISTEN
    if(NodoC == NULL && NodoF == NULL)
    {
        //cout<<"caso1"<<endl;
        ///CREAR COLUMNA
        NodoC = crearColumna(column);
        //cout<<"nodoC ejecutado"<<endl;
        ///CREAR FILA
        NodoF = crearFila(row);
        //cout<<"nodoF ejecutado"<<endl;
        ///INSERTAR ORDENADO EN COLUMNA
        nuevo = insertarOrdenadoColumna(nuevo,NodoF);
        //cout<<"nodoNuevoColumna insertado"<<endl;
        ///INSERTAR ORDENADO EN FILA
        nuevo = insertarOrdenadoFila(nuevo,NodoC);
       // cout<<"nodonuevoFila insertado"<<endl;
    }
    ///CASO 2: COLUMNA NO EXISTE, FILA SI EXISTE
    else if(NodoC == NULL && NodoF != NULL)
    {
        //cout<<"caso2"<<endl;
        ///CREAR FILA
        NodoC = crearColumna(column);
        //cout<<"nodoF ejecutado"<<endl;
        ///INSERTAR ORDENADO EN COLUMNA
        //cout<<"nodo: "<<nuevo->caracter<<endl;
        //cout<<"fila: "<<NodoF->fila<<endl;
        nuevo = insertarOrdenadoColumna(nuevo,NodoF);
        //cout<<"nodoNuevoColumna insertado"<<endl;
        ///INSERTAR ORDENADO EN FILA
        //cout<<"nodo"<<nuevo->caracter<<endl;
        //cout<<"nodo"<<NodoC->columna<<endl;
        nuevo = insertarOrdenadoFila(nuevo,NodoC);
        //cout<<"nodonuevoFila insertado"<<endl;
    }
    ///CASO 3: COLUMNA SI EXISTE, FILA NO EXISTE
    else if(NodoC != NULL && NodoF == NULL)
    {
        //cout<<"caso3"<<endl;
        ///CREAR COLUMNA
        NodoF = crearFila(row);
        //cout<<"nodoC ejecutado"<<endl;
        ///INSERTAR ORDENADO EN COLUMNA
        //cout<<"nodo: "<<nuevo->caracter<<endl;
        ///cout<<"fila: "<<NodoF->fila<<endl;
        nuevo = insertarOrdenadoColumna(nuevo,NodoF);
        //cout<<"nodoNuevoColumna insertado"<<endl;
        ///INSERTAR ORDENADO EN FILA
        //cout<<"nodo: "<<nuevo->caracter<<endl;
        //cout<<"columna: "<<NodoC->columna<<endl;
        nuevo = insertarOrdenadoFila(nuevo,NodoC);
        //cout<<"nodonuevoFila insertado"<<endl;
    }
    ///CASO 4: COLUMNA Y FILA SI EXISTEN
    else if(NodoC != NULL && NodoF != NULL)
    {
        //cout<<"caso4"<<endl;
        ///INSERTAR ORDENADO EN COLUMNA
        nuevo = insertarOrdenadoColumna(nuevo,NodoF);
        //cout<<"nodoNuevoColumna insertado"<<endl;
        ///INSERTAR ORDENADO EN FILA
        nuevo = insertarOrdenadoFila(nuevo,NodoC);
        //cout<<"nodonuevoFila insertado"<<endl;
    }
}
///IMPRIMIR MATRIZ
void MatrizD::imprimir()
{
    NodoM *tempC = root->siguiente;
    while(tempC != NULL)
    {
        NodoM *nodos = tempC->abajo;
        while(nodos != NULL)
        {
            cout<<"-Fila: "<<nodos->fila<<"Columna: "<<nodos->columna<<"caracter: "<<nodos->caracter<<endl;
            nodos = nodos->abajo;
        }
        tempC = tempC->siguiente;
    }
}
///MÉTODO QUE LLAMA AL METODO GRAFICAR MATRIZ
void MatrizD::Graficar()
{
    return GraficarMatriz(root);
}
///METODO QUE GRAFICA LA MATRIZ
void MatrizD::GraficarMatriz(NodoM* Raiz)
{
    ofstream archivoM;
    archivoM.open("C:/imagenes/MatrizDispersa.dot",ios::out);
    if(archivoM.fail())
    {
        cout<<"Error al crear el archivo";
        exit(1);
    }
    archivoM<<"digraph G {\ngraph [ranksep=\"0.5\", nodesep=\"0.5\"];\n"<<endl;
    if(root->siguiente == NULL && root->abajo == NULL)
    {
        string cadena = "";
        cout<<"matriz Vacia" <<endl;

        cadena +="F"+getString(root->caracter);
        cadena +="[label =\"";
        cadena += getString(root->caracter)+"\"";
        cadena +="width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"orange:red\", group = Mt0] ;\n";
        archivoM << cadena << endl;
    }
    else
    {
        archivoM <<"R[width = 1.0 group = \"Mt0\",  style=filled,shape=\"underline\",fillcolor=\"orange:red\" label=\"R\"];\n"<<endl;
        archivoM<<NodosFilas()<<endl;;
        archivoM<<NodosColumnas()<<endl;
        archivoM<<EnlaceNodos()<<endl;
        archivoM<<RankSame();
        archivoM<<enlaceColumna();
        archivoM<<enlaceNodosEnMedio();
    }
    archivoM<<"\n";
    archivoM<<"\tlabel=\"SCRABBLE\";"<<endl;
    archivoM<<"\n}"<<endl;
    archivoM.close();
    system("dot C:/imagenes/MatrizDispersa.dot -o C:/imagenes/MatrizDispersa.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/MatrizDispersa.png");
}
///CREANDO FILAS DE LA MATRIZ
string MatrizD::NodosFilas()
{
    string cadena = "";
    NodoM *aux = root->abajo;
    while(aux != NULL)
    {
        cadena +="F"+IntToString(aux->fila);
        cadena +="[label =\"";
        cadena += IntToString(aux->fila)+"\"";
        cadena +="width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"violet:red\", group = Mt0] ;\n";
        aux = aux->abajo;
    }
    aux = root->abajo;

    while(aux != NULL)
    {
        if(aux->abajo != NULL)
        {
            cadena += "F"+IntToString(aux->fila);
            cadena += "->";
            cadena += "F"+IntToString(aux->abajo->fila);
            cadena += " [dir=both];\n";
        }
        aux = aux->abajo;
    }
    return cadena;
}
///CREANDO COLUMNAS DE LA MATRIZ
string MatrizD::NodosColumnas()
{
    NodoM *aux = root->siguiente;
    NodoM *temp = root->abajo;
    string cadena = "";
    string primF ="";
    string primC ="";
    primC = "C"+IntToString(aux->columna);
    primF = "F"+IntToString(temp->fila);
    while(aux != NULL)
    {
        cadena += "C"+IntToString(aux->columna);
        cadena += "[label =\"";
        cadena += IntToString(aux->columna)+"\"";
        cadena += "width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"violet:red\", group = Mt0] ;\n";

        aux = aux->siguiente;
    }
    aux = root->siguiente;
    while(aux != NULL)
    {
        if(aux->siguiente != NULL)
        {
            cadena += "C"+IntToString(aux->columna);
            cadena += "->";
            cadena += "C"+IntToString(aux->siguiente->columna);
            cadena += "[dir=both];\n";
        }
        aux = aux->siguiente;
    }
    aux = root->siguiente;
    cadena += "{rank = same; R;";
    while(aux != NULL)
    {
        cadena += "C"+IntToString(aux->columna);
        if(aux->siguiente != NULL)
        {
            cadena += ";";
        }
        aux = aux->siguiente;
    }
    cadena += "}\n";
    cadena += "R ->"+primC+";\n";
    cadena += "R ->"+primF+";\n";
    return cadena;
}
///ENLACE DE LOS NODOS DE DATOS
string MatrizD::EnlaceNodos()
{
    //NodoM *aux = root->abajo;
    string cad = "";
    NodoM *contenidoF = root->abajo;
    NodoM *enlace = root->abajo;

    NodoM *primero;
    while(contenidoF != NULL)
    {
        if(contenidoF->siguiente != NULL)
        {
            cad += IntToString(contenidoF->siguiente->fila);
            cad += IntToString(contenidoF->siguiente->columna);
            cad += "[label=\"";
            cad += getString(contenidoF->siguiente->caracter)+"\"";
            cad += "width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"violet\",group =";
            cad += IntToString(contenidoF->siguiente->columna)+"];\n";
        }
        contenidoF = contenidoF->abajo;
    }

    while(enlace != NULL)
    {
        if(enlace->siguiente != NULL)
        {
            cad +="F"+IntToString(enlace->fila);
            cad += "->";
            cad += IntToString(enlace->siguiente->fila);
            cad += IntToString(enlace->siguiente->columna);
            cad += "[dir=both,constraint = false];\n";
        }
        enlace = enlace->abajo;
    }

    enlace = root->abajo;
    while(enlace != NULL)
    {
        if(enlace->siguiente->siguiente != NULL)
        {
            primero = enlace->siguiente->siguiente;
            while(primero != NULL)
            {
                cad += IntToString(primero->fila);
                cad += IntToString(primero->columna);
                cad += "[label=\"";
                cad += getString(primero->caracter)+"\"";
                cad += "width = 1.0 style = filled,shape=\"rectangle\", fillcolor = \"violet\", group =";
                cad += IntToString(primero->columna)+"];\n";
                primero = primero->siguiente;
            }
        }
        enlace = enlace->abajo;
    }
    enlace = root->abajo;
    while(enlace != NULL)
    {
        if(enlace->siguiente != NULL)
        {
            primero = enlace->siguiente;
            while(primero != NULL)
            {
                if(primero->siguiente != NULL)
                {
                    cad += IntToString(primero->fila);
                    cad += IntToString(primero->columna);
                    cad += "->";
                    cad += IntToString(primero->siguiente->fila);
                    cad += IntToString(primero->siguiente->columna);
                    cad += "[dir=both,contraint = false];\n";
                }
                primero = primero->siguiente;
            }
        }
        enlace = enlace->abajo;
    }
    return cad;
}
string MatrizD::RankSame()
{
    NodoM *tempFBaja = root->abajo;
    NodoM *tempFDerecha;
    string cadena ="";
    while(tempFBaja != NULL)
    {
        cadena += "{rank = same;";
        cadena += "F"+IntToString(tempFBaja->fila)+";";
        tempFDerecha = tempFBaja->siguiente;
        while(tempFDerecha != NULL)
        {
            cadena += IntToString(tempFDerecha->fila);
            cadena += IntToString(tempFDerecha->columna);
            cadena += ";";

            tempFDerecha = tempFDerecha->siguiente;
        }
        cadena += "}\n";

        tempFBaja = tempFBaja->abajo;
    }
    return cadena;
}
string MatrizD::enlaceColumna()
{
    NodoM *auxCol = root->siguiente;
    string cadena = "";
    while(auxCol != NULL)
    {
        if(auxCol->abajo != NULL)
        {
            cadena += "C"+IntToString(auxCol->columna);
            cadena += "->";
            cadena += IntToString(auxCol->abajo->fila);
            cadena += IntToString(auxCol->abajo->columna);
            cadena += "[dir=both];\n";
        }
        auxCol = auxCol->siguiente;
    }
    return cadena;
}
string MatrizD::enlaceNodosEnMedio()
{
    string cadena = "";
    NodoM *auxND = root->siguiente;
    NodoM *primero;
    while(auxND != NULL)
    {
        if(auxND->abajo != NULL)
        {
            primero = auxND->abajo;
            while(primero != NULL)
            {
                if(primero->abajo != NULL)
                {
                    cadena += IntToString(primero->fila);
                    cadena += IntToString(primero->columna);
                    cadena += "->";
                    cadena += IntToString(primero->abajo->fila);
                    cadena += IntToString(primero->abajo->columna);
                    cadena += "\n";
                    cadena += "[dir=both];\n";
                }
                primero = primero->abajo;
            }
        }
        auxND = auxND->siguiente;
    }
    return cadena;
}
string MatrizD::IntToString(int i)
{
    string str = to_string(i);
    return str;
}
string MatrizD::getString(char c)
{
    string s(1,c);
    return s;
}

void MatrizD::modificar(int x, int y, char dato)///HAY QUE ELIMINAR LAS CABECERAS DE FILAS Y COLUMNAS
{
    NodoM *tempC = root->siguiente;
    NodoM *tempF = root->abajo;
    while(tempC != NULL)
    {
        if(tempC->columna == x)
        {
            break;
        }
        tempC = tempC->siguiente;
    }
    while(tempF != NULL)
    {
        if(tempF->fila == y)
        {
            break;
        }
        tempF = tempF->abajo;
    }

    if(tempC->columna == x)
    {
        NodoM *tempInter = tempC->abajo;
        while(tempInter != NULL)
        {
            if(tempInter->fila == y)
            {
                break;
            }
            tempInter = tempInter->abajo;
        }

        if(tempInter->fila == y)
        {
            ///ACÁ SE REGRESA EL DATO A LA LISTA Y SE MUEVEN APUNTADORES
            cout << getString(tempInter->caracter);
            cout << IntToString(tempF->fila);///APUNTADOR A LA CABECERA DE FILA
            cout << IntToString(tempC->columna)<<endl;///APUNTADOR A LA CABECERA DE COLUMNA
            if(tempInter->siguiente != NULL && tempInter->anterior != NULL)
            {
                NodoM *Antaux = tempInter->anterior;
                NodoM *Sigaux = tempInter->siguiente;
                Antaux->siguiente = Sigaux;
                Sigaux->anterior = Antaux;/*
                tempInter->anterior->siguiente = tempInter->siguiente;
                tempInter->siguiente->anterior = tempInter->anterior;*/
            }
            if(tempInter->abajo != NULL && tempInter->arriba != NULL)
            {
                NodoM *Araux = tempInter->arriba;
                NodoM *Abaux = tempInter->abajo;
                Araux->abajo = Abaux;
                Abaux->arriba = Araux;/*
                tempInter->arriba->abajo = tempInter->abajo;
                tempInter->abajo->arriba = tempInter->arriba;*/
            }
            if(tempInter->arriba != NULL && tempInter->abajo == NULL)
            {
                NodoM *auxAr = tempInter->arriba;
                auxAr->abajo = NULL;
                tempInter->arriba = NULL;
                //tempInter->arriba->abajo = NULL;
                //tempInter->arriba = NULL;
            }
            if(tempInter->anterior != NULL && tempInter->siguiente == NULL)
            {
                NodoM *auxAnt = tempInter->anterior;
                auxAnt->siguiente = NULL;
                tempInter->anterior = NULL;
                /*
                tempInter->anterior->siguiente = NULL;
                tempInter->anterior = NULL;*/
            }/*
            if(tempInter->arriba->columna == tempC->columna && tempInter->abajo == NULL)
            {
                if(tempInter->siguiente == NULL && tempInter->anterior->fila == tempF->fila)
                {
                    tempInter->arriba = NULL;
                    tempInter->anterior = NULL;/*
                    tempC->abajo = NULL;
                    tempF->siguiente = NULL;/*
                    if(tempC->anterior != NULL && tempC->siguiente != NULL)
                    {
                        tempC->anterior->siguiente = tempC->siguiente;
                        tempC->siguiente->anterior = tempC->anterior;
                        tempC->siguiente = NULL;
                        tempC->anterior = NULL;
                    }
                    if(tempC->siguiente == NULL)
                    {
                        tempC->anterior->siguiente = NULL;
                        tempC->anterior = NULL;
                    }
                    if(tempF->arriba != NULL && tempF->abajo != NULL)
                    {
                        tempF->arriba->abajo = tempF->abajo;
                        tempF->abajo->arriba = tempF->arriba;
                        tempF->abajo = NULL;
                        tempF->arriba = NULL;
                    }
                    if(tempF->abajo == NULL)
                    {
                        tempF->arriba->abajo = NULL;
                        tempF->arriba = NULL;
                    }
                }
            }*/
            /*
            if(tempInter->arriba != NULL && tempInter->abajo == NULL)
            {
                if(tempInter->siguiente == NULL && tempInter->anterior != NULL)
                {
                    NodoM *arriba = tempInter->arriba;
                    NodoM *anterior = tempInter->anterior;
                    arriba->abajo = NULL;
                    anterior->siguiente = NULL;
                    //tempInter->arriba = NULL;
                    //tempInter->anterior = NULL;
                    /*
                    tempInter->arriba->abajo = NULL;;
                    //tempInter->arriba = NULL;
                    tempInter->anterior->siguiente = NULL;
                    //tempInter->anterior = NULL;
                }
            }
            /*
            if(tempInter->anterior->anterior == NULL && tempInter->siguiente == NULL)
            {
                tempInter->anterior->siguiente = NULL;
                tempInter->anterior = NULL;/*
                if(tempInter->arriba != NULL && tempInter->abajo == NULL)
                {
                    tempInter->arriba->siguiente = NULL;
                    tempInter->arriba = NULL;
                }
                ///NO FUNCIONA ESTE CODIGO
            else
            {
                NodoM *nodoFila = tempInter->anterior;
                if(nodoFila->abajo != NULL)
                {
                    nodoFila->abajo->arriba = nodoFila->arriba;
                    nodoFila->arriba->abajo = nodoFila->abajo;
                }
                else
                {
                    nodoFila->arriba->abajo = NULL;
                    nodoFila->arriba = NULL;
                }
                tempInter->anterior->siguiente = NULL;
                tempInter->anterior = NULL;
            }
            }

            if(tempInter->anterior && tempInter->siguiente != NULL)
            {
                tempInter->anterior->siguiente = tempInter->siguiente;
                tempInter->siguiente->anterior = tempInter->anterior;
            }
            else
            {
                tempInter->siguiente = NULL;
                tempInter->anterior = NULL;
                tempInter->arriba = NULL;
                tempInter->abajo = NULL;
            }*/
        }
        else
        {
            cout <<"nodo buscado no encontrado"<<endl;
            return;
        }
    }
}
