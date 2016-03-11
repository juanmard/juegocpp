#pragma once

#include <string>

using namespace std;

/**
 * \class   Nombres
 * \brief   Clase que reúne todos los nombres de objetos del juego.
 */
class Nombres
{
  public:
    enum codigo {pelota, paleta, herny, jugador, enemigo, ladrillo, mago, ben};

  public:
          Nombres     ();
          ~Nombres    ();

  /**
   * \brief   Convierte el código de un nombre en una cadena imprimible de caracteres.
   * \todo    Utilizar un operador de conversión de tipos para este método.
   *          En lugar de usar el 'switch' utilizar una estructura 'stl' tipo 'map'.
   */
  static string  Imprimir (const codigo cod_nombre)
  {
    string cadena;

    switch (cod_nombre)
    {
      case pelota:    cadena = "Pelota";      break;
      case paleta:    cadena = "Suelo";       break;
      case herny:     cadena = "Herny";       break;
      case jugador:   cadena = "Jugador";     break;
      case enemigo:   cadena = "Enemigo";     break;
      case ladrillo:  cadena = "Ladrillo";    break;
      case mago:      cadena = "Mago";        break;
      case ben:       cadena = "Ben";         break;
      default:        cadena = "Sin nombre";  break;
    }
    return cadena;
  }
};
