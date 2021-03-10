#pragma once
#include"Volador.h"
#include"Caja.h"
#include"Personaje.h"
#define MAX 3
class ListaVolador :public Volador
{
public:
	ListaVolador();
	~ListaVolador();
	bool agregar(Volador* ob);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	void colision(Pared p);
	void colision(Caja c);
	bool colision(Personaje h);
	
	Volador* operator[] (int index);
	int getNumero() { return numero; }
	void eliminar(Volador* ob);
	void eliminar(int index);
private:
	Volador* ob[MAX];
	int numero;
};
