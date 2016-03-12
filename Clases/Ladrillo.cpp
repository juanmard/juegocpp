///
/// @file    Ladrillo.cpp
/// @brief   Fichero de definición de la clase Ladrillo.
/// @details La documentación de los procedimientos se encuentra en su fichero de cabecera.
/// @author  Juan Manuel Rico.
/// @date    Marzo 2015
/// @version 1.0.0
///

#include "Ladrillo.h"
#include "Almacen.h"
#include "Dialog.h"
#include <allegro.h>
#include <fstream>

Ladrillo::Ladrillo ()
{
    crear_ladrillo ();
};

Ladrillo::Ladrillo (const Ladrillo &copia):
Actor (copia),
chaqueta(copia.chaqueta),
peloteo(copia.peloteo)
{
};

Ladrillo::Ladrillo (int x, int y)
{
    DatFile *sprites = new DatFile("sprites3.dat");
    chaqueta = new Bitmap(this, sprites->GetBitmap("suelo_2"));
    // A eliminar - Para pruebas de sonido.
    peloteo = (SAMPLE *) sprites->GetDat (76);
    crear_ladrillo ();
    set_x (x);
    set_y (y);
};

Ladrillo::Ladrillo (int x, int y, Almacen &almacen)
{
//    chaqueta = new Bitmap(this, almacen.GetBitmap("sprite_041"), "sprite_041");
      BITMAP *puntero = almacen.getBitmap("sprite_041");
      chaqueta = new Bitmap(this, puntero, almacen.getName (puntero));

      crear_ladrillo ();
      set_x (x);
      set_y (y);
};

Ladrillo::~Ladrillo ()
{
    // Liberar el recurso de la imagen del ladrillo si no la está usando nadie.
    // ¿Incluir un contador estático de uso dentro de la clase "Bitmap"?
    // Liberar el recurso de sonido.
    // Liberar los recursos utilizados por la clase base (Actor)
};

void  Ladrillo::hit  (Actor *who, int damage)
{
   switch (who->getCodigo ())
   {
       case Nombres::pelota:
           // Sonido de rebote de prueba.
           // play_sample (peloteo,200,128,800,FALSE);

           // Cambiamos el estado del ladrillo para que caiga.
           this->estado = EN_CAIDA;
           break;

       case Nombres::ladrillo:
           // estado = Ladrillo::EN_CAIDA;
           // set_y(get_y()+3);
           break;

       case Nombres::paleta:
           // play_sample (peloteo,200,128,500,FALSE);
           estado = Actor::eliminar;
           break;

       default:
           /*
           set_y(get_y()+1);
           if (this->estado == Ladrillo::EN_CAIDA)
           {
               play_sample (peloteo,200,128,500,FALSE);
               // set_y(get_y()+10);
               this->estado = ESPERA;
           }
           */
           break;
   }
};

void  Ladrillo::update ()
{
    switch (estado)
    {
    /// El ladrillo cae libremente en este estado.
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
};

Ladrillo* Ladrillo::clone () const
{
    return (new Ladrillo (*this));
};

void Ladrillo::getNombre (std::string &strNombre) const
{
  strNombre = Nombres::Imprimir (nombre);
};

std::string Ladrillo::getNombre () const
{
  return Nombres::Imprimir (nombre);
}

Menu& Ladrillo::getMenu () const
{
  // Obtenemos la referencia al menú más general de los actores.
  Menu &nuevo = Actor::getMenu();

  // Añadimos las opciones propias del 'Ladrillo'.
  // Se llama al procedimiento 'about' de prueba.
  nuevo.add (const_cast<char*>("Ladrillo - About"), Dialog::about);
  return nuevo;
};

void  Ladrillo::addGUI (vector<DIALOG> &gui_padre)
{
  // Agregamos la GUI como actor.
  Actor::addGUI (gui_padre);

  // Agregamos la GUI como Ladrillo y guardamos la referencia.
  //LadrilloGUI *gui = new LadrilloGUI (*this, gui_padre); // Warning de "gui" sin usar.
  new LadrilloGUI (*this, gui_padre);
};

std::ifstream&  Ladrillo::leer (std::ifstream& ifs)
{
    string comando, piel, sample;
    int x, y;

    // Lee el comando (Chaqueta).
    ifs >> comando;

    // Lee el valor entrecomillado.
    ifs.ignore(20,'\"');
    std::getline (ifs,piel,'\"');

#if _DEBUG_LADRILLO
    std::cout << "Comando: " << comando << "\t Valor: " << piel << std::endl;
#endif

    // Lee el comando de sonido y su valor entrecomillado.
    ifs >> comando;
    ifs.ignore(20,'\"');
    std::getline (ifs,sample,'\"');

#if _DEBUG_LADRILLO
    std::cout << "Comando: " << comando << "\t Valor: " << sample << std::endl;
#endif

    // Se lee el comando y los valores de la posición.
    ifs >> comando;
    ifs.ignore(20,'<') >> x;
    ifs.ignore(20,',') >> y;
    ifs.ignore(20,'>');

#if _DEBUG_LADRILLO
    std::cout << "Comando: " << comando << "\t Valor: <" << x << ", " << y << ">" << std::endl;
#endif

    // Actualiza o modifica los valores del ladrillo según los leídos en el fichero.
    Almacen *sprites = new Almacen("sprites3.dat");
    chaqueta = new Bitmap(this, sprites, piel);
    crear_ladrillo ();
    set_x (x);
    set_y (y);

    /*
    // No es necesario llamar a la clase base Actor puesto que el ladrillo completa
    // todos los valores del actor con la llamada "crear_ladrillo".
    return Actor::leer(ifs);
    */
    return ifs;
};

std::string Ladrillo::getString () const
{
  std::ostringstream cadena;

  // Se genera una cadena con los valores y propiedades actuales.
  cadena << "Ladrillo {" << std::endl \
         << "    Chaqueta  \"" << agraph->getString () << "\"" << std::endl \
         << "    Peloteo   \"" << "sample_001" << "\"" << std::endl \
         << "    Posición  <" << x << ", " << y << ">" << std::endl \
         << "}" << std::endl;

  // Se devuelve la cadena con el formato "string".
  return cadena.str ();
};

void Ladrillo::crear_ladrillo ()
{
  this->setCodigo (Nombres::ladrillo);
  this->set_actor_graphic (chaqueta);
  this->set_is_detected(true);
  // this->set_team(ENEMY);
  this->set_collision_method(CollisionManager::PP_COLLISION);
  this->set_wh (32,15);
  this->tiempo_estado=30;
  this->estado = Ladrillo::ESPERA;
};
