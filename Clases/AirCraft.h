///---------------------------------------------------------
/// @file       AirCraft.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Nave como actor controlable.
///---------------------------------------------------------

#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_

#include "ControllableActor.h"
#include <fstream>

namespace fwg {
     
     /// Predefinición de clases.
     class StageManager;

     /// Modela una nave espacial como actor controlable.
     ///
     /// Esta clase modela una nave espacial para probar
     /// los actores controlables.
     /// 
     /// @todo Cosas por hacer en esta clase:
     ///       - Modificar el método 'leer' para heredar
     ///         directamente del objeto 'ReadeableObject'.
     ///       - Elegir entre los métodos 'copia' o 'clonar'
     ///         para duplicar el objeto.
     ///       - Eliminar referencias a las bibliotecas
     ///         de Allegro.
     ///
    class AirCraft : public ControllableActor
    {
        public:
            /// Acciones en el movimiento de la nave.
            ///
            typedef enum
            {
                DOWN,   ///< Mover nave hacia abajo.
                UP,     ///< Mover nave hacia arriba.
                LEFT,   ///< Mover nave hacia la izquierda.
                RIGHT   ///< Mover nave hacia la derecha.
            } Action;

        protected:
            BITMAP* image; ///< Gráfico de la nave.

        public:
            /// Constructor.
            /// 
            AirCraft ();
            
            /// Constuctor de copia.
            /// 
            /// @param copia Referencia a la nave a copiar.
            /// 
            AirCraft (const AirCraft& copia);
            
            /// Ejecuta la acción recibida por el control.
            /// 
            /// @param act Acción recibida.
            /// @param magnitude Intensidad de la acción.
            /// 
            void doAction (ControllableObject::Action act, int magnitude);
            
            /// Existe colisión con la nave.
            /// 
            /// @param who Actor con el que está colisionando la nave.
            /// @param damage Intensidad de la colisión.
            /// 
            void hit (Actor* who, int damage);
                       
            /// Clonar la nave.
            /// 
            /// Clonar no es lo mismo que copiar, ya que se clona el objeto
            /// completo, las referencias gráficas incluídas.
            /// 
            /// @return Referencia a la nueva nave clonada.
            /// 
            virtual AirCraft* clone () const;

            /// Dibuja la nave de prueba.
            /// 
            /// Dibuja un rectángulo y una elipse a modo de prueba.
            /// 
            /// @param stageManager Referencia al controlador del escenario.
            /// 
            void draw (StageManager* stageManager);

            /// Lee la nave desde un 'stream' de fichero.
            /// 
            /// @param ifs Referencia al fichero de lectura (Input File Stream).
            /// @return Referencia al flujo del fichero.
            /// 
            /// @note Esta no es la forma adecuada de leer el objeto, ya que
            ///       sería mejor heredar de un objeto tipo "ReadableObjet".
            /// 
            std::ifstream& leer (std::ifstream& ifs);
    };

}

#endif
