#pragma once

#include <allegro.h>
#include "Actor.h"

/**
 * \brief       Muestra un actor en una pequeña GUI para editar sus propiedades.
 * \details     Esta GUI utiliza funciones básicas de Allegro. Contiene funciones globales para los
 *              "callback" de las componentes. Las funciones de modificación y actualización de
 *              objetos deben ser encomendadas a la clase "EditorManager".
 * \todo        Compatibilizar los "callback" globales mediante funciones estáticas de la clase.
 *              Ej. "DlgActor::d_mi_menu_proc" en las definiciones.
 */
class DlgActor
{
	public:
                DlgActor          (Actor *actor);
                DlgActor          (void);
                ~DlgActor         (void);
        void    show              (void);
        void    load              (Actor *actor);
        void    save              (void);

protected:
		Actor *actor;
        static DIALOG DlgActor::dlg_propiedades[];
};
