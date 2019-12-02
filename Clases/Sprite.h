///
/// @file Sprite.h
/// @brief Fichero de definición de la clase "Sprite".
/// @author Juan Manuel Rico
/// @date Octubre 2015
/// @version 1.0.0
///

#ifndef SPRITE_H
#define SPRITE_H

#include "ActorGraphic.h"
#include <vector>
#include "Frame.h"
#include <allegro.h>
#include <string.h>
#include "Actor.h"
#include "Mask.h"
#include <sstream>
#include <guichan/image.hpp>

namespace fgm {
    
//class Object;
class EditableObject;

/// Gráfico en movimiento, una animación simple para los actores.
/// Esta clase modela varias imágenes en movimiento como gráfico para un actor.
///
class Sprite : public EditableObject, public ActorGraphic //, Object
{
protected:
    std::vector<Frame> frames;  ///< Conjunto de cuadros que forman la animación.
    int actual_tick;            ///< Tick actual dentro de la animación.
    int actual_frame;           ///< Cuadro actual dentro de la animación.
    bool mirror;                ///< Indica si la animación se encuentra girada en espejo.

public:
    /// Constructor básico.
    /// @param aowner  Actor propietario del nuevo gráfico creado.
    ///
    Sprite (Actor* aowner);

    /// Constructor de copia.
    /// @param copia  Referencia al gráfico que se desea copiar.
    /// @param aowner  Actor propietario del nuevo gráfico copiado.
    ///
    Sprite (const Sprite& copia, Actor* aowner);

    /// Duplica el gráfico animado.
    /// @param propietario  Nuevo actor propietario del gráfico duplicado.
    /// @return Puntero al gráfico duplicado.
    ///
    virtual Sprite* clone (Actor* propietario) const;

    /// Dibuja el gráfico.
    /// @param bmp  Bitmap donde se copia el gráfico.
    ///
    void draw (BITMAP* bmp);

    /// Dibuja el gráfico.
    /// @param x  Posición x en el bitmap.
    /// @param y  Posición y en el bitmap.
    /// @param bmp  Bitmap donde se copia el gráfico.
    ///
    void draw (int x, int y, BITMAP* bmp);

    /// Actualiza el gráfico.
    ///
    void update ();

    /// Inicializa la parte gráfica del objeto.
    /// @note Esto provoca que el objeto no se clone en su estado actual.
    ///       Se deja en blanco y se inicializa en los constructorores.
    ///
    void init ();

    /// Obtiene el ancho del cuadro actual del gráfico.
    /// @return Ancho del cuadro actual.
    ///
    int get_w ();

    /// Obtiene el alto del cuadro actual del gráfico.
    /// @return Alto del cuadro actual.
    ///
    int get_h ();

    /// Obtiene la posición x del cuadro actual.
    /// @return Posición x del cuadro actual.
    ///
    int get_x ();

    /// Obtiene la posición y del cuadro actual.
    /// @return Posición y del cuadro actual.
    ///
    int get_y ();

    /// Añade un cuadro a la animación.
    /// @param bmp  Gráfico estático que forma el nuevo cuadro.
    /// @param cx  Posición relativa x del cuadro al origen del propietario del gráfico.
    /// @param cy  Posición relativa y del cuadro al origen del propietario del gráfico.
    /// @param ticks  Ticks de espera de este cuadro hasta el siguiente.
    ///
    void add_frame (BITMAP* bmp, int cx, int cy, int ticks);

    /// Obtiene la máscara del cuadro actual.
    /// @return Puntero a la mácara del cuadro actual.
    ///
    Mask* get_mask ();

    /// Cambia la variable de reflejo.
    /// @param paramMirror  Nuevo valor de la variable 'mirror'.
    ///
    /// @todo Sustituir la variable 'mirror' por un vector que haga el giro en cualquier
    ///       ángulo y en cualquier dirección.
    ///
    void setMirror (bool paramMirror);

    /// Obtiene el valor de la variable de reflejo.
    /// @return Valor actual de la variable en el gráfico.
    ///
    bool getMirror ();

    /// Cambia la variable de reflejo al valor negado del existente.
    ///
    void notMirror ();

    /// Entrega una cadena con la estructura y propiedades del gráfico.
    /// @return Cadena de caracteres con la estructura y propiedades de la animación.
    ///
    virtual std::string getString () const;

    /// Genera un menú para edición del sprite.
    /// @return Menú con las opciones para la edición del sprite.
    ///
    Menu& getMenu () const;

    /// Genera un formulario para edición del sprite.
    /// @return Formulario con los controles necesarios para la edición del sprite.
    ///
    alg4::Formulario& getFormulario () const;

    /// Prueba estática para menú.
    static int prueba_menu_static (void)
    {
        return D_O_K;
    };

    /// Entrega el "frame" del "sprite" indicado por su posición.
    /// @param  ind  Índice dentro de la sucesión de "frame".
    /// @return Referencia al "Frame" que contiene el "sprite".
    ///
    const Frame* getFrame (int ind) const;

    ///
    void setXFrame (int ind, int x);
    void setYFrame (int ind, int y);

    /// Entrega el número de "frames" del "sprite".
    /// @return Número de "frames" que tiene el "sprite".
    ///
    unsigned int getNumFrames () const;

    /// Entrega la imagen para la GUI que representa el "frame" indicado con el índice.
    /// @param  ind  Índice dentro de la sucesión de "frames".
    /// @return Referencia a una imagen creada que contiene el frame indicado por "ind".
    /// @warning El obtener una imagen para la GUI no es es un comportamiento necesario
    ///          para el desarrollo normal del juego, por tanto este comportamiento debe
    ///          trasladarse a otra clase que lo implemente. Quizás haciendo heredar la
    ///          la clase SpriteGUI de esta clase creando un Sprite con la característica
    ///          añadida de que se puede editar mediante una GUI, de esta forma se puede
    ///          independizar aún más el "juego" de lo que es la "edición del juego".
    /// @todo Pasar este procedimiento a SpriteGUI y heredar este de Sprite.
    ///
    virtual const gcn::Image* getImage (unsigned int ind) const;
};
}

#endif
