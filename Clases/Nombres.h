#pragma once

class Nombres
{
public:
    enum codigo {
                    pelota,
                    paleta,
                    herny,
                    jugador,
                    enemigo,
                    ladrillo
                };

public:
    Nombres(void);
    ~Nombres(void);
    /**
     * \todo    Crear un operador que transforme el nombre en una cadena.
     */
};
