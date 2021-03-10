#include "Personaje.h"
#include "glut.h"

Personaje::Personaje() :hombre("imagenes/Hombres1.png", 5),mujer("imagenes/Chica.png", 7)
{
	Vector2D  Posicion(0, 2);
	setPos(Posicion);
	altura = 8.0f;
	aceleracion.y = -20.0f; //hay que aplicarle la gravedad para que se termine de caer siempre y no se quede colgado a una cota superior.
	hombre.setCenter(1, 0);
	hombre.setSize(2, 8);
	mujer.setCenter(1, 0);
	mujer.setSize(3.5, 8);
	
}

Personaje::~Personaje() {}


void Personaje::Dibujamujer() {

	//CARACTERISTICAS DE DIBUJA MUJER
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	//glutSolidSphere(altura, 20, 20); 

	//gestion de direccion y animacion
	if (velocidad.x>0.01)mujer.flip(false, false);
	if (velocidad.x<-0.01)mujer.flip(true, false);
	if ((velocidad.x<0.01) && (velocidad.x>-0.01))
		mujer.setState(0);
	else if (mujer.getState() == 0)
		mujer.setState(1, false);
	mujer.draw();
	glPopMatrix();
}
void Personaje::Dibujahombre() {
	//CARACTERÍSTICAS DE DIBUJA HOMBRE
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	//glutSolidSphere(altura, 20, 20); 

	//gestion de direccion y animacion
	if (velocidad.x>0.01)hombre.flip(false, false);
	if (velocidad.x<-0.01)hombre.flip(true, false);
	if ((velocidad.x<0.01) && (velocidad.x>-0.01))
		hombre.setState(0);
	else if (hombre.getState() == 0)
		hombre.setState(1, false);
	hombre.draw();
	glPopMatrix();
}
void Personaje::mueve(float t)
{
	ObjetoMovil::mueve(t);
	hombre.loop();
	mujer.loop();
}
