///---------------------------------------------------------
/// @file       ActorGraphic.h
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.1.0
///
/// @brief      Parte gráfica del actor.
///---------------------------------------------------------
///

#ifndef _ACTORGRAPHIC_H_
#define _ACTORGRAPHIC_H_

#include <allegro.h>
#include <string>
#include <sstream>
#include "PrintableObject.h"

namespace fwg {
    
    /// Clases colaboradoras.
    /// 
    class Actor;
    class Mask;

    /// Controla la parte gráfica del actor.
    ///
    /// Esta clase define y controla la parte gráfica del actor.
    /// 
    /// @see Actor, PrintableObject, Mask
    ///
    /// @todo Por hacer en esta clase:
    ///       - Eliminar referencias a la biblioteca de Allegro para hacerla
    ///         más genérica.
    ///       - Hacer que la clase sea virtual pura, al menos alguno de sus
    ///         métodos. No tiene sentido un actor gráfico sin especificar qué
    ///         tipo de gráfico se usa.
    ///       - Hacer derivar de "PrintableObject" para poder representar el objeto
    ///         en un flujo de caracteres.
    ///       - Hacer derivar de "DrawableObject" para desligar estos objetos del
    ///         actor propietario y no tener duplicados los posibles "bitmaps" que
    ///         lo representan (usando una clase "StorageManager").
    ///       - Hacer derivar de "RedeableObject" para leer desde un flujo.
    /// 
    class ActorGraphic : public PrintableObject
    {
        protected:
            Actor* owner;       ///< Referencia al actor propietario del gráfico.
            bool graph_free;    ///< Indica si el gráfico está libre para ser cambiado por otro.

        public:
            /// Constructor por defecto.
            ///
            ActorGraphic ();

            /// Constructor con asignación del actor propietario.
            /// 
            /// @param a Refgerencia al actor que será propietario de
            ///          la parte gráfica creada.
            ///
            ActorGraphic (Actor* a);

            /// Destructor.
            ///
            virtual ~ActorGraphic ();

            /// Inicializa el gráfico.
            ///
            virtual void init ();

            /// Actualiza el gráfico.
            ///
            virtual void update ();

            /// Dibuja la parte gráfica del actor.
            /// @param bmp  BITMAP en donde se dibuja la parte gráfica del actor.
            ///
            /// @note Normalmente esta función es sobreescrita por el hijo
            ///       que hereda (Sprite, Bitmap, pixel...).
            ///       ¿Mejor hacerla virtual puro?
            ///
            /// @note Eliminar referencias a Allegro.
            ///
            virtual void draw (BITMAP* bmp);

            /// Dibuja la parte gráfica del actor.
            /// 
            /// @param x Coordenada x de la posición donde dibujar.
            /// @param y Coordenada y de la posición donde dibujar.
            /// @param bmp BITMAP en donde se dibujará la parte gráfica.
            /// 
            /// @note Eliminar las referencias a Allegro.
            ///
            virtual void draw (int x, int y, BITMAP* bmp);

            /// Obtener el ancho del gráfico.
            /// 
            /// @return Ancho obtenido.
            ///
            virtual unsigned int getW () const;

            /// Obtener el alto del gráfico.
            /// 
            /// @return Alto obtenido.
            ///
            virtual unsigned int getH () const;

            /// Obtener la posición X del actor propietario del gráfico.
            /// 
            /// @return Posición X del actor propietario.
            ///
            virtual int getX () const;

            /// Obtener la posición Y del actor propietario del gráfico.
            /// 
            /// @return Posición Y del propietario.
            ///
            virtual int getY () const;

            /// Obtiene la máscara del gráfico.
            /// 
            /// @return Referencia a la máscara del gráfico.
            /// 
            /// @note Esto no se usa, se mantiene como referencia y para
            ///       una posible ampliación de futuro.
            ///
            virtual Mask* getMask () const;

            /// Duplica la parte gráfica del actor y le asigna el nuevo propietario.
            /// 
            /// @param propietario Referencia del nuevo propietario al que asignar el duplicado.
            /// @return Referencia al gráfico creado.
            ///
            virtual ActorGraphic* clone (Actor* propietario) const;

            /// Entrega la estructura del gráfico en forma de cadena de caracteres.
            ///
            /// Este procedimiento es virtual para que lo definan los gráficos derivados.
            /// 
            /// @return Cadena con las propiedades del gráfico.
            /// 
            /// @todo Esta estructura es muy similar a la que se encuentra en la rama de
            ///       los actores, luego sería conveniente en agruparla en una clase común
            ///       a modo de interfaz que comparten (p.j. PrintableObject) y eliminar
            ///       este método de esta clase.
            ///
            ///       Y para desligar el gráfico de su actor propietario sería conveniente
            ///       que los gráficos tuvieran entidad propia derivando de "DrawableObject".
            ///
            virtual std::string& print () const;

            /// Lee el gráfico de un fichero.
            /// 
            /// @param ifs Fichero desde el que leer las propiedades gráficas.
            /// @return Referencia al fichero para poder encadenar lecturas.
            /// 
            /// @todo Hacer derivar de "RedeableObject" para leer del flujo y eliminar este
            ///       método de esta clase.
            ///
            virtual std::ifstream& leer (std::ifstream& ifs);

            /// Sobrecarga del operador >> para poder leer del fujo de datos del fichero.
            /// 
            /// @param ifs Fichero desde el que leer las propiedades gráficas.
            /// @param grafico Parte gráfica del actor que se actualizará desde la lectura del fichero.
            /// @return Referencia al fichero para poder encadenar lecturas.
            /// 
            /// @todo Pasar este método a la clase "RedeableObject".
            ///
            friend std::ifstream& operator>> (std::ifstream& ifs, ActorGraphic& grafico);

            /// Obtiene el actor propietario del gráfico.
            /// 
            /// @return Puntero al actor propietario.
            /// 
            virtual Actor* getActor () const;

            /// Se modifica el actor propietario del gráfico.
            /// 
            /// @param propietario Actor nuevo propietario del gráfico.
            /// 
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

            /// Indica si el gráfico es libre para ser cambiado por otro en el actor propietario.
            /// 
            /// @return Un booleano indicando si el gráfico está libre.
            ///
            /// @note Se ve la necesidad de crear este procedimiento para evitar que, animaciones
            ///       sobre todo, queden sin desarrollar completamente sus animación.
            ///       Esto sucede puesto que el procedimiento "Actor::setActorGraphic" simplemente
            ///       intercambia sus punteros.
            ///       Para eliminar esta necesidad, lo ideal es que las animaciones
            ///       se encuentren a disposición de cualquier actor en una clase
            ///       externa que las almacene y las controle (StorageManager).
            ///
            bool isFree ();

        public:
            /// Cambia el estado del gráfico, indicando si está o no libre
            /// para ser cambiado por otro.
            /// 
            /// @param estate Un booleano indicando si el gráfico deja o no
            ///        de estar libre.
            ///
            void setFree (bool estate);
        };
}

#endif
