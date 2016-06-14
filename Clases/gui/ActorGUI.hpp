///
///
///
#ifndef GUI_ACTORGUI_HPP
#define GUI_ACTORGUI_HPP

#include "../Actor.h"
#include <guichan.hpp>
#include <string>
#include "VectorGUI.hpp"

namespace gui
{
   
/// Clase para editar gráficamente (GUI) las propiedades de los actores del juego.
/// Su misión es mostrar las propiedades de un actor en pantalla y poder modificarlas mediante
///    pulsaciones de ratón y teclado. Para ello se utilizan las clases que nos proporciona GUICHAN.
///
class GCN_CORE_DECLSPEC ActorGUI :
                      public gcn::Container,
                      public gcn::MouseListener,
                      public gcn::KeyListener//,
                  //    public gcn::ActionListener
{
    public:
        /// Constructor por defecto de la GUI del actor.
        /// @note No asigna el actor que se desea editar.
                ActorGUI ();

        /// Constructor básico de la GUI.
                ActorGUI (Actor* actor);

        /// Destructor del actor.
        /// @note Se define virtual para que cada actor elimine sus recursos.
        virtual ~ActorGUI ();

        /// Asigna el actor que se va a editar mediante esta GUI.
        /// @param  nuevoActor  Referencia en forma de puntero al actor que se desea editar.
        ///
        void setActor (Actor* nuevoActor);

        // Heredado de ActionListener.
        //virtual void action (const gcn::ActionEvent& actionEvent);
        
        // Heredado de MouseListener.
        virtual void mouseEntered (gcn::MouseEvent& mouseEvent);

    private:
        /// Inicializa y crea la estructura de la GUI del actor.
        /// 
        void init ();

        /// Actualiza el nombre que se muestra.
        ///
        void update ();

        /// Cambia el nombre que se muestra en la GUI.
        /// @note Lo normal es que este sea el nombre que tiene asignado el actor,
        ///       es por eso que es un procedimiento no abierto al público y se deja
        ///       como un procedimiento privado de la clase.
        void setNombre (const std::string& nuevoNombre);

        /// Establece los valores que debe modificar al modificar la posición.
        /// @param  x  Valor a cambiar con la x.
        /// @param  y  Valor a cambiar con la y.
        ///
        void setPosicion (int x, int y);

        /// Establece los valores que debe modificar al modificar la posición.
        ///
        void setTamano (int w, int h);

    protected:
        Actor* actor;               ///< Referencia al actor que se desea editar.
        gcn::Label* nombre;         ///< Etiqueta que mostrará el nombre del actor.
        gui::VectorGUI* posicion;   ///< Vector que muestra la posición actual del actor en el escenario.
        gui::VectorGUI* tamano;     ///< Vector que muestra el tamaño actual del actor.
};
}

#endif // end GUI_ACTORGUI_HPP
