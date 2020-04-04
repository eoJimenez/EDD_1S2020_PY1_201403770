#include "Cola.h"
#include "ListaDoble.h"
#include "iostream"
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <time.h>

using namespace std;

//CONSTRUCTOR CLASE COLA
Cola::Cola()
{
    primero = NULL;
    ultimo = primero;
}

void Cola::agregarCola(char c, int p)
{
    nodoCola *aux = new nodoCola(c,p);
    if(primero != NULL)
    {
        ultimo->siguiente = aux;
        ultimo = ultimo->siguiente;
    }
    else
    {
        primero = aux;
        ultimo = primero;
    }
}

void Cola::imprimirCola()
{
    nodoCola *temp = primero;
    while(temp != NULL)
    {
        cout << temp->caracter <<" "<< temp->puntaje<<endl;
        temp = temp->siguiente;
    }
}

char Cola::eliminarCola()
{
    nodoCola *aux = primero;
    if(primero != NULL)
    {
        primero = aux->siguiente;
        char e = aux->caracter;
        return e;
        //cout << e << endl;
    }
}
void Cola::graficarCola()
{
    string cadena = "";
    string cadena1 = "";
    ofstream archivoCola;
    archivoCola.open("C:/imagenes/Cola.dot",ios::out);
    archivoCola <<"digraph Cola\n{"<<endl;
    archivoCola <<"node [shape=plaintext]" <<endl;
    archivoCola <<"some_node ["<<endl;
    archivoCola <<"label=<"<<endl;
    archivoCola <<"<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">"<<endl;
    /*archivoCola <<"\trankdir=LR;"<<endl;
    archivoCola<<"\tgraph [nodesep=0.3];"<<endl;
    archivoCola<<"\tsubgraph cluster_0{"<<endl;
    archivoCola<<"\tstyle=filled;"<<endl;
    archivoCola<<"\tcolor=lightgrey;"<<endl;
    archivoCola<<"\tlabelloc=t;"<<endl;
    archivoCola<<"\tnode [shape = record, style=\"rounded,filled\"fillcolor=\"red:violet\",width=0.7,height=0.5];"<<endl;*/
    cadena = DefNodos();
    //cadena1 = apuntadores();
    archivoCola<<"\n";
    archivoCola<<cadena<<endl;
    archivoCola<<"\n";
    //archivoCola<<cadena1<<endl;
    //archivoCola<<"\n";
    archivoCola<<"</table>>"<<endl;
    archivoCola<<"];"<<endl;
    archivoCola<<"\tlabel=\"Cola\n\n\";"<<endl;
    archivoCola<<"}"<<endl;
    archivoCola.close();
    system("dot C:/imagenes/Cola.dot -o C:/imagenes/Cola.png -Tpng -Gcharset=utf8");
    system("C:/imagenes/Cola.png");
}
string Cola::DefNodos()
{
    string cad = "";

    if(primero == NULL)
    {
        cout << "La Cola Esta Vacia" << endl;
    }
    else
    {
        nodoCola *aux = primero;
        while(aux != NULL)
        {
            cad += "<tr><td bgcolor=\"red:orange\">";
            cad += getString(aux->caracter)+" x "+getIntToString(aux->puntaje)+"pts";
            cad += "</td></tr>";
            cad += "\n";
            //cad += "\t"+getString(aux->caracter)+getIntToString(aux->puntaje)+"[label =\"{"+getString(aux->caracter)+" x "+getIntToString(aux->puntaje)+"pts"+ "}\"];\n";
            aux = aux->siguiente;
        }
    }
    return cad;
}
string Cola::apuntadores()
{
    string cad = "";
    if(primero == NULL)
    {
        cout << "La Cola Esta Vacia" << endl;
    }
    else
    {
        nodoCola *temp = primero;
        while(temp->siguiente != NULL)
        {
            cad += "\t"+getString(temp->caracter)+getIntToString(temp->puntaje)+"->"+getString(temp->siguiente->caracter)+getIntToString(temp->siguiente->puntaje)+";\n";
            temp = temp->siguiente;
        }
    }
    return cad;
}
string Cola::getString(char c)
{
    string s(1,c);
    return s;
}
string Cola::getIntToString(int i)
{
    string str = to_string(i);
    return str;
}
void Cola::colaAleatoria()
{

    char letras[95] = {'b','m','p','h','b','m','p','h','g','g',///2
                        'a','a','a','a','a','a','a','a','a','a','a','a',///12
                        'e','e','e','e','e','e','e','e','e','e','e','e',///12
                        'o','o','o','o','o','o','o','o','o',///9
                        'i','s','i','s','i','s','i','s','i','s','i','s',///6
                        'r','r','r','r','r','n','n','n','n','n',///5
                        'd','d','d','d','d','u','u','u','u','u',///5
                        'l','l','l','l',///4
                        'c','c','c','c','t','t','t','t',///4
                        'f','v','y','q','j','ñ','x','z'};
    int num, c, conA = 1,conE = 1,conO = 1,conI = 1,conS = 1,conN = 1,conL = 1,conR = 1,conU = 1,conT = 1;
    int conD,conG= 1,conC= 1,conB= 1,conM= 1,conP= 1,conH= 1,conF= 1,conV= 1,conY= 1,conQ= 1,conJ= 1,conX= 1,conZ = 1;
    srand(time(NULL));
    //for(c = 1; c <= 125; c++)
    while(conA < 12 || conE <12 || conO < 9 || conI < 6 || conS < 6 || conN < 5 || conL < 4
          || conR < 5 || conU < 5 || conT < 4 || conD < 5 || conG < 2 || conC < 4 || conB < 2
          || conM < 2 || conP < 2 || conH < 2 || conF < 1 || conV < 1 || conY < 1 || conQ < 1
          || conJ < 1 || conX < 1 || conZ < 1)
    {
        char caracter = letras[rand() % 95];
        //num = 1 + rand() % (21 - 1);
        //cout << caracter << " ";
        if(caracter == 'a' && conA <= 12)
        {
            agregarCola(caracter,1);
            conA++;
            //cout << caracter << endl;
        }
        else if(caracter == 'e' && conE <= 12)
        {
            agregarCola(caracter,1);
            conE++;
            //cout << caracter << endl;
        }
        else if(caracter == 'o' && conO <= 9)
        {
            agregarCola(caracter,1);
            conO++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'i' && conI <= 6)
        {
            agregarCola(caracter,1);
            conI++;
            //cout << caracter <<endl;
        }
        else if(caracter == 's' && conS <= 6)
        {
            agregarCola(caracter,1);
            conS++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'n' && conN <= 5)
        {
            agregarCola(caracter,1);
            conN++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'l'&& conL <= 4)
        {
            agregarCola(caracter,1);
            conL++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'r' && conR <= 5)
        {
            agregarCola(caracter,1);
            conR++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'u' && conU <=5)
        {
            agregarCola(caracter,1);
            conU++;
            //cout << caracter <<endl;
        }
        else if(caracter == 't' && conT <= 4)
        {
            agregarCola(caracter,1);
            conT++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'd' && conD <= 5)
        {
            agregarCola(caracter,2);
            conD++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'g' && conG <= 2)
        {
            agregarCola(caracter,2);
            conG++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'c' && conC <= 4)
        {
            agregarCola(caracter,3);
            conC++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'b' && conB <= 2)
        {
            agregarCola(caracter,3);
            conB++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'm' && conM <= 2)
        {
            agregarCola(caracter,3);
            conM++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'p' && conP <= 2)
        {
            agregarCola(caracter,3);
            conP++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'h' && conH <= 2)
        {
            agregarCola(caracter,4);
            conH++;
            //cout << caracter <<endl;
        }
        else if(caracter == 'f' && conF == 1)
        {
            agregarCola(caracter,4);
            //cout << caracter <<endl;
        }
        else if(caracter == 'v' && conV == 1)
        {
            agregarCola(caracter,4);
            //cout << caracter <<endl;
        }
        else if(caracter == 'y' && conY == 1)
        {
            agregarCola(caracter,4);
            //cout << caracter <<endl;
        }
        else if(caracter == 'q' && conQ == 1)
        {
            agregarCola(caracter,5);
            //cout << caracter <<endl;
        }
        else if(caracter == 'j' && conJ == 1)
        {
            agregarCola(caracter,8);
            //cout << caracter <<endl;
        }/*
        else if(caracter == 'Ñ')
        {
            agregarCola(caracter,8);
        }*/
        else if(caracter == 'x' && conX == 1)
        {
            agregarCola(caracter,8);
            //cout << caracter <<endl;
        }
        else if(caracter == 'z' && conZ == 1)
        {
            agregarCola(caracter,10);
            //cout << caracter <<endl;
        }
    }

    /*
    int contA,contB;
    char A;//B,C,D,E,F,G,H,I,J,K,L,M,N,Ñ,O,P,Q,R,S,T,U,V,X,Y,Z;
    char B;
    char letras[95] = { 'B','M','P','H','B','M','P','H','G','G',///2
                        'A','A','A','A','A','A','A','A','A','A','A','A',///12
                        'E','E','E','E','E','E','E','E','E','E','E','E',///12
                        'O','O','O','O','O','O','O','O','O',///9
                        'I','S','I','S','I','S','I','S','I','S','I','S',///6
                        'R','R','R','R','R','N','N','N','N','N',///5
                        'D','D','D','D','D','U','U','U','U','U',///5
                        'L','L','L','L',///4
                        'C','C','C','C','T','T','T','T',///4

                        'F','V','Y','Q','J','Ñ','X','Z'};///1
    for(int i = 0; i < 100; i++)
    {
        char caracter = letras[ rand() % 95];
        //cout << caracter<< ",";
        agregarCola(caracter,1);
    }*/

    //-getch();
}
void Cola::ObtenerFichas()
{
    int i;
    for (i = 1;i<=7 ;i++ )
        eliminarCola();
}
//CONSTRUCTOR CLASE NODO COLA
nodoCola::nodoCola(char c,int p)
{
    siguiente = NULL;
    caracter = c;
    puntaje = p;
}


