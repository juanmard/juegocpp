#ifndef ALLEGRORENDERER_H
#define ALLEGRORENDERER_H

#include <vector>
#include <memory>
#include <allegro.h>
#include "IRenderer.h"
#include "Dialog.h"
#include "Menu.h"
#include "SliderCtrl.h"
#include "VectorCtrl.h"

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
    void limpiarControl(Control* control) override;
    void invertirBackgroundForeground(VectorCtrl* vector) override;
    void editarTexto(VectorCtrl* vector) override;
    void refrescarPantalla() override {}; 
    const ItemMenu& mostrarMenu(const jmr::Menu& menu, int x, int y, int nivel=0) override;
    MENU* convertirItemsAMenu(const jmr::Menu& menu);
    void liberarMenu(MENU* menu);

    void dibujarFrontera (int x, int y, int w, int h, ColorType color) override;

public:
    int mostrarDialog(const jmr::Dialog& dialog) override;
    void setSliderValue(SliderCtrl* slider, int val) override;
    int defaultSlider(SliderCtrl* sld, const InputEvent& ev) override;
    int defaultVector(VectorCtrl* vector, const InputEvent& ev) override;
    int defaultControl(Control* ctrl, const InputEvent& ev) override;
    void updateVector(Control* control) override;
    DIALOG* findDialogControl(Control* control);

private:
    static int allegroCallback(int msg, DIALOG* d, int c);
    static void print (int msg);
    int eventToMsg (const ControlEvent ev) const;
    static ControlEvent msgToEvent (int msg);
    void extraerEnteros (std::string input, unsigned int& x, unsigned int& y);
    
    // Pruebas:
    static int dibujarPrueba(void);
    static AllegroRenderer* renderer_actual;
};

#endif