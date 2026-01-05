#ifndef IRENDERER_H
#define IRENDERER_H

namespace jmr {
    class Menu;
    class Dialog;
    class Control;
}

struct ItemMenu;
class SliderCtrl;
class VectorCtrl;
struct InputEvent;

class IRenderer {
public:
    using ColorType = unsigned int;

public:
    IRenderer () {};
    virtual ~IRenderer() {};
    virtual ColorType makeColor(int r, int g, int b) = 0;
    virtual void limpiarPantalla(ColorType color) = 0;
    virtual void limpiarControl (jmr::Control* control) = 0;
    virtual void dibujarTexto(const char* texto, int x, int y, ColorType color) = 0;
    virtual void dibujarCuadrado(int x, int y, ColorType color) = 0;
    virtual void dibujarFrontera (jmr::Control* ctrl) = 0;
    virtual const ItemMenu & mostrarMenu(const jmr::Menu& menu, int x, int y, int nivel = 0) = 0;
    virtual void refrescarPantalla() = 0;
    virtual int  mostrarDialog(const jmr::Dialog& dialog) = 0;
    virtual void setSliderValue(SliderCtrl* slider, int val) = 0;
    virtual void updateVector(jmr::Control* control) = 0;
    virtual int  defaultControl(jmr::Control* control, const InputEvent& ev) = 0;
    virtual int  defaultSlider(SliderCtrl* sld, const InputEvent& ev) = 0;
    virtual int  defaultVector(VectorCtrl* vector, const InputEvent& ev) = 0;
    virtual void invertirBackgroundForeground(jmr::Control* ctrl) = 0;
    virtual void editarTexto(VectorCtrl* control) = 0;
    virtual void dibujarEjes () = 0;
    virtual void showFrames (int graph_tick, int frame_skip) = 0;
    virtual bool createWindow (int width, int height) = 0;
};

#endif