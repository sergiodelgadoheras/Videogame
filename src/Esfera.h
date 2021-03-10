#pragma once

#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Esfera:public ObjetoMovil
{
	friend class Interaccion;
public:
	Esfera();
	Esfera(float rad, float x=0, float y=0, float vx=0, float vy=0);
	virtual ~Esfera();
	void dibuja();
	void setColor( Byte r,Byte v, Byte a);
	void setRadio(float r);
	float getPosX() { return posicion.x; };
	float getPosY() { return posicion.y; };
	virtual Esfera* dividir();
protected:
	SpriteSequence libro;
	ColorRGB color;
	float radio;
};


