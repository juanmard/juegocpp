// AllegroRenderer.cpp
#include "AllegroRenderer.h"
#include "SliderCtrl.h"
#include "VectorCtrl.h"
#include <allegro.h>
#include <iostream>

AllegroRenderer::AllegroRenderer() {
    // allegro_init();
    // install_keyboard();
    // set_color_depth(32);
    // if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
    //     allegro_message("Error al iniciar modo gráfico!");
    //     exit(1);
    // }
    // clear_to_color(screen, makecol(128,128,128));
    // show_mouse(screen);
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

AllegroRenderer* AllegroRenderer::renderer_actual = nullptr;

int AllegroRenderer::dibujarPrueba(void) {
    // std::cout << "Dibujando cuadrado" << std::endl;

    // Tenemos que usar el render_actual.
    AllegroRenderer* self = static_cast<AllegroRenderer*>(renderer_actual);
    if (self) {
        self->dibujarCuadrado (200,100,self->makeColor(0,220,23));
        // rectfill(screen, 200,100, 240, 140, makeacol(0,220,23,255));
    }
    return D_O_K;
}

/// @brief  Dibuja la frontera o límites del control.
/// @param x 
/// @param y 
/// @param w 
/// @param h 
/// @param color 
void AllegroRenderer::dibujarFrontera (Control* ctrl) {
    rect (screen, ctrl->x, ctrl->y, ctrl->x + ctrl->w, ctrl->y + ctrl->h, ctrl->fg);
}

const ItemMenu& AllegroRenderer::mostrarMenu(const jmr::Menu& menu, int x, int y, int nivel) {
    MENU* allegroMenu = convertirItemsAMenu(menu);
    gui_fg_color = makecol(0,0,255);
    gui_bg_color = makecol(255,255,255);
    gui_mg_color = makecol(128,128,128);

    // Prueba de menú anidado.
    if (allegroMenu[0].child == nullptr) {
        MENU *prueba = new MENU[4];  // 4 elementos (3 + NULL final)
        prueba[0] = { const_cast<char*>("prueba 1"), nullptr, nullptr, 0, nullptr };
        prueba[1] = { const_cast<char*>("prueba 2"), AllegroRenderer::dibujarPrueba, nullptr, 0, nullptr};
        prueba[2] = { const_cast<char*>("prueba 3"), nullptr, nullptr, 0, nullptr };
        prueba[3] = { NULL, NULL, NULL, 0, NULL };
        prueba[2].child = &prueba[1];
        allegroMenu[0].child = prueba;
    }

    // Mostramos e interaccionamos con el menú.
    renderer_actual = this;
    int selected = do_menu(allegroMenu, x, y);
    renderer_actual = nullptr;

    std::cout << "Item: " << selected << std::endl;
    liberarMenu(allegroMenu);
    return menu.items[selected];
}

MENU* AllegroRenderer::convertirItemsAMenu(const jmr::Menu& menu) {
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
        
        int modifiers = 0;
        InputEvent ev { msgToEvent (msg), c, modifiers };
        return ctrl->manejarEvento(ev);
    }
    return D_O_K;
}

