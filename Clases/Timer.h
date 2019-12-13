///---------------------------------------------------------
/// @file       Timer.h
/// @author     Juan Manuel Rico
/// @date       Diciembre 2019
/// @version    1.0.0
///
/// @brief      Timer del juego.
///---------------------------------------------------------
#ifndef _TIMER_H_
#define _TIMER_H_

namespace fwg {
    
    /// Temporizador del juego.
    /// Se trata de mantener la velocidad del juego para distintas máquinas.
    class Timer {
       
    protected:
        unsigned int    max_frame_skip; ///< Máximo cuadros a saltar.
        unsigned int    quantum;        ///< Tiempo en milisegundos entre tick.
        unsigned int    ticks_ps;       ///< Ticks por segundo (1000/quantum).
        
    private:
        unsigned int    actual_tick;    ///< Cuenta de tick actual.
        unsigned int    old_tick;       ///< Cuenta de tick antiguo.
        unsigned int    graphic_tick;   ///< Cuenta de tick gráficos.
        unsigned int    frame_skip;     ///< Cuadros saltados.

    public:
        /// Constructor.
        /// @param mseg Quantum en milisegundos entre ticks.
        /// @param max_fs Máximos cuadros que se pueden saltar.
        /// 
        Timer (unsigned int mseg=14, unsigned int max_fs=10);
        
        /// Ejecuta la instalación del timer en el sistema.
        /// 
        virtual void install ();
        
        /// Iniciar el temporizador.
        /// 
        void start ();
        
        /// Indica si se debe actualizar la lógica del juego.
        /// @return Devuelve 'true' si debe actualizarse.
        /// 
        bool updateLogic ();

        /// Indica si se debe actualizar la gráfica del juego.
        /// @return Devuelve 'true' si debe actualizarse.
        /// 
        bool updateGraphic ();

        /// Indica si tenemos un nuevo segundo.
        /// @return Devuelve 'true' si ha pasado un nuevo segundo.
        /// 
        bool has_new_second () const;

        /// Reinicia el contador para un nuevo segundo.
        /// Se utiliza para calcular los cuadros por segundo
        /// y los cuadros que se han saltado.
        /// 
        void reset_second ();
        
        /// Obtiene los cuadros por segundo.
        /// @return Cuadros por segundo.
        /// 
        unsigned int get_fps () const;
        
        /// Obtiene los cuadros saltados.
        /// @return Cuadros saltados.
        /// 
        unsigned int get_frameskip () const;

    protected:
        /// Obtiene los 'ticks' actuales.
        /// @return Ticks actuales.
        /// 
        virtual unsigned int getTick () const;
    };
}

#endif
