/**
 *  \file     Actor.cpp
 *  \brief    Prueba del "framework" de un juego.
 *
 *  \details  La clase instancia un tipo de juego de prueba con todos los controladores posibles.
 *            La primera versión de la instancia se utiliza para actualizar el juego de plataformas
 *            programado antiguamente en C "puro y duro".
 *
 *  \author   Juan Manuel Rico
 *  \date     diciembre 2010
 *  \version  1.00
 *
 *  \todo     Comentar todas estas clases y funciones más detalladamente.
 */
#include <sstream>
#include <iostream>
#include "Actor.h"
#include "ActorGraphic.h"
#include "StageManager.h"
#include "Dialog.h"

DIALOG Actor::dlg_actor[] =
{
   /* (proc)            (x) (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                            (dp2) (dp3) */
   { d_box_proc,        8,  336, 616, 240, 67,  243, 0,    0,      0,   0,   NULL,                           NULL, NULL },
   { Actor::callback,   8,  320, 80,  16,  67,  243, 0,    0,      0,   0,   (void*)"Pesta 01",              NULL, NULL },
   { d_text_proc,       16, 344, 168, 8,   67,  243, 0,    0,      0,   0,   (void*)"Propiedades de actor:", NULL, NULL },
   { d_shadow_box_proc, 24, 360, 320, 192, 67,  243, 0,    0,      0,   0,   NULL,                           NULL, NULL },
   { d_text_proc,       32, 368, 56,  8,   67,  243, 0,    0,      0,   0,   (void*)"Nombre:",               NULL, NULL },
   { d_text_proc,       32, 384, 80,  8,   67,  243, 0,    0,      0,   0,   (void*)"Posicion:",             NULL, NULL },
   { d_text_proc,       32, 400, 136, 8,   67,  243, 0,    0,      0,   0,   (void*)"Grafico asociado:",     NULL, NULL },
   { d_slider_proc,     32, 528, 280, 16,  67,  243, 0,    0,      16,  4,   NULL,                           NULL, NULL },
   { NULL,              0,  0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                           NULL, NULL }
};

/**
 * \brief   Constructor por omisión de la clase. 
 * \details No asigna gráfico y no se sitúa en el tiempo. 
 */
Actor::Actor():
agraph(NULL),
estado(actuar),
tiempo_estado(0),
mostrarBloque (false)
{
}

/**
 * \brief   Constructor copia de la clase.
 */
Actor::Actor(const Actor &copia):
nombre (copia.nombre),
x(copia.x), y(copia.y),
h(copia.h), w(copia.w),
color(copia.color),
collision_method(copia.collision_method),
is_detectable(copia.is_detectable),
//~ agraph(copia.agraph),
estado(copia.estado),
tiempo_estado(copia.tiempo_estado),
power(copia.power),
team(copia.team),
mostrarBloque (copia.mostrarBloque)
{
    // Duplicamos la parte gráfica del actor a copiar y se la asiganmos al nuevo.
    // Para ello...
    // 1. Conseguimos la parte gráfica del actor a copiar.
    // 2. Duplicamos la parte gráfica dando como propietario el nuevo actor.
    // 3. Asignamos la parte gráfica duplicada al nuevo actor.
    set_actor_graphic(copia.get_actor_graphic()->clone (this));
}

/**
 * Destruye el actor.
 * Si tiene asignado un gráfico lo elimina.
 */
Actor::~Actor()
{
    if (agraph) delete agraph;
}

/**
 * \brief   Visualiza el aspecto gráfico del actor.
 *          Delega esta función en el objeto gráfico.
 * \todo    Crear clase "Pantalla" para independizar del Bitmap de Allegro.
 */
void Actor::draw (BITMAP *bmp)
{
  // Se dibuja si tiene parte gráfica.
  if (agraph) agraph->draw (bmp);
}

/**
 * \brief   Visualiza las dimensiones del actor mediante un rectángulo.
 *          Utiliza la propiedad 'color' para ello.
 */
void Actor::draw_block (BITMAP *pantalla)
{
    rect (pantalla,x,y,x+w,y+h,color);
}

void Actor::hit (Actor *who, int damage)
{
};

void Actor::set_collision_method (CollisionManager::collision_method_t metodo)
{
    collision_method = metodo;
};

void Actor::set_team (Game::team_t equipo)
{
    team = equipo;
};

void Actor::set_is_detected (bool detectable)
{
    is_detectable = detectable;
};

void Actor::ActualizarEstado ()
{
}

void Actor::CambiarEstado ()
{
}

void Actor::set_tiempo (unsigned int tiempo)
{
    tiempo_estado = tiempo;
}

void Actor::update()
{
  // Se comprueba si existe la parte gráfica.
  // Si existe, se actualiza.
  if (agraph) agraph->update();

  // Actualiza los estados del actor.
  if (tiempo_estado)
  {
    tiempo_estado--;
    if (tiempo_estado == 0)
    {
      CambiarEstado ();
    }
    ActualizarEstado ();
  }
}

