#include "Ladrillo.h"
#include "Almacen.h"
#include "Dialog.h"
#include <allegro.h>
#include <fstream>

/**
 * \brief   Constructor que crea un objeto golpeable por la pelota en el juego.
 * \todo    Muchas cosas por hacer:
 *          - Eliminar la forma de obtener el sample. Crear un objeto propio de
 *            sonido para independizar lo más posible de Allegro.
 *          - Eliminar la carga del fichero de recursos "sprites.dat".
 *          - No me gusta como se identifica a los objetos, pues para crear un
 *            objeto hay que acordarse de añadir el nombre en la clase "Nombres".
 */
Ladrillo::Ladrillo ()
{
    crear_ladrillo ();
}

/**
 * \brief Constructor de copia.
 */
Ladrillo::Ladrillo (const Ladrillo &copia):
Actor (copia),
chaqueta(copia.chaqueta),
peloteo(copia.peloteo)
{
}

/**
 * \brief   Constructor para situar el ladrillo a la vez que lo creamos.
 * \warning Método a eliminar. Utilizar en su lugar el constructor que
 *          utiliza los recursos del almacén.
 */
Ladrillo::Ladrillo (int x, int y)
{
    DatFile *sprites = new DatFile("sprites.dat");
    chaqueta = new Bitmap(this, sprites->GetBitmap("suelo_2"));
    // A eliminar - Para pruebas de sonido.
    peloteo = (SAMPLE *) sprites->GetDat (76);
    crear_ladrillo ();
    set_x (x);
    set_y (y);
}

/**
 * \brief   Constructor para situar el ladrillo a la vez que lo creamos
 *          utilizando los recursos del almacén.
 */
Ladrillo::Ladrillo (int x, int y, Almacen &almacen)
{
//  chaqueta = new Bitmap(this, almacen.GetBitmap("sprite_041"), "sprite_041");
  BITMAP *puntero = almacen.getBitmap("sprite_041");
  chaqueta = new Bitmap(this, puntero, almacen.getName (puntero));

  crear_ladrillo ();
  set_x (x);
  set_y (y);
}

Ladrillo::~Ladrillo ()
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
   switch (who->getCodigo ())
   {
       case Nombres::pelota:
           /**
            * \brief   Sonido de rebote de prueba.
            * \todo    Crear clases separadas para objetos de sonido.
            */
           //play_sample (peloteo,200,128,800,FALSE);

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
           //play_sample (peloteo,200,128,500,FALSE);
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
void    Ladrillo::crear_ladrillo ()
{
  this->setCodigo (Nombres::ladrillo);
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
void  Ladrillo::update ()
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

/**
 * \brief   Clona el objeto.
 */
Ladrillo *  Ladrillo::clone () const
{
    return (new Ladrillo (*this));
};

/**
 * \brief   Obtiene el nombre en forma de cadena de texto.
 */
void  Ladrillo::getNombre (string &strNombre) const
{
  strNombre = Nombres::Imprimir (nombre);
}

/**
 * \brief   Devuelve el nombre del objeto.
 */
string  Ladrillo::getNombre () const
{
  return Nombres::Imprimir (nombre);
}

/**
 * \brief   Obtiene el menú de opciones del actor.
 */
Menu &  Ladrillo::getMenu () const
{
  // Obtenemos el menú más general de los actores.
  Menu &nuevo = Actor::getMenu ();

  // Añadimos las opciones propias del 'Ladrillo'.
  // Se llama al procedimiento 'about' de prueba.
  nuevo.add (const_cast<char*>("Ladrillo - About"), Dialog::about);
  return nuevo;
}

/**
 * \brief   GUI.
 */
void  Ladrillo::addGUI (vector<DIALOG> &gui_padre)
{
  // Agregamos la GUI como actor.
  Actor::addGUI (gui_padre);

  // Agregamos la GUI como Ladrillo y guardamos la referencia.
  //LadrilloGUI *gui = new LadrilloGUI (*this, gui_padre); // Warning de "gui" sin usar.
  new LadrilloGUI (*this, gui_padre);
}

/**
 * \brief   Obtiene los objetos de un flujo de datos.
 * \details Obtiene los valores de un nuevo ladrillo en el flujo de datos y actualiza
 *          el actor pasado por parámetro.
 */
istream&  Ladrillo::prueba_iostream (istream &is, Ladrillo &a)
{
  // Extrae los valores del flujo formateado.
  //string nombre;

  // TODO: Este nombre habría que convertirlo a tipo "Nombres::codigo"
  //is >> nombre;
  cout << "prueba_ladrillo ---" << nombre;
  is.ignore (10,'<');
  is >> a.x;
  is.ignore (10,',');
  is >> a.y;
  is.ignore (10,'<');
  is >> a.w;
  is.ignore (10,',');
  is >> a.h;
  is.ignore (10,'>');

  return is;
}

/**
 * \details Leer desde fichero.
 */
std::ifstream&  Ladrillo::leer (std::ifstream& ifs)
{
    string basura, comando, piel, sample;
    int x, y;

    ifs >> basura >> comando >> piel;
    std::cout << "Comando: " << comando << "\t Valor: " << piel << std::endl;
    ifs >> comando >> sample;
    std::cout << "Comando: " << comando << "\t Valor: " << sample << std::endl;
    ifs >> comando >> x >> y >> basura;
    std::cout << "Comando: " << comando << "\t Valor: " << x << ", " << y << std::endl;
  //ifs.ignore (10,'<');
  //is >> a.x;
  //is.ignore (10,',');
  //is >> a.y;
  //is.ignore (10,'<');
  //is >> a.w;
  //is.ignore (10,',');
  //is >> a.h;
  //is.ignore (10,'>');

    Almacen *sprites = new Almacen("sprites3.dat");
    chaqueta = new Bitmap(this, sprites, piel);
    crear_ladrillo ();
    set_x (x);
    set_y (y);

    // No es necesario ya que el ladrillo completa todos los valores del actor con la llamada "crear_ladrillo".
//    return Actor::leer(ifs);
    return ifs;
};

/**
 */
std::string  Ladrillo::getString () const
{
  std::ostringstream cadena;

  // Se genera una cade simple.
  cadena << "Ladrillo {" << std::endl \
         << "    Chaqueta  " << agraph->getString () << std::endl \
         << "    Peloteo   " << "sample_001" << std::endl \
         << "    Posición  " << x << "  " << y << std::endl \
         << "}" << std::endl;

  // Se devuelve la cadena con el formato "string".
  return cadena.str ();
};
