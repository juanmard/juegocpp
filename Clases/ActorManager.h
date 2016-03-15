#ifndef _ACTORMANAGER_H_
#define _ACTORMANAGER_H_

#include <list>
#include <iostream>
#include <string>
#include "Bloque.h"

//using namespace std;
using std::list;
using std::ostream;
using std::istream;
using std::string;

class Actor;
class Game;

/**
 * \brief   Maneja y controla los actores de la escena.
 * \details Esta clase controla todos los actores y sus estados dentro de la escena.
 */
class ActorManager
{
  public:
                                ActorManager          (Game *g);
                                ~ActorManager         ();
    void                        add                   (Actor *a);
    void                        del                   (Actor *a);
    void                        rewind                ();
    Actor *                     get_actor             (int x, int y);
    Actor *                     next                  ();
    Actor *                     current               ();

    /// Actualiza la lista completa de actores.
    /// En este caso actualiza el aspecto y la física implicada.
    ///
    void update ();

    int                         num_actors            ();
    list<Actor*>::iterator      get_begin_iterator    ();
    list<Actor*>::iterator      get_end_iterator      ();
    list<Actor*>                GetActores            (Bloque & bloque);
    Actor *                     getActor              (unsigned int indice);
    string                      getArmario            ();

    /// Borra todas las listas de los actores.
    ///
    void deleteActors ();

    /// Cargar los actores desde un fichero de texto plano.
    /// @param file Nombre del fichero a cargar.
    ///
    void load (const std::string& file);


protected:
    /// Actualiza la visualización del actor.
    /// @note No sé qué sentido tiene este procedimiento.
    ///
    void actualizarVisualizacion ();

    /// Avisa de que se ha agregado un actor sin componente gráfica.
    /// El aviso se realiza en la consola de salida.
    ///
    void avisoActorSinGrafico (Actor& a) const;

protected:
    Game *                      game;
    list<Actor*>                actors;
    list<Actor*>::iterator      actors_iter;
    list<Actor*>                to_del;
    list<Actor*>                to_create;

private:
    std::size_t     buscar_propiedad    (const std::string &propiedad, std::ifstream &inFile) const;
    std::size_t     buscar              (const std::string &palabra, std::ifstream &inFile) const;

    /// Crea un actor del tipo indicado.
    ///
    /// Para crear actores mediante, por ejemplo, la lectura de un fichero se necesita identificar
    /// la clase final (la "hoja" en el árbol de herencia) de dicho actor, de esta forma se obtendrán
    /// propiedades y procedimientos propios únicamente de dicha clase.
    /// @param clase Referencia constante al nombre de la clase actor que se desea crear.
    /// @return Referencia al nuevo actor creado.
    ///
    Actor& crearActor (const std::string& clase) const;

public:
    void                    add_all_to_create   ();
    void                    del_all_to_del      ();

    // Funciones amigas y no-miembro de la clase.
    friend    ostream&  operator<<   (ostream &os, const ActorManager &am);
    friend    istream&  operator>>   (istream &is, ActorManager &am);

};

#endif
