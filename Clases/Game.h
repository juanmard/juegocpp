///---------------------------------------------------------
/// @file       Game.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      FrameWork del juego.
///---------------------------------------------------------
#ifndef _GAME_H_
#define _GAME_H_

#include <string>

/// Espacio de nombre para el "FrameWork Game".
namespace fwg {

    /// Predefiniciones de clases.
    class ActorManager;
    class StageManager;
    class SoundManager;
    class ControlManager;
    class CollisionManager;
    class Almacen;
    class Timer;

    /// Clase que recoge las funciones básicas de un juego.
    /// 
    /// Se encarga de establecer variables generales, iniciar
    /// el motor gráfico y mantener los bucles de actualización
    /// de lógica y gráfica del juego.
    /// 
    /// @todo Cosas por corregir en la clase: 
    /// - Eliminar el tipo 'team_t' que no se usa.
    /// - Cambiar la clase 'Almacen' por clase 'StorageManager'.
    /// - Eliminar y aislar referencias a Allegro en esta clase.
    ///         
    class Game
    {
        public:
            typedef enum {ALLY, ENEMY} team_t;
            
            /// Estados del juego en su ciclo de vida.
            enum State
            {
              CREATED,  ///< Juego creado.
              INIT,     ///< Juego iniciado.
              RUNNING,  ///< Juego funciona normalmente.
              PAUSED,   ///< Juego en pausa.
              SHUTDOWN  ///< Juego apagándose.
            };

        public:
            ActorManager        *actorManager;     ///< Controlador de actores.
            StageManager        *stageManager;     ///< Controlador del escenario.
            SoundManager        *soundManager;     ///< Conttolador de sonidos.
            ControlManager      *controlManager;   ///< Controlador de controles.
            CollisionManager    *collisionManager; ///< Controlador de colisiones.
            Almacen             *storageManager;   ///< Controlador de recursos.

        protected:
            std::string name;           ///< Nombre del juego.
            int         gfx_w, gfx_h;   ///< Tamaño ventana.
            int         colors;         ///< Profundidad de color.

        private:
            Timer*  timer;      ///< Temporizador del juego.
            State   state;      ///< Estado actual del juego.

        public:
            /// Constructor por defecto.
            /// 
            Game ();
        
            /// Destructor virtual.
            /// 
            virtual ~Game ();
        
            /// Inicializador del juego.
            /// 
            /// Se encarga de inicializar el motor gráfico y variables del juego.
            /// Cada juego redefinirá este método según el tipo de motor gráfico
            /// que se utilice.
            /// 
            /// @param gfx_mode Modo de visualización.
            /// @param w Ancho de la pantalla.
            /// @param h Alto de la pantalla.
            /// @param col Profundidad de color.
            /// 
            virtual void init (int gfx_mode, int w, int h, int col);
            
            /// Procedimiento principal del juego.
            /// 
            /// Se encarga de establecer el bucle principal del juego.
            /// Cada juego redefinirá este método según el tipo de juego a
            /// construir.
            /// 
            virtual void mainGame ();

            /// Inicia o reanuda desde la pausa el juego.
            /// 
            /// Se inician las actualizaciones de lógica y gráfica en el
            /// bucle principal del juego.
            /// 
            void play ();
            
            /// Pausa el juego.
            /// 
            /// Se dejan de actualizar lógica y gráfica en el bucle
            /// principal del juego.
            /// 
            void pause ();
            
            /// Indica si el juego se encuentra en pausa.
            /// 
            /// @return Devuelve 'true' si el juego está en pausa.
            /// 
            bool isPaused () const;
            
            /// Establece el nombre del juego.
            /// 
            /// @param name Nombre del juego.
            /// 
            void setName (std::string name);
            
            /// Entrega el nombre del juego.
            /// 
            /// @return Nombre del juego como cadena de caracteres.
            /// 
            std::string getName () const;
            
            /// Actualiza el estado del juego.
            /// 
            /// Establece un nuevo ciclo de lógica y gráfica.
            /// 
            void update ();
            
            /// Establece el temporizador que se utilizará en el juego.
            /// 
            /// Este temporizador en 'tiempo real' permitirá que el
            /// juego se ejecute a la misma velocidad en distintas
            /// máquinas.
            /// 
            /// @param temporizador Referencia al temporizador del juego.
            /// 
            void setTimer (Timer* temporizador);

        private:
            /// Se inicia el juego.
            /// 
            /// Se establece el inicio del juego una vez inicialiado
            /// todo lo necesario.
            /// 
            void start ();
            
            /// Se apaga el juego.
            /// 
            /// Se ejecuta el procedimiento para terminar el juego.
            /// 
            /// @param message Mensaje final del juego por consola.
            /// 
            void shutdown (std::string message);
            
            /// Se crea el controlador de actores.
            ///
            virtual void createActorManager ();

            /// Se crea el controlador del escenario.
            ///
            virtual void createStageManager ();
            
            /// Se crea el controlador de sonido.
            ///
            virtual void createSoundManager ();

            /// Se crea el controlador de controles.
            ///
            virtual void createControlManager ();
            
            /// Se crea el controlador de colisiones.
            ///
            virtual void createCollisionManager ();
            
            /// Se crea el controlador de recursos.
            ///
            virtual void createStorageManager ();
    };
}

#endif
