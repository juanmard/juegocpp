#include "Ladrillo.h"

/**
 * \brief   Constructor que crea un objeto golpeable por la pelota en el juego.
 * \todo    Muchas cosas por hacer:
 *          - Eliminar la forma de obtener el sample. Crear un objeto propio de
 *            sonido para independizar lo más posible de Allegro.
 *          - Eliminar la carga del fichero de recursos "sprites.dat".
 *          - No me gusta como se identifica a los objetos, pues para crear un
 *            objeto hay que acordarse de añadir el nombre en la clase "Nombres".
 */
Ladrillo::Ladrillo(void)
{
    crear_ladrillo ();
}

/**
 * \brief   Constructor para situar el ladrillo a la vez que lo creamos.
 */
Ladrillo::Ladrillo(int x, int y)
{
    crear_ladrillo ();
    set_x (x);
    set_y (y);
}

Ladrillo::~Ladrillo(void)
{
}

/**
 * \brief   Intersección del ladrillo con otro actor de la escena.
 * \param   who Puntero al actor que provoca la colisión.
 * \param   damage Daño que se produce en la colisión. 
 * \todo    Se necesita calcular no sólo la energía con la que colisionan los
 *          objetos(damage), sino con qué inclinación colisionan.
 */
void  Ladrillo::hit  (Actor *who, int damage)
{
   switch (who->get_name())
   {
       case Nombres::pelota:
           /**
            * \brief   Sonido de rebote de prueba.
            * \todo    Crear clases separadas para objetos de sonido.
            */
           play_sample (peloteo,200,128,800,FALSE);

           /**
            * Cambiamos el estado del ladrillo para que caiga.
            */
           this->estado = EN_CAIDA;
           break;

       case Nombres::ladrillo:
           //estado = Ladrillo::EN_CAIDA;
           //set_y(get_y()+3);
           break;
       
       case Nombres::paleta:
           play_sample (peloteo,200,128,500,FALSE);
           estado = Actor::eliminar;
           break;

       default:
           /*
           set_y(get_y()+1);
           if (this->estado == Ladrillo::EN_CAIDA)
           {
               play_sample (peloteo,200,128,500,FALSE);
               //set_y(get_y()+10);
               this->estado = ESPERA;
           }
           */
           break;
   }
}

/**
 * \brief   Se llama desde el constructor para generar las características
 *          generales del ladrillo (de forma predeterminada).
 */
void    Ladrillo::crear_ladrillo (void)
{
    DatFile &sprites = DatFile("sprites.dat");
    chaqueta = new Bitmap(this, sprites.GetBitmap("suelo_2"));
    // A eliminar - Para pruebas de sonido.
    peloteo = (SAMPLE *) sprites.GetDat (76);

    this->set_name (Nombres::ladrillo);
    this->set_actor_graphic (chaqueta);
	this->set_is_detected(true);
    //this->set_team(ENEMY);
    this->set_collision_method(CollisionManager::PP_COLLISION);
    this->set_wh (32,15);
    this->tiempo_estado=30;
    this->estado = Ladrillo::ESPERA;
}

/**
 * \brief   Máquina de estados de la clase.
 */
void  Ladrillo::update  (void)
{
    switch (estado)
    {
    /* \brief El ladrillo cae libremente en este estado.
     * \todo Añadir física al juego, en este caso se necesitaría la aceleración de la gravedad.
     */
    case EN_CAIDA:
        this->set_y (this->get_y()+2);
        if (get_y()>600)
        {
            estado = Actor::eliminar;
        }
        break;

    case ESPERA:
    default:
        break;
    }
}