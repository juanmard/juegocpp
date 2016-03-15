#include "Suelo.h"

Suelo::Suelo (Actor *aowner, int size) : Mosaico (aowner)
{
    // TODO: Dejar de cargar continuamente el fichero de "sprites".
    //       Incluir quiz�s en los par�metros de creaci�n del actor.
    //       O crear una clase que sea "Vestuario" com�n a todos los
    //       actores de la escena desde el Juego principal (o quiz�s
    //       desde el "ActorManager".
    DatFile &file_dat = DatFile("sprites.dat");

    // Generamos el suelo seg�n el tama�o solicitado.
    int i;
    for (i=0; i<size; i++)
    {
        add_Tesela (new Tesela (this,file_dat.GetBitmap("suelo_2"),32*i,0));
    }
    
    // A�adimos las plataformas terminales al suelo.
    add_Tesela (new Tesela (this,file_dat.GetBitmap("suelo_1"),0,1));
    add_Tesela (new Tesela (this,file_dat.GetBitmap("suelo_1"),32*size-10,1,true));

    // Adaptamos el ancho y el alto del actor padre.
    // TODO: Igual esto no es deseable si queremos hacer un suelo "falso", es decir,
    //       que no sea tan extenso como lo que muestra el gr�fico.
    aowner->set_wh(32*size+20,15);
}
