#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <memory>
#include "Comando.h"
#include "ItemMenu.h"
#include "IRenderer.h"
#include "IInput.h"

namespace jmr {
class Menu {
public:
    std::string titulo;
    std::vector<ItemMenu> items;
    IRenderer* renderer = nullptr;
    IInput* input = nullptr;

    Menu(const std::string& tit) : titulo(tit) {}

    void agregarItem(const ItemMenu& item) {
        items.push_back(item);
    }

    void mostrar(IRenderer& renderer, IInput& input);
    const ItemMenu & mostrar(int x, int y);
    void setRenderer(IRenderer* r);
    void setInput(IInput* i);
};
}
#endif