/**
 * \brief   Inicializa la parte gráfica del actor.
 */
void Actor::init()
{
  // Se comprueba que el actor tiene parte gráfica.
  if (agraph) agraph->init();
}

void Actor::set_x(int pos_x)
{
    x=pos_x;
}

void Actor::set_color (int color_tmp)
{
    color = color_tmp;
}

void Actor::set_y (int pos_y)
{
    y=pos_y;
}

void Actor::set_wh (int w_tmp, int h_tmp)
{
  // Las dimensiones no pueden ser negativas. Las hacemos cero en ese caso.
  if (w_tmp < 0) w_tmp = 0;
  if (h_tmp < 0) h_tmp = 0;
  w = w_tmp;
  h = h_tmp;
}

void Actor::set_actor_graphic (ActorGraphic *ag)
{
  agraph=ag;
}

/**
 * \brief   Devuelve la referencia al objeto ActorGraphic.
 */
ActorGraphic *  Actor::get_actor_graphic () const
{
  return agraph;
}

/**
 * \brief   Devuelve el color del actor.
 */
int Actor::get_color (void)
{
    return color;
}

/**
 * \brief   Devuelve la componente x de la posición del actor.
 */
int Actor::get_x()
{
    return x;
}

/**
 * \brief   Devuelve la componente y de la posición del actor.
 */
int Actor::get_y()
{
    return y;
}

/**
 * \brief   Devuelve el ancho del actor.
 */
int Actor::get_w()
{
    return w;
}

/**
 * \brief   Devuelve el alto del actor.
 */
int Actor::get_h()
{
    return h;
}

/**
 * \brief   Devuelve la posición x del componente gráfico del actor.
 */
int Actor::get_graph_x()
{
    return agraph->get_x();
}

/**
 * \brief   Devuelve la posición y del componente gráfico del actor.
 */
int Actor::get_graph_y()
{
    return agraph->get_y();
}

/**
 * \brief   Método para obtener el código del nombre.
 */
Nombres::codigo  Actor::getCodigo (void)
{
  return nombre;
};

/**
 * \brief   Método para modificar el nombre.
 * \param   new_name    Nombre nuevo para sustituir.
 */
void  Actor::setCodigo (Nombres::codigo new_name)
{
  nombre = new_name;
};

/**
 * \brief   Método para obtener el estado actual del actor.
 */
Actor::estado_t  Actor::get_Estado (void)
{
    return estado;
}

/**
 * \brief   Clona un actor.
 */
Actor * Actor::clone () const {return NULL;};

/**
 * \brief   Comprueba si el actor intersecciona con el bloque pasado como parámetro.
 */
bool  Actor::isIntersectado  (Bloque bloque)
{
  // \todo  Desarrollar el código.
  return (true);
}

/**
 * \brief   Visualiza el aspecto gráfico del actor referida al escenario.
 *          Delega esta función en el objeto gráfico.
 */
void Actor::draw (StageManager *stageManager)
{
    // Se calcula la posición relativa del actor al escenario. 
    int relx = x - stageManager->getX();
    int rely = y - stageManager->getY();

    // Se dibuja en el escenario en la posición calculada.
    if (agraph) agraph->draw (relx,rely,stageManager->getBuffer());
}

/**
 * \brief   Visualiza el bloque de referencia del actor referida al escenario.
 * \warning   Quizás este procedimiento es más adecuado que esté en la clase
 *            'StageManager' ya que es la que debe saber dibujar cuadrados en el 
 *            escenario.
 */
void Actor::draw_block (StageManager *stageManager)
{
  // Si la propiedad del actor indica que mostremos el bloque lo mostramos.
  if (mostrarBloque)
  {
    // Se calcula la posición relativa del actor al escenario. 
    int relx = x - stageManager->getX ();
    int rely = y - stageManager->getY ();

    // Se dibuja en el escenario en la posición calculada.
    rect (stageManager->getBuffer(), relx, rely, w + relx, h + rely, color);
  }
}

/**
 * \brief   Obtiene el bloque que define las dimensiones del actor.
 * \todo    Integrar la clase 'Bloque' completamente en ésta y en otras clases.
 */
Bloque &  Actor::getBloque ()
{
  Bloque *tmp = new Bloque (x, y, w, h);
  return *tmp;
}

/**
 * \brief   Obtiene la posición del actor y actualiza la cadena pasada por parámetro.
 */
void  Actor::getXY (string &posicion) const
{
  stringstream  ss;
//  ss << "(" << x << ", " << y << ")";
  ss << x << ", " << y;
  posicion = ss.str();
};

/**
 * \brief   Obtiene las dimensiones del actor y actualiza la cadena 
 *          pasada por parámetro.
 * \param   dimensiones   Cadena para ser rellenada con las dimensiones.
 */
