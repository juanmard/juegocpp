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

class ComandoEjemplo : public Comando {
public:
    void ejecutar() override {
        std::cout << "Comando ejecutado desde Allegro\n";
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

#endif
