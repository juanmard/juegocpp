#ifndef SLIDERCTRL_H
#define SLIDERCTRL_H

#include <iostream>
#include "Control.h"
#include "IControlListener.h"
#include "VectorCtrl.h"

/// Control deslizante (slider) para seleccionar un valor dentro de un rango.
/// Permite al usuario ajustar un valor moviendo un "thumb" a lo largo de una barra.
///
/// @todo Añadir propiedades adicionales como orientación (horizontal/vertical), pasos, etc.
/// @todo Implementar métodos para obtener y establecer el valor actual del slider.
/// @todo Añadir soporte para eventos específicos del slider (p.ej. cambio de valor).
///
class SliderCtrl : public Control, public IControlListener {
public:
    unsigned int pos;   ///< Posición actual del slider.
    unsigned int min;   ///< Valor mínimo.
    unsigned int max;   ///< Valor máximo.

    SliderCtrl(int x_, int y_, int w_, int h_, int fg_, int bg_, int key_, int flags_, Comando* cmd = nullptr, void* d = nullptr)
        : Control(TipoControl::SLIDER, x_, y_, w_, h_, fg_, bg_, key_, flags_, cmd, d), pos(50), min(10), max(120) {};
        
    SliderCtrl(int x_, int y_) : Control(TipoControl::SLIDER, x_, y_, 0, 0, 0, 0, 0, 0), pos(50), min(10), max(120) {};
    void setComando (Comando* cmd) { comando = cmd; };

    /// @brief Establece el valor del slider dentro del rango permitido.
    /// @param value valor a establecer.
    /// @return Si el valor ha cambiado.
    ///
    bool setValue (unsigned int value) {
        bool need_change = (pos != value) && (value >= min) && (value <= max);
        if (need_change) {
            pos = value;
            notifyListeners();
        }
        return need_change;
    }

    /// @brief Notifica a este control otros controles que hayan cambiado.
    /// @param control Control que ha cambiado.
    ///
    void controlChanged(Control* control) override;

    /// @brief Maneja los eventos de entrada específicos del slider.
    /// @param ev Evento de entrada.
    /// @return Devuelve un código de resultado heredado de Allegro.
    /// 
    /// @todo Implementar códigos propios de resultado para independizar de Allegro.
    ///
    int manejarEvento(const InputEvent& ev) override;
};

#endif // SLIDERCTRL_H
