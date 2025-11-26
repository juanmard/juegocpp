#ifndef ITEMMENU_H
#define ITEMMENU_H

#include <string>
#include <memory>
#include "Comando.h"

struct ItemMenu {
    std::string nombre;
    bool estado;
    std::vector<ItemMenu> submenu;
    std::shared_ptr<Comando> comando;

    ItemMenu(const std::string& nom, bool est = true, std::shared_ptr<Comando> cmd = nullptr) : nombre(nom), estado(est), comando(cmd) {}
};

#endif