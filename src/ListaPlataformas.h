#pragma once
#include<stdlib.h>
#include"glut.h"
#include"Pared.h"
#include "Personaje.h"
#define MAX 6
class ListaPlataformas
{
	friend class Interaccion;
private:
	Pared *Lista[MAX];
	int numero;
public:
	ListaPlataformas();
	~ListaPlataformas();
	bool Agregar(Pared *p);
	void dibuja();
	Pared * operator [] (int i);
	void rebote(Personaje &h,Pared *Lista);
	int getNumero() { return numero; }
};

