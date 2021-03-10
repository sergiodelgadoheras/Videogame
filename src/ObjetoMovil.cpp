#include "ObjetoMovil.h"
#include <math.h>

ObjetoMovil::ObjetoMovil(void){}

ObjetoMovil::~ObjetoMovil(void){}

void ObjetoMovil::mueve(float t)
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}

void ObjetoMovil::mueve_armonico(float t, float Amp) 
{
	posicion.y = Amp * cos(2.0*3.1415*2.0*t);
}   

Vector2D ObjetoMovil::getPos()
{
	return posicion;
}
void ObjetoMovil::setVel(float vx, float vy)
{
	velocidad.x=vx;
	velocidad.y=vy;
}
void ObjetoMovil::setVel(Vector2D vel)
{
	velocidad=vel;
}
void ObjetoMovil::setPos(float x,float y)
{
	posicion.x=x;
	posicion.y=y;
}
void ObjetoMovil::setPos(Vector2D pos)
{
	posicion=pos;
}