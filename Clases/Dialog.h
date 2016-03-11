#pragma once

#include <allegro.h>
#include "EditorManager.h"
#include "DlgActor.h"

class EditorManager;
class DlgActor;

/**
 * \brief       Muestra una pequeña GUI para editar los objetos del juego.
 * \details     Esta GUI utiliza funciones básicas de Allegro. Contiene funciones globales para los
 *              "callback" de las componentes. Las funciones de modificación y actualización de
 *              objetos deben ser encomendadas a la clase "EditorManager".
 * \todo        Compatibilizar los "callback" globales mediante funciones estáticas de la clase.
 *              Ej. "Dialog::d_pantalla_proc" en las definiciones de "dialog".
 */
class Dialog
{
	public:
                    Dialog          (EditorManager *editor);
                    ~Dialog         (void);
        void        show            (void);
        void        mouse_out       (void);
        int         propiedades     (void);

protected:
		EditorManager   *owner;
        DlgActor        *dlg_actor;
};
