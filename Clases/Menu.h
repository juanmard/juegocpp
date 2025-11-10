///
/// @file Menu.h
/// @brief Fichero de definición de la clase "Menu".
/// @author Juan Manuel Rico
/// @date Noviembre 2025
/// @version 1.1.0
///

#ifndef _MENU_H_
#define _MENU_H_

#include <allegro.h>
#include <vector>
#include <string>

/// Menú para interaccionar con los objetos editables.
///
/// Se define esta clase para tratar de independizar lo más posible de los menús de Allegro y poder integrarla en la GUI de forma fácil.
/// @note Para pruebas de momento se deja la misma estructura de los items de menús pero en este caso se forman los menús de forma dinámica.
/// @todo Hay que solucionar como se llama a los métodos que define cada ítem, puesto que para que funcionen con la estructura de Allegro
///       se necesita que sean métodos estáticos.
///
class Menu
{
protected:
    std::vector<MENU>::iterator iter;   ///< Iterador para los items del menú.
    std::vector<MENU> items;            ///< Items que componen el menú.
    static MENU fin_menu;               ///< Item que marca el final de los items del menú.

public:
    /// Constructor.
    ///
    Menu ();

    /// Destructor.
    ///
    ~Menu ();

    /// Generamos un conversor de tipo para el tipo MENU de "Allegro".
    ///
    operator MENU* ();

    /// Añade un menú como parte del item del menú.
    ///
    /// @param nuevo  Menú a modo de ítem para añadir al menú principal.
    ///
    void add (Menu nuevo);

    /// Añade un nuevo componente de menú.
    ///
    /// @param etiqueta  Cadena con el valor de la etiqueta a mostrar.
    /// @param opciones  Opciones del menú (deshabilitado por defecto).
    /// @param metodo  Puntero al procedimiento que se ejecuta al elegir el menú (ningúno por defecto).
    /// @param hijo  Puntero al menú hijo (ninguno por defecto).
    /// @param data_pointer  Puntero a datos extras (ninguno por defecto).
    ///
    void add (const std::string& etiqueta, const int opciones=D_DISABLED, void* data_pointer=NULL, const MENU* hijo=NULL, int (*metodo)(void)=NULL);

    /// Comando que se ejecuta al seleccionar este menú.
    ///
    /// @note De pruebas...
    ///
    virtual int comando_menu (){return D_O_K;};

    /// Callback de la clase.
    ///
    /// @note De pruebas...
    ///
    static int callback (void)
    {
        // Si el menú actualmente activo tiene datos de puntero a función...
        if (active_menu->dp)
        {
            textout_ex (screen, font, "Prueba de callback - Menú", 10, 10, makecol(0,0,255), -1);
            //textout (screen,font,"Prueba de callback - Menu.h",10,10,23);
            //((Menu *)(active_menu->dp))->comando_menu();
        }
        return D_O_K;
    };
};

#endif
