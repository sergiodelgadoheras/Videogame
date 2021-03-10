#pragma once
#include"glut.h"
#include"ObjetoMovil.h"
#include"ETSIDI.h"
#include "Examen.h"

using ETSIDI::SpriteSequence;

class Boss
{
	friend class CoordinadorETSIDI;
private:
	float x_ojo, y_ojo, z_ojo;
	SpriteSequence prof;
	ObjetoMovil profesor;
	Examen *Ex;
	int vida;
	int indiceImpresionPreguntas;
public:
	Boss();
	~Boss();
	void inicializa(int v);
	void dibuja();
	void mueve(float t, float Amp);
	void teclaEspecial(unsigned char key);
	float getNota() { return Ex->getNota(); }
	void destruirEx() { Ex->destruirExamen(); delete Ex; }
	void loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
};

