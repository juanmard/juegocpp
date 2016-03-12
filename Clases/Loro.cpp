///
/// @file Loro.cpp
/// @brief Fichero de la clase "Loro".
/// @author Juan Manuel Rico
/// @date Marzo 2010
/// @version 1.0.0
///

#include "Loro.h"

Loro::Loro ():
ControllableActor ()
{
};

Loro::Loro (Almacen &almacen)
{
    // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
    // Animación de la derecha.
    izquierda = new Sprite(this);
    izquierda->add_frame(almacen.getBitmap("sprite_042"), 0, 13, 10);
    izquierda->add_frame(almacen.getBitmap("sprite_043"), 0,  0, 10);
    izquierda->add_frame(almacen.getBitmap("sprite_044"), 0,  3, 10);
    izquierda->setMirror(true);

    // Animación de la izquierda.
    derecha = new Sprite(this);
    derecha->add_frame(almacen.getBitmap("sprite_042"), 0, 13, 10);
    derecha->add_frame(almacen.getBitmap("sprite_043"), 0,  0, 10);
    derecha->add_frame(almacen.getBitmap("sprite_044"), 0,  3, 10);

    // Animación de giro.
    giro = new Sprite(this);
    giro->add_frame(almacen.getBitmap("pre2_338"), 0, 13, 10);
    giro->add_frame(almacen.getBitmap("pre2_338"), 0,  0, 10);
    giro->add_frame(almacen.getBitmap("pre2_338"), 0,  3, 10);

    // Animación de inicio.
    set_actor_graphic (derecha);

    setCodigo (Nombres::herny);
    set_x(SCREEN_W/2);
    set_y(SCREEN_H/2);
    set_is_detected (true);
    set_collision_method(CollisionManager::PP_COLLISION);
    set_wh (36,26);
};

void Loro::do_action (ControllableActor::action_t act, int magnitude)
{
    switch (act)
    {
        case DOWN:  y+=1; break;
        case UP:    y-=1; break;
        case LEFT:
          x-=1;
          /// @todo Habría que comparar con los estados actuales del actor, pero para pruebas
          ///       se comparará los punteros de gráficos.
          ///       Debería ser algo como...
          ///       @code
          ///           typedef enum {VOLANDO_IZQ, VOLAMDO_DER, GIRANDO} estado_t;
          ///           if (estado_actual == Loro::VOLANDO_IZQ) {};
          ///       @endcode
          ///
          if (this->get_actor_graphic() == derecha)
          {
            this->set_actor_graphic(giro);
          }
          else
          {
            this->set_actor_graphic(izquierda);
          }
          break;

        case RIGHT:
          x+=1;
          this->set_actor_graphic(derecha);
          break;

        case JUMP:  y-=4;
            break;
    }
};

void Loro::getNombre (std::string &strNombre) const
{
    strNombre = Nombres::Imprimir (nombre);
};
