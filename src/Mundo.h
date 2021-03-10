//Derkach
#pragma once
#include "Caja.h"	
#include "Personaje.h"	
#include "Esfera.h"		
#include "ListaEsferas.h"		
#include "EsferaPulsante.h"
#include"ListaPlataformas.h"
#include"ListaObjetoAtaca.h"



class Mundo
{
	friend class CoordinadorETSIDI;

	//ListaEsferas esferas;
	Personaje personaje;
	Caja caja;
	Pared plataforma;
	ListaPlataformas plataformas;
	ListaObjetoAtaca enemigo;
	ListaEsferas volador;
	//CoordinadorETSIDI g;
	float c = 0;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto;
	int nivel, i, num = 3;
	float a = 0, b = 0;
	int genero;
public:  
	Mundo();
	~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa_p1();
	void inicializa_p2();
	void inicializa_p3();
	void rotarOjo();
	void mueve_p1();
	void mueve_p2();
	void mueve_p3();
	void dibuja_p1(int);
	void dibuja_p2(int);
	void dibuja_p3(int);
	bool getImpacto() { return impacto; };
	void resetImpacto() { impacto = false; };
	int getNumEsferas() { return volador.getNumero(); };
	float Ojo (Personaje p);
	float getOjoX();
	float getPosX() { return personaje.getPosX(); };
	
	

	
	


};
