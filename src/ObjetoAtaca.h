#pragma once
#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class ObjetoAtaca:public ObjetoMovil
{
	friend class Interaccion;
public:
	ObjetoAtaca();
	~ObjetoAtaca();

	float getLado() { return lado; }
	void setPos(float ix, float iy);
	float getPosX() { return posicion.x; };
	float getPosY() { return posicion.y; };
	void SetLimpieza() { activo = &limpieza; };
	void SetAlumno() { activo = &alumno; };
	void DibujaLimpieza();
	void DibujaAlumno();
	void mueve_armonico(float t, float Amp);

protected:
	SpriteSequence limpieza, alumno;
	SpriteSequence* activo;
	float lado;
	Vector2D origen;
	int numero;
	int v[3];
};

