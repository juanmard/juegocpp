///---------------------------------------------------------
/// @file       Control.cpp
/// @author     Juan Manuel Rico
/// @date       Octubre 2015
/// @version    1.0.0
///
/// @brief      Define un objeto de control.
///---------------------------------------------------------

#include "Control.h"

namespace fwg {

    Control::Control ()
    {
    }
    
    void Control::addActionName (ControllableObject::Action act, std::string str)
    {
        Association asoc;
        asoc.act = act;
        asoc.name = str;
        asoc.peri = NULL;
        asoc.comp = -1;
        associations.push_back (asoc);
    }

    void  Control::setActionPeripheral (
          ControllableObject::Action act,
          Peripheral* peri,
          Peripheral::Component comp,
          Peripheral::Event e)
    {
        // Con el bucle se busca la acción en la lista de acciones.
        for (associationsIter = associations.begin();
           associationsIter != associations.end();
           associationsIter++)
        {
            // Si la acción es la requerida se asocia el periférico, el componente, el evento
            // y salimos del bucle.
            if (associationsIter->act == act)
            {
                associationsIter->peri = peri;
                associationsIter->comp = comp;
                associationsIter->newEvent = e;
                associationsIter->oldEvent = Peripheral::NO_EVENT;
                return;
            }
        }
    }

    void Control::addAssociation (Control::Association assoc)
    {
        associations.push_back (assoc);
    }

    void Control::setOwner (ControllableObject* co)
    {
        owner = co;
    }

    void Control::update ()
    {
        bool doActionOrder;
        Peripheral::State tmpState;
        Peripheral::Event tmpOldEvent;

        // El bucle comprueba y actualiza todos los estados de las asociaciones.
        for (associationsIter = associations.begin();
             associationsIter != associations.end();
             associationsIter++)
        {
            // Se lee temporalmente el estado actual del periférico y su componente
            // asociado.
            tmpState = associationsIter->peri->getState (associationsIter->comp);

            // Se lee temporalmente el evento anterior.
            tmpOldEvent = associationsIter->oldEvent;

            // En principio no se ejecutará la acción si no hay nadie que diga
            // lo contrario.
            doActionOrder = false;

            // Según el evento actual, el anterior y el estado guardado
            // temporalmente, se decide si ejecutar o no la acción del
            // control sobre el objeto propietario del mismo.
            switch (associationsIter->newEvent)
            {
                case Peripheral::ON_PRESSING:
                    if (tmpState != INVALID_STATE)
                    {
                        doActionOrder = true;
                    }
                    break;

                case Peripheral::ON_PRESS:
                    if ((tmpOldEvent == Peripheral::ON_RELEASE) &&
                        (tmpState != INVALID_STATE))
                    {
                        associationsIter->oldEvent = Peripheral::ON_PRESS;
                        doActionOrder = true;
                    }
                    else
                    {
                        if (tmpState == INVALID_STATE)
                        {
                            associationsIter->oldEvent = Peripheral::ON_RELEASE;
                        }
                    }
                    break;

                case Peripheral::ON_RELEASE:
                    if ((tmpOldEvent == Peripheral::ON_PRESS) &&
                        (tmpState == INVALID_STATE))
                    {
                        associationsIter->oldEvent = Peripheral::ON_RELEASE;
                        doActionOrder = true;
                    }
                    else
                    {
                        if (tmpState != INVALID_STATE)
                        {
                            associationsIter->oldEvent = Peripheral::ON_PRESS;
                        }
                    }
                    break;

              case Peripheral::ON_RELEASSING:
                    if (tmpState == INVALID_STATE)
                    {
                        doActionOrder = true;
                    }
                    break;

              default:
                    break;
            }

            // Si finalmente hay orden de realizar una acción,
            // manda ejecutarla al propietario del control.
            if (doActionOrder)
            {
                owner->doAction (associationsIter->act, tmpState);
            }
        }
    }

    std::string Control::getNameAction (ControllableObject::Action act)
    {
        for (associationsIter = associations.begin();
           associationsIter != associations.end();
           associationsIter++)
        {
            if (associationsIter->act == act)
            {
              return associationsIter->name;
            }
        }
        return "";
    }
}