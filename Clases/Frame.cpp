/**
 *  \file     Frame.cpp
 *  \brief    Prueba del "framework" de un juego.
 *
 *  \details  La clase instancia un tipo de juego de prueba con todos los controladores posibles.
 *            La primera versión de la instancia se utiliza para actualizar el juego de plataformas
 *            programado antiguamente en C "puro y duro".
 *
 *  \author  Juan Manuel Rico
 *  \date     diciembre 2010
 *  \version  1.00
 *
 *  \todo     Comentar todas estas clases y funciones más detalladamente.
 */

#include "Frame.h"
#include <sstream>

Frame::Frame ()
{
}

Frame::~Frame ()
{
}

string  Frame::getString () const
{
  ostringstream cadena;

  cadena  << "Pos <" << cx << "," << cy << "> " << "Ticks: " << ticks;
  return (cadena.str());
};

