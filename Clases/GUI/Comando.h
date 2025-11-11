#ifndef COMANDO_H
#define COMANDO_H

class Comando {
public:
    virtual void ejecutar() = 0;
    virtual ~Comando() {}
};

#endif
