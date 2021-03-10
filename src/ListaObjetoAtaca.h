#pragma once
#include"ObjetoAtaca.h"
#include"Caja.h"
#include"Personaje.h"
#define MAX 3
class ListaObjetoAtaca:public ObjetoAtaca
{
public:
	ListaObjetoAtaca();
	~ListaObjetoAtaca();
	bool agregar(ObjetoAtaca * ob);
	void destruirContenido();
	void mueve(float t);
	void DibujaLimpieza();
	void DibujaAlumno();
    void colision(Pared p);
	void colision(Caja c);
	bool colision(Personaje h);
	//bool colision(Mujer m);
	ObjetoAtaca* operator[] (int index);
	int getNumero() { return numero; }
	void eliminar(ObjetoAtaca* ob);
	void eliminar(int index);
private:
	ObjetoAtaca *ob[MAX];
	int numero;
};

