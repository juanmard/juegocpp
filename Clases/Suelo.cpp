#include "Suelo.h"

Suelo::Suelo (Actor *aowner, int new_size) : Mosaico (aowner)
{
    // TODO: Dejar de cargar continuamente el fichero de "sprites".
    //       Incluir quizás en los parámetros de creación del actor.
    //       O crear una clase que sea "Vestuario" común a todos los
    //       actores de la escena desde el Juego principal (o quizás
    //       desde el "ActorManager".
    DatFile &file_dat = DatFile("sprites.dat");
    suelo_1 = file_dat.GetBitmap("suelo_1");
    suelo_2 = file_dat.GetBitmap("suelo_2");


    // Generamos el suelo según el tamaño solicitado.
    int i;
    for (i=0; i<new_size; i++)
    {
        add_Tesela (new Tesela (this, suelo_2, 32*i, 0));
    }
    
    // Añadimos las plataformas terminales al suelo.
    add_Tesela (new Tesela (this, suelo_1, 0, 1));
    add_Tesela (new Tesela (this, suelo_1, 32*new_size-10, 1, true));

    // Adaptamos el ancho y el alto del actor padre.
    // TODO: Igual esto no es deseable si queremos hacer un suelo "falso", es decir,
    //       que no sea tan extenso como lo que muestra el gráfico.
    aowner->set_wh(32*new_size+20,15);

    // Una vez creado actualizamos la variable del tamaño.
    size = new_size;

    // Guardamos la última Tesela para poder modificar su tamaño.
    terminal_final = last_Tesela ();
}

/**
 * \brief Obtiene el tamaño actual del suelo.
 */
int Suelo::Get_size (void)
{
    return size;
}

/**
 * \brief Modifica el tamaño actual del suelo.
 */
void Suelo::Set_size (int new_size)
{
    // Sólo funciona si el nuevo tamaño es mayor al antiguo.
    int num = new_size - size;

    // Añadimos una Tesela.
    add_Tesela(new Tesela (this, suelo_2, 32*size));

    // Movemos el terminal.
    move_Tesela (32*num, 0, terminal_final);

    // Mover el terminal al final del mosaico para quede
    // sobre las demás teselas al dibujar en pantalla.
    // swap_Tesela (terminal_final, last_Tesela());

    // Actualizamos el tamaño actual.
    size = new_size;
}
