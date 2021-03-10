#pragma once

#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;


class Personaje : public ObjetoMovil
{
	friend class Interaccion;
	friend class Mundo;
public:
	Personaje();
	virtual  ~Personaje(); //habia un ~virtual
	void mueve(float t);
	float getPosX(void){ return posicion.x; };
	float getPosY(void){ return posicion.y; };
	float getVelY(void){ return velocidad.y; };
	void setVelY(float vy) { velocidad.y = vy; };
	void setPosY(float y) { posicion.y = y; };
	void setGravedad(float g) { aceleracion.y = g; };
	float getAltura() { return altura; };
	void SetHombre() { activo = &hombre; };
	void SetMujer() { activo = &mujer; };
	void Dibujahombre();
	void Dibujamujer();
protected:
	SpriteSequence hombre,mujer;
	SpriteSequence* activo;
	float altura;
	};


