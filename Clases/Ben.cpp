/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "Ben.h"
#include "ControllableActor.h"
#include "Almacen.h"
#include "Sprite.h"
#include <iostream>

using namespace std;


/**
 * \brief    Constructor por omisión.
 */
Ben::Ben (Almacen &almacen):
estado(andando),
estado_sig(andando),
timer(0),
gravedad (10),
sentido(1)
{
  // Guardamos el sprite para cada estado.
  // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
  sprites[andando_der] = new Sprite(this);
  sprites[andando_der]->add_frame(almacen.getBitmap("ben10_002"), 0, 0, 10);
  sprites[andando_der]->add_frame(almacen.getBitmap("ben10_003"), 0, 0, 20);
  sprites[andando_der]->add_frame(almacen.getBitmap("ben10_004"), 0, 0, 20);
  sprites[andando_der]->add_frame(almacen.getBitmap("ben10_005"), 0, 0, 10);
  sprites[andando_der]->init ();

  sprites[andando_izq] = new Sprite(this);
  sprites[andando_izq]->add_frame(almacen.getBitmap("ben10_006"), 0, 0, 10);
  sprites[andando_izq]->add_frame(almacen.getBitmap("ben10_007"), 0, 0, 10);
  sprites[andando_izq]->add_frame(almacen.getBitmap("ben10_008"), 0, 0, 10);
  sprites[andando_izq]->add_frame(almacen.getBitmap("ben10_009"), 0, 0, 10);
  sprites[andando_izq]->init ();

  sprites[esperando_der] = new Sprite(this);
  sprites[esperando_der]->add_frame(almacen.getBitmap("ben10_000"), 0, 0, 10);
  sprites[esperando_der]->init ();

  sprites[esperando_izq] = new Sprite(this);
  sprites[esperando_izq]->add_frame(almacen.getBitmap("ben10_001"), 0, 0, 10);
  sprites[esperando_izq]->init ();

  sprites[cayendo_der] = new Sprite(this);
  sprites[cayendo_der]->add_frame(almacen.getBitmap("ben10_021"), 0, 0, 10);
  sprites[cayendo_der]->init ();

  sprites[cayendo_izq] = new Sprite(this);
  sprites[cayendo_izq]->add_frame(almacen.getBitmap("ben10_020"), 0, 0, 10);
  sprites[cayendo_izq]->init ();

  sprites[disparando_der] = new Sprite(this);
  sprites[disparando_der]->add_frame(almacen.getBitmap("ben10_005"),  0, -2, 1);
  sprites[disparando_der]->add_frame(almacen.getBitmap("ben10_010"),  0, -5, 2);
  sprites[disparando_der]->add_frame(almacen.getBitmap("ben10_011"),  0, -8, 2);
  sprites[disparando_der]->add_frame(almacen.getBitmap("ben10_012"),  0, -8, 3);
  sprites[disparando_der]->add_frame(almacen.getBitmap("ben10_010"),  0, -5, 1);
  sprites[disparando_der]->init ();

  sprites[disparando_izq] = new Sprite(this);
  sprites[disparando_izq]->add_frame(almacen.getBitmap("ben10_009"),  1, -2, 1);
  sprites[disparando_izq]->add_frame(almacen.getBitmap("ben10_013"),  1, -5, 2);
  sprites[disparando_izq]->add_frame(almacen.getBitmap("ben10_014"), 35, -8, 2);
  sprites[disparando_izq]->add_frame(almacen.getBitmap("ben10_015"), 29, -8, 3);
  sprites[disparando_izq]->add_frame(almacen.getBitmap("ben10_013"),  1, -5, 1);
  sprites[disparando_izq]->init ();

  sprites[saltando_der] = new Sprite(this);
  sprites[saltando_der]->add_frame(almacen.getBitmap("ben10_016"),    0, 15, 10);
  sprites[saltando_der]->add_frame(almacen.getBitmap("ben10_gm_000"), 0, 15,  5);
  sprites[saltando_der]->add_frame(almacen.getBitmap("ben10_016"),    0, 15,  2);
  sprites[saltando_der]->add_frame(almacen.getBitmap("ben10_gm_000"), 0, 15,  4);
  sprites[saltando_der]->add_frame(almacen.getBitmap("ben10_016"),    0, 15,  3);
  sprites[saltando_der]->init ();

  sprites[saltando_izq] = new Sprite(this);
  sprites[saltando_izq]->add_frame(almacen.getBitmap("ben10_017"), 0, 15, 10);
  sprites[saltando_izq]->init ();

  sprites[bajando_der] = new Sprite(this);
  sprites[bajando_der]->add_frame(almacen.getBitmap("ben10_018"), 0, -25, 10);
  sprites[bajando_der]->init ();

  sprites[bajando_izq] = new Sprite(this);
  sprites[bajando_izq]->add_frame(almacen.getBitmap("ben10_019"), 0, -25, 10);
  sprites[bajando_izq]->init ();

  sprites[girando_der] = new Sprite(this);
  sprites[girando_der]->add_frame(almacen.getBitmap("ben10_001"), 0, 0, 10);
  sprites[girando_der]->add_frame(almacen.getBitmap("ben10_000"), 0, 0, 10);
  sprites[girando_der]->init ();

  sprites[girando_izq] = new Sprite(this);
  sprites[girando_izq]->add_frame(almacen.getBitmap("ben10_000"), 0, 0, 10);
  sprites[girando_izq]->add_frame(almacen.getBitmap("ben10_001"), 0, 0, 10);
  sprites[girando_izq]->init ();

  Sprites_t sprite_act = estado2Sprite (estado);
  set_actor_graphic (sprites[sprite_act]);
  setCodigo (Nombres::ben);
  set_x(SCREEN_W/3);
  set_y(SCREEN_H/2);
  set_is_detected (false);
  set_collision_method(CollisionManager::PP_COLLISION);
  set_wh (21,60);
};

