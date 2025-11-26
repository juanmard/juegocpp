#ifndef SDL2RENDERER_H
#define SDL2RENDERER_H

#include "Dialog.h"
#include "Control.h"
#include "Menu.h"
#include "SliderCtrl.h"
#include "IRenderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h> 

class SDL2Renderer : public IRenderer {
public:
    SDL2Renderer();
    ~SDL2Renderer();

    // Conversión RGB a ColorType (por ejemplo, empaquetar en 0xRRGGBB)
    ColorType makeColor(int r, int g, int b) override;

    // Limpia pantalla con color dado
    void limpiarPantalla(ColorType color) override;

    // Limpia un Control (puede usar SDL_RenderClear o similar)
    void limpiarControl(Control* control) override;

    // Dibuja texto en (x,y) con color dado (usando SDL_ttf o método propio)
    void dibujarTexto(const char* texto, int x, int y, ColorType color) override;

    // Dibuja un cuadrado coloreado (x,y pos + tamaño fijo o variable)
    void dibujarCuadrado(int x, int y, ColorType color) override;

    int mostrarMenu(const Menu& menu, int x, int y) override;

    void refrescarPantalla() override;

    int mostrarDialog(const Dialog& dialog) override;

    void setSliderValue(SliderCtrl* slider, int val) override;

    void updateVector(Control* control) override;

    int defaultSlider(SliderCtrl* sld, const InputEvent& ev) override;

    int defaultVector(VectorCtrl* vector, const InputEvent& ev) override;

    void invertirBackgroundForeground(VectorCtrl* vector) override;

    void editarTexto(VectorCtrl* control) override;

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    // Otras variables necesarias (por ejemplo, fuentes TTF, colores, etc.)

    // Métodos internos auxiliares para dibujado, gestión de texto, etc.

    // Pruebas con el Slider.
    int slider_x = 50, slider_y = 90;
    int slider_width = 300, slider_height = 8;
    int handle_width = 10, handle_height = 30;

    // Valor del slider: 0-100
    int slider_min = 10, slider_max = 120;
    int slider_value = 50;
    int handle_x = 0;
    bool dragging = false;
    bool dibujarMarco = false;

    // Pruebas de font.
    static TTF_Font* font;
    
};

#endif
