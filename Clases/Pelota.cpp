#include "Pelota.h"

/**
 * \brief   Constructor de copia.
 */
Pelota::Pelota (const Pelota &copia):
DirectorActor(copia),
direccion_x(copia.direccion_x),
direccion_y(copia.direccion_y),
tomate(copia.tomate),
granada(copia.granada),
estrella(copia.estrella),
rebote(copia.rebote)
{
}

/**
 * \brief Crea la pelota que se encargará de rebotar por la pantalla.
 * \todo Eliminar la creación contínua del objeto "sprite".
 * \todo Incluir rebote si tropieza con algún tipo de suelo.
 * \todo Incluir sonidos en el rebote.
 */
Pelota::Pelota(ActorManager *actor_manager):
DirectorActor (actor_manager)
{
    DatFile *sprites = new DatFile("sprites.dat");
    granada = new Bitmap(this, sprites->GetBitmap("granada"));
    tomate = new Bitmap(this, sprites->GetBitmap("tomate"));
    estrella = new Bitmap(this, sprites->GetBitmap("estrella"));
    
    // A eliminar - Para pruebas de sonido.
    rebote = (SAMPLE *) sprites->GetDat (77);

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
 * \brief   Actualiza la posición de la pelota.
 * \todo    Cambiar la animación cuando se produce el rebote.
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
 * \todo    Función a eliminar.
 */
void Pelota::CambiarEstado (void)
{
}

/**
 * \brief   Intersección de la pelota con otro actor de la escena.
 * \param   who Puntero al actor que provoca la colisión.
 * \param   damage Daño que se produce en la colisión. 
 * \todo    Se necesita calcular no sólo la energía con la que colisionan los
 *          objetos(damage), sino con qué inclinación colisionan.
 * \todo    Añadir un descritor (¿Quizás un "enum" en actor?) para interrogar
 *          al actor por su nombre (suelo, pelota, etc) y así sirva de "filtro"
 *          en las colisiones.
 */
void  Pelota::hit  (Actor *who, int damage)
{
   switch (who->get_name())
   {
       /**
        * Si tropezamos con un ladrillo. Cambiamos la dirección de rebote y
        * eliminamos el ladrillo de la escena.
        */
       case Nombres::ladrillo:
           // set_actor_graphic (tomate);
           direccion_y = -direccion_y;
           //Elimina (who);
           break;

       case Nombres::herny:
           /** \todo Añadir un estado general en el actor que lo identifique
            *        el ActorManager y lo marque para borrar de la lista de actores.
            */
           break;

       case Nombres::paleta:
            // set_actor_graphic (granada);
       default:
             // Queda comprobar desde donde rebota.
             //if ((get_y() > who->get_y() + who->get_h())
             //       || (who->get_y() > get_y() + get_h()))
             //{
             //  direccion_x = -direccion_x;
             //}
             direccion_y = -direccion_y;

            /**
             * \brief   Sonido de rebote de prueba.
             * \todo    Crear clases separadas para objetos de sonido.
             */
             play_sample (rebote,200,128,1500,FALSE);
             break;
   }


  /**
   * \todo  Crear clase para mostrar mensajes de depuración en pantalla.
   * \todo  Un convertidor a cadena para los nombres de los actores.
   */
  rectfill (screen, SCREEN_W-100,0,SCREEN_W,14,0);
  textprintf (screen, font, SCREEN_W-100,0,-1, "Hit: %d", who->get_name());
}

/**
 * \brief   Duplica el actor Pelota.
 */
Pelota *    Pelota::clone () const
{
    return (new Pelota(*this));
};
