#ifndef SDL2RENDERER_H
#define SDL2RENDERER_H

#include "IRenderer.h"
#include <SDL2/SDL.h>

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

    void setSliderValue(Control* control, int val) override;

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
};

#endif
