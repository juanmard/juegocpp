///
/// @file Menu.h
/// @brief Fichero de definición de la clase "Menu".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef _MENU_H_
#define _MENU_H_

#include <allegro.h>
#include <vector>
#include <string>

/// Menú para interaccionar con los objetos editables.
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
    /// @param nuevo  Menú a modo de item para añadir al menú principal.
    ///
    void add (Menu nuevo);

    /// Añade un nuevo componente de menú.
    /// @param etiqueta  Cadena con el valor de la etiqueta a mostrar.
    /// @param opciones  Opciones del menú (deshabilitado por defecto).
    /// @param metodo  Puntero al procedimiento que se ejecuta al elegir el menú (ningúno por defecto).
    /// @param hijo  Puntero al menú hijo (ninguno por defecto).
    /// @param data_pointer  Puntero a datos extras (ninguno por defecto).
    ///
    void add (const std::string& etiqueta, const int opciones=D_DISABLED, void* data_pointer=NULL, const MENU* hijo=NULL, int (*metodo)(void)=NULL);

    /// Comando que se ejecuta al seleccionar este menú.
    /// @note De pruebas...
    virtual int comando_menu (){return D_O_K;};

    /// Callback de la clase.
    /// @note De pruebas...
    static int callback (void)
    {
        // Si el menú actualmente activo tiene datos de puntero a función...
        if (active_menu->dp)
        {
            textout_ex (screen,font,"Prueba de callback - Menu.h",10,10,23,0);
            //((Menu *)(active_menu->dp))->comando_menu();
        }
        return D_O_K;
    };
};

#endif
