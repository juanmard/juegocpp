///---------------------------------------------------------
/// @file       ActorGraphic.cpp
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.1.0
///
/// @brief      Parte gráfica del actor.
///---------------------------------------------------------
///

#include "ActorGraphic.h"
#include "Actor.h"

namespace fwg {

    ActorGraphic::ActorGraphic ():
    owner(NULL),
    graph_free (true)
    {
    }

    ActorGraphic::ActorGraphic (Actor* a):
    owner(a),
    graph_free (true)
    {
    }

    ActorGraphic::~ActorGraphic ()
    {
    }

    void ActorGraphic::update ()
    {
    }

    void ActorGraphic::init ()
    {
    }

    /// @note Este método no me gusta ya que utiliza el escenario donde
    ///       se va a representar el actor como un BITMAP de Allegro.
    ///       Eliminar estas referencias y dejar las de el controlador
    ///       del escenario para hacerlo más genérico (StageManager).
    ///       
    void ActorGraphic::draw (BITMAP* bmp)
    {
    }

    /// @note Este método no me gusta ya que utiliza el escenario donde
    ///       se va a representar el actor como un BITMAP de Allegro.
    ///       Eliminar estas referencias y dejar las de el controlador
    ///       del escenario para hacerlo más genérico (StageManager).
    ///       
    void ActorGraphic::draw (int x, int y, BITMAP* bmp)
    {
    }

    unsigned int ActorGraphic::getW () const
    {
        return 0;
    }

    unsigned int ActorGraphic::getH () const
    {
        return 0;
    }

    int ActorGraphic::getX () const
    {
        return (int)(owner->get_x());
    }

    int ActorGraphic::getY () const
    {
        return (int)(owner->get_y());
    }

    Mask* ActorGraphic::getMask () const
    {
        return NULL;
    }

    /// @note Hay que decidir si clonar un actor gráfico consiste en
    ///       clonar también la imagen o Bitmap que lo representa o
    ///       simplemente tener estas imágenes en un "guardarropa" y
    ///       tomar las imágenes y animaciones de allí mediante una
    ///       referencia (StorageManager).
    ///       
    ActorGraphic* ActorGraphic::clone (Actor* propietario) const
    {
        return new ActorGraphic();
    }

    /// @todo Agrupar los valores de posición y dimensiones en un bloque,
    ///       para así poder imprimir directamente en el formato del bloque.
    ///       
    std::string& ActorGraphic::print () const
    {
        std::ostringstream cadena;

        cadena << "Propietario: " << owner->getNombre() << std::endl;
        cadena << "Posición: [" << getX() << ", " << getY() << "]" << std::endl;
        cadena << "Dimensiones: [" << getH() << ", " << getW() << "]" << std::endl;
        return *new std::string(cadena.str());
    }

    Actor* ActorGraphic::getActor () const
    {
      return owner;
    }

    std::ifstream& ActorGraphic::leer (std::ifstream& ifs)
    {
        return ifs;
    }

    std::ifstream& operator>> (std::ifstream& ifs, ActorGraphic& grafico)
    {
        return grafico.leer(ifs);
    }

    void ActorGraphic::setOwner (Actor& propietario)
    {
        if (!owner) this->owner = &propietario;
    }

    bool ActorGraphic::isFree ()
    {
        return graph_free;
    }

    void ActorGraphic::setFree (bool estate)
    {
        graph_free = estate;
    }

}