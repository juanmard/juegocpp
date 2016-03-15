///
/// @file Menu.h
/// @brief Fichero de definici�n de la clase "Menu".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef _MENU_H_
#define _MENU_H_

#include <allegro.h>
#include <vector>
#include <string>

/// @class Men� para interaccionar con los objetos editables.
///
class Menu
{
protected:
    std::vector<MENU>::iterator iter;   ///< Iterador para los items del men�.
    std::vector<MENU> items;            ///< Items que componen el men�.
    static MENU fin_menu;               ///< Item que marca el final de los items del men�.

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

    /// A�ade un men� como parte del item del men�.
    /// @param nuevo  Men� a modo de item para a�adir al men� principal.
    ///
    void add (Menu nuevo);

    /// A�ade un nuevo componente de men�.
    /// @param etiqueta  Cadena con el valor de la etiqueta a mostrar.
    /// @param opciones  Opciones del men� (deshabilitado por defecto).
    /// @param metodo  Puntero al procedimiento que se ejecuta al elegir el men� (ning�no por defecto).
    /// @param hijo  Puntero al men� hijo (ninguno por defecto).
    /// @param data_pointer  Puntero a datos extras (ninguno por defecto).
    ///
    void add (char* etiqueta, int opciones=D_DISABLED, void* data_pointer=NULL, MENU* hijo=NULL, int (*metodo)(void)=NULL);

    /// Comando que se ejecuta al seleccionar este men�.
    /// @note De pruebas...
    virtual int comando_menu (){return D_O_K;};

    /// Callback de la clase.
    /// @note De pruebas...
    static int callback (void)
    {
        // Si el men� actualmente activo tiene datos de puntero a funci�n...
        if (active_menu->dp)
        {
            textout(screen,font,"Prueba de callback",10,10,23);
            //((Menu *)(active_menu->dp))->comando_menu();
        }
        return D_O_K;
    };
};

#endif
