#include "Tesela.h"
#include <sstream>

using namespace std;

/**
 * \brief   Constructor copia. Se permite cambiar el padre de la nueva Tesela.
 */
Tesela::Tesela(const Tesela &copia, Mosaico *padre):
mosaico_padre(padre),
x(copia.x), y(copia.y),
dibujo(copia.dibujo),
mirror(copia.mirror)
{
}

/**
 * Constructor de clase.
 */
Tesela::Tesela(Mosaico *padre)
{
    mosaico_padre = padre;
}

/**
 * Constructor de clase.
 */
Tesela::Tesela (Mosaico *padre, BITMAP *imagen, int x_tmp, int y_tmp, bool mirror_tmp)
{
    mosaico_padre = padre;
    dibujo = imagen;
    x = x_tmp;
    y = y_tmp;
    mirror = mirror_tmp;
};

/**
 * Constructor de clase. Usando el 'Bitmap' propio.
 */
Tesela::Tesela (Mosaico *padre, string nombreImagen, int xParam, int yParam, bool mirrorParam):
mosaico_padre (padre),
dibujo (NULL),
x (xParam),
y (yParam),
mirror (mirrorParam)
{
  dibujoPrueba = new Bitmap (padre->getActor(), nombreImagen);
};


/**
 * Guarda en un fichero las teselas.
 */
void Tesela::Guardar (void)
{
  FILE    *handle;

  // TODO: Crear una clase de fichero y pasar el nombre del fichero por parámetros.
  handle = fopen ("clases.txt","w");

  fprintf (handle, "%s","<Tesela>\n{\n");
  // Habría que guardar el nombre o algo significativo de la imagen.
  fprintf (handle, "x,y: %d, %d\n", x, y);
  fprintf (handle, "mirror: %s\n",mirror?"true":"false");
  fprintf (handle, "}\n");
  fclose (handle);
};

/**
 * Cambiamos el dibujo de la Tesela.
 */
void Tesela::SetDibujo (BITMAP *imagen)
{
    dibujo = imagen;
}

/**
 * Cambiamos la x de la Tesela referida al mosaico padre.
 */
void Tesela::Set_x (int x_tmp)
{
    x = x_tmp;
}

/**
 * Cambiamos la y de la Tesela referida al mosaico padre.
 */
void Tesela::Set_y (int y_tmp)
{
    y = y_tmp;
}

/**
 * Obtenemos la x de la Tesela referida al mosaico padre.
 */
int Tesela::Get_x (void)
{
    return x;
}

/**
 * Obtenemos la y de la Tesela referida al mosaico padre.
 */
int Tesela::Get_y (void)
{
    return y;
}

/**
 * Se dibuja la Tesela referida al mosaico padre.
 */
void Tesela::draw (BITMAP *pantalla)
{
  // Se calcula la posición respecto al padre.
  int x_tmp = x + mosaico_padre->get_x ();
  int y_tmp = y + mosaico_padre->get_y ();

  // Se comprueba la dirección de la tesela para dibujarla.
  if (mirror)
  {
    draw_sprite_h_flip (pantalla, dibujo, x_tmp, y_tmp);    
  }
  else
  {
    draw_sprite (pantalla, dibujo, x_tmp, y_tmp);    
  }
}

/**
 * Se clona la Tesela asignándole un nuevo mosaico padre.
 */
Tesela * Tesela::clone (Mosaico *padre) const
{
    return (new Tesela(*this, padre));
}

/**
 * Se dibuja la Tesela referida a un punto relativo dado.
 */
void Tesela::draw (int relX, int relY, BITMAP *pantalla)
{
  // Se calcula la posición respecto al padre.
  int x_tmp = x + relX;
  int y_tmp = y + relY;

  // Se comprueba el bitmap que estamos usando.
  if (dibujo)
  {
    // Se comprueba la dirección de la tesela para dibujarla.
    if (mirror)
    {
      draw_sprite_h_flip (pantalla, dibujo, x_tmp, y_tmp);    
    }
    else
    {
      draw_sprite (pantalla, dibujo, x_tmp, y_tmp);    
    }
  }
  else
  {
    dibujoPrueba->draw (x_tmp, y_tmp, pantalla, mirror);
  }
}

/**
 * \brief   Devuelve una cadena con la estructura de la tesela.
 */
string  Tesela::getString () const
{
  ostringstream cadena;

  cadena << "{" << x << "," << y << ", " << (mirror?"true":"false") << "} " << dibujoPrueba->getString();
  return cadena.str ();
};
