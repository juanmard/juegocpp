#ifndef SPRITE_H
#define SPRITE_H

#include "ActorGraphic.h"
#include <allegro.h>
#include <string.h>
#include "Frame.h"
#include <vector>

//using namespace std;

class Actor;

/** 
 * \brief   Parte gráfica de un actor como un gráfico en movimiento.
 * \details Esta clase modela varias imágenes en movimiento como gráfico para un actor.
 */ 
class Sprite : public ActorGraphic
{
public:
                      Sprite      (const Sprite &copia, Actor *aowner);
                      Sprite      (Actor *aowner);
  virtual Sprite *    clone       (Actor *propietario) const;
  void                draw        (BITMAP *bmp);
  void                draw        (int x, int y, BITMAP *bmp);
  void                update      ();
  void                init        ();
  int                 get_w       ();
  int                 get_h       ();
  int                 get_x       ();
  int                 get_y       ();
  void                add_frame   (BITMAP *bmp, int cx, int cy, int ticks);
  Mask *              get_mask    ();
  void                setMirror   (bool paramMirror);
  bool                getMirror   ();
  void                notMirror   ();
  virtual string      getString   () const;

protected:
  vector<Frame>   frames;
  int             actual_tick, actual_frame;
  bool            mirror;
};

#endif
