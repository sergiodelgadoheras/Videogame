
#pragma once

#include "Pared.h"
#include <string>

using namespace std;

class Caja  
{
	friend class Interaccion;
	friend class Boss;
public:
	void dibuja();
	void dibuja_p2();
	void dibuja_p3();
	Caja();
	virtual ~Caja();
	float getSueloLimiteY2() { return suelo.getLimiteY2(); };
	void loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
private:
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;


};

