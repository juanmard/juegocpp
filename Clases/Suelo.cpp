///
/// @file Suelo.cpp
/// @brief Declaración de la clase gráfica Suelo.
/// @author Juan Manuel Rico
/// @date Enero 2009
/// @version 1.0.0
///

#include "Suelo.h"
#include "Actor.h"
#include <sstream>
#include <fstream>

Suelo::Suelo ():
Mosaico(),
size(0),
terminal(NULL),
bloque(NULL)
{
};

Suelo::Suelo (const Suelo& copia, Actor* propietario):
Mosaico (copia, propietario),
size (copia.size),
terminal (copia.terminal),
bloque (copia.bloque)
{
};

Suelo::Suelo (Actor* aowner, int new_size):
Mosaico (aowner)
{
    DatFile *file_dat = new DatFile("sprites3.dat");
    terminal = file_dat->GetBitmap("pre2_067");
    bloque = file_dat->GetBitmap("pre2_069");

    // Generamos el suelo según el tamaño solicitado.
    for (int i=0; i<new_size; i++)
    {
        add_ultima_Tesela (new Tesela (this, bloque, 32*i, 0));
    }
  
    // Añadimos las plataformas terminales al suelo.
    // Se hace al final para que queden dibujadas por encima de los bloques.
    add_ultima_Tesela (new Tesela (this, terminal, 0, 0));
    add_ultima_Tesela (new Tesela (this, terminal, 32*new_size-10, 0, true));

    // Una vez creado actualizamos la variable del tamaño.
    size = new_size;

    /// Adaptamos el ancho y el alto del actor padre.
    /// @note Igual esto no es deseable si queremos hacer un suelo "falso", es decir,
    ///       que no sea tan extenso como lo que muestra el gráfico.
    ///       Esto demuestra que es necesario desligar el gráfico del actor.
    ajustar ();
};

Suelo::Suelo (Actor* aowner, Almacen& almacen, int new_size):
Mosaico (aowner)
{
    // Nombres de gráficos para el fichero "sprites3.dat".
    terminal = almacen.get_bitmap("pre2_067");
    bloque = almacen.get_bitmap("pre2_069");

    // Generamos el suelo según el tamaño solicitado.
    for (int i=0; i<new_size; i++)
    {
        add_ultima_Tesela (new Tesela (this, bloque, 32*i, 0));
    }
  
    // Añadimos las plataformas terminales al suelo.
    add_ultima_Tesela (new Tesela (this, terminal, 0, 0));
    add_ultima_Tesela (new Tesela (this, terminal, 32*new_size-10, 0, true));

    // Una vez creado actualizamos la variable del tamaño.
    size = new_size;

    // Adaptamos el ancho y el alto del actor padre.
    // TODO: Igual esto no es deseable si queremos hacer un suelo "falso", es decir,
    //       que no sea tan extenso como lo que muestra el gráfico o si queremos desligar
    //       el actor del gráfico que lo.identifica.
    ajustar ();
};

int  Suelo::getSize () const
{
    return size;
};

void Suelo::setSize (int new_size)
{
  // Si el tamaño es cero (por una construcción básica del objeto)...
  // Hay que incluir al menos las imágenes de bitmap  con las que trabajar y agregar
  // las teselas de los terminales en el mosaico.
  if (size == 0)
  {
      inicializar ();
  };

  // Una vez con un suelo básico...
  // se calcula la diferencia de tamaños, es decir,
  // el número de bloques a incluir o eliminar.
  int num = new_size - size;

  // Si el tamaño es en realidad nuevo...
  if (num != 0)
  {
    // Movemos el terminal derecho (último) a la nueva posición.
    move_Tesela (32*num, 0, last_Tesela());

    // Si el tamaño es mayor...
    if (num > 0)
    {
      // Añadimos o quitamos teselas de "bloques".
      for (int i=0; i<num; i++)
      {   
        add_primera_Tesela (new Tesela (this, bloque, 32*(size+i)));
      }
    }
    // Si el tamaño es menor...
    else
    {
      num = -num;
      for (int i=0; i<num; i++)
      {   
        del_primera_Tesela ();
      }
    }

    // Actualizamos al tamaño actual.
    size = new_size;

    // Ajustamos las dimensiones del actor propietario al dibujo.
    ajustar ();
  }
};

void Suelo::inicializar ()
{
    DatFile *file_dat = new DatFile("sprites3.dat");
    terminal = file_dat->GetBitmap("pre2_067");
    bloque = file_dat->GetBitmap("pre2_069");

    //this->clear ();
    add_ultima_Tesela (new Tesela (this, bloque,   0, 0));
    add_ultima_Tesela (new Tesela (this, terminal, 0, 0));
    add_ultima_Tesela (new Tesela (this, terminal, 32-10, 0, true));

    size = 1;
};

Suelo*  Suelo::clone (Actor* propietario) const
{
    return (new Suelo(*this, propietario));
};

std::string  Suelo::getString () const
{
    std::ostringstream cadena;

    cadena << "    Suelo {" << std::endl \
           << "        Tamaño " << size << std::endl \

           /// @todo Al convertir los "BITMAP" en "Bitmap" aquí podríamos incluir
           ///       @code terminal.getString(); @endcode
           /// @note Si el suelo siempre se forma con los mismos gráficos no es necesario
           ///       incluirlo en la cadena de propiedades.
           // << "      terminal " << "sprite_" << std::endl \
           // << "      bloque " << "sprite_" << std::endl \


           << "    }" << std::endl;
    return cadena.str ();
};

std::ifstream& Suelo::leer (std::ifstream& ifs)
{
    std::string comando;

    ifs >> comando;
    if (!comando.compare("Tamaño"))
    {
        int tam;
        ifs >> tam;
        this->setSize(tam);
    }
    return ifs;
};

void Suelo::ajustar ()
{
    if(owner) owner->set_wh (32*size+20,15);
};

