#pragma once
#include <string>
#include "stdlib.h"
using namespace std;

class Pregunta
{
public:
	string Preg;			//Enunciado de la pregunta
	string opciones[4];		//Opciones a presentar
	unsigned char resp;			//Respuesta correcta

public:
	Pregunta(string p, string op1, string op2, string op3, string op4, unsigned char r); // Creará la pregunta personalizada
	~Pregunta();
	bool  getCorrecion(unsigned char key);										// Dirá si la respuesta dada es correcta
	void print();

};

