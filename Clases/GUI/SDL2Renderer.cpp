#include "SDL2Renderer.h"
#include <stdexcept>
#include <iostream>

TTF_Font* SDL2Renderer::font = nullptr;  // Definición e inicialización estática.

void SDL2Renderer::dibujarTexto(const char* texto, int x, int y, ColorType color) {
    if (!texto || texto[0] == '\0') return;

    // Convertir ColorType a R,G,B
    Uint8 r = (color >> 16) & 0xFF;
    Uint8 g = (color >> 8) & 0xFF;
    Uint8 b = color & 0xFF;

    SDL_Color sdlColor = { r, g, b, 255 };

    //SDL_Log("Dibujando texto: '%s' en (%d,%d) con color RGB(%d,%d,%d)", texto, x, y, r, g, b);
    SDL_Surface* surface = TTF_RenderText_Solid(font, texto, sdlColor);
    if (!surface) {
        SDL_Log("Error al crear superficie de texto: %s", TTF_GetError());
        throw std::runtime_error("Error al crear superficie de texto");
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if (!texture) {
        SDL_Log("Error al crear textura de texto: %s", SDL_GetError());
        throw std::runtime_error("Error al crear textura de texto");
    }
    SDL_FreeSurface(surface);

    SDL_Rect destRect = { x, y, 0, 0 };
    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);

    SDL_RenderCopy(m_renderer, texture, nullptr, &destRect);
    SDL_DestroyTexture(texture);
}

SDL2Renderer::SDL2Renderer()
: m_window(nullptr), m_renderer(nullptr) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("No se pudo inicializar SDL");
    }

    m_window = SDL_CreateWindow(
        "SDL2 Renderer Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    if (!m_window) {
        SDL_Quit();
        throw std::runtime_error("No se pudo crear la ventana SDL");
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        throw std::runtime_error("No se pudo crear el renderizador SDL");
    }

    // Inicializar TTF si se usa texto.
    if (TTF_Init() == -1) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        throw std::runtime_error("No se pudo inicializar SDL_ttf");
    }
    if (!font) {
        font = TTF_OpenFont("C:/Windows/Fonts/georgiab.ttf", 22);
        if (!font) {
            throw std::runtime_error("No se pudo cargar la fuente TTF");
        }
    }
}

SDL2Renderer::~SDL2Renderer() {
    TTF_Quit();
    if (m_renderer) SDL_DestroyRenderer(m_renderer);
    if (m_window) SDL_DestroyWindow(m_window);
    SDL_Quit();
}

