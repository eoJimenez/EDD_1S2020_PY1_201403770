#include "arbolprueba.h"

using namespace std;

arbolprueba::arbolprueba()
{
    root = NULL;
}

/*arbolprueba::~arbolprueba()
{
    //dtor
}*/

//METODO INSERTAR
void arbolprueba::insertar(char[] key)
{
    if(root != NULL)
    {
        insertar(key, root);
    }
    else
    {
        root = new nodoRoot(key);
        root->izquierdo = NULL;
        root->derecho = NULL;
    }
}

void arbolprueba::insertar(char[] key, nodoRoot* hoja)
{
    hoja->data
    if(strcmp(key,)
}

nodoRoot::nodoRoot(char[] key)
{
    izquierdo = NULL;
    derecho = NULL;
    data[] = key;
}
