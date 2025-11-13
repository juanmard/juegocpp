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

class CommandSalir : public Comando {
public:
    void ejecutar() override {
        // Aquí la acción para cerrar diálogo, se devuelve código Allegro esperado
        //return D_CLOSE;
        std::cout << "Comando salir\n";
    }
};

class CommandOtro : public Comando {
public:
    void ejecutar() override {
        std::cout << "Comando otro\n";
        // Otra acción
        //return D_O_K;
    }
};

class ComandoTest : public Comando {
public:
   SliderCtrl* control;

    ComandoTest(SliderCtrl* c) : control(c) {}
    void ejecutar() override {
        std::cout << "Comando test - " << ((control->tipo == TipoControl::BOX) ? "Es un SLIDER." : "No sé lo que es.") << "\n";
        // Otra acción
        //return D_O_K;
    }
};
#endif