/**
 * \brief   Acciones de Ben.
 */
void Ben::do_action (ControllableActor::action_t act, int magnitude)
{
  // Se actualiza el estado según la acción a ejecutar.
  switch (act)
  {
    case DOWN:
        estado_ant = estado;
        estado = bajando;
        estado_sig = esperando;
        timer = 20;
        break;

    case UP:
        estado_ant = estado;
        estado = saltando;
        estado_sig = esperando;
        timer = 10;
        break;

    case RIGHT:
        if (estado == esperando) estado = andando;
        if (estado == andando)
        {
          if (sentido > 0)
          {
            x += 2;
            estado_sig = esperando;
            timer = 3;
          }
        }
        sentido = 1;
        break;

    case LEFT:
        if (estado == esperando) estado = andando;
        if (estado == andando)
        {
          if (sentido < 0)
          {
            x -= 2;
            estado_sig = esperando;
            timer = 3;
          }
        }
        sentido = -1;
        break;

    case JUMP:
        estado_ant = estado;
        estado = disparando;
        estado_sig = esperando;
        timer = 10;
        break;

    case SPELL:
        break;
  }
}

/**
 * \brief   Actualizamos los estados de Ben.
 */
void Ben::update ()
{
  // Se actualiza el sprite según el estado.
//  if (estado != estado_ant)
//  {
    Sprite *tmp = sprites[estado2Sprite(estado)];
//    tmp->init ();
    set_actor_graphic (tmp);
//  }

  // Actualiza la parte gráfica.
  agraph->update();

  // Guardamos el estado anterior.
  estado_ant = estado;

  // Actualiza el estado dependiente del temporizador.
  // \todo  Generalizar este proceso para la clase Actor.
  if (timer)
  {
    timer--;
    if (timer == 0)
    {
      estado = estado_sig;
    }
  }

  // Actualiza las propiedades según los estados.
  switch (estado_ant)
  {
    case cayendo:
        y += gravedad/3;
        break;

    case esperando:
        if (gravedad != 0) estado = cayendo;
        break;

    case andando:
        if (gravedad != 0) estado = cayendo;
        break;

    case saltando:
        //if (gravedad != 0) estado = cayendo;
        break;

    case disparando:
        if (gravedad != 0) estado = cayendo;
        break;
  }

  // Graveddad...
  gravedad = 10;
}

