#ifndef DATFILE_H
#define DATFILE_H

#include <allegro.h>
#include <string>

using namespace std;

/**
 * \class  DatFile
 * \brief  Clase que maneja los recursos creados por "Grabber".
 * \todo   - Crear métodos "GetSample" y "SetSample" para manejo de sonidos.
 *         - Modificar el nombre de la clase para que refleje su asociación con
 *             "Grabber" (algo como "FileGrabber").
 */
class DatFile
{
public:
                DatFile     (string name);
                ~DatFile    (void);
    BITMAP *    GetBitmap   (int number);
    BITMAP *    GetBitmap   (string name_bitmap);
    void  *     GetDat      (int number);
    void        SetPalette  (int number);

private:
    DATAFILE *  file;
    string      name;
};

#endif