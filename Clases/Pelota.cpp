#include "Pelota.h"

/**
 * \brief Crea la pelota que se encargar� de rebotar por la pantalla.
 * \todo Eliminar la creaci�n cont�nua del objeto "sprite".
 * \todo Incluir rebote si tropieza con alg�n tipo de suelo.
 * \todo Incluir sonidos en el rebote.
 */
Pelota::Pelota(void)
{
    DatFile &sprites = DatFile("sprites.dat");
    tomate = new Bitmap(this, sprites.GetBitmap("tomate"));
    granada = new Bitmap(this, sprites.GetBitmap("granada"));
    estrella = new Bitmap(this, sprites.GetBitmap("estrella"));
    
    // A eliminar - Para pruebas de sonido.
    rebote = (SAMPLE *) sprites.GetDat (77);

    this->set_name (Nombres::pelota);
    this->set_x(0);
    this->set_y(0);
    this->set_actor_graphic (tomate);
	this->set_is_detected(true);
    //this->set_team(ENEMY);
    this->set_collision_method(CollisionManager::PP_COLLISION);
    this->set_wh (18,20);
    this->direccion_x = 2;
    this->direccion_y = 2;
    this->tiempo_estado=30;

    
}

/**
 * \brief Elimina la pelota.
 */
Pelota::~Pelota(void)
{
}

/**
 * \brief   Actualiza la posici�n de la pelota.
 * \todo    Cambiar la animaci�n cuando se produce el rebote.
 */
void Pelota::ActualizarEstado (void)
{
   x = x + direccion_x;
   y = y + direccion_y;
   if ((x+w)>= SCREEN_W || x <= 0)
   {
       direccion_x = -direccion_x;
//       this->set_actor_graphic (tomate);
   }
   if ((y+h)>=SCREEN_H || y<=0)
   {
       direccion_y = -direccion_y;
//       this->set_actor_graphic (granada);
   }
   this->tiempo_estado = 30;
}

/**
 * \brief   Cambia el estado de la pelota. 
 * \todo    Funci�n a eliminar.
 */
void Pelota::CambiarEstado (void)
{
}

/**
 * \brief   Intersecci�n de la pelota con otro actor de la escena.
 * \param   who Puntero al actor que provoca la colisi�n.
 * \param   damage Da�o que se produce en la colisi�n. 
 * \todo    Se necesita calcular no s�lo la energ�a con la que colisionan los
 *          objetos(damage), sino con qu� inclinaci�n colisionan.
 * \todo    A�adir un descritor (�Quiz�s un "enum" en actor?) para interrogar
 *          al actor por su nombre (suelo, pelota, etc) y as� sirva de "filtro"
 *          en las colisiones.
 */
void  Pelota::hit  (Actor *who, int damage)
{
   switch (who->get_name())
   {
       /**
        * \brief    Si tropezamos con la paleta...
        */
       case Nombres::ladrillo:
           direccion_y = -direccion_y;
           manager->del(who);
           break;

       case Nombres::herny:
            /** \todo A�adir un estado general en el actor que lo identifique
             *        el ActorManager y lo marque para borrar de la lista de actores.
             */
           /*
           {
           Pelota *prb = new Pelota();
           prb->set_y(200);
           manager->add(prb);
           }
           */
           break;

       case Nombres::paleta:
       default:
            /**
             * \brief   Sonido de rebote de prueba.
             * \todo    Crear clases separadas para objetosde sonido.
             */
             //set_actor_graphic (granada);
             direccion_y = -direccion_y;
             play_sample (rebote,200,128,1500,FALSE);
             break;
   }


  /**
   * \todo  Crear clase para mostrar mensajes de depuraci�n en pantalla.
   * \todo  Un convertidor a cadena para los nombres de los actores.
   */
  rectfill (screen, SCREEN_W-100,0,SCREEN_W,14,0);
  textprintf (screen, font, SCREEN_W-100,0,-1, "Hit: %d", who->get_name());
}