IRenderer::ColorType SDL2Renderer::makeColor(int r, int g, int b) {
    // Empaqueta en 0x00RRGGBB (usa 24 bits sin alfa)
    return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

void SDL2Renderer::limpiarPantalla(ColorType color) {
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;

    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    SDL_RenderClear(m_renderer);
}

void SDL2Renderer::dibujarCuadrado(int x, int y, ColorType color) {
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;

    SDL_Rect rect = { x, y, 150, 150 };  // Tamaño fijo 150x150, se puede modificar

    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    SDL_RenderFillRect(m_renderer, &rect);
}

// Los demás métodos se pueden implementar de forma similar en pasos posteriores...

void SDL2Renderer::limpiarControl(Control* control) {
    SDL_Rect rect = {control->x, control->y, control->w, control->h};
    SDL_SetRenderDrawColor(m_renderer, 128, 128, 128, 255);
    SDL_RenderFillRect(m_renderer, &rect);
}

int SDL2Renderer::mostrarMenu(const Menu& menu, int x, int y) { return 0; }

void SDL2Renderer::refrescarPantalla() {
    SDL_RenderPresent(m_renderer);
}
int SDL2Renderer::mostrarDialog(const Dialog& dialog) { return 0; }

/// @brief Cambia el valor del slider en la GUI.
/// @param control Control que representa al slider.
/// @param val Valor a cambiar.
/// @note Es posible que este método no sea necesario si el valor del slider en la GUI no se encontrara duplicado, si no
///       que fuera una referencia al único valor que representa el slider.
///
void SDL2Renderer::setSliderValue(Control* control, int val) {
        slider_value = val;
}

void SDL2Renderer::updateVector(Control* control) {
    VectorCtrl* vector = dynamic_cast<VectorCtrl*>(control);
    vector->texto = std::to_string(vector->x) + ", " + std::to_string(vector->y);
}

/// @brief Define el comportamiento por defecto de un slider en la GUI al recibir un evento.
/// @param sld Puntero al slider que se desea representar.
/// @param ev Evento sobre el slider.
/// @return Devuelve un valor según su comportamiento.
/// @note Este valor que devuelve tiene sentido en Allegro. Independizar creando los propios valores de retorno.
///
int SDL2Renderer::defaultSlider(SliderCtrl* sld, const InputEvent& ev) {
    switch (ev.event){
        case ControlEvent::Draw:
        {
            // Barra del slider
            slider_x = sld->x;
            slider_y = sld->y;
            slider_width = sld->w;
            slider_height = sld->h;
            SDL_Rect bar = {slider_x, slider_y, slider_width, slider_height};
            SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 255);
            SDL_RenderFillRect(m_renderer, &bar);

            // Manija del slider
            handle_x = slider_x + (slider_value-slider_min)*(slider_width-handle_width)/(slider_max-slider_min);
            SDL_Rect handle = {handle_x, slider_y-handle_height/2+slider_height/2, handle_width, handle_height};
            SDL_SetRenderDrawColor(m_renderer, 180, 60, 60, 255);
            SDL_RenderFillRect(m_renderer, &handle);
        }
        break;
        case ControlEvent::LeftPress:
        {
            int mx, my;
            sld->input->obtenerPosicionMouse(mx, my);
            if(mx >= handle_x && mx <= handle_x+handle_width && my >= slider_y-handle_height/2 && my <= slider_y+handle_height/2){
                dragging = true;
            }
            if (mx>= slider_x && mx <= slider_x + slider_width && my >= slider_y && my <= slider_y + slider_height) {
                SDL_Log("Click en la barra del slider");
                int pos = mx - slider_x - handle_width/2;
                if(pos < 0) pos = 0;
                if(pos > slider_width-handle_width) pos = slider_width - handle_width;
                slider_value = slider_min + pos*(slider_max-slider_min)/(slider_width-handle_width);
                sld->setValue(slider_value);
           }
        }
        break;
        case ControlEvent::LeftRelease:
        {
            dragging = false;
        }
        break;
        case ControlEvent::MouseMove:
        {
            if (dragging) {
                int mx, my;
                sld->input->obtenerPosicionMouse(mx,my);
                int pos = mx - slider_x - handle_width/2;
                if(pos < 0) pos = 0;
                if(pos > slider_width-handle_width) pos = slider_width - handle_width;
                slider_value = slider_min + pos*(slider_max-slider_min)/(slider_width-handle_width);
                sld->setValue(slider_value);
            }
        }
        break;
    }
    return 0;
};

int SDL2Renderer::defaultVector(VectorCtrl* vector, const InputEvent& ev) {
        switch (ev.event){
        case ControlEvent::Draw: {
                //std::cout << "Draw" << std::endl;
                // Letras.
                dibujarTexto (vector->texto.c_str(), (int)vector->Control::x + 22, (int)vector->Control::y, makeColor(250,250,0));

                // Marco del vector.
                if (dibujarMarco) {
                    SDL_Rect marco = {(int)vector->Control::x, (int)vector->Control::y, (int)vector->w, (int)vector->h};
                    SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 255);
                    SDL_RenderDrawRect(m_renderer, &marco);
                }
            }
            break;

        case ControlEvent::DoubleClick:
            dibujarMarco = !dibujarMarco;
            break;

        case ControlEvent::Wheel:
            vector->setXY(vector->x + ev.c, vector->y);
            break;

        case ControlEvent::LeftPress:
            std::cout << "Vector LPress" << std::endl;
            break;

        default:
            break;
        }
    return 0;
}

void SDL2Renderer::invertirBackgroundForeground(VectorCtrl* vector) {}
void SDL2Renderer::editarTexto(VectorCtrl* control) {}
