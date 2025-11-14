#ifndef COMANDOSCONCRETOS_H
#define COMANDOSCONCRETOS_H

#include <memory>
#include "Comando.h"
#include "Grafico.h"
#include "Control.h"
#include "SliderCtrl.h"

class ComandoDibujar : public Comando {
    Grafico* objetoGrafico;
public:
    ComandoDibujar(Grafico* g) : objetoGrafico(g) {}
    void ejecutar() override {
        if (objetoGrafico)
            objetoGrafico->dibujar();
    }
};

class ComandoEjemplo : public Comando {
public:
    void ejecutar() override {
        std::cout << "Comando ejecutado desde Allegro" << std::endl;
    }
};

class ComandoCuadrado : public Comando {
    Grafico* objetoGrafico;
public:
    ComandoCuadrado(Grafico* g) : objetoGrafico(g) {}
    void ejecutar() override {
        if (objetoGrafico)
            objetoGrafico->dibujarCuadrado ();
    }
};

class CommandSalir : public Comando {
public:
    void ejecutar() override {
        //std::cout << "Comando salir" << std::endl;
    }
};

class CommandOtro : public Comando {
public:
    void ejecutar() override {
        std::cout << "Comando otro" << std::endl;
    }
};

class ComandoTest : public Comando {
public:
   SliderCtrl* ctrl;

    ComandoTest(SliderCtrl* c) { ctrl = c; }
    void ejecutar() override {
        // std::cout << "pos - " << ctrl->pos << std::endl;
    }
};
#endif
