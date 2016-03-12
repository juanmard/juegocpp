///
/// @file Mapa.cpp
/// @brief Fichero de implementación de la clase "Mapa".
/// @author Juan Manuel Rico
/// @date Noviembre 2015
/// @version
///      - 1.0.0 Noviembre 2015
///

#include "Mapa.h"
#include "ActorManager.h"
#include "Actor.h"
#include <fstream>

/// Macro para comparar y crear el actor de clase "cls".
#define CMP_CLASE(cls) if (!clase.compare (#cls)) return (*new cls());
#include "AirCraft.h"
#include "Ben.h"
#include "Herny.h"
#include "Ladrillo.h"
#include "Loro.h"
#include "Mago.h"
#include "Paleta.h"
#include "Pelota.h"
#include "Plataforma.h"

Mapa::Mapa ():
nombre ("sin nombre"),
fichero (NULL)
{
};

Mapa::Mapa (DatFile& ficheroDatos):
nombre ("sin nombre"),
fichero (&ficheroDatos)
{
};

Mapa::~Mapa ()
{
};

void Mapa::read (const ActorManager& manager)
{
};

void Mapa::load (std::string& file, ActorManager& manager)
{
#ifdef _DEBUG
    std::cout << "Prueba de carga de actores desde fichero." << std::endl \
              << "Fichero a cargar: \"" << file << "\"" << std::endl;
#endif

    // Se crea un nuevo fichero para lectura.
    std::ifstream& ifs = *new std::ifstream();

    // Se intenta abrir el fichero.
    try
    {
        ifs.open(file.c_str());

        // Si el fichero no se ha abierto, se intenta con el nombre por omisión.
        if (!ifs.is_open())
        {
            std::cout << "Fichero \"" << file << "\" no se ha podido abrir. Se intenta nombre por omisión." << std::endl;
            ifs.open("actores.txt"); ///< \todo Hacer de la cadena un literal.
            if (ifs.is_open())
            {
                std::cout << "Abierto fichero \"actores.txt\"" << std::endl;
            }
            else
            {
                // Si finalmente no se puede abrir se da por terminado el intento y se lanza la excepción.
                throw std::string("Fichero \"actores.txt\" no se ha podido abrir.");
            }
        }
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;
        return;
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "Error al abrir el fichero: \"" << file << "\"" << std::endl;
        std::cout << "Error: " << std::endl << e.what();
        return;
    }

    // Si se consigue localizar y abrir el fichero se continua procesando.
    std::cout << "Se procesa el fichero. " << std::endl;

    /// @todo Una primera línea que compruebe la versión del fichero de datos.
    // string version;
    // getline(fs,version);
    // if (!version.compare("JUEGO v2.0")) {return "El fichero de datos no está en la versión correcta)};
    //size_t pos = buscar_propiedad ("Actores", ifs);
    buscar_propiedad ("Actores", ifs);

    // Se obtiene del fichero el comando y el valor.
    std::string comando, valor, clase;
    int num;

    ifs >> std::skipws >> comando >> std::skipws >> num;
    // std::cout << "Comando: " << comando << "\tValor: " << num << "\t" << std::endl;

    // Se procesan el número de actores indicados (num).
    for (int i=0; i<num; i++)
    {
        // Leer la clase del actor.
        ifs >> clase;
        std::cout << "Clase: " << clase << std::endl;

        // Se intenta crear un nuevo actor (vacío) de la clase pasada por parámetro, pero devolviendo
        // la clase abstracta actor.
        try {
            Actor& actor = crear_actor(clase);

            // Se leen los valores de las propiedades del actor desde el fichero de texto.
            ifs.ignore (100,'{');
            ifs >> actor;
            ifs.ignore (100,'}');

            // Se agrega el actor leído a la lista.
            manager.add (&actor);
        }
        catch (std::string error)
        {
            std::cout << "Error: " << error << std::endl \
                      << "Se intentará con el siguiente comando.";
            ifs.ignore (200,'}');
        }
    }
    // Se preparan todos los actores agregados para actuar.
    manager.add_all_to_create ();

    // Se cierra el fichero.
    ifs.close();
};

void Mapa::save (const ActorManager& manager)
{
};

std::string& Mapa::print () const
{
  return *new std::string ("Código print del Mapa por hacer.");
};

std::size_t Mapa::buscar (const std::string& palabra, std::ifstream& canal) const
{
    std::size_t pos;
    std::string linea;

    // Se toma línea por línea y se busca la palabra.
    while (getline(canal,linea))
    {
      std::cout << linea << std::endl;
      pos = linea.find(palabra);
      if (pos != std::string::npos) // std::string::npos is returned if string is not found
      {
        std::cout << "Found! in " << pos << std::endl;
        break;
      }
    }
    return pos;
};

std::size_t Mapa::buscar_propiedad (const std::string& propiedad, std::ifstream& canal) const
{
    std::string busqueda;

    // Se crea el formato de la propiedad dentro del fichero.
    // ej. "[Actores]"
    // @note Intentar hacerlo de manera más limpia ignorando los caracteres hasta encontrar el primer caracter '['
    //       con la función "ignore(256,'[');"
    busqueda += '[';
    busqueda += propiedad;
    busqueda += ']';

    std::cout << "Se busca la propiedad: " << busqueda << std::endl;

    // Se busca la palabra creada.
    std::size_t pos = buscar (busqueda, canal);
    return pos;
};

Actor& Mapa::crear_actor (const std::string& clase) const
{
    CMP_CLASE(AirCraft);
    CMP_CLASE(Ben);
    CMP_CLASE(Herny);
    CMP_CLASE(Ladrillo);
    CMP_CLASE(Loro);
    CMP_CLASE(Mago);
    CMP_CLASE(Paleta);
    CMP_CLASE(Pelota);
    CMP_CLASE(Plataforma);
    throw std::string ("La clase \"" + clase + "\" no existe o no puede ser controlada por \"ActorManager\"");
};

