#include "DatFile.h"

/**
 * \brief Constructor encargado de cargar el fichero de recursos.
 * \todo    - Controlar mejor los errores. En modo DEBUG si no encuentra
 *            el fichero, abrir una ventana para pedir se localice el
 *            fichero de recursos.
 *          - Controlar la carga se un único fichero de recurso para evitar
 *            duplicaciones en memoria.
 */
DatFile::DatFile(string file_name)
{
   file = load_datafile(file_name.c_str ());
   if (!file)
   {
     //No se encontró el fichero.
     name = "";
   }
   else
   {
     name = file_name.c_str();
   }
}

/**
 * \brief   Destructor que debe descargar de memoria el recurso y cerrar el fichero.
 * \todo    Problemas al descargar un recurso si está duplicado, controlar este proceso.    
 */
DatFile::~DatFile(void)
{
//    if (file) unload_datafile (file);
}

/**
 * \brief   Devuelve un BITMAP como recurso dando el número identificativo indicado 
 *          en el fichero de cabecera generado por Grabber.
 * \todo    Controlar que el recurso solicitado es realmente un BITMAP.
 */
BITMAP *DatFile::GetBitmap(int number)
{
    return (BITMAP *) file[number].dat;
}

/**
 * \brief   Devuelve un BITMAP como recurso dando el nonbre del recurso. 
 * \todo    Controlar que el recurso solicitado es realmente un BITMAP.
 */
BITMAP *DatFile::GetBitmap(string name_bitmap)
{
    DATAFILE *tmp_dat;
    BITMAP *tmp_bmp = NULL;

    // Se comprueba si el fichero existe.
    if (file)
    {
        // Se obtiene el objeto del fichero.
        tmp_dat = load_datafile_object( name.c_str(), name_bitmap.c_str() );

        // Se comprueba que realmente es de tipo BITMAP.
        // TODO: Comprobar por qué no funciona esta comparación.
        //if (tmp_dat->type != DAT_BITMAP)
        //{
            tmp_bmp = (BITMAP *) tmp_dat->dat;
        //}
    }
    return (BITMAP *)tmp_bmp;
}

/**
 * \brief   Obtiene un recurso cualquiera dando el número identificativo.
 * \todo    Se debería eliminar por inconsistencia de tipos. Se utiliza de momento
 *          pruebas dentro del programa.
 */
void  *DatFile::GetDat(int number)
{
    return file[number].dat;
}

/**
 * \brief   Devuelve un BITMAP como recurso dando el nonbre del recurso. 
 * \todo    - Controlar que el recurso solicitado es realmente una paleta de colores.
 *          - No volver a cargar el fichero de recursos.      
 */
void DatFile::SetPalette (int number)
{
    /* TODO: Comprobar que lo que se pide es realmente una paleta de colores. */
    //if (file[number].type != DAT_PALETTE)
    //{
    DATAFILE *objeto = load_datafile_object("sprites.dat", "SPRITES");
    set_palette ((RGB *)objeto->dat);
//      set_palette ((RGB *)file[number].dat);
    //};
}
