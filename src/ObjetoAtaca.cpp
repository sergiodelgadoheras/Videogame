#include "ObjetoAtaca.h"
#include<stdlib.h>
#include"glut.h"
#include"Pared.h"


ObjetoAtaca::ObjetoAtaca() : limpieza("imagenes/Limpieza.png", 1), alumno ("imagenes/Alumno.png", 2 )
{
	limpieza.setCenter(getPosX(), getPosY());
	limpieza.setSize(6, 8);
	lado = 1;
	velocidad.x = -3.5f;
	alumno.setCenter(getPosX(), getPosY());
	alumno.setSize(3, 8);
}


ObjetoAtaca::~ObjetoAtaca(){}

void ObjetoAtaca::DibujaLimpieza() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);

	limpieza.setState(1, false);
	limpieza.draw();

	glPopMatrix();

	}

void ObjetoAtaca::DibujaAlumno() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);

	alumno.setState(1, false);
	alumno.draw();

	glPopMatrix();

}
void ObjetoAtaca:: setPos(float ix, float iy)
{
	//ix = 1 + rand() % (101 - 1);
	//iy = 1 + rand() % (11 - 1);
		ObjetoMovil::setPos(ix, iy);
		origen =posicion;//cambiar
	}