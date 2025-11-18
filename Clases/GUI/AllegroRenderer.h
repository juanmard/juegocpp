#ifndef ALLEGRORENDERER_H
#define ALLEGRORENDERER_H

#include <vector>
#include <memory>
#include "IRenderer.h"
#include "Dialog.h"
#include "Menu.h"
#include <allegro.h>

class AllegroRenderer : public IRenderer {
public:
    const std::vector<std::unique_ptr<Control>>* controls; // Vector para mantener referencia a los controles. @todo ¿Simplificar la declaración con una clase?
    DIALOG* allegroDialog;

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
    void setSliderValue(Control* control, int val) override;
    void updateVector(Control* control) override;
    DIALOG* findDialogControl(Control* control);

private:
    static int allegroCallback(int msg, DIALOG* d, int c);
    static void print (int msg);
    static void extraerEnteros (std::string input, unsigned int& x, unsigned int& y);
};

#endif