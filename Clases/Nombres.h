#pragma once

#include <string>
#include <iostream>

using namespace std;
//using std::string;
//using std::ostream;

/**
 * \class   Nombres
 * \brief   Clase que reúne todos los nombres de objetos del juego.
 */
class Nombres
{
    
  public:
    enum codigo {pelota, paleta, herny, jugador, enemigo, ladrillo, mago, ben, camello, plataforma};

  public:
          Nombres     ();
          ~Nombres    ();

  public:
  /**
   * \brief   Convierte el código de un nombre en una cadena imprimible de caracteres.
   * \todo    Utilizar un operador de conversión de tipos para este método.
   *          En lugar de usar el 'switch' utilizar una estructura 'stl' tipo 'map'.
   *          Esto mismo se hizo para referenciar los punteros y los nombres de los Bitmaps en la clase 'Almacen'.
   */
  static std::string Imprimir (const codigo cod_nombre)
  {
    string cadena;

    switch (cod_nombre)
    {
      case pelota:     cadena = "Pelota";      break;
      case paleta:     cadena = "Suelo";       break;
      case herny:      cadena = "Herny";       break;
      case jugador:    cadena = "Jugador";     break;
      case enemigo:    cadena = "Enemigo";     break;
      case ladrillo:   cadena = "Ladrillo";    break;
      case mago:       cadena = "Mago";        break;
      case ben:        cadena = "Ben";         break;
      case camello:    cadena = "Camello";     break;
      case plataforma: cadena = "Plataforma";  break;
      default:         cadena = "Sin nombre";  break;
    }
    return cadena;
  }

  // Permiso de la función para un uso amistoso de los métodos de la clase.
  friend  ostream&  operator<< (ostream &os, const Nombres::codigo cod);
};
