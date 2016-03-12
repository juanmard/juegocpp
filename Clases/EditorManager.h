#pragma once

#include <allegro.h>
#include <string>
#include "Bloque.h"
#include "Almacen.h"

//using namespace std;
using std::string;

class Game;
class Actor;
class Dialog;

/**
 *  \brief      Edita las listas de objetos involucrados en un juego.
 *  \details    Edita las listas de objetos involucrados en un juego y permite modificar, guardar
 *              y recuperar dichos objetos. Esta edición puede realizarse en la misma ventana donde
 *              se desarrolla el juego o en una ventana aparte. Debe permitir editar todas y cada una
 *              de las animaciones de los objetos, así como modificar el estado de los mismos.
 *              Aunque se podría incluir en la clase "ActorManager" se decide crear una clase 
 *              independiente puesto que la edición no es un proceso normal del juego una vez terminado.
 */
class EditorManager
{
  public:
              EditorManager         (Game *g);
              ~EditorManager        ();
    void      activate              ();
    void      dibujarEscenario      ();
    void      duplicarActor         (Actor *);
    void      moverActor            (int x, int y);
    int       getActorX             () const;
    int       getActorY             () const;
    void      setActorX             (int x);
    void      setActorY             (int y);
    Actor *   getActor              (int x, int y) const;
    string    getNombreActor        (int indice) const;
    int       getNumTrajes          () const;
    void      cambiarTraje          (int indice);
    int       getEscenarioX         () const;
    int       getEscenarioY         () const;
    void      moverEscenario        (int x, int y);
    void      step                  () const;
    BITMAP *  getBuffer             ();
    void      ActualizarEscenario   ();
    void      dibujarCuadrado       (Bloque cuadro, int color);
    int       getNumActores         () const;
    void      setRibete             (Bloque bloque) const;
    void      borrarPantalla        () const;
    void      centrarActor          (int indice) const;
    void      setColorRibete        (int color);
    void      getEscenarioXY        (string &posicion) const;
    Almacen & getAlmacen            () const;

    // Nueva generación de métodos para GUI dinámica:
    bool      isActorActivo         () const;
    bool      isActorAtrapado       () const;
    bool      isActorFijo           () const;
    void      atraparActor          (int x, int y);
    void      activarActor          (int x, int y);
    void      fijarActor            (int x, int y);
    void      liberarActor          ();
    bool      isDecoradoAtrapado    () const;
    void      moverActor2           (int x, int y);
    void      moverDecorado         (int x, int y);
    void      actualizarActor       ();
    void      actualizarDecorado    ();
    int       getGlobalX            (int x);
    int       getGlobalY            (int y);
    int       getLocalX             (int x);
    int       getLocalY             (int y);

  private:
      static int refX, refY;

// Lo hacemos público para pruebas.
//  protected:
public:
    //typedef enum {activado, fijado, atrapado} Estado;
    Game *      game;
    Dialog *    gui;
    Actor *     actor;
    //Estado      estado;
    bool        actorActivado;
    bool        actorAtrapado;
    bool        actorFijado;
};
