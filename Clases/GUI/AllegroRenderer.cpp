// AllegroRenderer.cpp
#include "AllegroRenderer.h"
#include <allegro.h>

AllegroRenderer::AllegroRenderer() {
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
        allegro_message("Error al iniciar modo gráfico!");
        exit(1);
    }
    clear_to_color(screen, makecol(128,128,128));
    show_mouse(screen);
}

AllegroRenderer::~AllegroRenderer() {
    allegro_exit();
}

void AllegroRenderer::dibujarTexto(const char* texto, int x, int y, ColorType color) {
    textout_ex(screen, font, texto, x, y, color, -1);
}

void AllegroRenderer::dibujarCuadrado(int x, int y, ColorType color) {
    rectfill(screen, x, y, x+40, y+40, color);
}

AllegroRenderer::ColorType AllegroRenderer::makeColor(int r, int g, int b) {
    return makecol(r, g, b);
}

void AllegroRenderer::limpiarPantalla(ColorType color) {
    clear_to_color(screen, color);
}

int AllegroRenderer::mostrarMenu(const Menu& menu, int x, int y) {
    MENU* allegroMenu = convertirItemsAMenu(menu);
    gui_fg_color = makecol(0,0,255);
    gui_bg_color = makecol(255,255,255);
    gui_mg_color = makecol(128,128,128);
    int selected = do_menu(allegroMenu, x, y);
    liberarMenu(allegroMenu);
    return selected;
}

MENU* AllegroRenderer::convertirItemsAMenu(const Menu& menu) {
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

void AllegroRenderer::liberarMenu(MENU* menu) {
    delete[] menu;
}

int AllegroRenderer::allegroCallback(int msg, DIALOG* d, int c) {
    Control* ctrl = reinterpret_cast<Control*>(d->dp);
    if (ctrl && ctrl->comando) {
        ctrl->comando->ejecutar();
        return D_O_K;
    }
    return d_keyboard_proc(msg, d, c);
}

int AllegroRenderer::mostrarDialog(const Dialog& dialog) {
    // Se convierte Dialog -> DIALOG.
    // @todo Separarlo en un método privado.
    size_t n = dialog.controls.size();
    DIALOG* allegroDialog = new DIALOG[n + 1];

    for (size_t i = 0; i < n; ++i) {
        const Control& c = dialog.controls[i];

        /// Se inicia por defecto.
        allegroDialog[i].proc = allegroCallback;
        allegroDialog[i].x = c.x;
        allegroDialog[i].y = c.y;
        allegroDialog[i].w = c.w;
        allegroDialog[i].h = c.h;
        allegroDialog[i].fg = c.fg;
        allegroDialog[i].bg = c.bg;
        allegroDialog[i].key = c.key;
        allegroDialog[i].flags = c.flags;
        allegroDialog[i].d1 = 0;
        allegroDialog[i].d2 = 0;
        allegroDialog[i].dp = const_cast<Control*>(&c);
        allegroDialog[i].dp2 = nullptr;
        allegroDialog[i].dp3 = nullptr;

        /// Cambios según el tipo de control.
        switch (c.tipo) {
        case TipoControl::SLIDER:
            allegroDialog[i].proc = d_slider_proc;
            allegroDialog[i].d1 = 20;
            allegroDialog[i].d2 = 10;
            allegroDialog[i].dp = nullptr;
            break;
        case TipoControl::BUTTON:
            allegroDialog[i].proc = d_button_proc;
            allegroDialog[i].dp = (void*) "Botón de prueba.";
            // allegroDialog[i].flags = D_EXIT;
            break;
        case TipoControl::BOX:
            allegroDialog[i].proc = d_box_proc;
            allegroDialog[i].dp = nullptr;
            break;
        case TipoControl::LABEL:
        {   
            PALETTE palette;
            allegroDialog[i].proc = d_ctext_proc;
            allegroDialog[i].dp = (void*) "Texto con un aspecto distinto.";
            allegroDialog[i].dp2 = (void*) load_font("../../Extras/prueba-font.pcx", palette, NULL);
            if (!allegroDialog[i].dp2) {
                allegroDialog[i].dp = (void*) "No existe: '../../Extras/prueba-font.pcx'.";
            }
        }
            break;
        case TipoControl::TEXTBOX:
            allegroDialog[i].proc = d_textbox_proc;
            allegroDialog[i].dp = (void*) "Un objeto de cuadro de texto. El campo dp apunta al texto que se mostrará en el cuadro. Si el texto es largo, habrá una barra de desplazamiento vertical en el lado derecho del objeto que se puede usar para desplazarse por el texto. El valor predeterminado es imprimir el texto con ajuste de línea, pero si se establece la marca D_SELECTED, el texto se imprimirá con ajuste de caracteres. El campo d1 se usa internamente para almacenar el número de líneas de texto y d2 se usa para almacenar cuánto se ha desplazado por el texto.";
            allegroDialog[i].flags = D_SELECTED;
            break;
        default:
            break;
        }

    }

    // Fin array de Allegro.
    allegroDialog[n].proc = NULL;
    allegroDialog[n].x = allegroDialog[n].y = 0;
    allegroDialog[n].w = allegroDialog[n].h = 0;
    allegroDialog[n].fg = allegroDialog[n].bg = 0;
    allegroDialog[n].d1 = allegroDialog[n].d2 = 0;
    allegroDialog[n].key = allegroDialog[n].flags = 0;
    allegroDialog[n].dp = nullptr;
    allegroDialog[n].dp2 = nullptr;
    allegroDialog[n].dp3 = nullptr;
    allegroDialog[n].d1 = allegroDialog[n].d2 =0;

    int result = do_dialog(allegroDialog, -1);
    delete[] allegroDialog;
    return result;
}
