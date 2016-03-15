///
/// @file Juego2.h
/// @brief Fichero de declaración de la clase "Juego2".
/// @author Juan Manuel Rico
/// @date Octubre 2010
/// @version 1.0.0
///

#ifndef _JUEGO2_H_
#define _JUEGO2_H_

///
/// Define la compilación de forma estática.
/// @todo Automatizar esto en el marco de trabajo ("FrameWork") para
///       que pueda ser elegido desde "Game.cpp".
/// @code
///
///    #define ALLEGRO_STATICLINK
///
/// @endcode
///

#include "Game.h"
#include "Mapa.h"
#include  <allegro.h>
#include  "Control.h"
#include  "AirCraft.h"
#include  "Keyboard.h"
#include  "Paleta.h"
#include  "Sprite.h"
#include  "ActorManager.h"
#include  "Herny.h"
#include  "Pelota.h"
#include  "Ladrillo.h"
#include  "ControlManager.h"
#include  "EditorManager.h"
#include  "StageManager.h"
#include  "Almacen.h"
#include  "Loro.h"
#include  "Mago.h"
#include  "Ben.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Plataforma.h"

/// Juego de prueba heredado de Game.
///
/// Esta clase genera un simple juego para probar los distintos actores.
///
class Juego2 : public Game
{
public:
    /// Constructor.
    ///
    Juego2 ();

    /// Definición del procedimiento principal del juego.
    ///
    /// Crea actores y controladores para el juego de prueba.
    ///
    void mainGame ();

    /// Se crea el almacén para este juego.
    ///
    /// En el almacén se dispone de todo el vestuario y recursos necesarios
    /// que se van a necesitar a lo largo del juego (Gráficos, animaciones, sonidos, etc.).
    ///
    void create_storage_manager ();
};

#endif
