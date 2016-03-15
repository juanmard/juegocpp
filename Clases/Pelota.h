#pragma once
#include "DirectorActor.h"
#include "DatFile.h"
#include "Bitmap.h"
#include "Nombres.h"

class Pelota : public DirectorActor
{
public:
    Pelota(void);
    ~Pelota(void);
    void CambiarEstado (void);
    void ActualizarEstado (void);
    void hit (Actor *who, int damage);

protected:
    /**
     * \brief   direccion_x y direccion_y, modelan la direcci�n y cantidad 
     *          de pixels con que se mueve la pelota en cada direcci�n.
     *
     * \details Ser�a algo semejante a un vector de velocidad.
     *
     * \todo    Modelar mejor estos valores generales de velocidad para todos
     *          los objetos. Crear unas clases independientes para estas magnitudes
     *          ser�a lo adecuado.
     */
    int direccion_x, direccion_y;

    /**
     * \brief   tomate, granada y estrella son los punteros a distintos objetos tipo BITMAP.
     *
     * \details Estos se utilizan para asignar como la parte gr�fica
     *          del actor. Se cargan al crear el objeto.
     *
     * \todo    Estos objetos, que son como el "vestuario"
     *          del actor, deben ser guardados en clases accesibles por
     *          todos los actores para reutilizarlos en distintos actores.
     */
    Bitmap *tomate, *granada, *estrella;
    SAMPLE  *rebote;
};
