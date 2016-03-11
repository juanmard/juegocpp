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
        add_ultima_Tesela (new Tesela (this, suelo_2, 32*i, 0));
    }
    
    // Añadimos las plataformas terminales al suelo.
    add_ultima_Tesela (new Tesela (this, suelo_1, 0, 1));
    add_ultima_Tesela (new Tesela (this, suelo_1, 32*new_size-10, 1, true));

    // Adaptamos el ancho y el alto del actor padre.
    // TODO: Igual esto no es deseable si queremos hacer un suelo "falso", es decir,
    //       que no sea tan extenso como lo que muestra el gráfico.
    aowner->set_wh(32*new_size+20,15);

    // Una vez creado actualizamos la variable del tamaño.
    size = new_size;
}

/**
 * \brief Obtiene el tamaño actual del suelo.
 */
int Suelo::Get_size (void)
{
    return size;
}

/**
 * \brief   Modifica el tamaño actual del suelo.
 * \details El tamaño del suelo se mide por la cantidad de bloques que tiene,
 *          no se incluyen los terminales del suelo.
 * \todo    Insertar y borrar las teselas del suelo por detrás de los dos 
 *          suelos terminales y así mantener la coherencia del mosaico guardado
 *          y el mostrado en pantalla.
 */
void Suelo::Set_size (int new_size)
{
    // Se calcula la diferencia de tamaños, es decir,
    // el número de bloques a incluir o eliminar.
    int num = new_size - size;

    // Si el tamaño es en realidad nuevo...
    if (num != 0)
    {
        // Movemos el terminal derecho (último) a la nueva posición.
        move_Tesela (32*num, 0, last_Tesela());

        // Si el tamaño es mayor...
        if (num > 0)
        {
            // Añadimos o quitamos teselas del "suelo_2".
            for (int i=0; i<num; i++)
            {   
                add_primera_Tesela(new Tesela (this, suelo_2, 32*(size+i)));
            }
        }
        // Si el tamaño es menor...
        else
        {
            num = -num;
            for (int i=0; i<num; i++)
            {   
                del_primera_Tesela ();
            }
        }

        // Actualizamos el tamaño actual.
        size = new_size;
    }
}
