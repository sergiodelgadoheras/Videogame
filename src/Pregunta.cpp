#include "Pregunta.h"
#include "ETSIDI.h"
#include <string>
#include <stdlib.h>
using namespace std;



Pregunta::Pregunta(string p, string op1, string op2, string op3, string op4, unsigned char r)
{
	Preg = p;
	opciones[0] = op1;
	opciones[1] = op2;
	opciones[2] = op3;
	opciones[3] = op4;
	resp = r;
}


Pregunta::~Pregunta()
{
}

bool Pregunta::getCorrecion(unsigned char key)
{
	if (key == resp)
		return true;
	else
		return false;
}

void Pregunta::print()
{
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 12);
	ETSIDI::printxy(Preg.c_str(), -11,1.0, 15); 

	for (int i = 0; i < 4; i++)
	{
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 10);
		ETSIDI::printxy(opciones[i].c_str(), -11, 0 - i, 15); 
	}

}