void  Actor::getWH (string &dimensiones) const
{
  stringstream  ss;
//  ss << "(" << w << ", " << h << ")";
  ss << w << ", " << h;
  dimensiones = ss.str();
};

/**
 * \brief   Obtiene el estado actual del actor.
 * \param   dimensiones   Cadena para ser rellenada con el estado.
 */
void  Actor::getEstado (string &estado) const
{
  estado = "sin estado";
};

/**
 * \brief   Obtiene el nombre del actor.
 * \param   dimensiones   Cadena para ser rellenada con el nombre.
 * \todo    Para compatibilizar con elformato estándar 'std' crear un método
 *          que devuelva la cadena en lugar de recibirla como parámetro:
 *            - string  Actor::getNombre () const;
 *          Lo que nos permitiría hacer cosas como:
 *            - cout << "El nombre del actor es " << actor.getNombre();
 */
void  Actor::getNombre (string &nombre) const
{
  nombre = "Sin nombre";
};

string  Actor::getNombre () const
{
  return "Sin nombre";
};


/**
 * \brief   Cambia si se desea mostrar el bloque (posición y dimensiones) del actor
 *          en pantalla.
 * \param   mostrar   Si es 'true' se mostrará y si es 'false' no se mostrará.
 */
void  Actor::setMostrarBloque (bool mostrar)
{
  mostrarBloque = mostrar;
}

/**
 * \brief   Obtiene un menú con las acciones posibles según el tipo de actor.
 * \warning Esto se utiliza para el editor. Es posible que no sea conveniente mezclarlo con la clase genérica del Actor.
 */
Menu &  Actor::getMenu () const
{
  Menu *menu = new Menu();
  menu->add("Actor - Mover");
  menu->add("Actor - Tamaño");
  return *menu;
}

/**
 * \brief   Devuelve una cadena de texto con la estructura y propiedades del actor.
 */
string  Actor::getString () const
{
  ostringstream cadena;
  string nombre;

  // Se obtienen las propiedades del actor.
  getNombre (nombre);
  cadena << nombre << " {" << endl \
         << "Posición <" << x << "," << y << ">" << endl \
         << "Bloque <" << w << "," << h << ">" <<endl;

  // Se obtiene la parte gráfica del actor.
  if (agraph)
  {
   cadena << "Gráfico {" << endl \
         <<  agraph->getString () \
         << "}" <<endl;
  }

  // Se cierra la cadena.
  cadena << "}" << endl;

  // Se devuelve la cadena.
  return cadena.str ();
};

/**
 * \brief   Muestra en consola el error de no tener asignado una parte gráfica.
 */
void  Actor::mensajeErrorGrafico () const
{
  string nombre;
  getNombre (nombre);
  cout << "ERROR: Actor \"" << nombre << "\" sin componente gráfica." << endl;
}

/**
 * \brief   Prueba para enviar la GUI de las propiedades del actor.
 * \todo    Pasar a una clase distinta y sin referencias a Allegro.
 */
vector<DIALOG> &  Actor::getDIALOG ()
{
  // Prueba de DIALOG. Llenamos el vector de DIALOG's.
  // Usamos la plantilla global.
  vec_actor.clear ();
  for (int i=0; i<=7; i++)
  {
    vec_actor.push_back(dlg_actor[i]);
  }

  // Rellenamos con los datos del objeto.
  string *cadena = new string("Nombre: " + getNombre());
  vec_actor[4].dp = const_cast<char*>(cadena->c_str());
  ostringstream posicion;
  posicion << "Posición: " << x << "," << y;
  string *pos = new string (posicion.str());
  vec_actor[5].dp = const_cast<char*>(pos->c_str());
  string *grafico = new string("Gráfico: " + agraph->getString());
  vec_actor[6].dp = const_cast<char*>(grafico->c_str());
  return vec_actor;
};

/**
 * \brief   Prueba para añadir la GUI de las propiedades del actor a una GUI padre.
 * \todo    Pasar a una clase distinta y sin referencias a Allegro.
 */
void  Actor::addGUI (vector<DIALOG> &gui_padre)
{
  // Rellenamos con los datos del objeto.
  string *cadena = new string("Nombre: " + getNombre());
  dlg_actor[4].dp = const_cast<char*>(cadena->c_str());
  ostringstream posicion;
  posicion << "Posición: " << x << "," << y;
  string *pos = new string (posicion.str());
  dlg_actor[5].dp = const_cast<char*>(pos->c_str());
  string *grafico = new string("Gráfico: " + agraph->getString());
  dlg_actor[6].dp = const_cast<char*>(grafico->c_str());

  // Prueba de DIALOG. Llenamos el vector de DIALOG's.
  // Usamos la plantilla global.
  gui_padre.insert (gui_padre.end()-1, &dlg_actor[0], &dlg_actor[8]);
};
