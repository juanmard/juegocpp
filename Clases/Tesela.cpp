///
/// @file Tesela.cpp
/// @brief Fichero de implementación de la clase "Tesela".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#include "Tesela.h"
#include <sstream>
#include <stdio.h>
#include "Mosaico.h"

Tesela::Tesela (const Tesela& copia, Mosaico* padre):
mosaico_padre(padre),
x(copia.x),
y(copia.y),
dibujo(copia.dibujo),
mirror(copia.mirror)
{
};

Tesela::Tesela (Mosaico* padre)
{
    mosaico_padre = padre;
};

Tesela::Tesela (Mosaico* padre, BITMAP* imagen, int x_tmp, int y_tmp, bool mirror_tmp)
{
    mosaico_padre = padre;
    dibujo = imagen;
    x = x_tmp;
    y = y_tmp;
    mirror = mirror_tmp;
};

Tesela::Tesela (Mosaico* padre, std::string& nombreImagen, int xParam, int yParam, bool mirrorParam):
mosaico_padre (padre),
dibujo (NULL),
x (xParam),
y (yParam),
mirror (mirrorParam)
{
  dibujoPrueba = new Bitmap (padre->getActor(), nombreImagen);
};

void Tesela::guardar () const
{
  FILE* handle;

  /// @todo Crear una clase de fichero y pasar el nombre del fichero por parámetros.
  /// @warning C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead.
  /// @todo Hacer esto mismo con la biblioteca de fstream.
  handle = fopen ("clases.txt","w");

  fprintf (handle, "%s","<Tesela>\n{\n");
  /// @note Habría que guardar el nombre o algo significativo de la imagen.
  fprintf (handle, "x, y: %d, %d\n", x, y);
  fprintf (handle, "mirror: %s\n",mirror?"true":"false");
  fprintf (handle, "}\n");
  fclose (handle);
};

void Tesela::set_dibujo (BITMAP* imagen)
{
    dibujo = imagen;
};

void Tesela::set_x (int x_tmp)
{
    x = x_tmp;
};

void Tesela::set_y (int y_tmp)
{
    y = y_tmp;
};

int Tesela::get_x () const
{
    return x;
};

int Tesela::get_y () const
{
    return y;
};

void Tesela::draw (BITMAP* pantalla) const
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
};

Tesela* Tesela::clone (Mosaico* padre) const
{
    return (new Tesela(*this, padre));
};

void Tesela::draw (int relX, int relY, BITMAP* pantalla) const
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
};

std::string& Tesela::print () const
{
  std::ostringstream oss;

  // @warning Aparecen problemas con el puntero de Bitmap... todo está en pruebas... un desastre.
  //  oss << "{" << x << "," << y << ", " << (mirror?"true":"false") << "} " << dibujoPrueba->print ();
  oss << "{" << x << "," << y << ", " << (mirror?"true":"false") << "} " << "Tesela sin Bitmap";
  return *new std::string(oss.str ());
};

