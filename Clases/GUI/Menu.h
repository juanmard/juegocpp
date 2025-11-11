#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <memory>
#include "Comando.h"

constexpr int ESC_KEY_CODE = 59;
constexpr int KEY_1_CODE = 28;
constexpr int KEY_2_CODE = 29;
constexpr int KEY_3_CODE = 30;

struct ItemMenu {
    std::string nombre;
    bool estado;
    std::vector<ItemMenu> submenu;
    std::shared_ptr<Comando> comando;

    ItemMenu(const std::string& nom, bool est = true,
             std::shared_ptr<Comando> cmd = nullptr)
        : nombre(nom), estado(est), comando(cmd) {}
};

class IRenderer {
public:
    using ColorType = unsigned int; // o typedef de un tipo abstracto

    virtual ColorType makeColor(int r, int g, int b) = 0;
    virtual void limpiarPantalla(ColorType color) = 0;
    virtual void dibujarTexto(const char* texto, int x, int y, ColorType color) = 0;
    virtual void refrescarPantalla() = 0;
    virtual ~IRenderer() {}
};

class IInput {
public:
    // Devuelve el código de la tecla pulsada, o 0 si no hay
    virtual int obtenerCodigoTecla() = 0;

    // Opcional, para esperar o pausar
    virtual void esperar(int ms) = 0;

    virtual bool clicDerecho() = 0;
    virtual ~IInput() {}
};

class Menu {
public:
    std::string titulo;
    std::vector<ItemMenu> items;

    Menu(const std::string& tit) : titulo(tit) {}

    void agregarItem(const ItemMenu& item) {
        items.push_back(item);
    }

    void mostrar(IRenderer& renderer, IInput& input);
    void mostrar_allegro(int x, int y);
};

#endif
