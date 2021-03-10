#include "ListaObjetoAtaca.h"
#include"Interaccion.h"

ListaObjetoAtaca::ListaObjetoAtaca()
{
	for (int i = 0; i < MAX; i++) ob[i] = 0;
	numero = 0;
}

ListaObjetoAtaca::~ListaObjetoAtaca(){}

void ListaObjetoAtaca::DibujaLimpieza()
{
	if (numero>0) {
		for (int i = 0; i < numero; i++)
			ob[i]->DibujaLimpieza();
	}
}
void ListaObjetoAtaca::DibujaAlumno()
{
	if (numero>0) {
		for (int i = 0; i < numero; i++)
			ob[i]->DibujaAlumno();
	}
}
void ListaObjetoAtaca::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		ob[i]->mueve(t);
}
bool ListaObjetoAtaca::agregar(ObjetoAtaca *o)
{

	for (int i = 0; i<numero; i++)//para evitar que se añada una esfera ya existente
		if (ob[i] == o)
			return false;

	if (numero<MAX)
		ob[numero++] = o;
	else
		return false;
	return true;
	
}
bool ListaObjetoAtaca::colision(Personaje h)
{
		for (int i = 0; i < numero; i++)
		{
			if (Interaccion::colision(*(ob[i]), h)) {
				eliminar(ob[i]);
				return true;
			}
		}
		return false; //no hay colisión
}


void ListaObjetoAtaca::colision(Caja c)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision((ob[i]), c))
		{
			delete ob[i];
		}
	}
}

void ListaObjetoAtaca::colision(Pared p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision((ob[i]), p))
		{
			ob[i]->setVel(0, 0);
		}
	}
}

void ListaObjetoAtaca::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete ob[i];
	numero = 0;
}

void ListaObjetoAtaca::eliminar(int index)
{
	if ((index >= 0) || (index < numero)) {
		delete ob[index];
		numero--;
		for (int i = index; i < numero; i++)
			ob[i] = ob[i + 1];
	}
}

void ListaObjetoAtaca::eliminar(ObjetoAtaca *o)
{
	for (int i = 0; i < numero; i++) {
		if (ob[i] == o)
		{
			eliminar(i);
			return;
		}
	}

}

ObjetoAtaca  *ListaObjetoAtaca::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return ob[i];
}
