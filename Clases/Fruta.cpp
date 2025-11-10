///
/// @file Fruta.cpp
/// @brief Fichero de la clase "Fruta".
/// @details En esta clase describimos el comportamiento de una fruta en el juego.
/// @author Juan Manuel Rico
/// @date Noviembre 2025
/// @version 1.0.0
///

#include "Fruta.h"

Fruta::Fruta ():
Actor ()
{
};

Fruta::Fruta (Almacen &almacen):
Actor ()
{
    // ¡Cuidado! Esto falla si en el almacén no existe el bitmap que se pide.
    // Creamos la animación de la espera.
    idle = new Sprite(this);
    idle->add_frame(almacen.get_bitmap("sprite_016"), 0,  2, 10);
    idle->add_frame(almacen.get_bitmap("sprite_016"), 0,  0, 30);
    idle->add_frame(almacen.get_bitmap("sprite_016"), 0, -2, 10);
    idle->add_frame(almacen.get_bitmap("sprite_016"), 0,  0, 20);
    idle->setMirror(false);

    uvas = new Sprite(this);
    uvas->add_frame(almacen.get_bitmap("sprite_014"), 0,  2, 10);
    uvas->add_frame(almacen.get_bitmap("sprite_014"), 0,  0, 30);
    uvas->add_frame(almacen.get_bitmap("sprite_014"), 0, -2, 10);
    uvas->add_frame(almacen.get_bitmap("sprite_014"), 0,  0, 20);
    uvas->setMirror(false);

    // Establecemos las variables del actor de la fruta.
    setCodigo (Nombres::fruta);
    set_x(177);
    set_y(187);
    set_is_detected (true);
    set_collision_method(CollisionManager::PP_COLLISION);
    set_wh (15,18);

    // Asignamos la animación de inicio a la fruta.
    // @todo Hacer en este caso una llamada más sencilla para crear y asignar la animación, algo como:
    //       @code
    //         set_actor_graphic (new Sprite(Animaciones::fruta_en_espera))
    //       @endcode
    //       Donde la clase "Animaciones" sería una clase con las animaciones ya predefinidas.
    //
    set_actor_graphic (uvas);
};

void Fruta::getNombre (std::string &strNombre) const
{
    strNombre = Nombres::Imprimir (nombre);
};

std::string Fruta::getNombre () const
{
    return "Fruta";
};

void Fruta::hit (Actor* who, int damage)
{
    std::cout << "Tropezando " << this->getNombre() << " con " << who->getNombre() << std::endl;
    switch (who->getCodigo())
    {
    case Nombres::ben:
        // Movimiento de prueba. Lo ideal será cambiar la animación.
        this->set_x(this->get_x()+2);
        this->set_actor_graphic(idle);
        break;
    default:
        break;
    };
};

std::string& Fruta::get_nombre () const {
    return *new std::string ("Fruta");
};

Menu& Fruta::getMenu () const {
    Menu *menu = new Menu();
    menu->add(const_cast<char*>("Fruta - Update"), 0, (void *) this, NULL, Menu::callback);
    menu->add("Fruta - Draw", 0);
    menu->add("Prueba",0, (void*) this, NULL, NULL);
    menu->add(const_cast<char*>("Fruta - Último"), 0, (void *) this, NULL, NULL);
    return *menu;
};

Formulario& Fruta::getFormulario () const {
    return (*new Formulario());
};
