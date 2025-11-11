#ifndef COMANDOSCONCRETOS_H
#define COMANDOSCONCRETOS_H

#include <memory>
#include "Comando.h"
#include "Grafico.h"

class ComandoDibujar : public Comando {
    Grafico* objetoGrafico;
public:
    ComandoDibujar(Grafico* g) : objetoGrafico(g) {}
    void ejecutar() override {
        if (objetoGrafico)
            objetoGrafico->dibujar();
    }
};

#endif
