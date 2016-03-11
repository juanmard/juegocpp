/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * linux
 * Copyright (C) Juanma Rico 2010 <juanmard@gmail.com>
 * 
 */

#include "Bloque.h"

/**
 * \brief	Constructor por omisión.
 */
Bloque::Bloque ():
x(0), y(0), w(0), h(0)
{
};

/**
 * \brief	Constructor por omisión.
 */
Bloque::Bloque (int paramX, int paramY, int paramW=0, int paramH=0):
x(paramX), y(paramY), w(paramW), h(paramH)
{
};

/**
 * \brief	Destructor por omisión.
 */
Bloque::~Bloque  (){};

/**
 * \brief	Cambia posición del bloque.
 */
void Bloque::setXY (int paramX, int paramY)
{
	x = paramX;
	y = paramY;
};

/**
 * \brief	Cambia las dimensiones del bloque.
 */
void Bloque::setWH (int paramW, int paramH)
{
	w = paramW;
	h = paramH;
};

/**
 * \brief	Devuelve la coordenada X de la posición.
 */
int Bloque::getX  ()
{
	return x;
};

/**
 * \brief	Devuelve la coordenada Y de la posición.
 */
int	Bloque::getY  ()
{
	return y;
};

/**
 * \brief	Devuelve el ancho del bloque.
 */
int Bloque::getW  ()
{
	return w;
};

/**
 * \brief	Devuelve el alto del bloque.
 */
int Bloque::getH  ()
{
	return h;
};

