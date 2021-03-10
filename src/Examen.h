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
	void dibuja(int i);										//DIBUJAR� CADA PREGUNTA
	bool Correccion(unsigned char key, int i);				//CORREGIR� CADA PREGUNTA Y SUMAR� A NOTA
	void destruirExamen();
	unsigned char respuesta;
	float getNota() { return nota; }

};

