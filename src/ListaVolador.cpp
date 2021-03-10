#include "ListaVolador.h"
#include"Interaccion.h"



ListaVolador::ListaVolador()
{
	for (int i = 0; i < MAX; i++) ob[i] = 0;
	numero = 0;
}


ListaVolador::~ListaVolador()
{
}
void ListaVolador::dibuja()
{
	if (numero > 0) {
		for (int i = 0; i < numero; i++)
			ob[i]->dibuja();
	}
}
void ListaVolador::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		ob[i]->mueve(t);
}
bool ListaVolador::agregar(Volador* o)
{
	if (numero < MAX) {
		for (int i = 0; i < numero; i++) { //para vigilar que no se agregue el mismo dos veces
			if (ob[i] == o) return false;
		}
		ob[numero++] = o;
		return true;
	}
	return false;

}
bool ListaVolador::colision(Personaje h)
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

void ListaVolador::colision(Caja c)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision((ob[i]), c))
		{
			delete ob[i];

		}
	}
}
void ListaVolador::colision(Pared p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision((ob[i]), p))
		{
			ob[i]->setVel(0, 0);
		}
	}
}
void ListaVolador::destruirContenido()
{
	for (int i = 0; i < numero; i++) delete ob[i];
	numero = 0;
}
void ListaVolador::eliminar(int index)
{
	if ((index >= 0) || (index < numero)) {
		delete ob[index];
		numero--;
		for (int i = index; i < numero; i++)
			ob[i] = ob[i + 1];
	}
}

void ListaVolador::eliminar(Volador* o)
{
	for (int i = 0; i < numero; i++) {
		if (ob[i] == o)
		{
			eliminar(i);
			return;
		}
	}

}
Volador* ListaVolador::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return ob[i];
}
