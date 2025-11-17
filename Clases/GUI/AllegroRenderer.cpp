// AllegroRenderer.cpp
#include "AllegroRenderer.h"
#include "SliderCtrl.h"
#include "VectorCtrl.h"
#include <allegro.h>
#include <iostream>

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
    Control* ctrl = reinterpret_cast<Control*>(d->dp3);
    if (ctrl && ctrl->comando) {
        ctrl->comando->ejecutar();
        switch (ctrl->tipo){
            case TipoControl::SLIDER:
            // print (msg);
            {
                SliderCtrl *sld = reinterpret_cast<SliderCtrl*>(ctrl);
                sld->setValue(d->d2);
                // std::cout << "pos - " << sld->pos << std::endl;
                return d_slider_proc (msg, d, c);
            }
            break;
            case TipoControl::VECTOR:
                //d->dp = (void *) "Test de prueba.";
                if (msg == MSG_DRAW) {rectfill(screen, d->x, d->y, d->x + d->w - 1, d->y + d->h - 1, d->bg);};
                return d_ctext_proc (msg, d, c);
            break;
        }
    }
    return D_O_K;
}

int AllegroRenderer::mostrarDialog(const Dialog& dialog) {
    // Se convierte Dialog -> DIALOG.
    // @todo Separarlo en un método privado.
    controls = &dialog.controls; // Mantener referencia a los controles del diálogo.
    size_t n = controls->size();
    allegroDialog = new DIALOG[n + 1];

    for (size_t i = 0; i < n; ++i) {
        const Control& c = *(dialog.controls[i].get());

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
        allegroDialog[i].dp = nullptr;
        allegroDialog[i].dp2 = nullptr;
        allegroDialog[i].dp3 = const_cast<Control*>(&c);

        /// Cambios según el tipo de control.
        switch (c.tipo) {
        case TipoControl::SLIDER:
            // allegroDialog[i].proc = d_slider_proc;
            allegroDialog[i].d1 = 100;
            allegroDialog[i].d2 = reinterpret_cast<const SliderCtrl&>(c).pos;
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
        case TipoControl::VECTOR:
        {   
            PALETTE palette;
            allegroDialog[i].proc = allegroCallback;
            // allegroDialog[i].proc = d_ctext_proc;
            allegroDialog[i].dp = (void*) "Texto con un aspecto distinto.";
            allegroDialog[i].dp2 = (void*) load_font("../../Extras/prueba-font.pcx", palette, NULL);
            if (!allegroDialog[i].dp2) {
                allegroDialog[i].dp = (void*) "No existe: '../../Extras/prueba-font.pcx'.";
            }
        }
            break;
        case TipoControl::TEXTBOX:
            allegroDialog[i].proc = d_textbox_proc;
            allegroDialog[i].d2 = 0;
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

    int result = do_dialog(allegroDialog, -1);
    delete[] allegroDialog;
    return result;
}

void AllegroRenderer::setSliderValue(Control* control, int val) {
    // Obtener DIALOG* asociado a control
    DIALOG* dlgCtrl = findDialogControl(control);
    if (dlgCtrl) {
        dlgCtrl->d2 = val;  // d2 = valor slider
        // Forzar refuerzo gráfico
        dlgCtrl->flags |= D_DIRTY;
    }
}

DIALOG* AllegroRenderer::findDialogControl(Control* control) {
    auto it = std::find_if(
        controls->begin(), controls->end(),
        [control](const std::unique_ptr<Control>& ptr) { return ptr.get() == control; }
    );
    if (it != controls->end()) {
        size_t index = std::distance(controls->begin(), it);
        return &allegroDialog[index];
    }
    return nullptr;
}

void AllegroRenderer::print (int msg) {
    static std::string textos[]= {
        "MSG_START", "MSG_END", "MSG_DRAW", "MSG_CLICK",
        "MSG_DCLICK", "MSG_KEY", "MSG_CHAR", "MSG_UCHAR",
        "MSG_XCHAR", "MSG_WANTFOCUS", "MSG_GOTFOCUS",
        "MSG_LOSTFOCUS", "MSG_GOTMOUSE", "MSG_LOSTMOUSE",
        "MSG_IDLE", "MSG_RADIO", "MSG_WHEEL", "MSG_LPRESS",
        "MSG_LRELEASE", "MSG_MPRESS", "MSG_MRELEASE",
        "MSG_RPRESS", "MSG_RRELEASE", "MSG_WANTMOUSE",
        "MSG_USER"
    };
    if ( (msg != MSG_IDLE) && (msg != MSG_WANTMOUSE) ) {
        std::cout << textos[msg-1] << std::endl;
    }
}

void AllegroRenderer::updateVector(Control* control) {
    VectorCtrl* vctrl = reinterpret_cast<VectorCtrl*>(control);
    DIALOG* dlgCtrl = findDialogControl(control);
    if (dlgCtrl) {
        // Actualiza la propiedad texto con las coordenadas
        vctrl->texto = std::to_string(vctrl->x) + ", " + std::to_string(vctrl->y);

        // Apunta dp directamente al buffer interno del string
        dlgCtrl->dp = const_cast<char*>(vctrl->texto.c_str());

        dlgCtrl->flags |= D_DIRTY;  // marcar para redibujar
        // std::cout << "Vector actualizado en GUI: " << vctrl->texto << std::endl;
    }
}