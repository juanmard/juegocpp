#ifndef GAME_H
#define GAME_H

#include <string>

// Predefiniciones de clases.
class ActorManager;
class StageManager;
class SoundManager;
class ControlManager;
class CollisionManager;

using namespace std;

/* \brief   Clase que recoge las funciones básicas de un juego.
 * \todo   Definir el tipo 'team_t' como una clase externa.
 */
class Game
{
	public:
        typedef enum
        {
            ALLY,
            ENEMY
        }team_t;

		ActorManager        *actor_manager;
		StageManager       *stage_manager;
		SoundManager      *sound_manager;
        ControlManager     *control_manager;
        CollisionManager    *collision_manager;

                               Game		();
		virtual			   ~Game		();
		virtual void    init		    (int gfx_mode, int w, int h, int col);
		virtual void    main    		(void);
        void	               pause        (void);
		void	               play        	(void);
		bool	               is_paused	(void);
		void			       set_name	(string name);
		string			   get_name	(void);
		void                update		(void);

	protected:
		string     name;
		int         gfx_w, gfx_h;
		int         colors;

        void		  set_max_frame_skip	(int max_fs);

	private:
		int     actual_tick;
		int     old_tick;
		int     graphic_tick;
		int     frame_skip;
		int     max_frame_skip;
		bool    paused;

		void	                start           					(void);
		void	                shutdown		        		(string message);
        virtual void    create_actormanager    (void);
        virtual void    create_stagemanager    (void);
        virtual void    create_soundmanager   (void);
        virtual void    create_controlmanager  (void);
        virtual void    create_collisionmanager (void);
};

#endif
