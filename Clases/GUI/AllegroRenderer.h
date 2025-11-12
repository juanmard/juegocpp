#ifndef ALLEGRORENDERER_H
#define ALLEGRORENDERER_H

#include "IRenderer.h"
#include "Dialog.h"
#include <allegro.h>
#include "Menu.h"

class AllegroRenderer : public IRenderer {
public:
    AllegroRenderer();
    ~AllegroRenderer();
    void dibujarTexto(const char* texto, int x, int y, ColorType color) override;
    void dibujarCuadrado(int x, int y, ColorType color) override;
    ColorType makeColor(int r, int g, int b) override;
    void limpiarPantalla(ColorType color) override;
    void refrescarPantalla() override {}; 
    int mostrarMenu(const Menu& menu, int x, int y) override;
    MENU* convertirItemsAMenu(const Menu& menu);
    void liberarMenu(MENU* menu);

public:
    int mostrarDialog(const Dialog& dialog) override;

private:
    static int allegroCallback(int msg, DIALOG* d, int c);
};

#endif