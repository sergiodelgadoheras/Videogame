

#include "Esfera.h"
#include "glut.h"
                       //Esferas -- Libros

Esfera::Esfera():libro("imagenes/Volador.png",1)
{
	libro.setCenter(posicion.x, posicion.y);
	libro.setSize(3, 3);
	radio=1.0f;
	aceleracion.y=-9.8f;
	velocidad.x=4;
	velocidad.y=4;
}

Esfera::~Esfera(){}

Esfera::Esfera(float rad, float x, float y, float vx, float vy):libro("imagenes/Volador.png",1)
{
	libro.setCenter(posicion.x,posicion.y);
	libro.setSize(3, 6);
	radio=rad;
	posicion.x=x;
	posicion.y=y;
	velocidad.x=vx;
	velocidad.y=vy;
	setColor(255,255,100);
	aceleracion.y=-9.8;
}

void Esfera::dibuja()
{
	libro.setPos(getPosX()-1.5, getPosY()-1.5);
	//color.ponColor();
	//glTranslatef(posicion.x,posicion.y,0);
	//glutSolidSphere(radio,20,20);
	//glTranslatef(-posicion.x,-posicion.y,0);

	libro.setState(1, false);
	libro.draw();
	libro.loop();
}

void Esfera::setColor( Byte r,Byte v, Byte a)
{
	color.set(r,v,a);
}
void Esfera::setRadio(float r)
{
	if(r<0.1F)
		r=0.1F;
	radio=r;
}	
Esfera* Esfera::dividir()
{
		if (radio < 1.0f)
			return 0; //no dividimos
		radio /= 2.0f;//Dividimos el radio por 2

		//Creamos una esfera nueva, copiando la actual
		Esfera *aux = new Esfera(*this);
		
		//Les damos nuevas velocidades
		aux->setVel(5, 8);//a la nueva mitad
		setVel(-5, 8);//a la mitad original
		return aux;
}
