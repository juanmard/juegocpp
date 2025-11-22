#ifndef VECTORCTRL_H
#define VECTORCTRL_H

#include <iostream>
#include "Control.h"
#include "IControlListener.h"
#include "SliderCtrl.h"

/// @brief Control que nos muestra un vector de dos componentes.
/// 
class VectorCtrl : public Control, public IControlListener {
public:
    // @todo Sustituir en futuro por una clase (p.j. la clase "Bloque").
    unsigned int x;      ///< Posición - Coordenada x.
    unsigned int y;      ///< Posición - Coordenada y.
    //unsigned int z;    ///< Posición - Coordenada z.
    std::string texto;   ///< Texto asociado al vector.
    bool modoEdicion;    ///< Nos indica si el vector está siendo editado.

    /// @brief Constructor del vector dando todos los parámetros.
    /// 
    VectorCtrl(int x_, int y_, int w_, int h_, int fg_, int bg_, int key_, int flags_, Comando* cmd = nullptr, void* d = nullptr)
        : Control(TipoControl::VECTOR, x_, y_, w_, h_, fg_, bg_, key_, flags_, cmd, d), x(0), y(0) {};
        
    /// @brief Constructor del vector estableciendo la posición en la pantalla.
    /// @param x_ Posición x del control en pantalla.
    /// @param y_ Posición y del control en pantalla.
    ///
    VectorCtrl(unsigned int x_, unsigned int y_) : Control(TipoControl::VECTOR, x_, y_, 0, 0, 0, 0, 0, 0), x(0), y(0), texto(""), modoEdicion(false) {};
    
    /// @brief Establece el comando a ejecutar.
    /// @param cmd Comando a ejecutar.
    ///
    void setComando (Comando* cmd) { comando = cmd; };

    /// @brief Establece los valores de x e y.
    /// @param x_ Valor nuevo de x.
    /// @param y_ Valor nuevo de y.
    ///
    void setXY (unsigned int x_, unsigned int y_) {
        bool changed = false;
        if ( x != x_) {
             x = x_;
             changed = true;
        }
        if ( y != y_) {
             y = y_;
             changed = true;
        }
        if (changed) {
            renderer->updateVector(this);
            notifyListeners();
        }
    }

    /// @brief Establece el comportamiento del vector según cambie el control que escucha.
    /// @param control Control que ha cambiado.
    ///
    void controlChanged(Control* control) override;
    
    /// @brief Establece el comportamiento del vector ante eventos.
    /// @param ev Evento que se produce.
    /// @return Resultado del procesado del evento.
    /// @todo Independizar el resultado de Allegro creando un resultado propio.
    ///
    int manejarEvento(const InputEvent& ev) override;
};

#endif // VECTORCTRL_H
