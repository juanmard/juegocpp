/*
 * Juego++
 * Copyright (C) Juanma Rico 2009 <juanmard@gmail.com>
 */

#ifndef _DIALOGALG_H_
#define _DIALOGALG_H_

#include <allegro.h>
#include <vector>
#include "ControlALG.h"

//using namespace std;
using std::vector;

class ControlALG;

class DialogALG
{
public:
	DialogALG 		();
	~DialogALG  	();
	void		show 	();
	void     add		(ControlALG control);
	
protected:
	vector<DIALOG >::iterator 		iter;
	vector<DIALOG >						controles;
	static	DIALOG						control_fin;
};

#endif // _DIALOGALG_H_
