#ifndef IRENDERER_H
#define IRENDERER_H

#include "Menu.h"

class Menu;

class IRenderer {
public:
    using ColorType = unsigned int;

    virtual ColorType makeColor(int r, int g, int b) = 0;
    virtual void limpiarPantalla(ColorType color) = 0;
    virtual void dibujarTexto(const char* texto, int x, int y, ColorType color) = 0;
    virtual void dibujarCuadrado(int x, int y, ColorType color) = 0;
    virtual int mostrarMenu(const Menu& menu, int x, int y) = 0;
    virtual void refrescarPantalla() = 0;
    virtual ~IRenderer() {}
};

#endif