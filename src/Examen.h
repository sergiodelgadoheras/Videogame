#pragma once
#include "Pregunta.h"

class Examen
{
protected:
	Pregunta *lista[4]; //LISTA DE PREGUNTAS;
	float nota;
	int numero;

public:
	Examen(int v);
	Examen();
	~Examen();
	void dibuja(int i);										//DIBUJARÁ CADA PREGUNTA
	bool Correccion(unsigned char key, int i);				//CORREGIRÁ CADA PREGUNTA Y SUMARÁ A NOTA
	void destruirExamen();
	unsigned char respuesta;
	float getNota() { return nota; }

};