/**
 * \brief   Intersección de Ben con otro actor de la escena.
 * \param   who       Puntero al actor que provoca la colisión.
 * \param   damage    Daño que se produce en la colisión. 
 */
void  Ben::hit  (Actor *who, int damage)
{
  switch (who->getCodigo ())
  {
    case Nombres::ladrillo:
    case Nombres::pelota:
    case Nombres::paleta:
    case Nombres::herny:
          switch (estado)
          {
              case disparando:
              case saltando:
              case andando:
              default:
                  // El suelo anula la gravedad propia de Ben.
                  // \todo  Generalizar para todos los actores.
                  y = who->get_y () - h;
                  gravedad = 0;
                  estado = esperando;
                  break;
          }
          break;

    default:
          break;
  }
}

/**
 * \brief   Transforma un estado en un tipo 'sprite' según el estado pasado como
 *          parámetro y las propiedades internas actuales de Ben.
 * \param   estado_act    Estado que se quiere convertir.
 * \return  Devuelve el enumerado sprite que corresponde actualmente a ese estado.
 */
Ben::Sprites_t  Ben::estado2Sprite (Estados_t estado_act) const
{
  Sprites_t sprite_act;
  
  switch (estado_act)
  {
    case esperando:
        if (sentido > 0) sprite_act = esperando_der; else sprite_act = esperando_izq;
        break;

    case andando:
        if (sentido > 0) sprite_act = andando_der; else sprite_act = andando_izq;
        break;

    case cayendo:
        if (sentido > 0) sprite_act = cayendo_der; else sprite_act = cayendo_izq;
        break;

    case disparando:
        if (sentido > 0) sprite_act = disparando_der; else sprite_act = disparando_izq;
        break;

    case saltando:
        if (sentido > 0) sprite_act = saltando_der; else sprite_act = saltando_izq;
        break;

    case bajando:
        if (sentido > 0) sprite_act = bajando_der; else sprite_act = bajando_izq;
        break;

    case girando:
        if (sentido > 0) sprite_act = girando_der; else sprite_act = girando_izq;
        break;

    default:
        break;
  }
  return sprite_act;
}

/**
 * \brief   Obtiene el estado en forma de cadena de texto. 
 */
void  Ben::getEstado (string &strEstado) const
{
  // \ todo   Guardar los estados y sus cadenas en un stl tipo map y se podrá hacer
  //          algo como: strEstado = mapEstados[estado];
  switch (estado)
  {
    case esperando:   strEstado = "esperando";    break;
    case andando:     strEstado = "andando";      break;
    case girando:     strEstado = "girando";      break;
    case cayendo:     strEstado = "cayendo";      break;
    case disparando:  strEstado = "disparando";   break;
    case saltando:    strEstado = "saltando";     break;
    case bajando:     strEstado = "bajando";      break;
    default:          strEstado = "sin definir";  break;
  }
};

/**
 * \brief   Obtiene el nombre en forma de cadena de texto. 
 */
void  Ben::getNombre (string &strNombre) const
{
  strNombre = Nombres::Imprimir (nombre);
}

/**
 * \brief   Obtiene el nombre en forma de cadena de texto. 
 */
string  Ben::getNombre () const
{
  return Nombres::Imprimir (nombre);
}

/**
 * \brief   Obtiene cadena representativa del objeto. 
 */
ostream&  Ben::operator<< (ostream *sb)
{
    *sb << "Prueba de cadena desde \"Ben.cpp\"" << endl;
    return *sb;
}
