///
/// @file Tesela.h
/// @brief Fichero de definición de la clase "Tesela".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#ifndef _TESELA_
#define _TESELA_

#include <allegro.h>
#include "PrintableObject.h"
#include "Bitmap.h"
#include <string>

namespace fwg {

class Mosaico;

/// Parte gráfica de un Mosaico.
/// @todo Por hacer para afinar el comportamiento de una tesela:
///        - Permitir que el mosaico sea de sprites, es decir de hacer mosaicos con partes animadas.
///        - Generar una clase con estos bloques.
///          Y ser estos los que se interseccionan. De esta forma un actor puede estar
///          compuesto de varios bloques y afinar la intersección.
///          Se pueden dibujar estos contornos para referencia. Para las teselas
///          sólo se necesitan las referencias enlazadas.
///          @code
///             typedef struct Bloque
///             {
///               int x, y;
///               int ancho, alto;
///             };
///          @endcode
///
class Tesela : public PrintableObject
{
private:
    Mosaico* mosaico_padre;     ///< Puntero al mosaico padre propietario de la tesela.
    BITMAP* dibujo;             ///< BITMAP de Allegro representación de la tesela.
    /// @var Bitmap* dibujoPrueba;
    /// Prueba para sustituir los BITMAP's de Allegro por los propios.
    Bitmap* dibujoPrueba;       ///< Representación gráfica de la tesela.
    int x;                      ///< Coordenada x de la posición relativa al mosaico padre.
    int y;                      ///< Coordenada y de la posición relativa al mosaico padre.
    /// @todo Incluir los 360 grados de giro.
    ///       En lugar de únicamente la simetría en x.
    bool mirror;                ///< Reflexión o no de la imagen de la tesela respecto a la imagen original.

public:
    /// Constructor copia.
    /// @param copia  Tesela a copiar.
    /// @param padre  Mosaico al que asignar la copia.
    ///
    Tesela (const Tesela& copia, Mosaico* padre);

    /// Constructor.
    /// @param padre  Mosaico al que asignar la tesela.
    ///
    Tesela (Mosaico* padre);

    /// Costructor. Usando el BITMAP de Allegro.
    /// @param padre  Mosaico donde se incluye la tesela.
    /// @param imagen  BITMAP de Allegro con la imagen que tendrá la tesela.
    /// @param x_tmp  Coordenada x de la posición relativa de la tesela.
    /// @param y_tmp  Coordenada y de la posición relativa de la tesela.
    /// @param mirror_tmp  Indica si el dibujo de la tesela se representará o no reflejado respecto al original.
    ///
    Tesela (Mosaico* padre, BITMAP* imagen, int x_tmp=0, int y_tmp=0, bool mirror_tmp=false);

    /// Constructor de clase. Usando el 'Bitmap' propio.
    /// @param padre  Mosaico donde se incluye la tesela.
    /// @param nombreImagen  Nombre de la imagen que tendrá la tesela.
    /// @param x  Coordenada x de la posición relativa de la tesela.
    /// @param y  Coordenada y de la posición relativa de la tesela.
    /// @param mirror  Indica si el dibujo de la tesela se representará o no reflejado respecto al original.
    ///
    Tesela (Mosaico* padre, std::string& nombreImagen, int x=0, int y=0, bool mirror=false);

    /// Se clona la Tesela asignándole un nuevo mosaico padre.
    /// @param padre  Mosaico padre de la tesela.
    /// @return Puntero a la nueva tesela clonada.
    ///
    virtual Tesela* clone (Mosaico* padre) const;

    /// Se dibuja la Tesela referida al mosaico padre.
    /// @param pantalla  Zona donde se debe dibujar la tesela.
    ///
    void draw (BITMAP* pantalla) const;

    /// Se dibuja la Tesela referida a un punto relativo dado.
    /// @param relX  Coordenada x relativa donde dibujar la tesela.
    /// @param relY  Coordenada y relativa donde dibujar la tesela.
    /// @param pantalla  Zona donde dibujar la tesela.
    ///
    void draw (int relX, int relY, BITMAP* pantalla) const;

    /// Cambiamos el dibujo de la Tesela.
    /// @param imagen  Dibujo de la tesela.
    ///
    void set_dibujo (BITMAP* imagen);

    /// Cambiamos la x de la Tesela referida al mosaico padre.
    /// @param x_tmp  Nueva coordenada x de la posición.
    ///
    void set_x (int x_tmp);

    /// Cambiamos la y de la Tesela referida al mosaico padre.
    /// @param y_tmp  Nueva coordenada y de la posición.
    ///
    void set_y (int y_tmp);

    /// Obtenemos la x de la Tesela referida al mosaico padre.
    /// @return Coordenada x de la posición relativa actual de la tesela.
    ///
    int get_x () const;

    /// Obtenemos la y de la Tesela referida al mosaico padre.
    /// @return Coordenada y de la posición relativa actual de la tesela.
    ///
    int get_y () const;

    /// Guarda en un fichero las teselas.
    /// @todo Incluir como herencia de una clase SavableObject.
    ///
    void guardar () const;

    /// Obtiene una cadena de caracteres con la estructura de la tesela.
    /// @return Cadena de caracteres con la estructura.
    ///
    virtual std::string& print () const;
};


}
#endif
