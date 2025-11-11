#ifndef ALLEGROADAPTER_H
#define ALLEGROADAPTER_H

#include "Menu.h"
#include <allegro.h>

class AllegroRenderer : public IRenderer {
public:
    AllegroRenderer() {
        allegro_init();
        install_keyboard();
        set_color_depth(32);
        if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
            allegro_message("Error al iniciar modo gráfico!");
            exit(1);
        }
        clear_to_color(screen, makecol(0,0,0));
        show_mouse(screen);
    }

    ~AllegroRenderer() {
        allegro_exit();
    }

    void dibujarTexto(const char* texto, int x, int y, ColorType color) override {
        textout_ex(screen, font, texto, x, y, color, -1);
    }

    void dibujarCuadrado(int x, int y, ColorType color) override {
        rectfill(screen, x, y, x+40, y+40, color);
    }

    ColorType makeColor(int r, int g, int b) override {
        return makecol(r, g, b);
    }

    void limpiarPantalla(ColorType color) override {
        clear_to_color(screen, color);
    }

    void refrescarPantalla() override { 
        // En Allegro 4 el dibujo va directo a screen, no hay buffer swap
    }

    int mostrarMenu(const Menu& menu, int x, int y) override {
        MENU* allegroMenu = convertirItemsAMenu(menu);
        gui_fg_color = makecol(0,0,255);
        gui_bg_color = makecol(255,255,255);
        gui_mg_color = makecol(128,128,128);
        int selected = do_menu(allegroMenu, x, y);
        liberarMenu(allegroMenu);
        return selected;
    }

    MENU* convertirItemsAMenu(const Menu& menu) {
        const auto& items = menu.items;
        MENU* allegroMenu = new MENU[items.size() + 1];
        for (size_t i = 0; i < items.size(); ++i) {
            allegroMenu[i].text = const_cast<char*>(items[i].nombre.c_str());
            allegroMenu[i].proc = nullptr; // uso do_menu para índice, no callback
            allegroMenu[i].child = nullptr;
            allegroMenu[i].flags = items[i].estado ? 0 : D_DISABLED;
            allegroMenu[i].dp = nullptr;
        }
        allegroMenu[items.size()].text = nullptr;
        allegroMenu[items.size()].proc = nullptr;
        allegroMenu[items.size()].child = nullptr;
        allegroMenu[items.size()].flags = 0;
        allegroMenu[items.size()].dp = nullptr;
        return allegroMenu;
    }

    void liberarMenu(MENU* menu) {
        delete[] menu;
    }

};

class AllegroInput : public IInput {
public:
    AllegroInput() {
        install_mouse();
        install_keyboard();
    }

    int obtenerCodigoTecla() override {
        if (keypressed()) {
            int c = readkey();
            return c >> 8; // o interpreta según convenga
        }
        return 0;
    }

    void esperar(int ms) override { rest(ms); }

    bool clicDerecho() override {
        return mouse_b & 2;
    }
};

#endif
