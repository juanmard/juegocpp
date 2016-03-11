#include "Suelo.h"

Suelo::Suelo (Actor *aowner, int new_size) : Mosaico (aowner)
{
    // TODO: Dejar de cargar continuamente el fichero de "sprites".
    //       Incluir quiz�s en los par�metros de creaci�n del actor.
    //       O crear una clase que sea "Vestuario" com�n a todos los
    //       actores de la escena desde el Juego principal (o quiz�s
    //       desde el "ActorManager".
    DatFile &file_dat = DatFile("sprites.dat");
    suelo_1 = file_dat.GetBitmap("suelo_1");
    suelo_2 = file_dat.GetBitmap("suelo_2");


    // Generamos el suelo seg�n el tama�o solicitado.
    int i;
    for (i=0; i<new_size; i++)
    {
        add_ultima_Tesela (new Tesela (this, suelo_2, 32*i, 0));
    }
    
    // A�adimos las plataformas terminales al suelo.
    add_ultima_Tesela (new Tesela (this, suelo_1, 0, 1));
    add_ultima_Tesela (new Tesela (this, suelo_1, 32*new_size-10, 1, true));

    // Adaptamos el ancho y el alto del actor padre.
    // TODO: Igual esto no es deseable si queremos hacer un suelo "falso", es decir,
    //       que no sea tan extenso como lo que muestra el gr�fico.
    aowner->set_wh(32*new_size+20,15);

    // Una vez creado actualizamos la variable del tama�o.
    size = new_size;
}

/**
 * \brief Obtiene el tama�o actual del suelo.
 */
int Suelo::Get_size (void)
{
    return size;
}

/**
 * \brief Modifica el tama�o actual del suelo.
 * \todo Permitir cambio en cualquier sentido (mayor o menor) y de cualquier tama�o.
 */
void Suelo::Set_size (int new_size)
{
    // S�lo funciona si el nuevo tama�o es mayor al antiguo.
    int num = new_size - size;

    // Movemos el terminal.
    move_Tesela (32*num, 0, last_Tesela());

    // A�adimos una Tesela.
    add_primera_Tesela(new Tesela (this, suelo_2, 32*size));

    // Mover el terminal al final del mosaico para quede
    // sobre las dem�s teselas al dibujar en pantalla.
    // swap_Tesela (terminal_final, last_Tesela());

    // Actualizamos el tama�o actual.
    size = new_size;
}
