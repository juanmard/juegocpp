/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#ifndef _BLOQUE_H_
#define _BLOQUE_H_

class Bloque
{
public:
			Bloque 		();
			Bloque 		(int x, int y, int w, int h);
			~Bloque 	();
	void	setXY		(int x, int y);
	void	setWH		(int w, int h);
	int		getX		();
	int		getY		();
	int		getW		();
	int		getH		();

protected:

private:
  int	x, y;
  int	w, h;
};

#endif // _BLOQUE_H_
