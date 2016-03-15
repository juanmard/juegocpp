///
/// @file StageManager.h
/// @brief Fichero de la clase "StageManager".
/// @author Juan Manuel Rico
/// @date Octubre 2010
/// @version 1.0.0
///

#ifndef _STAGEMANAGER_H_
#define _STAGEMANAGER_H_

#include <allegro.h>
#include <string.h>
#include "Game.h"
#include "Actor.h"
#include "ActorManager.h"

/// Controlador del escenario del juego.
///
/// Debe controlar como se representa el escenario del juego en pantalla y brindar
/// los procedimientos necesarios. 
///
class StageManager
{
protected:
    Game* game;             ///< Referencia al juego propietario.
    BITMAP* buffer;         ///< Buffer principal a volcar en pantalla.
    Bloque marco;           ///< Marco dentro de las coordenadas del juego.
    Bloque ribete;          ///< Marco dentro de las coordenadas de la pantalla.
    int colorRibete;        ///< Color del ribete.
    Actor* actorSeguido;    ///< Actor al que se le realiza el seguimiento.
    bool verBloques;        ///< Muestra los bloques de los actores.
    bool verInfo;           ///< Muestra las informaciones del juego.
    bool verRibete;         ///< Muestra el ribete en pantalla.
    std::string info;       ///< Cadena de informaci�n a mostrar.

public:
    /// Constructor.
    /// @param g  Puntero al juego propietario del control del escenario.
    /// @param w  Ancho del escenario.
    /// @param h  Alto del esceanrio.
    ///
    StageManager (Game* g, int w = SCREEN_W, int h = SCREEN_H);

    /// Destructor.
    ///
    /// Se libera la memoria del buffer creado como bitmap de Allegro.
    ///
    ~StageManager ();

    /// Obtiene el ancho del marco del escenario.
    /// @return Ancho del marco.
    ///
    unsigned int get_w () const;

    /// Obtiene el alto del marco del escenario.
    /// @return Alto del escenario.
    ///
    unsigned int get_h () const;

    /// Obtiene la posici�n 'x' del marco.
    /// @return Posici�n 'x' del marco.
    ///
    unsigned int get_x () const;

    /// Obtiene la posici�n 'y' del marco.
    /// @return Posici�n 'y' del marco.
    ///
    unsigned int get_y () const;

    /// Obtiene el buffer del escenario.
    /// @return Buffer del escenario.
    ///
    BITMAP* getBuffer () const;

    /// Actualiza gr�ficamente el escenario.
    /// @note Actualmente al actualizar el escenario �nicamnente lo vuelve a dibujar.
    ///
    void update ();

    /// Rellena el buffer del escenario con los actores en juego.
    ///
    /// Para ello recorre la lista de actores y les manda dibujarse en el buffer
    /// que posteriormente se vuelca en la pantalla ('screen' de Allegro).
    ///
    void rellenar_buffer ();

    /// Dibuja el escenario.
    ///
    /// Para ello recorre la lista de actores y les manda dibujarse en el buffer
    /// que posteriormente se vuelca en la pantalla ('screen' de Allegro).
    ///
    void draw ();

    /// Mueve el marco del escenario a la posici�n especificada dentro de las
    /// coordenadas generalizadas del juego.
    /// @param x  Posici�n 'x' del marco de la nueva posici�n.
    /// @param y  Posici�n 'y' del marco de la nueva posici�n.
    ///
    void mover_marco (int x, int y);

    /// Activa el seguimiento de un actor por el juego.
    /// @param paramActor  Puntero al actor al que se le desea hacer el seguimiento.
    ///
    void set_seguimiento (Actor* paramActor = NULL);

    /// Actualiza el seguimiento a un actor.
    ///
    /// Actualiza el seguimiento del marco del escenario sobre un actor.
    ///
    void actualizar_seguimiento ();

    /// Confirma si existe un actor que est� siendo seguido por el escenario.
    /// @return Si existe o no seguimiento de alg�n actor.
    ///
    bool is_seguimiento () const;

    /// Confirma si el escenario quiere mostrar informaci�n.
    /// @return Si est� mostrando o no mensajes de informaci�n.
    ///
    bool is_info () const;


    /// Cambia la activaci�n de la visualizaci�n de los bloques.
    /// @param activar  Si es 'true' activamos la visualizaci�n de los bloques.
    ///
    void set_ver_bloques (bool activar = true);

    /// Obtiene el estado de la visualizaci�n de los bloques.
    /// @return  Si es 'true' es que los bloques est�n activos.
    ///
    bool get_ver_bloques () const;

    /// Dibuja un rect�ngulo en el buffer.
    ///
    /// Dibuja un rect�ngulo referido al inicio del buffer. En coordenadas del juego,
    /// referido a la posici�n actual del escenario.
    /// @param cuadro  Bloque con las dimensiones del rect�ngulo que se quiere dibujar.
    /// @param color Color del rect�ngulo a dibujar.
    ///
    void dibujar_cuadro (Bloque cuadro, int color);

    /// Delimita la zona del marco con el dibujo de un rect�ngulo que hace de ribete.
    /// @param ribete  Bloque con las dimensiones del ribete.
    ///
    void set_ribete (Bloque ribete);

    /// Obtiene la referencia al ribete del marco.
    /// @return Devuelve el bloque que define al ribete.
    ///
    Bloque& get_ribete ();

    /// Cambia el color del ribete.
    /// @param color Color del ribete.
    ///
    void set_color_ribete (int color = makecol(255,0,0));

    /// Obtiene las dimensiones del marco del escenario.
    /// @return Referencia al bloque que define al marco.
    ///
    Bloque& get_marco ();

    /// Concatena la cadena a la l�nea de informaci�n.
    /// @param cadena  Informaci�n a concatenar.
    /// @return Referencia a la cadena para seguir concatenando.
    ///
    std::string& operator<< (std::string cadena);
};

#endif
