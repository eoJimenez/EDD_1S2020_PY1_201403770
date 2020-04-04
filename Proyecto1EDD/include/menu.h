#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;
class menu
{
    public:
        menu();
        void MenuPrincipal();///MENU PRINCIPAL
        ///SUB MENU
        void LeerArchivo();///MÉTODO QUE SE EJECUTA
        void Reportes();///LLAMADAS A LOS METODOS QUE HACEN LAS GRÁFICAS
        void IniciarJuego();
        ///SUB MENU JUGAR
        void ingresarJugadores();
        void MenuJugar();
        ///SUB MENU MENUJUGAR
        void validarJugadores();
        void MenuScrabble();
        ///MOVIMIENTOS DE LOS JUGADORES
        void movimientoJ1();
        void movimientoJ2();
        void cambioFichasJ1();
        void cambioFichasJ2();


    protected:

    private:
};

#endif // MENU_H
