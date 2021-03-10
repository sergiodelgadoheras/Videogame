#pragma once

#include "Personaje.h"
#include "Caja.h"
#include "Esfera.h"
#include "ObjetoAtaca.h"
#include"ListaPlataformas.h"

class Interaccion  
{
public:
	
	Interaccion();
	virtual ~Interaccion();	

	//funciones que modifican (paso por referencia) los objetos que se les pasa como parametro	
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static void rebote(Personaje& h, Caja c);
	
	static bool rebote(Esfera& e1, Esfera& e2);
	static void rebote(Personaje& h, Pared plataforma);
	static void rebote(Personaje& h, Pared*p);


	//funciones de informacion, no cambian los objetos, solo devuelven true si hay colision
	static bool colision(Esfera e, Personaje h);
	static bool colision(ObjetoAtaca o, Personaje h);

	static bool colision(ObjetoAtaca* o, Pared p);
	static bool colision(ObjetoAtaca* o, Caja c);




};

