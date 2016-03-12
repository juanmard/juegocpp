#ifndef _ACTORGRAPHIC_H_
#define _ACTORGRAPHIC_H_

#include <string>
#include <allegro.h>

class Actor;
class Mask;

//using namespace std;
using std::string;


/** 
 * \brief   Controla la parte gráfica del actor.
 * \details Esta clase define la parte gráfica del actor.
 */
class ActorGraphic
{
public:
    /// Constructor mínimo.
    ///
    ActorGraphic ();

                                ActorGraphic    (Actor *a);
        virtual                 ~ActorGraphic   ();
        virtual void            init            ();
        virtual void            update          ();
        virtual void            draw            (BITMAP *bmp);
        virtual void            draw            (int x, int y, BITMAP *bmp);
        virtual int             get_w           ();
        virtual int             get_h           ();
        virtual int             get_x           ();
        virtual int             get_y           ();
        virtual Mask*           get_mask        ();
        virtual ActorGraphic *  clone           (Actor *propietario) const;

    /// Entrega la estructura del gráfico en forma de cadena de caracteres.
    ///
    /// Este procedimiento es virtual para que lo definan los gráficos derivados.
    /// @return Cadena con las propiedades del gráfico.
    /// @todo Esta estructura es muy similar a la que se encuentra en la rama de
    ///       los actores, luego sería conveniente en agruparla en una clase común
    ///       a modo de interfaz que comparten (p.j. PrintableObject).
    ///
    ///       Y para desligar el gráfico de su actor propietario sería conveniente
    ///       que los gráficos tuvieran entidad propia derivando de "DrawableObject".
    ///
    virtual std::string getString () const;

    /// Lee el gráfico de un fichero.
    /// @param ifs Fichero desde el que leer las propiedades gráficas.
    /// @return Referencia al fichero para poder encadenar lecturas.
    ///
    virtual std::ifstream& leer (std::ifstream& ifs);

    /// Sobrecarga del operador >> para poder leer del fujo de datos del fichero.
    /// @param ifs Fichero desde el que leer las propiedades gráficas.
    /// @param grafico Parte gráfica del actor que se actualizará desde la lectura del fichero.
    /// @return Referencia al fichero para poder encadenar lecturas.
    ///
    friend std::ifstream& operator>> (std::ifstream& ifs, ActorGraphic& grafico);

    virtual Actor *         getActor        () const;

    /// Se modifica el actor propietario del gráfico.
    /// @param propietario Actor nuevo propietario del gráfico.
    /// @note Esta modificación puede generar una incongruencia, ya que el
    ///       antiguo actor propietario puede quedar con un gráfico asignado
    ///       que ya no es el suyo, mientras que el gráfico considera que
    ///       ahora su propietario es otro.
    ///
    ///       Para evitar esta incongruencia únicamente se modificará el
    ///       actor propietario si previamente el gráfico no tenía ninguno
    ///       asignado.
    ///
    void setOwner (Actor& propietario);

protected:
        Actor *owner;
};

#endif
