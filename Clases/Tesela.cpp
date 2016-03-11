#include "Tesela.h"

Tesela::Tesela(Mosaico *padre)
{
    mosaico_padre = padre;
}

Tesela::Tesela (Mosaico *padre, BITMAP *imagen, int x_tmp, int y_tmp, bool mirror_tmp)
{
    mosaico_padre = padre;
    dibujo = imagen;
    x = x_tmp;
    y = y_tmp;
    mirror = mirror_tmp;
};

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

void Tesela::SetDibujo (BITMAP *imagen)
{
    dibujo = imagen;
}

void Tesela::Set_x (int x_tmp)
{
    x = x_tmp;
}

void Tesela::Set_y (int y_tmp)
{
    y = y_tmp;
}

int Tesela::Get_x (void)
{
    return x;
}

int Tesela::Get_y (void)
{
    return y;
}

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

