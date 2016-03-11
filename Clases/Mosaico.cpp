#include "Mosaico.h"


/**
 * \brief   Constructor de copia de la clase.
 */
Mosaico::Mosaico(const Mosaico &copia, Actor *propietario):
ActorGraphic (propietario),
teselas(copia.teselas)
{
    list<Tesela *>::iterator tmp_iter = teselas.begin();
    (*tmp_iter)->Set_x(20);
    
    // Se genera una nueva lista y se copian las teleslas.
    // \todo Encapsular esto en una clase propia de lista de Teselas.
    //;
    //list<Tesela *>::iterator inicio;
    //list<Tesela *>::iterator fin;

    //inicio = teselas.begin();
    //fin = teselas.end();
    //for (tmp_iter=inicio; tmp_iter!=fin; tmp_iter++)
    //{
    //    this->add_primera_Tesela (new Tesela(**tmp_iter,this));
    //}    
}

Mosaico::Mosaico(Actor *aowner):
ActorGraphic (aowner)
{
}

/**
 * \brief   Añade una nueva tesela al final de la lista.
 * \details Al añadirse al final de la lista es la
 *          última tesela en dibujarse, quedando por
 *          delante del resto.
 * \param   nueva   Puntero a la tesela a añadir.
 * \todo    Integrar "add_ultima_Tesela" y "add_primera_Tesela" en una única
 *          "add_Tesela (Tesela *nueva, Posicion pos = Mosaico::Delante)".
 */
void    Mosaico::add_ultima_Tesela (Tesela *nueva)
{
    teselas.push_back (nueva);
};    

/**
 * \brief   Añade una nueva tesela al inicio de la lista.
 * \details Al añadirse al inicio de la lista es la
 *          primera tesela en dibujarse, quedando por
 *          detrás del resto.
 * \param   nueva   Puntero a la tesela a añadir.
 */
void    Mosaico::add_primera_Tesela (Tesela *nueva)
{
    teselas.push_front (nueva);
};    

/**
 * \brief   Borra una tesela al inicio de la lista.
 */
void    Mosaico::del_primera_Tesela (void)
{
    teselas.erase (teselas.begin());
};    

void Mosaico::draw (BITMAP *pantalla)
{
    list<Tesela *>::iterator tmp_iter;

    // Dibuja todas las teselas del mosaico.
    for (tmp_iter=teselas.begin(); tmp_iter!=teselas.end(); tmp_iter++)
    {
        (*tmp_iter)->draw (pantalla);
    }
}

/**
 * \brief Mueve la tesela elegida según un incremento de 'y' y de 'x'.
 */
void    Mosaico::move_Tesela     (int inc_x, int inc_y, Tesela *elegida)
{
    elegida->Set_x (elegida->Get_x() + inc_x);
    elegida->Set_y (elegida->Get_y() + inc_y);
}

/**
 * \brief Devuelve la última tesela añadida.
 */
Tesela *    Mosaico::last_Tesela     (void)
{
    return teselas.back();
}

/**
 * \brief   Intercambia dos Teselas.
 * \todo   
 *         - Sobrecargar esta función con los índices de las teselas.
 *         - Desarrollar la función si fuera necesaria. 
 */
void    Mosaico::swap_Tesela     (Tesela *tesela_1, Tesela *tesela_2)
{
    //teselas.swap ();           
}

/**
 * \brief   Clona un mosaico completo.
 */
Mosaico *   Mosaico::clone  (Actor *propietario) const
{
    return (new Mosaico(*this,propietario));
}