int AllegroRenderer::mostrarDialog(const jmr::Dialog& dialog) {
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

        /// Inicializaciones varias según el tipo de control.
        switch (c.tipo) {
        case TipoControl::SLIDER:
        {
            // allegroDialog[i].proc = d_slider_proc;
            SliderCtrl& slider = dynamic_cast<SliderCtrl&>(const_cast<Control&>(c));
            allegroDialog[i].d1 = slider.max - slider.min; // rango
            allegroDialog[i].d2 = slider.pos - slider.min; // valor actual
        }
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
                allegroDialog[i].dp2 = (void*) load_font("./prueba-font.pcx", palette, NULL);
                if (!allegroDialog[i].dp2) {
                    allegroDialog[i].dp = (void*) "No existe: '../../Extras/prueba-font.pcx' ni './prueba-font.pcx'.";
                }
            }
        }
            break;
        case TipoControl::TEXTBOX:
            allegroDialog[i].proc = d_textbox_proc;
            allegroDialog[i].d2 = 0;
            allegroDialog[i].dp = (void*) "Un objeto de cuadro de texto. El campo dp apunta al texto que se mostrará en el cuadro. Si el texto es largo, habrá una barra de desplazamiento vertical en el lado derecho del objeto que se puede usar para desplazarse por el texto. El valor predeterminado es imprimir el texto con ajuste de línea, pero si se establece la marca D_SELECTED, el texto se imprimirá con ajuste de caracteres. El campo d1 se usa internamente para almacenar el número de líneas de texto y d2 se usa para almacenar cuánto se ha desplazado por el texto.";
            allegroDialog[i].flags = D_SELECTED;
            break;
        case TipoControl::STAGE:
            // allegroDialog[i].proc = d_box_proc;
            allegroDialog[i].dp = nullptr;
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


    // Prueba de dialog.
    static DIALOG test[] = {
        { d_text_proc,                  10, 360, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Prueba 01"),        NULL, NULL },
        { d_text_proc,                  10, 380, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Prueba 02"),        NULL, NULL },
        { d_text_proc,                  10, 400, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Prueba 03"),        NULL, NULL },
        { d_text_proc,                  10, 420, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Prueba 04"),        NULL, NULL },
        { d_text_proc,                  10, 440, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Prueba 05"),        NULL, NULL },
        { d_text_proc,                  10, 460, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Prueba 06"),        NULL, NULL },
        { NULL,                          0,   0,  0,  0,    0,    0, 0,    0,      0,   0,   NULL,                                   NULL, NULL }
    };

    int result = do_dialog(allegroDialog, -1);
    result = do_dialog(test, -1);
    delete[] allegroDialog;
    return result;
}

void AllegroRenderer::setSliderValue(SliderCtrl* slider, int val) {
    DIALOG* dlgCtrl = findDialogControl(slider);
    if (dlgCtrl) {
        dlgCtrl->d2 = val;
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
    VectorCtrl* vctrl = dynamic_cast<VectorCtrl*>(control);
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

int AllegroRenderer::defaultSlider(SliderCtrl* sld, const InputEvent& ev) {
    DIALOG* dlgCtrl = findDialogControl(sld);
    sld->setValue(dlgCtrl->d2 + sld->min);
    return d_slider_proc(eventToMsg(ev.event), dlgCtrl, ev.c);
};

int AllegroRenderer::defaultControl(Control* ctrl, const InputEvent& ev) {
    //DIALOG* dlgCtrl = findDialogControl(ctrl);
    //return d_slider_proc(eventToMsg(ev.event), dlgCtrl, ev.c);
    if (ev.event == ControlEvent::WantFocus) { return D_WANTFOCUS; }
    return D_O_K;
};

int AllegroRenderer::defaultVector (VectorCtrl* vector, const InputEvent& ev) {
    DIALOG* dlgCtrl = findDialogControl(vector);
    if (ev.event == ControlEvent::WantFocus) { return D_WANTFOCUS; }
    if (vector->modoEdicion) return d_edit_proc(eventToMsg(ev.event), dlgCtrl, ev.c);
    else return d_ctext_proc(eventToMsg(ev.event), dlgCtrl, ev.c);
};

int AllegroRenderer::eventToMsg (const ControlEvent evtype) const {
    switch (evtype){
        case ControlEvent::Start:         return MSG_START;     break;
        case ControlEvent::End:           return MSG_END;       break;
        case ControlEvent::Draw:          return MSG_DRAW;      break;
        case ControlEvent::Click:         return MSG_CLICK;     break;
        case ControlEvent::DoubleClick:   return MSG_DCLICK;    break;
        case ControlEvent::Key:           return MSG_KEY;       break;
        case ControlEvent::Char:          return MSG_CHAR;      break;
        case ControlEvent::UChar:         return MSG_UCHAR;     break;
        case ControlEvent::XChar:         return MSG_XCHAR;     break;
        case ControlEvent::WantFocus:     return MSG_WANTFOCUS; break;
        case ControlEvent::GotFocus:      return MSG_GOTFOCUS;  break;
        case ControlEvent::LostFocus:     return MSG_LOSTFOCUS; break;
        case ControlEvent::GotMouse:      return MSG_GOTMOUSE;  break;
        case ControlEvent::LostMouse:     return MSG_LOSTMOUSE; break;
        case ControlEvent::Idle:          return MSG_IDLE;      break;
        case ControlEvent::Radio:         return MSG_RADIO;     break;
        case ControlEvent::Wheel:         return MSG_WHEEL;     break;
        case ControlEvent::LeftPress:     return MSG_LPRESS;    break;
        case ControlEvent::LeftRelease:   return MSG_LRELEASE;  break;
        case ControlEvent::MiddlePress:   return MSG_MPRESS;    break;
        case ControlEvent::MiddleRelease: return MSG_MRELEASE;  break;
        case ControlEvent::RightPress:    return MSG_RPRESS;    break;
        case ControlEvent::RightRelease:  return MSG_RRELEASE;  break;
        case ControlEvent::WantMouse:     return MSG_WANTMOUSE; break;
        default:                          return MSG_USER;      break;
    }
}

ControlEvent AllegroRenderer::msgToEvent (int msg) {
    ControlEvent evtype;
    switch (msg) {
        case MSG_START:     evtype = ControlEvent::Start;         break;
        case MSG_END:       evtype = ControlEvent::End;           break;
        case MSG_DRAW:      evtype = ControlEvent::Draw;          break;
        case MSG_CLICK:     evtype = ControlEvent::Click;         break;
        case MSG_DCLICK:    evtype = ControlEvent::DoubleClick;   break;
        case MSG_KEY:       evtype = ControlEvent::Key;           break;
        case MSG_CHAR:      evtype = ControlEvent::Char;          break;
        case MSG_UCHAR:     evtype = ControlEvent::UChar;         break;
        case MSG_XCHAR:     evtype = ControlEvent::XChar;         break;
        case MSG_WANTFOCUS: evtype = ControlEvent::WantFocus;     break;
        case MSG_GOTFOCUS:  evtype = ControlEvent::GotFocus;      break;
        case MSG_LOSTFOCUS: evtype = ControlEvent::LostFocus;     break;
        case MSG_GOTMOUSE:  evtype = ControlEvent::GotMouse;      break;
        case MSG_LOSTMOUSE: evtype = ControlEvent::LostMouse;     break;
        case MSG_IDLE:      evtype = ControlEvent::Idle;          break;
        case MSG_RADIO:     evtype = ControlEvent::Radio;         break;
        case MSG_WHEEL:     evtype = ControlEvent::Wheel;         break;
        case MSG_LPRESS:    evtype = ControlEvent::LeftPress;     break;
        case MSG_LRELEASE:  evtype = ControlEvent::LeftRelease;   break;
        case MSG_MPRESS:    evtype = ControlEvent::MiddlePress;   break;
        case MSG_MRELEASE:  evtype = ControlEvent::MiddleRelease; break;
        case MSG_RPRESS:    evtype = ControlEvent::RightPress;    break;
        case MSG_RRELEASE:  evtype = ControlEvent::RightRelease;  break;
        case MSG_WANTMOUSE: evtype = ControlEvent::WantMouse;     break;
        default:            evtype = ControlEvent::Unknown;       break;
    }
    return evtype;
}

void AllegroRenderer::limpiarControl (Control* control) {
    DIALOG* d = findDialogControl(control);
    rectfill(screen, d->x, d->y, d->x + d->w - 1, d->y + d->h - 1, d->bg);
}

void AllegroRenderer::invertirBackgroundForeground(Control* ctrl){
    DIALOG* d = findDialogControl(ctrl);
    std::swap(ctrl->fg, ctrl->bg);
    std::swap(d->fg, d->bg);
    d->flags |= D_DIRTY;
};

void AllegroRenderer::editarTexto(VectorCtrl* vector){
    DIALOG* d = findDialogControl(vector);

    if (vector->modoEdicion){
        unsigned int x, y;
        extraerEnteros ((char*)d->dp, x, y);
        vector->setXY (x, y);
        d->flags |= D_DIRTY;
    } else {
        d->dp = const_cast<char*>(vector->texto.c_str());
        d->d1 = vector->texto.size()*4;
        d->d2 = 0;
        d->flags |= D_DIRTY;
    }
};

void AllegroRenderer::extraerEnteros (std::string input, unsigned int& x, unsigned int& y)
{
    // Encontrar la posición de la coma.
    size_t commaPos = input.find(',');
    if (commaPos == std::string::npos) {
        std::cerr << "Error: no se encontró coma en la cadena." << std::endl;
        return;
    }
    
    // Extraer las subcadenas antes y después de la coma.
    std::string xStr = input.substr(0, commaPos);
    std::string yStr = input.substr(commaPos + 1);
    
    // Convertir las subcadenas a enteros.
    x = std::stoi(xStr);
    y = std::stoi(yStr);
    
    // Mostrar resultados.
    std::cout << "x = " << x << ", y = " << y << std::endl;
}