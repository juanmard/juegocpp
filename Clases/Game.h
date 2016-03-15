#ifndef GAME_H
#define GAME_H

#include <allegro.h>
#include <string>
#include <iostream>
#include "ActorManager.h"
#include "StageManager.h"
#include "ControlManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"

using namespace std;

class ActorManager;
class StageManager;
class SoundManager;
class ControlManager;
class CollisionManager;

class Game
{
	public:
        typedef enum
        {
            ALLY,
            ENEMY
        }team_t;

		ActorManager        *actor_manager;
		StageManager        *stage_manager;
		SoundManager        *sound_manager;
        ControlManager      *control_manager;
        CollisionManager    *collision_manager;

						Game		();
		virtual			~Game		();
		virtual void	init		(int gfx_mode, int w, int h, int col);
		virtual void	main		();
		void			set_name	(string name);
		string			get_name	();
		void update					();

	protected:
		string name;
		int gfx_w,gfx_h;
		int colors;
		
		void		set_max_frame_skip	(int max_fs);

	private:
		int actual_tick;
		int old_tick;
		int graphic_tick;
		int frame_skip;
		int max_frame_skip;

		void	        start					();
		void	        shutdown				(string message);
        virtual void    create_actormanager     ();
        virtual void    create_stagemanager     ();
        virtual void    create_soundmanager   ();
        virtual void    create_controlmanager   ();
        virtual void    create_collisionmanager ();
};

#endif
