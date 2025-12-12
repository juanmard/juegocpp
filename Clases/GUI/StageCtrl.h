#ifndef STAGECTRL_H
#define STAGECTRL_H

#include <iostream>
#include "Control.h"
#include "IControlListener.h"
#include "EditorManager.h"
#include "Bloque.h"

/// Control del escenario.
/// Permite mostrar al usuario una representación de los actores en la escena y modificar los mismos.
///
/// @todo Sustiturir las propiedades x, y, width y height por una variable "Bloque".
///
class StageCtrl : public Control, public IControlListener {
public:
    Bloque marco;
    bool dragEscenario;

    /// Referencia al EditorManager, de prueba.
    EditorManager* editor_manager = nullptr;

    ///
    StageCtrl(int x_, int y_, int w_, int h_, int fg_, int bg_, int key_, int flags_, Comando* cmd = nullptr, void* d = nullptr) :
    Control(TipoControl::STAGE, x_, y_, w_, h_, fg_, bg_, key_, flags_, cmd, d),
    marco(x_, y_, w_, h_), dragEscenario(false) {
        //editor_manager->set_ribete(marco);
    }

    ///
    StageCtrl(int x_, int y_) :
    Control(TipoControl::STAGE, x_, y_, 0, 0, 0, 0, 0, 0),
    marco(x_, y_, 600, 100), dragEscenario(false) {
        // Prueba.
    };

    ///
    void setComando (Comando* cmd) { comando = cmd; };

    /// @brief Notifica a este control otros controles que hayan cambiado.
    /// @param control Control que ha cambiado.
    ///
    void controlChanged(Control* control) override;

    /// @brief Maneja los eventos de entrada específicos del escenario.
    /// @param ev Evento de entrada.
    /// @return Devuelve un código de resultado heredado de Allegro.
    /// 
    /// @todo Implementar códigos propios de resultado para independizar de Allegro.
    ///
    int manejarEvento(const InputEvent& ev) override;

    /// @brief Dibuja el marco del control.
    ///
    void dibujarMarco (void);

    /// De forma temporal usamos una referencia al "game" completo.
    void setEditorManager(EditorManager* _editor_manager) {editor_manager = _editor_manager; };
};

#endif // STAGECTRL_H
